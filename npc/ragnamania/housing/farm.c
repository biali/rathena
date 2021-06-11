//Func Main
function	script	farm	{

	set .@pID,getarg(0);
	set .@item,getarg(1);
	set .@cName$,strcharinfo(0);
	set .@cID,getcharid(0);
	
	getmapxy(.@map$,.@x,.@y,BL_PC);
	set .@y,.@y-1;

	if(checknonearnpc(strcharinfo(3),2) < 1) {
		dispbottom "You cannot plant it here as it's too close to another NPC. Please choose a different spot.",0xFF0000;
		getitem .@item,1; 
		end;
	}

	if(!@instance) {
		dispbottom "You can only plant in the premisses of your house.",0xFF0000;
		getitem .@item,1; 
		end;
	}
	
	query_sql "SELECT `plant_id` FROM `farm` WHERE `map`='"+.@map$+"' AND `x`="+.@x+" AND `y`="+.@y+"",.@ccheck;
	
	if(.@ccheck){ 
		dispbottom "This spot is taken. Please choose a different place.",0xFF0000; 
		getitem .@item,1; 
		end; 
	}
	
	mes "Do you want to go ahead and plant it here?";
	if(select("Yes:No")==2){ 
		getitem .@item,1;
		close; 
	}
 	close2;	
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
		getitem .@item,1; 
		end; 
	}
	
	showscript "Planting...";
	progressbar "0xFFFFFF",1;
	.@id$ = .@rst+""+getcharid(0);
	duplicatenpc("planta2", " ",""+.@id$,.@map$,.@x,.@y,DIR_SOUTH,atoi(.@PlantVal$[3]));
	set .@tTmp,(gettimetick(2)+atoi(.@PlantVal$[7]));
	query_sql "INSERT INTO `farm` (`id`,`char_id`,`name`,`map`,`x`,`y`,`plant_ord`,`plant_id`,`stage`,`time`,`finaltime`) VALUES ("+"'"+.@id$+"'"+","+.@cid+",'"+.@cName$+"','"+.@map$+"',"+.@x+","+.@y+","+.@rst+","+.@pID+",1,"+.@tTmp+","+(gettimetick(2)+86400)+")";
	end;
}


