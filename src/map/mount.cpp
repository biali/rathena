// Complete Mount Rework (c) Biali
// Gmail: ubiali@gmail.com

#include "mount.hpp"

#include <map>

#include <math.h>
#include <stdlib.h>

#include <yaml-cpp/yaml.h>

#include "../common/cbasetypes.hpp"
#include "../common/core.hpp" // get_svn_revision()
#include "../common/ers.hpp"  // ers_destroy
#include "../common/malloc.hpp"
#include "../common/mmo.hpp" //NAME_LENGTH
#include "../common/nullpo.hpp"
#include "../common/showmsg.hpp"
#include "../common/socket.hpp" // session[]
#include "../common/strlib.hpp" // safestrncpy()
#include "../common/timer.hpp"
#include "../common/utilities.hpp"
#include "../common/utils.hpp"

#include "battle.hpp"
#include "clif.hpp"
#include "map.hpp"
#include "pc.hpp"
#include "status.hpp"

static DBMap* mount_db=NULL;

struct mount_data *mount_search(int id)
{
	if(id < 1 || id > MAX_MOUNT)
		return NULL;

	return (struct mount_data*)idb_get(mount_db,id);
}


int mount_aura_clear(struct block_list *bl,va_list ap)
{
	struct map_session_data *sd = BL_CAST(BL_PC,bl);
	struct block_list *tbl = va_arg(ap,struct block_list*);

	if( bl == tbl )
		return 0;

	clif_getareachar_unit(sd,tbl);
	return 0;
}


int mount_sendaurastoone(struct block_list *bl,va_list ap)
{
	struct map_session_data *sd = BL_CAST(BL_PC,bl);
	struct block_list *tbl = va_arg(ap,struct block_list*);
    int i;

    if( bl == tbl )
		return 1;

    clif_getareachar_unit(sd,tbl);

}

void mount_setride(struct map_session_data *sd, struct mount_data *mdb) {
	if(sd->mount_remount_timer != INVALID_TIMER) {
		clif_messagecolor(&sd->bl,color_table[COLOR_RED],"You can't mount right now.",false,SELF);
	} else {
		sc_start(NULL, &sd->bl, SC_ALL_RIDING, 10000, 1, INFINITE_TICK); //mount
		sd->mount = mdb->id;
		clif_hat_effect_single(&sd->bl,mdb->aura,true);
		mount_pc_status(sd);
		//map_foreachinrange(mount_sendaurastoone, &sd->bl, AREA_SIZE, BL_PC, &sd->bl);
	}
}

void mount_desmount(struct map_session_data *sd) {
	if(pc_readparam(sd, SP_HP >= 1))
		pc_setremounttimer(sd,REMOUNT_TIMER * 1000);
	else
		pc_setremounttimer(sd,REMOUNT_TIMER * 6 * 1000);
    status_change_end(&sd->bl, SC_ALL_RIDING, INVALID_TIMER); //release mount
	struct mount_data *mdb = mount_search(sd->mount);
    sd->mount = 0;
	clif_hat_effect_single(&sd->bl,mdb->aura,false); //Area
	mount_pc_status(sd);
    //map_foreachinrange(mount_sendaurastoone, &sd->bl, AREA_SIZE, BL_PC, &sd->bl);
    //clif_refresh(sd);
}

void mount_pc_status(struct map_session_data *sd) {

	struct mount_data *mdb = NULL;
	struct status_data *status = status_get_base_status(&sd->bl);
	
	if( (mdb = mount_search(sd->mount)) != NULL) {
		pc_setparam( sd, SP_MAXHP, mdb->max_hp );
    	pc_setparam( sd, SP_HP, mdb->max_hp );

		status->race 	= mdb->race;
		status->def_ele	= mdb->ele;
		status->ele_lv 	= mdb->ele_lvl;
		status->size	= mdb->size;

		run_script(mdb->script,0,sd->bl.id,0);
		pc_bonus_script(sd);

	} else{
		ShowWarning("Biali entrou aki \m");
		pc_setparam( sd, SP_MAXHP, sd->status.max_hp );
		pc_setparam( sd, SP_HP, sd->status.hp );
		status_calc_pc(sd,SCO_NONE);
	}
}


