-	script	#bz_battle_chest	-1,{
	query_sql("SELECT `char_num` FROM `char` WHERE `char_id` = "+getcharid(0)+" limit 1", .@char_num);
	if(.@char_num[0] > .max_chars) {
		debugmes "ERROR. Please report this to a member of the staff.";
		debugmes "System misconfigured to deal with " + getbattleflag("chars_per_account") + " char per account.";
		logmes "ERROR: chars_per_account is setup with a higher number than the private storages can handle";
		end;
	}

	.@id = atoi(strnpcinfo(2)) + .@char_num[0];
	openstorage2 .@id,STOR_MODE_GET|STOR_MODE_PUT;
	end;
OnTimer3000:
	misceffect 12;
	stopnpctimer;
	initnpctimer;
	end;

OnInit:
	//.max_chars = getbattleflag("chars_per_account"); // not working anymore WTF?
	.max_chars = 4; // slots 0 to 4
	initnpctimer;
	end;
}

ars_fild04,168,268,0	duplicate(#bz_battle_chest)	Battle Chest#20	10005
ars_fild27,71,148,0	duplicate(#bz_battle_chest)	Battle Chest#30	10005
ars_fild16,240,192,0	duplicate(#bz_battle_chest)	Battle Chest#40	10005
ars_fild09,288,142,0	duplicate(#bz_battle_chest)	Battle Chest#50	10005
ars_fild26,132,91,0	duplicate(#bz_battle_chest)	Battle Chest#60	10005
ars_fild10,171,200,0	duplicate(#bz_battle_chest)	Battle Chest#70	10005
ars_fild13,156,186,0	duplicate(#bz_battle_chest)	Battle Chest#80	10005


// hellgates maps
moc_fild18,58,334,0	duplicate(#bz_battle_chest)	Battle Chest#100	10005
pay_fild07,111,267,0	duplicate(#bz_battle_chest)	Battle Chest#110	10005
ra_fild13,289,102,0	duplicate(#bz_battle_chest)	Battle Chest#120	10005
prt_fild00,253,52,0	duplicate(#bz_battle_chest)	Battle Chest#130	10005
hu_fild03,269,172,0	duplicate(#bz_battle_chest)	Battle Chest#140	10005