-	script	farmer	-1,{
    end;

OnInit:
		// Player Settings
		//								   fazenda 1,						fazenda 2       						   Fazenda 3
	set .Xp2LvlUp, 1000;	//				   apple,      grapes,   orange, strawbe,  prickly, mastela,  yggdrasil   , - 
	setarray .FarmerTitle$[0],			"Apprentice","Journeyman","Skilled","Expert","Artisan","Master","Grand Master","Illustrious";
	setarray .Farmer_Lvl[0],	                   0,           1,        2,       3,        4,       5,             6,            7; // * Required Lvl to Work on It
	setarray .Farmer_Exp[0], 	  	              12,          10,        8,       5,        4,       3,             2,            1; // * Experience gained per craft
    end;
}

farm,28,50,8	script	Board#1	858,{
	mes "[ Bulletin Board ]";
	mes "The land ahead will";
	mes "be available only";
	mes "to ^0000FFArtisan Farmers^000000.";
	close;
}

farm,58,51,8	script	Board#2	858,{
	mes "[ Bulletin Board ]";
	mes "The land ahead will";
	mes "be available only";
	mes "to ^0000FFIllustrious Farmers^000000.";
	close;
}

farm,46,98,5	script	farm_return	100,{
	mes "[ Sailor ]";
	mes "Are you ready to depart?";
	if(select("Yes, please:Not yet") == 2)
		close;
	close2;
	set @instance, 0;
	instance_destroy();
	end;
}