// ID,Mount Name,Max_hp,Race,Element,Element lvl,Size,skill_id,skill_lv,{ Aura: #1 #2 #3 }
static int mount_readdb(void)
{
	struct mount_data *mdb;
	const char *filename = "mount_db.txt";
	uint32 lines = 0, count = 0;
	char line[1024], path[256];
	FILE *fp;
	void *aChSysSave = NULL;

	struct item_data *idt = NULL;

	sprintf(path, "%s/%s", db_path, filename);
	if((fp = fopen(path, "r")) == NULL ) {
		ShowWarning("mount_readdb: File not found \"%s\", skipping.\n", path);
		return 0;
	}

	while(fgets(line, sizeof(line), fp)) 
	{
		char *str[32], *p;
		int i, id, max_hp, race, ele, ele_lvl, size, skill_id, skill_lv, speed_bonus, cast_time, aura, k = 0;
		t_itemid item;

		lines++;
		if(line[0] == '/' && line[1] == '/')
			continue;
		memset(str, 0, sizeof(str));

		p = line;
		while( ISSPACE(*p) )
			++p;
		if( *p == '\0' )
			continue;
		for( i = 0; i < 11; ++i ) {
			str[i] = p;
			p = strchr(p,',');
			if( p == NULL )
				break;
			*p = '\0';
			++p;
		}

		if( p == NULL ) {
			ShowError("mount_readdb: Insufficient columns in line %d of \"%s\" (mount id %d), skipping.\n", lines, path, atoi(str[0]));
			continue;
		}

		id = atoi(str[0]);

		if( id < 1 || id > MAX_MOUNT ) {
			ShowError("mount_readdb : Incorrect Mount ID: %d, must be between 0 and %d\n", id, MAX_MOUNT);
			continue;
		} else if( mount_search(id) ) {
			ShowError("mount_readdb : Duplicate Mount ID %d, line %d.\n", id, lines);
			continue;
		}

		max_hp = atoi(str[2]);
		if( max_hp < 1 || max_hp > INT_MAX ) {
			ShowWarning("mount_readdb : Invalid max_hp: %d, in line %d of \"%s\" (Mount id %d).\n", max_hp, lines, path, atoi(str[0]));
			ShowWarning("mount_readdb : Max HP must be between %d and %d. Default to %d.\n", 1, INT_MAX, 1);
			max_hp = 1;
		}

		race = atoi(str[3]);
		if( race < RC_FORMLESS || race > RC_DRAGON ) {
			ShowWarning("mount_readdb : Invalid race: %d, in line %d of \"%s\" (Mount id %d).\n", race, lines, path, atoi(str[0]));
			ShowWarning("mount_readdb : race must be between %d and %d. Default to %d.\n", RC_FORMLESS, RC_DRAGON, RC_DEMIHUMAN);
			race = RC_DEMIHUMAN;
		}

		ele = atoi(str[4]);
		if( ele < ELE_NEUTRAL || ele > ELE_UNDEAD ) {
			ShowWarning("mount_readdb : Invalid element: %d, in line %d of \"%s\" (Mount id %d).\n", ele, lines, path, atoi(str[0]));
			ShowWarning("mount_readdb : element must be between %d and %d. Default to %d.\n", ELE_NEUTRAL, ELE_UNDEAD, ELE_NEUTRAL);
			ele = ELE_NEUTRAL;
		}

		ele_lvl = atoi(str[5]);
		if( ele_lvl < 1 || ele_lvl > 4 ) {
			ShowWarning("mount_readdb : Invalid element level: %d, in line %d of \"%s\" (Mount id %d).\n", ele_lvl, lines, path, atoi(str[0]));
			ShowWarning("mount_readdb : element must be between 1 and 4. Default to 1.\n");
			ele_lvl = 1;
		}

		size = atoi(str[6]);
		if( size < 0 || size > 2 ) {
			ShowWarning("mount_readdb : Invalid size: %d, in line %d of \"%s\" (Mount id %d).\n", size, lines, path, atoi(str[0]));
			ShowWarning("mount_readdb : size must be 0, 1 or 2. Default to 0.\n");
			size = 0;
		}

		speed_bonus = atoi(str[7]);
		if( speed_bonus < -100 || speed_bonus > 100 ) {
			ShowWarning("mount_readdb : Invalid speed bonus: %d, in line %d of \"%s\" (Mount id %d).\n", speed_bonus, lines, path, atoi(str[0]));
			ShowWarning("mount_readdb : speed must be between -100 and 100. Default to 25.\n");
			speed_bonus = 25;
		}

        cast_time = atoi(str[8]);
		if( cast_time < 0 || cast_time > 60 ) {
			ShowWarning("mount_readdb : Invalid cast time: %d, in line %d of \"%s\" (Mount id %d).\n", cast_time, lines, path, atoi(str[0]));
			ShowWarning("mount_readdb : cast time must be between 1 and 60. Default to 1.\n");
			cast_time = 1;
		}

		aura = atoi(str[9]);
		if( aura < 0 || aura > INT_MAX ) {
			ShowWarning("mount_readdb : Invalid aura: %d, in line %d of \"%s\" (Mount id %d).\n", aura, lines, path, atoi(str[0]));
			ShowWarning("mount_readdb : aura must be between 0 and %d. Default to 0.\n",INT_MAX);
			aura = 0;
		}

		item = atoi(str[10]);
		if( (idt = itemdb_search(item)) == NULL ) {
			ShowWarning("mount_readdb : Invalid item: %d, in line %d of \"%s\" (Mount id %d). Skipping.\n", item, lines, path, atoi(str[0]));
			continue;
		} else 
			idt->flag.isMount = true;

		// // script
		str[11] = p;

		CREATE(mdb,struct mount_data,1);
		mdb->id = id;
		safestrncpy(mdb->name,str[1],sizeof(mdb->name));
		mdb->max_hp = max_hp;
		mdb->race = race;
		mdb->ele = ele;
		mdb->ele_lvl = ele_lvl;
		mdb->size = size;
		mdb->skill_id = skill_id;
		mdb->skill_lv = skill_lv;
		mdb->speed_bonus = speed_bonus;
        mdb->cast_time = cast_time;
		mdb->aura = aura;
		mdb->script = parse_script(str[11],path,lines,0);

		idb_put(mount_db,id,mdb);

		count++;
	}
	fclose(fp);
	ShowStatus("Done reading '" CL_WHITE"%lu" CL_RESET "' mounts in file '" CL_WHITE "%s" CL_RESET "'.\n", count, filename);

	return 0;
}

static void destroy_mount_data(struct mount_data *self, int free_self)
{
	if( self == NULL )
		return;
	if( free_self )
		aFree(self);
}

static int mount_final_sub(DBKey key, DBData *data, va_list ap)
{
	struct mount_data *mdb = (struct mount_data *)db_data2ptr(data);

	if( mdb != NULL )
		destroy_mount_data(mdb, 1);

	return 0;
}

void mount_read(void)
{
	mount_readdb();
}

void do_init_mount(void)
{
	mount_db 	= idb_alloc(DB_OPT_BASE);
	mount_read();
}

void do_final_mount(void)
{
	mount_db->destroy(mount_db,mount_final_sub);
}