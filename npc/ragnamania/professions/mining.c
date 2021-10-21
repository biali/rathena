-	script	pedra_main	FAKE_NPC,{
	function respawn; function updateXp; function getVeinLvl;
	//Checks
    if(PROFESSION != CRAFTSMAN) { dispbottom "I need to be a Craftsman for that."; end; }
	//if(getequipid(EQI_ACC_R)==.equip){ set .@eqiON,1; }
	// if(!.@eqiON){ dispbottom "I will need a " + getitemname(PICKAXE) + " for that." ; end; }
	if(getd(".depleted_"+strnpcinfo(2))) { dispbottom "The vein is dry.",0xFF6600; end; }
	.@pickaxe = getequipid(EQI_ACC_R);
	if((.@pickaxeLvl = inarray(.equip,.@pickaxe)) <= 0) {
		dispbottom "I'll need a pickaxe equiped in order to do that";
		end;
	}
	.@spr = substr(strnpcinfo(2),0,5);
	.@veinlvl = getVeinLvl(.@spr);

	if(.@pickaxeLvl < .@veinlvl) {
		dispbottom "I need a proper tool to mine that.",0xFF6600;
		end;
	}
	
	if(getd("."+strnpcinfo(2))){ dispbottom "That is rude!",0xFF6600; end; } else setd("."+strnpcinfo(2)+"",1); //someone else is gathering here	

	if(.@veinlvl <= 0 ) {
		dispbottom "ERROR: Please report this to a member of the staff",0xFF6600;
		end;
	}

	if((.@veinlvl -1) > (PRO_INFO[0])) {
		dispbottom "I don't think I am skilled enough to work on this",0xFF6600;
		end;
	}

	//sets
	setd ".name_"+strnpcinfo(2)+"$", strnpcinfo(0);

	@reward = 30350 + .@veinlvl;

	pcblockmove getcharid(3),1;
	cutin "p_00",2; sleep2 200; specialeffect2 457;
	cutin "p_01",2; sleep2 200; if(rand(2)==1) getrandgroupitem IG_RM_007;
	cutin "p_02",2; sleep2 200;
	cutin "p_03",2; sleep2 200;
	cutin "p_04",2; sleep2 200;
	cutin "p_05",2; sleep2 200;
	cutin "p_06",2; sleep2 200; 
	cutin "p_07",2; sleep2 200; specialeffect2 457;
	cutin "p_08",2; sleep2 200; if(rand(2)==1) getrandgroupitem IG_RM_007;
	cutin "p_09",2; sleep2 200;
	cutin "p_10",2; sleep2 200;
	cutin "p_11",2; sleep2 200;
	cutin "p_12",2; sleep2 200;
	cutin "p_13",2; sleep2 200;
	cutin "p_14",2; sleep2 200; specialeffect2 457;
	cutin "p_15s",2; sleep2 500; cutin "",255;
	if(.@spr >= G_VEIN_COPPER)
		getitem @reward,2;
	else
		getitem @reward,1;
	pcblockmove getcharid(3),0;

	respawn();
	setd ".depleted_"+strnpcinfo(2), 1;

	addreputation(getcharid(6),.faction_exp * .@veinlvl, .faction_points * .@veinlvl); // this will give faction points towards the faction reputation points in faction points
	updateXp(.baseXP * .@veinlvl);

	setd("."+strnpcinfo(2)+"",0); // make it again available for gathering
	
	sleep .tempo_main * .@veinlvl;
	respawn();

	end;


OnInit:
	// === configurações básicas
	set .tempo_main,300000;	//tempo base que irá nascer aleatóriamente no mapa (em milisegundos). Default 5 mins (300000)
	setarray .equip[1],30311,30312,30313,30314,30315,30316,30317,30318;	//equipamento necessário
	set .faction_exp, 100;
	set .faction_points, 1;
	set .baseXP, 10;
	end;


	function getVeinLvl {
		.@id = getarg(0,0);
		switch(.@id) {
			case L_VEIN_COPPER: 	case G_VEIN_COPPER: 		return 1;
			case L_VEIN_TIN: 		case G_VEIN_TIN: 			return 2;
			case L_VEIN_IRON: 		case G_VEIN_IRON: 			return 3;
			case L_VEIN_TITANIUM: 	case G_VEIN_TITANIUM: 		return 4;
			case L_VEIN_RUNITE: 	case G_VEIN_RUNITE: 		return 5;
			case L_VEIN_METEORITE: 	case G_VEIN_METEORITE: 		return 6;
			case L_VEIN_ADAMANTIUM:	case G_VEIN_ADAMANTIUM: 	return 7;
			case L_VEIN_BRADIUM:	case G_VEIN_BRADIUM:	 	return 8;
			default: return -1;
		}

	}


	function respawn {
		.@spr = substr(strnpcinfo(2),0,5);
		switch(getd(".depleted_"+strnpcinfo(2))){
			case 0:
				setnpcdisplay(getd(".name_"+strnpcinfo(2)+"$"), .@spr+1);
				setd ".depleted_"+strnpcinfo(2), 1;
				break;
			case 1:
				setnpcdisplay(getd(".name_"+strnpcinfo(2)+"$"), .@spr);
				setd ".depleted_"+strnpcinfo(2), 0;
				break;
		}

		return;
	}

	function updateXp {
		.@lv = PRO_INFO[0];
		if(.@lv == (getarraysize(getvariableofnpc(.Craftsman_Exp,"craftsman")) -1))
			return;
		.@xp = getarg(0,10);
		.@lv1 = .@lv + 1;
		dispbottom "Gainned " + .@xp + " craftsman experience points.",0xff6600;
		setarray PRO_INFO[1], PRO_INFO[1] + .@xp;
		if(PRO_INFO[1] >= getvariableofnpc(.Craftsman_Exp[.@lv1],"craftsman") && .@lv < (getarraysize(getvariableofnpc(.CraftsmanTitle$,"craftsman")) -1)) {
			setarray PRO_INFO[0], .@lv1;
			setarray PRO_INFO[1], 0;
			specialeffect2 999;
			soundeffect "bijou_die.wav", 0;
			announce "CRAFTSMAN LEVEL UP!",bc_blue|bc_self;
			dispbottom "You are now a " + getvariableofnpc(.CraftsmanTitle$[.@lv1],"craftsman") + " Craftsman. Congratulations!";
		}
		return;
	}
}