farm,60,86,4	script	Food Processing	548,{
	function add2menu; function showIngredients;
L_MENU:
	.@lv = PRO_INFO[0];
	mes .n$;
	mes "Hello, " + strcharinfo(0);
	mes "How can I help?";
	.@menu$ = "";
	switch(select("Process Food:Cancel")) {
		case 2:
			close;
			break;
		case 1:
			cleararray @ids[0],0,getarraysize(@ids);
			// craftable items comma separated eg "1030,1045,1050"
			switch(.@lv) {
				case 7:
				case 6:
					.@menu$ += add2menu("30800");
				case 5: // mastela
					.@menu$ += add2menu("30750");
				case 4: // pricly
					.@menu$ += add2menu("30700");
				case 3: // strawberry
					.@menu$ += add2menu("30650");
				case 2: // orange
					.@menu$ += add2menu("30620");
				case 1: // grape
					.@menu$ += add2menu("30533");
				case 0: // apple
					.@menu$ += add2menu("30531");
					break;
			}
			break;
	}
	explode(.@names$,.@menu$,":");
	.@menu$ += "^FF0000Cancel^000000";
	.@op = select(.@menu$) -1;

	if(.@op == getarraysize(.@names$))
		close;

	clear;
DO_IT:
	set .@lv, PRO_INFO[0]+1;
	mes .n$;
	mes "Producing: ^0000FF" + .@names$[.@op] + "^000000";
	set .@cost, $rQtd - .@lv;
	mes "Focus: ^000000("+ callfunc("F_InsertComma",FOCUS) + "/" + callfunc("F_InsertComma",.@cost) + ")";
	mes "Ingredients:";
	
	if(showIngredients(@ids[.@op]) == 1) {
		.@m = prompt("Create "+.@name$[.@op]+":Cancel");
		if(.@m != 1) {
			cleararray @ids[0],0,getarraysize(@ids);
			cleararray @ingredients[0],0,getarraysize(@ingredients);
			clear;
			goto L_MENU;
		}

		if(FOCUS < .@cost) {
			mes "^FF0000 You don't have enough Focus to do this.";
			next;
			goto L_MENU;
		}

		for(.@i=0; .@i<getarraysize(@ingredients); .@i+=2) {
			if(countitem(@ingredients[.@i]) < @ingredients[(.@i+1)] ) {
				mes "^ff0000ERROR! Items no longer found in the inventory. This incident has been reported to the staff.^000000";
				logmes "Cheater. Food Processing script.";
				close;
			}
		}

		for(.@i=0; .@i<getarraysize(@ingredients); .@i+=2)
			delitem @ingredients[.@i], @ingredients[(.@i+1)];
		
		set FOCUS, FOCUS - .@cost;

		cutin "f_00",2; sleep2 200; specialeffect2 457;
		cutin "f_01",2; sleep2 200;
		cutin "f_02",2; sleep2 200; 
		cutin "f_03",2; sleep2 200;
		cutin "f_04",2; sleep2 200;
		cutin "f_05",2; sleep2 200;
		cutin "f_06",2; sleep2 200; specialeffect2 457;
		cutin "f_ok",2; sleep2 500; cutin "",255; 

		clear;
		mes .n$;
		mes "^00AA00Success!^000000";
		specialeffect2 305;
		getitem @ids[.@op],1;

		callfunc "updateXP";
		next;
		goto DO_IT;

	} else {
		next;
		cleararray @ingredients[0],0,getarraysize(@ingredients);
		clear;
		goto L_MENU;
	}
	

OnInit:
	.n$ = "^FF6600[ Cheff ]^000000";
	// apples
	setarray .i_30531[0],30512,1,512,2;
	// setarray .i_501[0],512,5,507,1;
	// setarray .i_598[0],512,8,507,5;
	// setarray .i_545[0],512,10,507,10;

	// grapes
	setarray .i_30533[0],30514,1,30512,2;
	// setarray .i_12061[0],514,5,518,1;
	// setarray .i_656[0],514,5,511,2;
	// setarray .i_506[0],514,1,511,5;

	// oranges
	setarray .i_30620[0],30582,1,30514,2;
	// setarray .i_502[0],582,5,508,1;
	// setarray .i_599[0],582,8,508,5;

	// strawberries
	setarray .i_30650[0],30578,1,30582,2;
	// setarray .i_504[0],509,5;
	// setarray .i_11501[0],509,8;
	// setarray .i_547[0],578,2,509,10;

	// prickly
	setarray .i_30700[0],30576,1,30578,2;
	// setarray .i_12067[0],576,3,587,3,578,3;

	// mastela
	setarray .i_30750[0],30522,1,30576,2;
	// setarray .i_505[0],510,6;
	// setarray .i_11502[0],510,5,522,1;

	// yggdrasil
	setarray .i_30800[0],30607,1,30522,1,30576,1,30578,1,30582,1,30514,1,30512,1;
	// setarray .i_12437[0],607,3,11502,1;
	end;


	function add2menu {
		.@m$ = "";
		explode(.@items$,getarg(0),",");
		for(.@i=0;.@i<getarraysize(.@items$);.@i++){
			.@m$ += getitemname(atoi(.@items$[.@i])) + ":";
			setarray @ids[getarraysize(@ids)],atoi(.@items$[.@i]);
		}
		return .@m$;
	}

	function showIngredients {
		.@item = getarg(0,0);
		cleararray @ingredients[0],0,getarraysize(@ingredients);
		if(.@item == 0) {
			dispbottom "ERROR. Please inform the Admins about this",0xFF0000;
			close;
		}
		
		.@ar$ = ".i_" + .@item;
		.@passou = 1;
		if(countitem(713) < 1) {
			mes "^AA00001x " + getitemname(713) + "^000000";
			.@passou = 0;
		} else
			mes "^00AA001x " + getitemname(713) + "^000000";

		for(.@i=0;.@i<getarraysize(getd(.@ar$));.@i+=2) {
			if(countitem(getitemname(getd(.@ar$ +"["+.@i+"]"))) < getd(.@ar$ +"["+(.@i+1)+"]")) {
				mes "^AA0000"+getd(.@ar$ +"["+(.@i+1)+"]") + "x " + getitemname(getd(.@ar$ +"["+.@i+"]")) + "^000000";
				.@passou = 0;
			} else
				mes "^00AA00"+getd(.@ar$ +"["+(.@i+1)+"]") + "x " + getitemname(getd(.@ar$ +"["+.@i+"]")) + "^000000";
		}
		copyarray @ingredients[0],getd(.@ar$+"[0]"),getarraysize(getd(.@ar$));
		setarray @ingredients[getarraysize(@ingredients)],713,1;
		return .@passou;
	}
}





