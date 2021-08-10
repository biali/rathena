// Complete Mount Rework (c) Biali
// Gmail: ubiali@gmail.com

#ifndef MOUNT_HPP
#define MOUNT_HPP

#include <map>
#include <vector>

#include "../common/database.hpp"
#include "../common/db.hpp"
#include "../common/malloc.hpp"
#include "../common/mmo.hpp" // ITEM_NAME_LENGTH

#include "script.hpp"
#include "status.hpp"

#define DEFAULT_MOUNT 1
#define MAX_MOUNT 100
// Moved to mmo.hpp because of the timers
//#define REMOUNT_TIME 30 // 30 seconds (multiplied by 6 when unmounted by dmg)



struct mount_data {
	uint32 id;
	std::string name;
	uint16 max_hp;
	short race;
	short ele;
	short ele_lvl;
	short size;
	short speed_bonus;
	short cast_time;
	uint16 aura;
	t_itemid summon_item;
	uint64 jobs[3]; //class_base
	uint16 classes; //cass_upper
	struct script_code *script;
	struct script_code *equip_script;
	struct script_code *unequip_script;

	~mount_data() {
		if (this->script){
			script_free_code(this->script);
			this->script = nullptr;
		}

		if (this->equip_script){
			script_free_code(this->equip_script);
			this->equip_script = nullptr;
		}

		if (this->unequip_script){
			script_free_code(this->unequip_script);
			this->unequip_script = nullptr;
		}
	}
};

class MountDatabase : public TypesafeCachedYamlDatabase<uint16, mount_data> {

public:
	MountDatabase() : TypesafeCachedYamlDatabase("MOUNT_DB", 1) {

	}

	const std::string getDefaultLocation();
	uint64 parseBodyNode(const YAML::Node& node);
	void loadingFinished();
};

extern MountDatabase mount_db;

// struct mount_data *mount_search(int);
struct mount_data* mountdb_exists(uint32 id);
void mount_setride(struct map_session_data *sd, mount_data *mdb);
void mount_desmount(struct map_session_data *sd, bool force);
void mount_pc_status(struct map_session_data *sd);

void do_init_mount(void);
void do_final_mount(void);

#endif