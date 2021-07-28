// Complete Faction System (c) Lilith
// Skype: amurov4shtefan
// ICQ: 450327002
// Gmail: amurov.ro@gmail.com
// MSN: amurov.ro@hotmail.com

#include "../common/db.hpp"
#include "../common/malloc.hpp"
#include "../common/socket.hpp"
#include "../common/showmsg.hpp"
#include "../common/strlib.hpp"
#include "../common/nullpo.hpp"

#include "atcommand.hpp"
#include "faction.hpp"
#include "elemental.hpp"
#include "guild.hpp"
#include "homunculus.hpp"
#include "intif.hpp"
#include "map.hpp"
#include "mercenary.hpp"
#include "mapreg.hpp"
#include "mob.hpp"
#include "npc.hpp"
#include "pc.hpp"
#include "pet.hpp"
#include "skill.hpp"
#include "status.hpp"
#include "script.hpp"
#include "channel.hpp"

#include <stdlib.h>

static DBMap* faction_db; // int faction_id -> struct faction_data*
static DBMap* voting_db; // int char_id -> struct voting_data*

struct guild factions[MAX_FACTION]; // Temporal fake guild information

int faction_reload_fvf_sub(struct block_list *bl, va_list ap)
{
	if( !faction_get_id(bl) )
		return 0;

	switch( bl->type ) {
		case BL_PC:
			{
				TBL_PC *sd = (TBL_PC*)bl;
				status_calc_pc(sd,SCO_NONE);
				if( !pc_isdead(sd) )
					pc_setpos(sd, sd->mapindex, bl->x, bl->y, CLR_OUTSIGHT);
			}
		break;

		case BL_NPC:
		case BL_MOB:
			{
				struct status_change* sc = status_get_sc(bl);
				if( sc->option&(OPTION_HIDE|OPTION_CLOAK|OPTION_CHASEWALK|OPTION_INVISIBLE) || sc->data[SC_CAMOUFLAGE] )
					break;
			}
		default:
			clif_spawn(bl);
		break;
	}
	return 0;
}

void faction_calc(struct block_list *bl)
{
	struct faction_data *fdb;

	if( (fdb = faction_search(faction_get_id(bl))) == NULL )
		return;

	if( bl->type == BL_PC ) {
		TBL_PC *sd = (TBL_PC*)bl;
		struct status_change *sc = status_get_sc(bl);
		int i;

	}

	if( battle_config.faction_status_bl&bl->type ) {
		struct status_data *status = bl->type == BL_MOB ? status_get_status_data(bl) : status_get_base_status(bl);

		status->race 	= fdb->race;
		status->def_ele	= fdb->ele;
		status->ele_lv 	= fdb->ele_lvl;
		status->size	= fdb->size;
	}
}

void faction_hp(struct map_session_data *sd)
{
	uint8 buf[34];
	const int cmd = 0x2e0;
	nullpo_retv(sd);

	WBUFW(buf,0) = cmd;
	WBUFL(buf,2) = sd->status.account_id;
	memcpy(WBUFP(buf,6), sd->status.name, NAME_LENGTH);

	if( sd->battle_status.max_hp > INT16_MAX ) {
		WBUFW(buf,30) = sd->battle_status.hp/(sd->battle_status.max_hp/100);
		WBUFW(buf,32) = 100;
	} else {
		WBUFW(buf,30) = sd->battle_status.hp;
		WBUFW(buf,32) = sd->battle_status.max_hp;
	}
	clif_send(buf, packet_len(cmd), &sd->bl, FACTION_AREA_WOS);
}


int faction_sendaurastoone(struct block_list *bl,va_list ap)
{
	struct map_session_data *sd = BL_CAST(BL_PC,bl);
	struct block_list *tbl = va_arg(ap,struct block_list*);
    int i;

    if( bl == tbl )
		return 1;

    clif_getareachar_unit(sd,tbl);
}

void faction_spawn(struct map_session_data *sd)
{
	if(sd->status.faction_id) {
		struct faction_data *fdb = NULL;
		if( (fdb = faction_search(sd->status.faction_id)) == NULL)  {
			ShowError("faction_spawn : Faction not found \n");
		} else {
			faction_update_data(sd);
			clif_bg_belonginfo(sd);
			clif_bg_emblem(sd, &sd->faction.g);

			clif_name_area(&sd->bl);

			// this will send the auras
			clif_hat_effect_single(&sd->bl,fdb->aura,true); //Area
			clif_hat_effect_single2(&sd->bl,fdb->aura,true); //Self

			map_foreachinrange(faction_sendaurastoone, &sd->bl, AREA_SIZE, BL_PC, &sd->bl);

			// this will change the cloth colors
			clif_refreshlook(&sd->bl,sd->bl.id,LOOK_CLOTHES_COLOR, fdb->ccolor,AREA);
		}
	}
}