//Func Main
function	script	farm	{

	set .@pID,getarg(0);
	set .@item,getarg(1);
	set .@cName$,strcharinfo(0);
	set .@cID,getcharid(0);
	set .@mapname$, "farm";
	set .@lv, PRO_INFO[0];

	getmapxy(.@map$,.@x,.@y,BL_PC);

	if(PROFESSION != FARMER) {
		dispbottom "You need to be a farmer in order to do that.";
		end;
	}

	if(.@lv < (.@pID -1)) {
		dispbottom "That plant requires some knowledge you don't have just yet",0xFf6600;
		end;
	}

	if(checknonearnpc(strcharinfo(3),2) < 1) {
		dispbottom "You cannot plant it here as it's too close to another NPC. Please choose a different spot.",0xFF0000;
		end;
	}

	if(checkcell(.@map$,.@x,.@y,cell_chkplant) == 0) {
		dispbottom "I can only plant in fertile soil I own.",0xFF0000;
		end;
	}
	
	if(select("Plant it here:Cancel")==2)
		end; 

	query_sql "SELECT COUNT(`char_id`) FROM `farm` WHERE `char_id`="+.@cid+"",.@rst;
	
	if(.@rst) {
		for(set .@i,0; .@i<=.@rst; set .@i,.@i+1) {
			query_sql "SELECT `plant_ord` FROM `farm` WHERE `char_id`="+.@cid+" ORDER BY `plant_ord` ASC",.@irst;			
			if(.@irst[.@i] != .@i && .@chk < 1) { 
				set .@rst,.@i; 
				set .@chk,1;
			}
		}
	}
	
	set .@PlantInfo,explode(.@PlantVal$, callfunc("plant_type",.@pID),",");
	
	if(.@PlantVal$[3] == "null"){ 
		dispbottom "PlantID: "+.@pID+" - Stage: 1 - SpriteID: "+.@PlantVal$[3]+"  [ ERROR ]",0xFF0000; 
		end; 
	}
	
	delitem .@item,1;

	pcblockmove getcharid(3),1;
	cutin "f_00",2; sleep2 200; specialeffect2 457;
	cutin "f_01",2; sleep2 200;
	cutin "f_02",2; sleep2 200; 
	cutin "f_03",2; sleep2 200;
	cutin "f_04",2; sleep2 200;
	cutin "f_05",2; sleep2 200;
	cutin "f_06",2; sleep2 200; specialeffect2 457;
	cutin "f_ok",2; sleep2 500; cutin "",255; 
	pcblockmove getcharid(3),0;

	.@id$ = .@rst+""+getcharid(0);
	duplicatenpc("planta2", " ",""+.@id$,.@map$,.@x,.@y,DIR_SOUTH,atoi(.@PlantVal$[3]));
	set .@tTmp,(gettimetick(2)+atoi(.@PlantVal$[7]));
	query_sql "INSERT INTO `farm` (`id`,`char_id`,`name`,`map`,`x`,`y`,`plant_ord`,`plant_id`,`stage`,`time`,`finaltime`) VALUES ("+"'"+.@id$+"'"+","+.@cid+",'"+.@cName$+"','"+.@mapname$+"',"+.@x+","+.@y+","+.@rst+","+.@pID+",1,"+.@tTmp+","+(gettimetick(2)+604800)+")"; // 7 days until automatical deletion of the plant
	end;
}


