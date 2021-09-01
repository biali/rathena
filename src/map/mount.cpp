// Complete Mount Rework (c) Biali
// Gmail: ubiali@gmail.com

#include "mount.hpp"

#include <map>
#include <stdlib.h>

#include "../common/nullpo.hpp"
#include "../common/random.hpp"
#include "../common/showmsg.hpp"
#include "../common/strlib.hpp"
#include "../common/utils.hpp"
#include "../common/utilities.hpp"

#include "battle.hpp" // struct battle_config
#include "cashshop.hpp"
#include "clif.hpp"
#include "intif.hpp"
#include "log.hpp"
#include "mob.hpp"
#include "pc.hpp"
#include "status.hpp"


using namespace rathena;

static void itemdb_jobid2mapid(uint64 bclass[3], e_mapid jobmask, bool active);

const std::string MountDatabase::getDefaultLocation(){
	return std::string(db_path) + "/mount_db.yml";
}

/**
 * Reads and parses an entry from the mount_db.
 * @param node: YAML node containing the entry.
 * @return count of successfully parsed rows
 */
uint64 MountDatabase::parseBodyNode(const YAML::Node &node) {
	uint32 id;

	if (!this->asUInt32(node, "Id", id))
		return 0;

	std::shared_ptr<mount_data> mount = this->find(id);
	bool exists = mount != nullptr;

	if (!exists) {
		mount = std::make_shared<mount_data>();
		mount->id = id;
		// mount->flag.available = true;
	}

	if (this->nodeExists(node, "Name")) {
		std::string name;

		if (!this->asString(node, "Name", name))
			return 0;

		mount->name.resize(ITEM_NAME_LENGTH);
		mount->name = name.c_str();
	}
	// Max HP
	if (this->nodeExists(node, "MaxHP")) {
		uint32 max_hp;

		if (!this->asUInt32(node, "MaxHP", max_hp))
			return 0;

		mount->max_hp = max_hp;
	} else {
		if (!exists)
			mount->max_hp = 5000;
	}
	//Race
	if (this->nodeExists(node, "Race")) {
		uint16 race;

		if (!this->asUInt16(node, "Race", race))
			return 0;

		mount->race = race;
	} else {
		if (!exists)
			mount->race = 2;
	}
	//Element
	if (this->nodeExists(node, "Element")) {
		uint16 ele;

		if (!this->asUInt16(node, "Element", ele))
			return 0;

		mount->ele = ele;
	} else {
		if (!exists)
			mount->ele = 0;
	}
	//Element Level
	if (this->nodeExists(node, "ElementLvl")) {
		uint16 ele_lvl;

		if (!this->asUInt16(node, "ElementLvl", ele_lvl))
			return 0;

		mount->ele_lvl = ele_lvl;
	} else {
		if (!exists)
			mount->ele_lvl = 1;
	}
	//Size
	if (this->nodeExists(node, "Size")) {
		uint16 size;

		if (!this->asUInt16(node, "Size", size))
			return 0;

		mount->size = size;
	} else {
		if (!exists)
			mount->size = 0;
	}
	//Speed bonus
	if (this->nodeExists(node, "SpeedBonus")) {
		uint16 speed_bonus;

		if (!this->asUInt16(node, "SpeedBonus", speed_bonus))
			return 0;

		mount->speed_bonus = speed_bonus;
	} else {
		if (!exists)
			mount->speed_bonus = 25;
	}
	//Cast Time
	if (this->nodeExists(node, "Cast")) {
		uint16 cast_time;

		if (!this->asUInt16(node, "Cast", cast_time))
			return 0;

		mount->cast_time = cast_time;
	} else {
		if (!exists)
			mount->cast_time = 5;
	}
	//Hateffect (aura)
	if (this->nodeExists(node, "Aura")) {
		uint16 aura;

		if (!this->asUInt16(node, "Aura", aura))
			return 0;

		mount->aura = aura;
	} else {
		if (!exists)
			mount->aura = 0;
	}
	//Summon Item
	if( this->nodeExists( node, "SummonItem" ) ){
		std::string summon_item;

		if( !this->asString( node, "SummonItem", summon_item ) ){
			return 0;
		}

		struct item_data* item = itemdb_search_aegisname( summon_item.c_str() );

		if( item == nullptr ){
			this->invalidWarning( node["SummonItem"], "Summon item %s does not exist.\n", summon_item.c_str() );
			return 0;
		}

		mount->summon_item = item->nameid;
		item->flag.isMount = true;
	}else{
		if( !exists ){
			mount->summon_item = 0;
		}
	}
	// Jobs
	if (this->nodeExists(node, "Jobs")) {
		const YAML::Node &jobNode = node["Jobs"];

		mount->jobs[0] = mount->jobs[1] = mount->jobs[2] = 0;

		if (this->nodeExists(jobNode, "All")) {
			bool active;

			if (!this->asBool(jobNode, "All", active))
				return 0;

			itemdb_jobid2mapid(mount->jobs, MAPID_ALL, active);
		}

		for (const auto &jobit : jobNode) {
			std::string jobName = jobit.first.as<std::string>();

			// Skipped because processed above the loop
			if (jobName.compare("All") == 0)
				continue;

			std::string jobName_constant = "EAJ_" + jobName;
			int64 constant;

			if (!script_get_constant(jobName_constant.c_str(), &constant)) {
				this->invalidWarning(jobNode[jobName], "Invalid mount job %s, defaulting to All.\n", jobName.c_str());
				itemdb_jobid2mapid(mount->jobs, MAPID_ALL, true);
				break;
			}

			bool active;

			if (!this->asBool(jobNode, jobName, active))
				return 0;

			itemdb_jobid2mapid(mount->jobs, static_cast<e_mapid>(constant), active);
		}
	} else {
		if (!exists) {
			mount->jobs[0] = mount->jobs[1] = mount->jobs[2] = 0;

			itemdb_jobid2mapid(mount->jobs, MAPID_ALL, true);
		}
	}
	// Classes
	if (this->nodeExists(node, "Classes")) {
		const YAML::Node &classNode = node["Classes"];

		if (this->nodeExists(classNode, "All")) {
			bool active;

			if (!this->asBool(classNode, "All", active))
				return 0;

			if (active)
				mount->classes |= ITEMJ_ALL;
			else
				mount->classes &= ~ITEMJ_ALL;
		}

		for (const auto &classit : classNode) {
			std::string className = classit.first.as<std::string>();

			// Skipped because processed above the loop
			if (className.compare("All") == 0)
				continue;

			std::string className_constant = "ITEMJ_" + className;
			int64 constant;

			if (!script_get_constant(className_constant.c_str(), &constant)) {
				this->invalidWarning(classNode[className], "Invalid class upper %s, defaulting to All.\n", className.c_str());
				mount->classes |= ITEMJ_ALL;
				break;
			}

			bool active;

			if (!this->asBool(classNode, className, active))
				return 0;

			if (active)
				mount->classes |= constant;
			else
				mount->classes &= ~constant;
		}
	} else {
		if (!exists)
			mount->classes = ITEMJ_ALL;
	}
	//Script
	if (this->nodeExists(node, "Script")) {
		std::string script;

		if (!this->asString(node, "Script", script))
			return 0;

		if (exists && mount->script) {
			script_free_code(mount->script);
			mount->script = nullptr;
		}

		mount->script = parse_script(script.c_str(), this->getCurrentFile().c_str(), node["Script"].Mark().line + 1, SCRIPT_IGNORE_EXTERNAL_BRACKETS);
	} else {
		if (!exists) 
			mount->script = nullptr;
	}
	// Script Equip
	if (this->nodeExists(node, "EquipScript")) {
		std::string script;

		if (!this->asString(node, "EquipScript", script))
			return 0;

		if (exists && mount->equip_script) {
			script_free_code(mount->equip_script);
			mount->equip_script = nullptr;
		}

		mount->equip_script = parse_script(script.c_str(), this->getCurrentFile().c_str(), node["EquipScript"].Mark().line + 1, SCRIPT_IGNORE_EXTERNAL_BRACKETS);
	} else {
		if (!exists)
			mount->equip_script = nullptr;
	}
	// Script Unequip
	if (this->nodeExists(node, "UnEquipScript")) {
		std::string script;

		if (!this->asString(node, "UnEquipScript", script))
			return 0;

		if (exists && mount->unequip_script) {
			script_free_code(mount->unequip_script);
			mount->unequip_script = nullptr;
		}

		mount->unequip_script = parse_script(script.c_str(), this->getCurrentFile().c_str(), node["UnEquipScript"].Mark().line + 1, SCRIPT_IGNORE_EXTERNAL_BRACKETS);
	} else {
		if (!exists)
			mount->unequip_script = nullptr;
	}

	if( !exists ){
		this->put( id, mount );
	}

	return 1;
}

