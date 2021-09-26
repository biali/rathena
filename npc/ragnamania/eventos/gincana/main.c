
quiz_00,66,6,6	script	gincana	-1,{
	function shuffleEvent;
	end;

OnLoadEvent:
	//setarray .playersInTheLobby[(.totalPlayers = getarraysize(.playersInTheLobby))], getcharid(0);
	if(strcharinfo(3) == "quiz_00") {
		callfunc "F_Dispell";
	}
	end;

OnInit:
OnGincanaStart:
	initnpctimer;
	startnpctimer;
	end;

OnTimer30000:
	stopnpctimer;
	//cleararray .playersInTheLobby[0],0,getarraysize(.playersInTheLobby);
	.totalInLobby = getmapunits(BL_PC,"quiz_00",.playersInTheLobby[0]);
	if(.totalInLobby > 0) {
		//.@x = shuffleEvent(.totalInLobby);
		//debug
		.@x=1;
		callfunc("F_GEvt_"+.@x);
	}

	initnpctimer;
	startnpctimer;
	end;


	function shuffleEvent {
		.@t = getarg(0);
		switch(.@t) {
			case 1: return callfunc("F_Rand",1,2,3);
			case 2: case 3: return callfunc("F_Rand",1,2,3,4,5);
			case 4: return callfunc("F_Rand",4,5,6);
			default: return callfunc("F_Rand",6,7,8,9);
		}
	}
}

// Gincana Event
// Players: 1 player
// Name: Maze Runner
// Description: Player will try to escape an instanced maze within 3 minutes.
function	script	F_GEvt_1	{
	addrid(5,0,"quiz_00");

	if(@instance > 0) {
		instance_destroy @instance;
		sleep2 500;
	}

	.@create = instance_create("Maze Runner", IM_NONE);
	if (.@create < 0) {
		switch (.@create) {
			case -1: dispbottom "ERROR: Invalid type."; break;
			case -2: dispbottom "ERROR: Party not found."; break;
			case -3: dispbottom "ERROR: Instance already exists."; break;
			case -4: dispbottom "ERROR: No free instances."; break;
		}
		dispbottom "Instance creation ^FF0000failed^000000.";
		//clearData();
	}

	@instance = .@create;

	.@enter = instance_enter("Maze Runner",-1,-1,getcharid(0),@instance);
	if (.@enter != 0) {
		switch (.@enter) {
			case 1: dispbottom "ERROR: Party not found."; break;
			case 2: dispbottom "ERROR: Party does not have an instance."; break;
			case 3: dispbottom "ERROR: Unknown error."; break;
		}
		dispbottom "Instance entry ^FF0000failed^000000.";
		//clearData();
	}
}






-	script	gincana_entrance	-1,{
	mes .n$;
	mes "Do you want to join the Gincana?";
	if(select("Yes, Please:No, Thankyou") == 2)
		close;
	mes "Great! There you go!";
	close2;
		warp "quiz_00",65,7;
		end;

OnInit:
	.n$ = "^FF6600[ Gincana ]^000000";
	end;
}

prontera,174,182,2	duplicate(gincana_entrance)	Gincana#prt	779