// Main NPC
-	script	planta2	-1,{

	getmapxy(.@map$, .@x, .@y, BL_NPC);
	for(.@a=0;.@a<getstrlen(strnpcinfo(2));.@a++) {
		if(charat(strnpcinfo(2),.@a) == " " || charat(strnpcinfo(2),.@a) =="#")
			continue;
		.@name$ += charat(strnpcinfo(2),.@a);
	}

	if(.@rst = query_sql("SELECT `id`,`char_id`,`plant_ord`,`plant_id`,`stage`,`time` FROM `farm` WHERE `id`="+.@name$,.@id,.@cID,.@pOrd,.@pID,.@stage,.@time) > 0) {
		
		if(.@cID) {
			mes "^ff0000Plant Name:^000000 "+$@PlantName$[.@pID]+"";			
			mes "^ff0000Growth:^000000 "+.@stage+"/4";		
			mes "";

			if(.@stage < 4) {
				set .@cost, $rQtd - .@pID;
				mes "^ff0000Focus: ^000000("+ callfunc("F_InsertComma",FOCUS) + "/" + callfunc("F_InsertComma",.@cost)+ ")";
			} else {
				set .@calcT,.@time-gettimetick(2);
				mes "^ff0000Harvest: ^000000 "+ ( .@calcT < 3600 ? (.@calcT < 60 ? (.@calcT < 0 ? "Ready":.@calcT+"sec"):(.@calcT/60)+"min+") : (.@calcT/3600)+" hours and "+(.@calcT%3600)/60 + " minutes" );
			}
			menu (.@stage < 4 ? "Water":"")+"",-,(.@stage == 4 ? "Harvest":"")+"",-,"Close",-;
			set .@mn,@menu;
			set .@PlantInfo,explode(.@PlantVal$, callfunc("plant_type",.@pID),",");

			switch(.@stage)
			{
				case 1: set .@cTime,(gettimetick(2)+atoi(.@PlantVal$[8])); 	set .@cSpr,4; set .@cStage,2; break;
				case 2: set .@cTime,(gettimetick(2)+atoi(.@PlantVal$[9])); 	set .@cSpr,5; set .@cStage,3; break;
				case 3: set .@cTime,(gettimetick(2)+atoi(.@PlantVal$[10]));	set .@cSpr,6; set .@cStage,4; break;
			}
			
			switch(.@mn)
			{
				case 1:
				case 2:
					if(gettimetick(2) < .@time){ mes "You cannot "+(.@stage == 4 ? "harvest":"water")+" it just yet."; close; }
					
					if(.@stage < 4)
					{	// Water
						if(FOCUS < .@cost) {
							mes "^FF0000* You don't have enough Focus to do that.^000000";
							close;
						}								
						set .@nTmp$,strnpcinfo(0);
						query_sql "UPDATE `farm` SET `stage`="+.@cStage+",`time`="+.@cTime+" WHERE `char_id` = "+getcharid(0)+" AND `plant_ord`="+.@pOrd+" AND `plant_id`="+.@pID;
						// delitem $Regador,$rQtd;
						set FOCUS, FOCUS - .@cost;
						close2;
						duplicateremove(strnpcinfo(0));
						duplicatenpc("planta2", " ",.@nTmp$,.@map$,.@x,.@y,DIR_SOUTH,atoi(.@PlantVal$[.@cSpr]));				
					}
					else
					{	// Harvest
						if(getstatus(SC_WEIGHT50)) { 
							npctalk "[Harvest]: It seems you are carrying too much weight to continue."; 
							close; 
						} else 
							if(select("Harvest:Cancel") == 2)
								close;
							else
								close2;

						// set .@PlantInfo,explode(.@PlantVal$, callfunc("plant_type",.@pID),",");

						.@lootid1 = atoi(.@PlantVal$[1]);
						.@lootid2 = atoi(.@PlantVal$[11]);
						.@loot1  = atoi(.@PlantVal$[2]);

						pcblockmove getcharid(3),1;
						cutin "f_00",4; sleep2 300; specialeffect2 457;
						cutin "f_01",4; specialeffect2 457;
						getitem .@lootid2, rand(1,3); sleep2 300;
						cutin "f_02",4; specialeffect2 457; sleep2 300;
						cutin "f_03",4; specialeffect2 457; sleep2 300;
						if(rand(1,10) <= .@pID)
							getitem 526,2; // royal jelly
						cutin "f_04",4; specialeffect2 457; sleep2 300;
						cutin "f_05",4; specialeffect2 457; sleep2 300;
						cutin "f_06",4; specialeffect2 457; sleep2 300;
						for(.@j=0;.@j<.@loot1;.@j++) {
							if(rand(2) == 1) {
								getitem .@lootid1, 1;
							} else {
								.@inferior = .@lootid1 - 30000;
								getitem .@inferior, 1;
							}
						}
						cutin "f_ok",4; specialeffect2 457; sleep2 400;
						cutin "",255;
						pcblockmove getcharid(3),0;

						// getitem atoi(.@PlantVal$[1]),($PlantGain ? rand(1,atoi(.@PlantVal$[2])):atoi(.@PlantVal$[2]));
						query_sql "DELETE FROM `farm` WHERE `id` = "+.@name$;							


						callfunc "updateXP",.@PlantInfo[0];

						duplicateremove(strnpcinfo(0));
						end;
					}
					break;
			}
			end;
		}
	}
	dispbottom "This doesn't seem to belong to you."; 
	end;

}