//NPC Main
-	script	planta2	-1,{

	getmapxy(.@map$, .@x, .@y, BL_NPC);
	for(.@a=0;.@a<getstrlen(strnpcinfo(2));.@a++) {
		if(charat(strnpcinfo(2),.@a) == " " || charat(strnpcinfo(2),.@a) =="#")
			continue;
		.@name$ += charat(strnpcinfo(2),.@a);
	}

	if(.@rst = query_sql("SELECT `id`,`char_id`,`plant_ord`,`plant_id`,`stage`,`time` FROM `farm` WHERE `id`="+.@name$,.@id,.@cID,.@pOrd,.@pID,.@stage,.@time) > 0) {
		
		if(.@cID) {
			mes "^ff0000Plant Name:^000000 "+$PlantName$[.@pID]+"";			
			mes "^ff0000Growth:^000000 "+.@stage+"/4";		
			mes "";			
			set .@calcT,.@time-gettimetick(2);

			mes "^ff0000"+(.@stage == 3 ? "Ready to Harvest:":"Next Stage:")+"^000000 "+(.@calcT < 60 ? (.@calcT < 0 ? "Ready":.@calcT+"sec"):(.@calcT/60)+"min+");
			
			menu (.@stage < 4 ? "Water":"")+"",-,(.@stage == 4 ? "Harvest":"")+"",-,"Tag",-,"Close",-;
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
					{
						if(countitem($Regador) < $rQtd){ 
							mes "^FF0000* You'll need a "+$rQtd+"x "+getitemname($Regador)+" in order to do that.^000000"; 
							close; 
						}									
						set .@nTmp$,strnpcinfo(0);
						query_sql "UPDATE `farm` SET `stage`="+.@cStage+",`time`="+.@cTime+" WHERE `char_id` = "+getcharid(0)+" AND `plant_ord`="+.@pOrd+" AND `plant_id`="+.@pID;
						delitem $Regador,$rQtd;
						close2;
						duplicateremove(strnpcinfo(0));
						duplicatenpc("planta2", " ",.@nTmp$,.@map$,.@x,.@y,DIR_SOUTH,atoi(.@PlantVal$[.@cSpr]));				
					}
					else
					{
						if(getstatus(SC_WEIGHT50)) { 
							npctalk "[Harvest]: It seems you are carrying too much weight to continue."; 
							close; 
						} else 
							if(select("Harvest:Cancel") == 2)
								close; 

						
						set .@PlantInfo,explode(.@PlantVal$, callfunc("plant_type",.@pID),",");
						getitem atoi(.@PlantVal$[1]),($PlantGain ? rand(1,atoi(.@PlantVal$[2])):atoi(.@PlantVal$[2]));
						query_sql "DELETE FROM `farm` WHERE `id` = "+.@name$;							
						mes "Harvesting...!";
						// setarray $PlantSySTmP$[(getarraysize($PlantSySTmP$) ? getarraysize($PlantSySTmP$):0)],strnpcinfo(0);
						close2;
						// deletearray $PlantSySTmP$[(inarray($PlantSySTmP$[0],strnpcinfo(0)))],1;
						duplicateremove(strnpcinfo(0));
						end;
					}
					break;
						
				case 3:				
						if(select("Enable Tag:Disable Tag")==2){ delwaitingroom strnpcinfo(0); close; }						
						if(!getwaitingroomstate(3,strnpcinfo(0))){ mes "It is already active!"; close; }						
						waitingroom "[ "+strcharinfo(0)+" ]",0;						
						close;
			}
			end;
		}
	}
	dispbottom "This doesn't seem to belong to you."; end;
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
	set $Regador,523;		//ID do item que vai regar as plantas.	
	set $rQtd,1;			//Quantidade do item que vai ser utilizado
	set $PlantGain,1;		// 0 = ganha o valor fixo definido na fun��o, 1 = ganha um valor aleat�rio definido na fun��o
	
	setarray $PlantName$[1],"Apple Tree","Yggdrasil Tree","Orange Tree";
	query_sql "CREATE TABLE IF NOT EXISTS `farm`(`char_id` INT NOT NULL,`name` VARCHAR(30) NOT NULL,`map` VARCHAR(13) NOT NULL,`x` SMALLINT(3) NOT NULL,`y` SMALLINT(3) NOT NULL,`plant_ord` TINYINT(3) NOT NULL,`plant_id` TINYINT(3) NOT NULL,`stage` TINYINT(1) NOT NULL,`time` INT(12) NOT NULL,`finaltime` INT(13) NOT NULL)";

	query_sql "SELECT `char_id`,`map`,`x`,`y`,`stage`,`plant_id`,`plant_ord`,`finaltime` FROM `farm`",.@cID,.@map$,.@x,.@y,.@stage,.@pID,.@pOrd,.@pFtime;
	
	if(getarraysize(.@cID))
	{
		for(set .@i,0; .@i<getarraysize(.@cID); set .@i,.@i+1)
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
				
				if(.@PlantVal$[.@cSpr] == "null"){
					debugmes "PlantID: "+.@pID[.@i]+" - Stage: "+.@cSpr+" - SpriteID: "+.@PlantVal$[.@cSpr]+" [ ERROR ]"; 
				} else {
					if(compare(.@map$[.@i], "#") == 1)
						continue;
					duplicatenpc("planta2"," ",""+.@pOrd[.@i]+""+.@cID[.@i],.@map$[.@i],.@x[.@i],.@y[.@i],DIR_SOUTH,atoi(.@PlantVal$[.@cSpr])); 
				}
			}
			else { 
				query_sql "DELETE FROM `farm` WHERE `char_id`="+.@cID[.@i]+" AND `plant_ord`="+.@pOrd[.@i]+" AND `finaltime`="+.@pFtime[.@i]+""; 
			}
		}
	}
	initnpctimer;
	end;
}




// == Func que guarda os tipos de plantas e suas informa��es
/*
	val 1 = Tipo de planta (ID �nico)
	var 2 = ID Item ganho ao coletar/cortar
	val 3 = Quantidade que ir� ser dado ao coletar (no script do Plant_Control deve configurar a forma que ser� dado essa quantidade)
	var 4 = NPC SPRITE ID STAGE 1
	var 5 = NPC SPRITE ID STAGE 2
	var 6 = NPC SPRITE ID STAGE 3
	var 7 = NPC SPRITE ID STAGE 4
	var 8 = TEMPO EM DELAY AP�S  PLANTAR/REGAR STAGE 1
	var 9 = TEMPO EM DELAY AP�S  PLANTAR/REGAR STAGE 2
	var 10 = TEMPO EM DELAY AP�S PLANTAR/REGAR STAGE 3
	var 11 = TEMPO EM DELAY AP�S PLANTAR/REGAR STAGE 4
*/	
function	script	plant_type	{

	if(!getarg(0)) return;
	
	switch(getarg(0))
	{
		case 1: set .@PlantSet$,"1,512,30,10463,10464,10465,10466,180,180,180,180"; break;	//Planta 1 (NPC-ID-1,NPC-ID-2,NPC-ID-3)
		case 2: set .@PlantSet$,"2,607,8,10463,10464,10465,10467,180,180,180,180"; break;	//Planta 2 (NPC-ID-1,NPC-ID-2,NPC-ID-3)
	}
	
return (.@PlantSet$ != "" ? .@PlantSet$:"null");
}


// This is used by the Housing System (called from functions.c at the moment the player steps in their house)
function	script	F_SpawnCrops	{
	.@count = query_sql("SELECT `char_id`,`x`,`y`,`stage`,`plant_id`,`plant_ord`,`finaltime` FROM `farm` WHERE `map` LIKE '%#%' AND `char_id` = " + getcharid(0),.@cID,.@x,.@y,.@stage,.@pID,.@pOrd,.@pFtime);
	.@map$ = instance_mapname("rentb1",@instance);
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