MountDatabase mount_db;

/** Searches for the mount_data. Use this to check if mount exists or not.
* @param id
* @return *mount_data if item is exist, or NULL if not
*/
struct mount_data* mountdb_exists(uint32 id) {
	std::shared_ptr<mount_data> mount = mount_db.find(id);

	return mount ? mount.get() : nullptr;
}

void MountDatabase::loadingFinished(){
	if( !this->exists( ITEMID_DUMMY ) ){
		// Create dummy item
		std::shared_ptr<mount_data> dummy_mount = std::make_shared<mount_data>();

		dummy_mount->id = ITEMID_DUMMY;
		dummy_mount->name = "UNKNOWN_ITEM";
		dummy_mount->summon_item = ITEMID_DUMMY;

		mount_db.put( ITEMID_DUMMY, dummy_mount );
	}
}

/**
 * Converts the jobmask from the format in itemdb to the format used by the map server.
 * @param bclass: Pointer to store itemdb format
 * @param jobmask: Job Mask to convert
 * @param active: Whether the flag is active or not
 * @author: Skotlex
 */
static void itemdb_jobid2mapid(uint64 bclass[3], e_mapid jobmask, bool active)
{
	uint64 temp_mask[3] = { 0 };

	if (jobmask != MAPID_ALL) {
		// Calculate the required bit to set
		uint64 job = 1ULL << ( jobmask & MAPID_BASEMASK );

		// 2-1
		if( ( jobmask & JOBL_2_1 ) != 0 ){
			temp_mask[1] |= job;
		// 2-2
		}else if( ( jobmask & JOBL_2_2 ) != 0 ){
			temp_mask[2] |= job;
		// Basejob
		}else{
			temp_mask[0] |= job;
		}
	} else {
		temp_mask[0] = temp_mask[1] = temp_mask[2] = MAPID_ALL;
	}

	for (int i = 0; i < ARRAYLENGTH(temp_mask); i++) {
		if (temp_mask[i] == 0)
			continue;

		if (active)
			bclass[i] |= temp_mask[i];
		else
			bclass[i] &= ~temp_mask[i];
	}
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
		sd->mount_id = mdb->id;
		clif_hat_effect_single(&sd->bl,mdb->aura,true);
		mount_pc_status(sd);
	}
}