function	script	updateXP	{
	.@lv = PRO_INFO[0];
	if(.@lv == (getarraysize(getvariableofnpc(.Farmer_Exp$,"farmer")) -1))
		return;

	.@plantlvl = getarg(0,0);

	if(.@plantlvl == 0) {
		// xp from creating food
		PRO_INFO[1] += (.@xp = 8);
	} else {
		// xp from harvesting
		if(.@lv < 7 && .@plantlvl < .@lv) 
			PRO_INFO[1] += (.@xp = getvariableofnpc(.Farmer_Exp[.@plantlvl],"farmer"));
		else 
			PRO_INFO[1] += (.@xp = getvariableofnpc(.Farmer_Exp[.@lv],"farmer"));
	}
	
	dispbottom "Farmer Exp gained: " + .@xp;
	

	if(PRO_INFO[1] >= getvariableofnpc(.Xp2LvlUp,"farmer") && PRO_INFO[0] < (getarraysize(getvariableofnpc(.Farmer_Exp,"farmer")) -1)) {
		.@lv++;
		setarray PRO_INFO[0], .@lv;
		setarray PRO_INFO[1], 0;
		specialeffect2 999;
		soundeffect "bijou_die.wav", 0;
		
		announce "Farmer LEVEL UP!",bc_blue|bc_self;
		dispbottom "You are now a " + getvariableofnpc(.Farmer_Exp$[.@lv],"farmer") + " Farmer. Congratulations!";
		if(.@lv < 7)
			dispbottom "You can now plant " + $@PlantName$[(.@lv+1)] + ".";

		if(.@lv >= 3) {
			setcell instance_mapname("farm", @instance),18,14,25,17,CELL_PLANT,1;
			setcell instance_mapname("farm", @instance),18,20,25,23,CELL_PLANT,1;
			setcell instance_mapname("farm", @instance),18,26,25,29,CELL_PLANT,1;

			setcell instance_mapname("farm", @instance),28,14,35,17,CELL_PLANT,1;
			setcell instance_mapname("farm", @instance),28,20,35,23,CELL_PLANT,1;
			setcell instance_mapname("farm", @instance),28,26,35,29,CELL_PLANT,1;

			setcell instance_mapname("farm", @instance),38,14,45,17,CELL_PLANT,1;
			setcell instance_mapname("farm", @instance),38,20,45,23,CELL_PLANT,1;
			setcell instance_mapname("farm", @instance),38,26,45,29,CELL_PLANT,1;
			dispbottom "First farm extension unlocked.";
		}

		if(.@lv == 7) {
			setcell instance_mapname("farm", @instance),50,14,57,17,CELL_PLANT,1;
			setcell instance_mapname("farm", @instance),50,20,57,23,CELL_PLANT,1;
			setcell instance_mapname("farm", @instance),50,26,57,29,CELL_PLANT,1;

			setcell instance_mapname("farm", @instance),60,14,67,17,CELL_PLANT,1;
			setcell instance_mapname("farm", @instance),60,20,67,23,CELL_PLANT,1;
			setcell instance_mapname("farm", @instance),60,26,67,29,CELL_PLANT,1;

			setcell instance_mapname("farm", @instance),70,14,77,17,CELL_PLANT,1;
			setcell instance_mapname("farm", @instance),70,20,77,23,CELL_PLANT,1;
			setcell instance_mapname("farm", @instance),70,26,77,29,CELL_PLANT,1;
			dispbottom "Second farm extension unlocked.";
		}
	}
	return;
}



