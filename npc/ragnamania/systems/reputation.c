-	script	reputation	-1,{
	function CalcRep; function Red; function Orange; function Green; function Acqua; function Blue;
	end;

OnShowReputationAll:
	for(.@i=1;.@i<=.totalfac;.@i++) {
		.@rep$ = CalcRep(.@i);
		mes factioninfo(.@i,0) + " : " + .@rep$;
	}
	end;

OnInit:
	.totalfac	= 4;
	.min 		= getbattleflag("reputation_min");
	.hated 		= getbattleflag("reputation_hated");
	.unfriendly = getbattleflag("reputation_unfriendly");
	.normal 	= getbattleflag("reputation_normal");
	.friendly 	= getbattleflag("reputation_friendly");
	.honored 	= getbattleflag("reputation_honored");
	.max 	= getbattleflag("reputation_max");
	end;

	function CalcRep {
		.@faction = getarg(0,0);
		if(.@faction == 0)
			return -1;
		
		.@rep = getreputation(.@faction);
		if(.@rep >= .honored) return Blue("[ Honored ]");
		else if(.@rep >= .friendly) return Acqua("[ Friendly ]");
		else if(.@rep > .unfriendly && .@rep < .friendly) return Green("[ Normal ]");
		else if(.@rep <= .hated) return Red("[ Hated ]");
		else if(.@rep <= .unfriendly) return Orange("[ Unfriendly ]");
	}

	function Red {
		.@t$ = getarg(0);
		return "^cc0000" + .@t$ + "^000000";
	} 
	function Orange {
		.@t$ = getarg(0);
		return "^ff6600" + .@t$ + "^000000";
	} 
	function Green {
		.@t$ = getarg(0);
		return "^009933" + .@t$ + "^000000";
	} 
	function Acqua {
		.@t$ = getarg(0);
		return "^3399ff" + .@t$ + "^000000";
	} 
	function Blue {
		.@t$ = getarg(0);
		return "^0033cc" + .@t$ + "^000000";
	} 

}