void mount_desmount(struct map_session_data *sd, bool force) {
	int val;
	if(!force)
		val = REMOUNT_TIMER * 1000;
	else
		val = REMOUNT_TIMER * 6 * 1000;

    status_change_end(&sd->bl, SC_ALL_RIDING, INVALID_TIMER); //release mount
	struct mount_data *mdb = mountdb_exists(sd->mount_id);
	clif_hat_effect_single(&sd->bl,mdb->aura,false); //Area
	sd->mount_id = 0;
	mount_pc_status(sd);
	pc_setremounttimer(sd,val);
}

void mount_pc_status(struct map_session_data *sd) {
	short speed;
	struct mount_data *mdb = NULL;
	struct status_data *status = status_get_base_status(&sd->bl);
	if( (mdb = mountdb_exists(sd->mount_id)) != NULL) {
		sd->tmp_hp = pc_readparam(sd, SP_HP);
		sd->tmp_maxhp = pc_readparam(sd, SP_MAXHP);
		pc_setparam( sd, SP_MAXHP, mdb->max_hp );
    	pc_setparam( sd, SP_HP, mdb->max_hp );

		status->race 	 = mdb->race;
		status->def_ele	 = mdb->ele;
		status->ele_lv 	 = mdb->ele_lvl;
		status->size	 = mdb->size;

		speed = DEFAULT_WALK_SPEED - mdb->speed_bonus;
		sd->base_status.speed = cap_value(speed, MIN_WALK_SPEED, MAX_WALK_SPEED);
		if (sd->base_status.speed != DEFAULT_WALK_SPEED)
			sd->state.permanent_speed = 1; // Set lock when set to non-default speed.
		status_calc_bl(&sd->bl, SCB_SPEED|SCB_SIZE|SCB_RACE|SCB_ATK_ELE|SCB_DEF_ELE);

		run_script(mdb->script,0,sd->bl.id,0);
		pc_bonus_script(sd);
		// status_calc_pc(sd,SCO_NONE);
	} else{
		pc_setparam( sd, SP_MAXHP, (sd->tmp_maxhp)?:sd->status.max_hp);
		pc_setparam( sd, SP_HP, (sd->tmp_hp)?:sd->status.hp);
		sd->state.permanent_speed = 0; // Remove lock when set back to default speed.
		sd->base_status.speed = DEFAULT_WALK_SPEED;
		status_calc_bl(&sd->bl, SCB_SPEED|SCB_MAXHP|SCB_SIZE|SCB_RACE|SCB_ATK_ELE|SCB_DEF_ELE);
		status_calc_pc(sd,SCO_NONE);
	}
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

static void mount_read(void)
{
	mount_db.load();
	// mount_readdb();
}

void do_init_mount(void)
{
	// mount_db 	= idb_alloc(DB_OPT_BASE);
	mount_read();
}

void do_final_mount(void)
{
	mount_db.clear();
	// mount_db->destroy(mount_db,mount_final_sub);
}