//NPC Controle de Tempo & Configura��es
-	script	Plant_Control	FAKE_NPC,{

//Faz checagem a cada 10min (para verificar o tempo das plantas)
OnTimer600000: //10min

	query_sql "SELECT `id`,`plant_ord`,`finaltime` FROM `farm` WHERE `finaltime` <= "+gettimetick(2)+"",.@ID,.@pOrd,.@pTime;
    
	//Plantas expiradas
    if(getarraysize(.@ID)) {
        for(set .@i,0; .@i<getarraysize(.@ID); set .@i,.@i+1) {
			query_sql "DELETE FROM `farm` WHERE `id` = "+.@ID[.@i]+"";
			duplicateremove(" #"+.@ID[.@i]);
        }
    }
	stopnpctimer;
	initnpctimer;
	end;
	

OnInit:
	// set $Regador,523;		//ID do item que vai regar as plantas.	
	set $rQtd,90;			//Quantidade de foco para regar a planta
	// set $PlantGain,1;		// 0 = ganha o valor fixo definido na fun��o, 1 = ganha um valor aleat�rio definido na fun��o
	
	setarray $@PlantName$[1],"Apple Tree","Grapes Tree","Orange Tree","Strawberry Tree","Prickly Fruit Tree","Mastela Tree","Yggdrasil Tree";
	query_sql "CREATE TABLE IF NOT EXISTS `farm`(`char_id` INT NOT NULL,`name` VARCHAR(30) NOT NULL,`map` VARCHAR(13) NOT NULL,`x` SMALLINT(3) NOT NULL,`y` SMALLINT(3) NOT NULL,`plant_ord` TINYINT(3) NOT NULL,`plant_id` TINYINT(3) NOT NULL,`stage` TINYINT(1) NOT NULL,`time` INT(12) NOT NULL,`finaltime` INT(13) NOT NULL)";

	debugmes "Cleaning expired plants...";
	query_sql ("DELETE FROM `farm` WHERE `finaltime` <= "+gettimetick(2)+"");

	// query_sql "SELECT `char_id`,`map`,`x`,`y`,`stage`,`plant_id`,`plant_ord`,`finaltime` FROM `farm`",.@cID,.@map$,.@x,.@y,.@stage,.@pID,.@pOrd,.@pFtime;
	
	// if(getarraysize(.@cID))
	// {
	// 	for(set .@i,0; .@i<getarraysize(.@cID); set .@i,.@i+1)
	// 	{
	// 		if(.@pFtime[.@i] > gettimetick(2))
	// 		{
	// 			switch(.@stage[.@i])
	// 			{
	// 				case 1: set .@cSpr,3; break;
	// 				case 2: set .@cSpr,4; break;
	// 				case 3: set .@cSpr,5; break;
	// 				case 4: set .@cSpr,6; break;
	// 			}
	// 			set .@PlantInfo,explode(.@PlantVal$, callfunc("plant_type",.@pID[.@i]),",");
				
	// 			if(.@PlantVal$[.@cSpr] == "null"){
	// 				debugmes "PlantID: "+.@pID[.@i]+" - Stage: "+.@cSpr+" - SpriteID: "+.@PlantVal$[.@cSpr]+" [ ERROR ]"; 
	// 			} else {
	// 				if(compare(.@map$[.@i], "#") == 1)
	// 					continue;
	// 				duplicatenpc("planta2"," ",""+.@pOrd[.@i]+""+.@cID[.@i],.@map$[.@i],.@x[.@i],.@y[.@i],DIR_SOUTH,atoi(.@PlantVal$[.@cSpr])); 
	// 			}
	// 		}
	// 		else { 
	// 			query_sql "DELETE FROM `farm` WHERE `char_id`="+.@cID[.@i]+" AND `plant_ord`="+.@pOrd[.@i]+" AND `finaltime`="+.@pFtime[.@i]+""; 
	// 		}
	// 	}
	// }
	initnpctimer;
	end;
}




