// Complete Mount Rework (c) Biali
// Gmail: ubiali@gmail.com

#ifndef MOUNT_HPP
#define MOUNT_HPP

#include "../common/mmo.hpp"

#define DEFAULT_MOUNT 1
#define MAX_MOUNT 100
// Moved to mmo.hpp because of the timers
//#define REMOUNT_TIME 30 // 30 seconds (multiplied by 6 when unmounted by dmg)

struct mount_data *mount_search(int);
void mount_setride(struct map_session_data *sd, struct mount_data *mdb);
void mount_desmount(struct map_session_data *sd, bool force);
void mount_pc_status(struct map_session_data *sd);

void do_init_mount(void);
void do_final_mount(void);

struct mount_data {
	int id;
	char name[NAME_LENGTH];
	int max_hp, race, ele, ele_lvl, size, skill_id, skill_lv, speed_bonus, cast_time, aura;
	struct script_code *script;
};

#endif