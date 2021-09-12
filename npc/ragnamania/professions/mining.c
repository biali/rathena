-	script	pedra_main	FAKE_NPC,{
	function respawn; function updateXp;
	//Checks
    if(PROFESSION != CRAFTSMAN) { dispbottom "I need to be a Craftsman for that."; end; }
	if(getequipid(EQI_ACC_R)==.equip){ set .@eqiON,1; }
	if(!.@eqiON){ dispbottom "I will need a " + getitemname(PICKAXE) + " for that." ; end; }
	if(getd(".depleted_"+strnpcinfo(2))) { dispbottom "The vein is dry.",0xFF6600; end; }
	if(getd("."+strnpcinfo(2))){ dispbottom "That is rude!",0xFF6600; end; } else setd("."+strnpcinfo(2)+"",1); //someone else is gathering here
	
	//sets
	setd ".name_"+strnpcinfo(2)+"$", strnpcinfo(0);

	// Possiveis recompensas. (aleatório)
	switch(rand(20))
	{
		case 1: 					set @reward,723; break; // Ruby
		case 2:						set @reward,721; break; // Emerald
		case 3: case 4: case 5:		set @reward,727; break; // opal
		case 6:						set @reward,725; break; // Sardonyx
		case 7: case 8:				set @reward,985; break; // Elunium
		case 9:						set @reward,7619; break; // enriched elunium
		case 10:					set @reward,7620; break; // enriched oridecon
		case 11:					set @reward,984; break; // Oridecon
		case 12: case 13: 			set @reward,985; break; // Elunium
		case 14: case 15: 			set @reward,984; break; // Oridecon
		default: 					set @reward,0; break; 	// valor de falha (não adicionar id aqui)
	}
	

	set @rand,rand(1,3);
	.@max = getarraysize(.item) -1;
	getitem .item[rand(0,.@max)],@rand;

	pcblockmove getcharid(3),1;
	cutin "p_00",2; sleep2 200; 
	cutin "p_01",2; sleep2 200;
	cutin "p_02",2; sleep2 200; specialeffect2 457;
	cutin "p_03",2; sleep2 200;
	cutin "p_04",2; sleep2 200;
	cutin "p_05",2; sleep2 200; specialeffect2 457;
	cutin "p_06",2; sleep2 200; 
	cutin "p_07",2; sleep2 200;
	cutin "p_08",2; sleep2 200; specialeffect2 457;
	cutin "p_09",2; sleep2 200;
	cutin "p_10",2; sleep2 200;
	cutin "p_11",2; sleep2 200; specialeffect2 457;
	cutin "p_12",2; sleep2 200;
	cutin "p_13",2; sleep2 200;
	cutin "p_14",2; sleep2 200; specialeffect2 457;
	if(@reward == 0){ 
		cutin "p_15f",2; sleep2 500; cutin "",255; 
	} else {
		cutin "p_15s",2; sleep2 500; cutin "",255; 
		getitem @reward,1;
	}
	pcblockmove getcharid(3),0;

	respawn();
	setd ".depleted_"+strnpcinfo(2), 1;

	// should we use this or getexp?
	addreputation(getcharid(6),.faction_exp,.faction_points); // this will give 1000 points towards the faction reputation and 5 points in faction points
	updateXp(1);

	setd("."+strnpcinfo(2)+"",0); // make it again available for gathering
	
	sleep .tempo_main;
	respawn();

	end;


OnInit:
	// === configurações básicas
	set .tempo_main,600000;	//tempo que irá nascer aleatóriamente no mapa (em milisegundos).
	set .equip,PICKAXE;	//equipamento necessário
	set .faction_exp, 1000;
	set .faction_points, 5;
	setarray .item[0],756,757,757,998,999,756,757,756; 		//item de recompensa.
	end;


	function respawn {
		.@spr = substr(strnpcinfo(2),0,5);

		switch(getd(".depleted_"+strnpcinfo(2))){
			case 0:
				if(.@spr == LESSER_VEIN)
					setnpcdisplay(getd(".name_"+strnpcinfo(2)+"$"), LESSER_VEIN_EMPTY);
				else
					setnpcdisplay(getd(".name_"+strnpcinfo(2)+"$"), GREATER_VEIN_EMPTY);
				setd ".depleted_"+strnpcinfo(2), 1;
				break;
			case 1:
				if(.@spr == LESSER_VEIN)
					setnpcdisplay(getd(".name_"+strnpcinfo(2)+"$"), LESSER_VEIN);
				else
					setnpcdisplay(getd(".name_"+strnpcinfo(2)+"$"), GREATER_VEIN);
				setd ".depleted_"+strnpcinfo(2), 0;
				break;
		}

		return;
	}

	function updateXp {
		.@lv = PRO_INFO[0];
		if(.@lv == (getarraysize(getvariableofnpc(.Craftsman_Exp$,"craftsman")) -1))
			return;
		.@xp = getarg(0,1);
		PRO_INFO[1] += .@xp;
		if(PRO_INFO[1] >= getvariableofnpc(.Xp2LvlUp,"craftsman") && .@lv < (getarraysize(getvariableofnpc(.CraftsmanTitle$,"craftsman")) -1)) {
			.@lv++;
			setarray PRO_INFO[0], .@lv;
			setarray PRO_INFO[1], 0;
			specialeffect2 999;
			soundeffect "bijou_die.wav", 0;
			announce "CRAFTSMAN LEVEL UP!",bc_blue|bc_self;
			dispbottom "You are now a " + getvariableofnpc(.CraftsmanTitle$[.@lv],"craftsman") + " Craftsman. Congratulations!";
		}
		return;
	}
}



-	script	::spawn_rocks	-1,{
    function spawn;
    end;

OnInit:
	setarray .caves$[0], "alde_dun01","alde_dun02","alde_dun03","alde_dun04","gef_dun00","gef_dun01","gef_dun02","gef_dun03","gl_dun01","gl_dun02","iz_dun00","iz_dun01","iz_dun02","iz_dun03","iz_dun04","izlu2dun","mjo_dun01","mjo_dun02","mjo_dun03","orcsdun01","orcsdun02","pay_dun00","pay_dun01","pay_dun02","pay_dun03","pay_dun04","beach_dun","beach_dun2","beach_dun3","mag_dun01","mag_dun02","gon_dun01","gon_dun02","gon_dun03","ein_dun01","ein_dun02","ice_dun01","ice_dun02","ice_dun03","ice_dun04","bra_dun01","bra_dun02","iz_dun05";
    .lesser_veins = 12;
	.greater_veins = 6;

	freeloop(1);
	for(.@i=0;.@i<getarraysize(.caves$);.@i++) {
		spawn(.caves$[.@i],LESSER_VEIN,.lesser_veins);
		spawn(.caves$[.@i],GREATER_VEIN,.greater_veins);
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
            case LESSER_VEIN : .@n$ = "Lesser Vein"; break;
            case GREATER_VEIN : .@n$ = "Greater Vein"; break;
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
					// debugmes ">>>>>>>>>>>> "+.@nTmp$+" Pedra "+.@i+" em .@x1,.@y1: " + .@x1 + "," + .@y1;
					.@done = duplicatenpc("pedra_main",""+.@n$+"",""+.@nTmp$+"",.@map$,.@x1,.@y1,DIR_SOUTH,.@id);
				}
			}
        }
		freeloop(0);
        return 1;
    }
}