// == Func que guarda os tipos de plantas e suas informa��es
/*
	val 1 = Tipo de planta (ID �nico)
	var 2 = ID Item ganho ao coletar/cortar
	val 3 = Quantidade que ir� ser dado ao coletar (no script do Plant_Control deve configurar a forma que ser� dado essa quantidade)
			o script sorteara de 1 a var3. dara o numero sorteado em var2 e a diferenca do var3 - rand(x) em var12
	var 4 = NPC SPRITE ID STAGE 1
	var 5 = NPC SPRITE ID STAGE 2
	var 6 = NPC SPRITE ID STAGE 3
	var 7 = NPC SPRITE ID STAGE 4
	var 8 = TEMPO EM DELAY AP�S  PLANTAR/REGAR STAGE 1
	var 9 = TEMPO EM DELAY AP�S  PLANTAR/REGAR STAGE 2
	var 10 = TEMPO EM DELAY AP�S PLANTAR/REGAR STAGE 3
	var 11 = TEMPO EM DELAY AP�S PLANTAR/REGAR STAGE 4
	var 12 = ID DO SEGUNDO ITEM A DROPAR
*/	
function	script	plant_type	{

	if(!getarg(0)) return;
	
	switch(getarg(0))
	{
		case 1: set .@PlantSet$,"1,30512,10,10463,10464,10465,10466,0,0,0,86400,507"; break; // apple tree
		case 2: set .@PlantSet$,"2,30514,10,10463,10464,10465,10468,0,0,0,86400,511"; break; // grapes tree
		case 3: set .@PlantSet$,"3,30582,10,10463,10464,10465,10469,0,0,0,86400,508"; break; // orange tree
		case 4: set .@PlantSet$,"4,30578,10,10463,10464,10465,10470,0,0,0,86400,509"; break; // strawberry tree
		case 5: set .@PlantSet$,"5,30576, 8,10463,10464,10465,10472,0,0,0,86400,587"; break; // prickly tree
		case 6: set .@PlantSet$,"6,30522, 6,10463,10464,10465,10471,0,0,0,86400,510"; break; // mastela tree
		case 7: set .@PlantSet$,"7,30607, 6,10463,10464,10465,10467,0,0,0,86400,12292"; break; // yggdrasil tree
	}
	
	return (.@PlantSet$ != "" ? .@PlantSet$:"null");
}


// This is used by the Farm System (called the moment the player enters the farm)
function	script	F_SpawnFarmCrops	{
	.@count = query_sql("SELECT `char_id`,`x`,`y`,`stage`,`plant_id`,`plant_ord`,`finaltime` FROM `farm` WHERE `map` = 'farm' AND `char_id` = " + getcharid(0),.@cID,.@x,.@y,.@stage,.@pID,.@pOrd,.@pFtime);
	.@map$ = instance_mapname("farm",@instance);
	if(getarraysize(.@cID))
	{
		for(.@i=0; .@i<.@count;.@i++)
		{
			if(.@pFtime[.@i] > gettimetick(2))
			{
				switch(.@stage[.@i])
				{
					case 1: set .@cSpr,3; break;
					case 2: set .@cSpr,4; break;
					case 3: set .@cSpr,5; break;
					case 4: set .@cSpr,6; break;
				}
				set .@PlantInfo,explode(.@PlantVal$, callfunc("plant_type",.@pID[.@i]),",");
				
				if(.@PlantVal$[.@cSpr] != "null")
					duplicatenpc("planta2"," ",""+.@pOrd[.@i]+""+.@cID[.@i],.@map$,.@x[.@i],.@y[.@i],DIR_SOUTH,atoi(.@PlantVal$[.@cSpr])); 
			}
			else
				query_sql "DELETE FROM `farm` WHERE `char_id`="+.@cID[.@i]+" AND `plant_ord`="+.@pOrd[.@i]+" AND `finaltime`<="+.@pFtime[.@i]+"";
		}
	}
	return;
}


