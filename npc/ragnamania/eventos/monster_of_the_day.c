prontera,125,210,5	script	Connor::motdBoard	632,{
	mes "^0000FF[ Connor ]^000000";
	mes "Hello, traveler!";
	mes "Do you want to help me out?";
	next;
	mes "^0000FF[ Connor ]^000000";
	mes "Today I've been requested to kill";
	mes "some ^FF0000"+getmonsterinfo($@motd_mobid,MOB_NAME)+"^000000.";
	mes "I've set a bounty on their head:";
	next;
	mes "^0000FF[ Connor ]^000000";
	mes "Exp Bonus : ^EE00AA" + callfunc("F_InsertComma",$@motd_XP)+"^000000.";
	mes "A chance to get ^DD0088"+getitemname($@HUNTING_MEDAL)+"s^000000.";
	mes "A chance to get ^CC0066"+getitemname(30022)+"s^000000.";
	mes "A chance to get ^BB0044"+getitemname(30027)+"es^000000.";
	next;
	mes "^0000FF[ Connor ]^000000";
	mes "So, what are you waiting for?";
	close2;
	atcommand "#whereis \""+ strcharinfo(0)+"\" "+$@motd_mobid;
	end;

OnInit:
	setarray .mobs[0],1207,1310,1213,1206,1102,1197,1196,1278,1379,1713,1753,1777,1505,1317,1193,1408,1679,1870;

	callfunc "ChangeMob","motdMob";
	end;

OnBite:
	npctalk "Wow! Careful there! Don't get that close!";
	end;
}



prontera,123,209,5	script	MotD::motdMob	1002,{
	percentheal(-10,0);
	soundeffect "matyr_attack.wav",0;
	donpcevent "motdBoard"+"::OnBite";
	end;

OnClock0001:
	callfunc "ChangeMob";
	end;

OnTimer10100:
	misceffect 231;
	stopnpctimer;
	initnpctimer;
	end;

OnInit:
	initnpctimer;
	misceffect 231;
	end;
}



function	script	ChangeMob	{
	.@npc$ = getarg(0,strnpcinfo(3));
	.@id = monsteroftheday(getelementofarray(getvariableofnpc(.mobs,"motdBoard"),rand(getarraysize(getvariableofnpc(.mobs,"motdBoard")))));
	setnpcdisplay(.@npc$,getmonsterinfo(.@id,MOB_NAME), .@id);
	addmonsterdrop .@id,30027,200;	// Ragnamania Loot Boxes
	addmonsterdrop .@id,30023,200;	// Ragnamania Bag of Manias
	addmonsterdrop .@id,$@HUNTING_MEDAL,200;	// Ragnamania Hunting Coins

	return;
}