struct faction_data *faction_search(int id)
{
	if(id < 1 || id > MAX_FACTION)
		return NULL;

	return (struct faction_data*)idb_get(faction_db,id);
}

int faction_get_id(struct block_list *bl)
{
	if( bl ) {
		switch( bl->type ) {
			case BL_PC:			// Player
				return ((TBL_PC*)bl)->status.faction_id;
			case BL_PET:		// Pet
				if( ((TBL_PET*)bl)->master )
					return ((TBL_PET*)bl)->master->status.faction_id;
			case BL_MOB:		// Monster
			{
				struct map_session_data *msd;
				struct mob_data *md = (TBL_MOB*)bl;
				if( md->special_state.ai && (msd = map_id2sd(md->master_id)) != NULL )
					return msd->status.faction_id;
				return md->faction_id;
			}
			// case BL_NPC:		// NPC
			// 	return ((TBL_NPC*)bl)->faction_id; //BIALI TODO: why are npcs crashing the server?
			case BL_HOM:		// Homunculus
				if( ((TBL_HOM*)bl)->master )
					return ((TBL_HOM*)bl)->master->status.faction_id;
			case BL_MER:		// Mercenary
				if( ((TBL_MER*)bl)->master )
					return ((TBL_MER*)bl)->master->status.faction_id;
			case BL_ELEM:		// Elemental
				if( ((TBL_ELEM*)bl)->master )
					return ((TBL_ELEM*)bl)->master->status.faction_id;
			case BL_SKILL:		// Skill
				return ((TBL_SKILL*)bl)->group->faction_id;
			default:
				return 0;
				break;
		}
	}
	return 0;
}


