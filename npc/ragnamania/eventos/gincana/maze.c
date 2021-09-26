maze,369,162,4	script	Event Organizer	405,4,4,{
	if(@fail) {
		@fail = 0;
		mes "^FF6600[ Event Organizer ]^000000";
		mes "You didn't make it.";
		mes "But worry not!";
		mes "I am sure you will";
		mes "have better luck";
		mes "next time. Don't give up!";
		close2;
		warp "quiz_00", 66,6;
		instance_destroy(@instance);
		@instance = 0;
		end;
	} 
	npctalk "Come, quick! You need to come over here to win!";
	end;

OnInit:
	setmapflag "maze",mf_noitemconsumption;
	setmapflag "maze",mf_noskill;
	end;

OnInstanceInit:
	setcell instance_mapname(strnpcinfo(4)),360,149,361,148,cell_walkable,0;
	initnpctimer;
	startnpctimer;
	end;

OnTimer30000: // 30 seconds: Start!
	setcell instance_mapname(strnpcinfo(4)),360,149,361,148,cell_walkable,1;
	mapannounce instance_mapname(strnpcinfo(4)),"GO!",BC_SELF,0xFF0000,FW_BOLD,64;
	end;

OnTimer1200000: // 20 minutes: It is over
	stopnpctimer;
	mapannounce instance_mapname(strnpcinfo(4)),"TIME'S UP!",BC_SELF,0xFF0000,FW_BOLD,64;
	addrid(5,0,instance_mapname(strnpcinfo(4)));
	set @fail, 1;
	sleep2 5000;
	warp instance_mapname(strnpcinfo(4)),368,161;
	end;
	
OnTouch:
	if(@fail) end;
	stopnpctimer;
	announce "WINNER!",BC_SELF,0x00CC00,FW_BOLD,64;
	mes "^FF6600[ Event Organizer ]^000000";
	mes "Congratulations! You won!";
	next;
	mes "^FF6600[ Event Organizer ]^000000";
	mes "Please accept your reward!";
	next;
	getrandgroupitem IG_RM_008;
	mes "^FF6600[ Event Organizer ]^000000";
	mes "'til next time!";
	close2;
	warp "quiz_00", 66,6;
	instance_destroy(@instance);
	@instance = 0;
	end;
}