function	script	F_FarmInstancing	{
	.@instance$ = "Farm";
	if(@instance > 0) {
		instance_destroy @instance;
		sleep2 500;
	}

    .@create = instance_create(.@instance$, IM_NONE);
    if (.@create < 0) {
        switch (.@create) {
            case -1: dispbottom "ERROR: Invalid type."; break;
            case -2: dispbottom "ERROR: Party not found."; break;
            case -3: dispbottom "ERROR: Instance already exists."; break;
            case -4: dispbottom "ERROR: No free instances."; break;
        }
        dispbottom "Instance creation ^FF0000failed^000000.";
        end;
    }

	@instance = .@create;

	setcell instance_mapname("farm", @instance),1,1,300,300,CELL_PLANT,0;

	// Farmer lvl 0-2  = 30.000z to buy the land
    setcell instance_mapname("farm", @instance),38,60,45,63,CELL_PLANT,1;
	setcell instance_mapname("farm", @instance),38,66,45,69,CELL_PLANT,1;
	setcell instance_mapname("farm", @instance),38,72,45,75,CELL_PLANT,1;
	setcell instance_mapname("farm", @instance),38,78,45,81,CELL_PLANT,1;

	setcell instance_mapname("farm", @instance),50,60,57,63,CELL_PLANT,1;
	setcell instance_mapname("farm", @instance),50,66,57,69,CELL_PLANT,1;
	setcell instance_mapname("farm", @instance),50,72,57,75,CELL_PLANT,1;
	setcell instance_mapname("farm", @instance),50,78,57,81,CELL_PLANT,1;

	if(PRO_INFO[0] >= 3) {
		setcell instance_mapname("farm", @instance),18,14,25,17,CELL_PLANT,1;
		setcell instance_mapname("farm", @instance),18,20,25,23,CELL_PLANT,1;
		setcell instance_mapname("farm", @instance),18,26,25,29,CELL_PLANT,1;

		setcell instance_mapname("farm", @instance),28,14,35,17,CELL_PLANT,1;
		setcell instance_mapname("farm", @instance),28,20,35,23,CELL_PLANT,1;
		setcell instance_mapname("farm", @instance),28,26,35,29,CELL_PLANT,1;

		setcell instance_mapname("farm", @instance),38,14,45,17,CELL_PLANT,1;
		setcell instance_mapname("farm", @instance),38,20,45,23,CELL_PLANT,1;
		setcell instance_mapname("farm", @instance),38,26,45,29,CELL_PLANT,1;
	}
	if(PRO_INFO[0] >= 4) {
		setcell instance_mapname("farm", @instance),50,14,57,17,CELL_PLANT,1;
		setcell instance_mapname("farm", @instance),50,20,57,23,CELL_PLANT,1;
		setcell instance_mapname("farm", @instance),50,26,57,29,CELL_PLANT,1;

		setcell instance_mapname("farm", @instance),60,14,67,17,CELL_PLANT,1;
		setcell instance_mapname("farm", @instance),60,20,67,23,CELL_PLANT,1;
		setcell instance_mapname("farm", @instance),60,26,67,29,CELL_PLANT,1;

		setcell instance_mapname("farm", @instance),70,14,77,17,CELL_PLANT,1;
		setcell instance_mapname("farm", @instance),70,20,77,23,CELL_PLANT,1;
		setcell instance_mapname("farm", @instance),70,26,77,29,CELL_PLANT,1;
	}

	callfunc "F_SpawnFarmCrops";

	.@enter = instance_enter(.@instance$,-1,-1,getcharid(0),@instance);
	if (.@enter != 0) {
		switch (.@enter) {
			case 1: dispbottom "ERROR: Party not found."; break;
			case 2: dispbottom "ERROR: Party does not have an instance."; break;
			case 3: dispbottom "ERROR: Unknown error."; break;
		}
		dispbottom "Instance entry ^FF0000failed^000000.";
		end;
	}
	end;
}


// SHOPS
-	shop	Farmer Shop	-1,30033:-1,30039:-1,30037:-1,30034:-1,30038:-1,30036:-1,30035:-1
farm,65,82,4	shop	Farmer Shop#2	577,30033:-1,30039:-1,30037:-1,30034:-1,30038:-1,30036:-1,30035:-1


hugel,149,196,4	script	Farmer Dealer	577,{
	mes " [Farmer Dealer] ";
	mes "Howdy, Stranger!";
	mes "Lookin' for somethin' special?";
	close2;
	callshop "Farmer Shop",0;
	end;
}