-	script	::spawn_rocks	-1,{
    function spawn;
    end;

OnInit:
	setarray .caves$[0], "alde_dun01","alde_dun02","alde_dun03","alde_dun04","gef_dun00","gef_dun01","gef_dun02","gef_dun03","gl_dun01","gl_dun02","iz_dun00","iz_dun01","iz_dun02","iz_dun03","iz_dun04","mjo_dun01","mjo_dun02","mjo_dun03","orcsdun01","orcsdun02","pay_dun00","pay_dun01","pay_dun02","pay_dun03","pay_dun04","beach_dun","beach_dun2","beach_dun3","mag_dun01","mag_dun02","gon_dun01","gon_dun02","gon_dun03","ein_dun01","ein_dun02","ice_dun01","ice_dun02","ice_dun03","bra_dun01","bra_dun02","juperos_01","thor_v01","thor_v02","thor_v03","abyss_01","abyss_02","abyss_03";
    setarray .maplvl[0],			3,			 3,			  4,		   4,		   1,		   1,		   2,		   2,		  3,		 4,			1,		   1,		  2,		 2,			3,			2,			2,			3,			1,			2,			1,			1,			2,			3,			4,			4,			5,			  2,	 	  4,		  5,		  4,		  5,		  6,		  4,		  5,		  5,		  5,		  6,		  5,		  7,		   6,		  6,		 7,			8,		   6,		  7,		 8;
	.lesser_veins = 12;
	.greater_veins = 4;

	freeloop(1);
	for(.@i=0;.@i<getarraysize(.caves$);.@i++) {
		switch(.maplvl[.@i]) {
			case 1:	.@id = 25701; break;
			case 2:	.@id = 25703; break;
			case 3:	.@id = 25705; break;
			case 4:	.@id = 25707; break;
			case 5:	.@id = 25709; break;
			case 6:	.@id = 25711; break;
			case 7:	.@id = 25713; break;
			case 8:	.@id = 25715; break;
			default: .@id = 25701; break;
		}
		spawn(.caves$[.@i],.@id,.lesser_veins);
		if (.maplvl[.@i] > 1)
			spawn(.caves$[.@i],.@id-2,.greater_veins);
		spawn(.caves$[.@i],.@id+20,.greater_veins);
	}
	freeloop(0);
    end;
	

    function spawn {
        .@map$ = getarg(0,"");
        .@id = getarg(1,0);
        .@qt = getarg(2,5);
        .@x = getarg(3,400);
        .@y = getarg(4,400);

        if(.@id == 0 || .@map$ == "")
            return -1;

        switch(.@id) {
            case L_VEIN_COPPER		: .@n$ = "Copper Vein"; break;
			case L_VEIN_TIN			: .@n$ = "Tin Vein"; break;
			case L_VEIN_IRON		: .@n$ = "Iron Vein"; break;
			case L_VEIN_TITANIUM	: .@n$ = "Titanium Vein"; break;
			case L_VEIN_RUNITE		: .@n$ = "Runite Vein"; break;
			case L_VEIN_METEORITE	: .@n$ = "Meteorite Vein"; break;
			case L_VEIN_ADAMANTIUM	: .@n$ = "Adamantium Vein"; break;
			case L_VEIN_BRADIUM		: .@n$ = "Bradium Vein"; break;
			case G_VEIN_COPPER		: .@n$ = "Copper Vein"; break;
			case G_VEIN_TIN			: .@n$ = "Tin Vein"; break;
			case G_VEIN_IRON		: .@n$ = "Iron Vein"; break;
			case G_VEIN_TITANIUM	: .@n$ = "Titanium Vein"; break;
			case G_VEIN_RUNITE		: .@n$ = "Runite Vein"; break;
			case G_VEIN_METEORITE	: .@n$ = "Meteorite Vein"; break;
			case G_VEIN_ADAMANTIUM	: .@n$ = "Adamantium Vein"; break;
			case G_VEIN_BRADIUM		: .@n$ = "Bradium Vein"; break;
        }

		freeloop(1);
        for(.@i=0; .@i <.@qt;.@i++ ) {
			.@nTmp$ = .@id + "_" + $@rockcounter;
			$@rockcounter++;
			.@done = 0;
            while(.@done < 1) {
				.@x1 = rand(1,.@x);
				.@y1 = rand(1,.@y);

				if ( checkcell(.@map$,.@x1,.@y1,cell_chkpass) ) {
					.@done = duplicatenpc("pedra_main",""+.@n$+"",""+.@nTmp$+"",.@map$,.@x1,.@y1,DIR_SOUTH,.@id);
				}
			}
        }
		freeloop(0);
        return 1;
    }
}