// ID,Faction Name,Faction Player name,Location,X,Y,Race,Element,Element lvl,Size,Clothes Color,Color of mes
static int faction_readdb(void)
{
	struct faction_data *fdb;
	const char *filename = "faction_db.txt";
	uint32 lines = 0, count = 0;
	char line[1024], path[256];
	FILE *fp;
	void *aChSysSave = NULL;

	memset(&factions, 0, sizeof(factions));

	sprintf(path, "%s/%s", db_path, filename);
	if((fp = fopen(path, "r")) == NULL ) {
		ShowWarning("faction_readdb: File not found \"%s\", skipping.\n", path);
		return 0;
	}

	while(fgets(line, sizeof(line), fp)) {
		char *str[14], *p, *p_tmp, map[MAP_NAME_LENGTH], out[100];
		int i, id, race, ele, ele_lvl, size, x, y, k = 0, ccolor, aura;
		unsigned long chat_color;
		uint16 mapindex = -1;
		FILE *fp2 = NULL;

		lines++;
		if(line[0] == '/' && line[1] == '/')
			continue;
		memset(out, 0, sizeof(out));
		memset(map, 0, sizeof(map));
		memset(str, 0, sizeof(str));

		p = line;

		while( ISSPACE(*p) )
			++p;
		if( *p == '\0' )
			continue;
		for( i = 0; i < 13; ++i ) {
			str[i] = p;
			p = strchr(p,',');
			if( p == NULL )
				break;
			*p = '\0';
			++p;
		}

		if( p == NULL ) {
			ShowError("faction_readdb: Insufficient columns in line %d of \"%s\" (faction id %d), skipping.\n", lines, path, atoi(str[0]));
			continue;
		}

		id = atoi(str[0]);

		if( id < 1 || id > MAX_FACTION ) {
			ShowError("faction_readdb : Incorrect Faction ID: %d, must be between 0 and %d\n", id, MAX_FACTION);
			continue;
		} else if( faction_search(id) ) {
			ShowError("faction_readdb : Duplicate Faction ID %d, line %d.\n", id, lines);
			continue;
		}

		safestrncpy(map,str[3],MAP_NAME_LENGTH);
		if( map[0] != '\0' && (mapindex = mapindex_name2id(map)) < 0 ) {
			ShowWarning("faction_readdb: Invalid map: '%s' in line %d of \"%s\" (faction id %d).\n", map, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb: removing home location...\n");
			memset(map, '\0', sizeof(map));
		}

		if( mapindex >= 0 ) {
			x = atoi(str[4]);
			if( x < 0 || x > 512 ) {
				ShowWarning("faction_readdb : Invalid X coordinate: %d, in line %d of \"%s\" (faction id %d).\n", x, lines, path, atoi(str[0]));
				ShowWarning("faction_readdb : X must be between 0 and 512. Default to 0.\n");
				x = 0;
			}

			y = atoi(str[5]);
			if( y < 0 || y > 512 ) {
				ShowWarning("faction_readdb : Invalid Y coordinate: %d, in line %d of \"%s\" (faction id %d).\n", y, lines, path, atoi(str[0]));
				ShowWarning("faction_readdb : Y must be between 0 and 512. Default to 0.\n");
				y = 0;
			}
		} else x = y = 0;

		race = atoi(str[6]);
		if( race < RC_FORMLESS || race > RC_DRAGON ) {
			ShowWarning("faction_readdb : Invalid race: %d, in line %d of \"%s\" (faction id %d).\n", race, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb : race must be between %d and %d. Default to %d.\n", RC_FORMLESS, RC_DRAGON, RC_DEMIHUMAN);
			race = RC_DEMIHUMAN;
		}

		ele = atoi(str[7]);
		if( ele < ELE_NEUTRAL || ele > ELE_UNDEAD ) {
			ShowWarning("faction_readdb : Invalid element: %d, in line %d of \"%s\" (faction id %d).\n", ele, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb : element must be between %d and %d. Default to %d.\n", ELE_NEUTRAL, ELE_UNDEAD, ELE_NEUTRAL);
			ele = ELE_NEUTRAL;
		}

		ele_lvl = atoi(str[8]);
		if( ele_lvl < 1 || ele_lvl > 4 ) {
			ShowWarning("faction_readdb : Invalid element level: %d, in line %d of \"%s\" (faction id %d).\n", ele_lvl, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb : element must be between 1 and 4. Default to 1.\n");
			ele_lvl = 1;
		}

		size = atoi(str[9]);
		if( size < 0 || size > 2 ) {
			ShowWarning("faction_readdb : Invalid size: %d, in line %d of \"%s\" (faction id %d).\n", size, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb : size must be 0, 1 or 2. Default to 0.\n");
			size = 0;
		}

		ccolor = atoi(str[10]);
		if( ccolor < battle_config.min_cloth_color || ccolor > battle_config.max_cloth_color ) {
			ShowWarning("faction_readdb : Invalid clothes color: %d, in line %d of \"%s\" (faction id %d).\n", ccolor, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb : clothes color must be between %d and %d. Default to %d.\n", battle_config.min_cloth_color, battle_config.max_cloth_color, battle_config.min_cloth_color);
			ccolor = battle_config.min_cloth_color;
		}

		chat_color = strtoul(str[11],NULL,0);
		chat_color = ( chat_color&0x0000FF ) << 16 | ( chat_color&0x00FF00 ) | ( chat_color&0xFF0000 ) >> 16;

		aura = atoi(str[12]);
		if( aura < 1 || aura > INT_MAX ) {
			ShowWarning("faction_readdb : Invalid size: %d, in line %d of \"%s\" (faction id %d).\n", aura, lines, path, atoi(str[0]));
			ShowWarning("faction_readdb : size must between 204 and %d. Default to 204.\n",INT_MAX);
			aura = 204;
		}

		CREATE(fdb,struct faction_data,1);
		fdb->id = id;
		safestrncpy(fdb->name,str[1],sizeof(fdb->name));
		safestrncpy(fdb->pl_name,str[2],sizeof(fdb->pl_name));
		memcpy(fdb->map, map, MAP_NAME_LENGTH);
		fdb->x = x;
		fdb->y = y;
		fdb->race = race;
		fdb->ele = ele;
		fdb->ele_lvl = ele_lvl;
		fdb->size = size;
		fdb->ccolor = ccolor;
		fdb->chat_color = chat_color;
		fdb->aura = aura;

		fdb->emblem_id = 1;
		sprintf(path, "%s/emblems/faction_%d.ebm", db_path, id);
		if( (fp2 = fopen(path, "rb")) != NULL ) {
			fseek(fp2, 0, SEEK_END);
			fdb->emblem_len = ftell(fp2);
			fseek(fp2, 0, SEEK_SET);
			fread(&fdb->emblem_data, 1, fdb->emblem_len, fp2);
			fclose(fp2);
		}

		idb_put(faction_db,id,fdb);

		factions[id].guild_id = INT16_MAX - 100 - fdb->id;
		factions[id].guild_lv = 1;
		factions[id].emblem_id = 1; // Emblem Index
		factions[id].emblem_len = fdb->emblem_len;
		memcpy(factions[id].emblem_data, fdb->emblem_data, sizeof(fdb->emblem_data));
		factions[id].max_member = MAX_CLAN;
		snprintf(factions[id].name, NAME_LENGTH, fdb->name); 
		safestrncpy(factions[id].master, fdb->pl_name, NAME_LENGTH);
		snprintf(factions[id].position[0].name, NAME_LENGTH, "%s Leader", fdb->pl_name);
		safestrncpy(factions[id].position[1].name, fdb->pl_name, NAME_LENGTH);


		count++;
	}
	fclose(fp);
	ShowStatus("Done reading '" CL_WHITE"%lu" CL_RESET "' factions in file '" CL_WHITE "%s" CL_RESET "'.\n", count, filename);

	return 0;
}

// by biali
void faction_update_data(struct map_session_data *sd) {
	
	nullpo_retv(sd);
	
	if(sd->status.faction_id > 0) { 
		//someone has joined the faction
		sd->faction.g = factions[sd->status.faction_id];
		sd->guild_emblem_id = factions[sd->status.faction_id].emblem_id;
		safestrncpy(sd->faction.name, sd->faction.g.name, NAME_LENGTH);
		safestrncpy(sd->faction.pl_name, sd->faction.g.position[1].name, NAME_LENGTH);
	} else {
		//someone has left the faction
		faction_leave(sd);
	}

	return;
}

void faction_leave( struct map_session_data *sd) {
	
	nullpo_retv(sd);

	if(!sd->status.faction_id)
		return;

	struct faction_data *fdb = faction_search(sd->status.faction_id);

	clif_name_area(&sd->bl);
	clif_refreshlook(&sd->bl,sd->bl.id,LOOK_CLOTHES_COLOR,sd->vd.cloth_color,AREA);
	clif_hat_effect_single(&sd->bl,fdb->aura,false); //Area
	clif_hat_effect_single2(&sd->bl,fdb->aura,false); //Self

	struct guild *g = NULL;
	sd->status.faction_id = 0;
	sd->faction = {};
	sd->faction.g = {};
	sd->guild_emblem_id = 0;
	if (sd->status.guild_id && (g = guild_search(sd->status.guild_id)) != NULL) {
		//if player was originally in a guild... reload its info
		sd->guild_emblem_id = sd->guild->emblem_id;
		clif_guild_belonginfo(sd);
		clif_guild_basicinfo(sd);
		clif_guild_allianceinfo(sd);
		clif_guild_memberlist(sd);
		clif_guild_skillinfo(sd);
		clif_guild_emblem(sd, g);
	} else {
		//else clean all the visuals related to guild
		clif_messagecolor(&sd->bl, color_table[COLOR_RED], "Please log out to reload the visual information of your char.", false, SELF);
	}

}


static void destroy_faction_data(struct faction_data *self, int free_self)
{
	if( self == NULL )
		return;

	if( free_self )
		aFree(self);
}

static int faction_final_sub(DBKey key, DBData *data, va_list ap)
{
	struct faction_data *fdb = (struct faction_data *)db_data2ptr(data);

	if( fdb != NULL )
		destroy_faction_data(fdb, 1);

	return 0;
}

void faction_read(void)
{
	faction_readdb();
}

void do_reload_faction(void)
{
	faction_db->clear(faction_db,faction_final_sub);
	faction_read();
	map_foreachiddb(faction_reload_fvf_sub);
}

void do_init_faction(void)
{
	faction_db 	= idb_alloc(DB_OPT_BASE);
	faction_read();
}

void do_final_faction(void)
{
	// DBIterator *iter = db_iterator(faction_db);
	// struct faction_data *fdb;

    // for( fdb = (struct faction_data*)dbi_first(iter); dbi_exists(iter); fdb = (struct faction_data*)dbi_next(iter) ) {
    //     if( fdb->channel != NULL )
    //         channel_delete(fdb->channel,false);
    // }

	// dbi_destroy(iter);

	faction_db->destroy(faction_db,faction_final_sub);
}