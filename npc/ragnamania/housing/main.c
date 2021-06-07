-	script	HousingCfg	-1,{ 
	end;
OnInit:
	// Constantes com as coordenadas das entradas das casas
	// Localizacao do warp que leva da praca para o patio da casa
	setarray $@HDWarpMx[0],106,78,40,40,40,40,40,40,49,77,105,133,161,189,217,225,225,225,225,225,225,189,161,108,108,159,159;
	setarray $@HDWarpMy[0],42,42,49,77,105,133,161,189,225,225,225,225,225,225,225,188,160,132,104,76,48,42,42,108,159,159,108;
	// Localizacao do Respawn quando sai do patio da casa para a praca
	setarray $@HDRespMx[0],106,78,44,44,44,44,44,44,48,77,105,133,161,189,217,220,220,220,220,220,220,189,161,113,113,155,155;
	setarray $@HDRespMy[0],47,47,49,76,105,133,161,189,220,220,220,220,220,220,220,188,160,132,104,76,48,47,47,113,154,155,114;	
	
	// *** Uncommend these line to setup regions when the server runs for
	// *** the first time after a wipe.
		set $Region[23],1; // Midgardian Village

	// INFOSHEET //

	// #HOUSING_TIPS$[0]		: Gardener
	// #HOUSING_TIPS$[1]		: Housekeeper

	// #HOUSING$[0]				: House Id
	// #HOUSING$[1]				: Rend amount
	// #HOUSING$[2]				: Gardener
	// #HOUSING$[3] 			: Housekeeper
	// #HOUSING$[4]				: Claning Lady
	// #HOUSING$[5] 			: Oven
	// #HOUSING$[6] 			: Storage
	// #HOUSING$[7] 			: Beds
	// #HOUSING$[8]				: Wardrobe/Mirror
	end;
}


rent_mb,134,58,4	script	Properties Manager::mngr	1902,{
	function	ExtendContract; function	HireService; function	WipeData;
	if(atoi(#HOUSING$[0]) > 0 && atoi(#HOUSING$[1]) < gettimetick(2)) {
		WipeData();
		mes .n$;
		mes "Oh Lord, you've missed your contract renew date. I am afraid I have just rented your previous house to someone else.";
		next;
		mes .n$;
		mes "I was ver clear the first time: Not a second late!";
		next;
	} else {
		mes .n$;
		mes "Howdy, "+strcharinfo(0);
		mes "How ya' doing today?";
		next;
		mes .n$;
		mes "Busy as usual, I can see...";
		mes "Well, how can I be of your help, then?";
		next;
	}
	switch(select("I'd like to rent a house:About my contract")) {
	RentHouse:
	case 1:
		if(atoi(#HOUSING$[1]) > gettimetick(2)) {
			mes .n$;
			mes strcharinfo(0) + ", my dear, I am sorry but you can only have one house at the time.";
			next;
			mes .n$;
			mes "Your place at number ^AA11AA"+#HOUSING$[0]+"^000000 is paid and yours to use for another ^AA11AA"+ callfunc("Time2Str",atoi(#HOUSING$[1]))+"^000000.";
			mes "Do you wanna extent your contract now?";
			next;
			if(select("Yes, please.:No, not now. Thanks") == 2)
				close;
			ExtendContract();
			mes .n$;
			mes "All done! Thank you very much!";
			mes "Your new contract ends in ^AA11AA" + callfunc("Time2Str",atoi(#HOUSING$[1])) + "^000000.";
			close;
			end;
		}
		mes .n$;
		mes "Of course, why not?";
		mes "Well, it's been pretty busy, recently...";
		next;
		mes .n$;
		mes "Because of that the prices are a bit in a steep right now.";
		next;
		mes .n$;
		mes "But worry not!";
		mes "I have this lovely two-bedroom house available for a very competitive price.";
		mes "Not sale, though. Renting.";
		next;
		mes .n$;
		mes "That one will cost you "+F_InsertComma(.Rent)+"z per week.";
		mes "What do you think?";
		next;
		if(select("That is fine, I will take it.:No, that is too much.") == 2) {
			mes .n$;
			mes "I understand... Just don't wait too much. They are limited, you know...";
			close;
		}
		mes .n$;
		mes "Fantastic!";
		mes "It will be "+F_InsertComma(.Rent)+"z paid in advance, please.";
		mes "I will then show you your new home!";
		next;
		if(select("Pay now:Cancel") == 2)
			close;
		ExtendContract();
		mes .n$;
		mes "Perfect!";
		mes "Your new place is ^AA5500house number " + #HOUSING$[0] + "^000000.";
		next;
		mes .n$;
		mes "Are you excited to meet the place? I bet you are gonna love it and this neighbourhood is so lively!";
		next;
		mes .n$;
		mes "Remember! Your rent is due to renew in ^5599AA" + callfunc("Time2Str",atoi(#HOUSING$[1])) + "^000000.";
		next;
		mes .n$;
		mes "I'd appreciate if you paid before the deadline. I won't tolerate any delays and will take the house back the second after the expiration time.";
		next;
		mes .n$;
		mes "If you force me to do that, you are gonna lose any improvements you've carried out in the house may you want to rent it again.";
		next;
		mes .n$;
		mes "You can always pay rent in advance, though. Any time, just talk to me and we can extend your contract.";
		next;
		mes .n$;
		mes "Well, that covers every thing, I belive.";
		mes "Should we meet at the house?";
		mes "See you there!";
		close;
		break;
	case 2:
		if(getarraysize(#HOUSING$) == 0) {
			mes .n$;
			mes "I am afraid I could not find anything on your name in my records...";
			close;
		}
		mes .n$;
		mes "^AA0000-- Contract for House # " + #HOUSING$[0] + " --^000000";
		mes "Rent: " + (atoi(#HOUSING$[1])<gettimetick(2)?F_InsertComma(.Rent)+"z p/w":callfunc("Expire",atoi(#HOUSING$[1]))+ " ("+.Rent+"z p/w)");
		mes "Gardener: " + (atoi(#HOUSING$[2])<gettimetick(2)?F_InsertComma(.Gardener)+"z p/w":callfunc("Expire",atoi(#HOUSING$[2]))+ " ("+.Gardener+"z p/w)");
		mes "Housekeeper: " + (atoi(#HOUSING$[3])<gettimetick(2)?F_InsertComma(.Housekeeper)+"z p/w":callfunc("Expire",atoi(#HOUSING$[3]))+" ("+.Housekeeper+"z p/w)");
		.@total = callfunc("F_CalcCosts");
		mes "Total per Week: " + F_InsertComma(.@total);
		next;
		switch(select("Renew Rent:Gardening Services:Housekeeping Services:Cancel")) {
		case 1:
			mes .n$;
			if( atoi(#HOUSING$[0]) == 0 || atoi(#HOUSING$[1]) < gettimetick(2) ) {
				// First time or after expiration
				mes .n$;
				mes "I am afraid we don't have any contracts in your name. You may want to rent a house, maybe?";
				next;
				goto RentHouse;
			} else if(atoi(#HOUSING$[1]) > gettimetick(2)) {
				mes .n$;
				mes "Absolutely, that will be ^AA11AA"+F_InsertComma(.Rent)+"^000000z for another week of rent.";
				next;
				ExtendContract();
				mes .n$;
				mes "All done! Thank you very much!";
				mes "Your new contract ends in ^AA11AA" + callfunc("Time2Str",atoi(#HOUSING$[1])) + "^000000.";
				close;
			}
			break;
		case 2:
			mes .n$;
			if(atoi(#HOUSING$[2]) < gettimetick(2)) {
				mes "Do you wanna hire a gardener to help you with the chores and perhaps even plot the land and produce a some delicious fruits and veggies?";
				next;
				mes .n$;
				mes "We have Maia available, she is very good. Reliable, hard worker...";
				mes "She is available for " + F_InsertComma(.Gardener) + "z per week.";
				next;
				if(select("Hire Maia:Cancel") == 2)
					goto Dismiss;
				else {
					HireService(2,.Gardener);
					mes .n$;
					mes "All done... She is ready to start.";
					mes "Thank you for your custom.";
					close;
				}
			} else {
				mes "Do you want to extend your contract with ^AA00AAMaia^000000 for another week? That would be another "+ F_InsertComma(.Gardener) +"z. Payment in advance. Always.";
				next;
				if(select("Yes, please:No, Thank you") == 2)
					goto Dismiss;
				HireService(2,.Gardener);
				mes .n$;
				mes "All done! Thank you very much!";
				mes "Your new contract with ^AA00AAMaia^000000 ends in ^AA11AA" + callfunc("Time2Str",atoi(#HOUSING$[2])) + "^000000.";
				close;
			}
			break;
		case 3:
			mes .n$;
			if(atoi(#HOUSING$[3]) < gettimetick(2)) {
				mes "Do you wanna hire a housekeeper to help you with the pool? I bet there are a couple of very interesing things one can do with a pool around.";
				next;
				mes .n$;
				mes "We have Alfonso available, he is highly recommended!";
				mes "He is available for " + F_InsertComma(.Housekeeper) + "z per week.";
				next;
				if(select("Hire Alfonso:Cancel") == 2)
					goto Dismiss;
				else {
					if(Zeny < .Housekeeper)
						goto OnNoZeny;
					set Zeny, Zeny - .Housekeeper;
					set #HOUSING$[3],gettimetick(2)+.Period;
					mes .n$;
					mes "All done... He is on his way!";
					mes "Thank you for your custom.";
					close;
				}
			}
			break;
		case 4:
			close;
			break;
		}

	}
	end;

OnNoZeny:
	mes .n$;
	mes "Oh, " + strcharinfo(0) + ", what is going on here? You don't seem to have enough Zeny for this.";
	close;

Dismiss:
	mes .n$;
	mes "No problem, I understand.";
	mes "See you around!";
	close;

OnInit:
	.n$ 		= "^0000FF[ Properties Manager ]^000000";
	.Rent 		= 40000;
	.Period 	= 604800; 	// 7 dias
	.Gardener 	= 12000;
	.Housekeeper= 18000;
	end;

	function	ExtendContract	{
		if(Zeny < .Rent){
			goto OnNoZeny;
			end;
		}
		set Zeny, Zeny - .Rent;
		if(atoi(#HOUSING$[1]) < gettimetick(2)) {
			set #HOUSING$[0], rand(1,23);				// House Id
			set #HOUSING$[1], gettimetick(2) + .Period;	// Rent amount
			set #HOUSING$[2], 0; 						// Gardener
			set #HOUSING$[3], 0; 						// Housekeeper
			set #HOUSING$[4], 0; 						// Claning Lady
			set #HOUSING$[5], 0; 						// Oven
			set #HOUSING$[6], 0; 						// Storage
			set #HOUSING$[7], 0; 						// Beds
			set #HOUSING$[8], 0; 						// Wardrobe/Mirror
		} else {
			set #HOUSING$[1], atoi(#HOUSING$[1]) + .Period;	// Rent amount
		}
		return;
	}

	function	HireService	{
		.@index 	= getarg(0);
		.@cost		= getarg(1);
		if(Zeny < .@cost) {
			goto OnNoZeny;
			end;
		}
		set Zeny, Zeny - .@cost;
		if(atoi(#HOUSING$[.@index]) < gettimetick(2)) { // New Service or it was expired
			switch(atoi(#HOUSING$[.@index])) {
			case 2: // Gardener
				setarray #HOUSING_CROPS$[0],		"0","0","0","0","0","0","0","0","0","0";
				setarray #HOUSING_CROPS_QTY$[0],	"0","0","0","0","0","0","0","0","0","0";
				set #HOUSING_TIPS$[0],				"0";
				break;
			case 3: // Housekeeper
				break;
			}
			set #HOUSING$[.@index],gettimetick(2) + .Period;
		} else { // Renewing before expiration
			set #HOUSING$[.@index],atoi(#HOUSING$[.@index]) + .Period;
		}
		return;
	}

	function	WipeData	{
		// services array
		deletearray #HOUSING$[0],getarraysize(#HOUSING$);
		deletearray #HOUSING_TIPS$[0], getarraysize(#HOUSING_TIPS$);
		// gardener-related array
		deletearray #HOUSING_CROPS$[0],getarraysize(#HOUSING_CROPS$);
		deletearray #HOUSING_CROPS_QTY$[0],getarraysize(#HOUSING_CROPS_QTY$);

		return;
	}
}


// ********************************************
// Plaquinhas das casas
// ********************************************
rent_mb,111,45,1	script	House Plate#1	837,{
	mes "[Home Sweet Home]";
	mes "Welcome to my house!";
	mes " ";
	mes "House Number ^0000FF *~~ [" + strnpcinfo(2) + "] ~~* ^000000";
	close;
OnInit:
	waitingroom "House # "+strnpcinfo(2),0;
}



// ********************************************************************
// Housing Warps 

// ********************************************************************
// House Entrance (door steps, outside -> in)
// ********************************************************************
rentb1,19,24,0	script	PortaDeCasa#b1	45,2,2,{
	end;

OnInstanceInit:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnTouch:
	.@map$ = "rentin"+strnpcinfo(2);
	warp instance_mapname(.@map$,@instance),26,7;
	end;
}

// ********************************************************************
// House Entrance (door steps, inside -> out)
// ********************************************************************
rentinb1,34,3,0	script	FrontDoorIn#b1	45,2,2,{
	end;

OnInstanceInit:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnTouch:
	.@map$ = "rent"+strnpcinfo(2);
	warp instance_mapname("rentb1",@instance),20,17;
	end;
}

// ********************************************************************
// Front Gate of the House (inside -> out)
// ********************************************************************
rentb1,22,2,0	script	FrontGate#rent_mb	45,2,2,{
	end;

OnTouch:
	warp strnpcinfo(2),$@HDRespMx[atoi(#HOUSING$[0])-1],$@HDRespMy[atoi(#HOUSING$[0])-1];
	instance_destroy;
	@instance = 0;
	end;
}


// ********************************************************************
// Front Gate of the House (outside -> in)
// ********************************************************************

rent_mb,106,42,0	script	PortaoDaCasa#1	45,2,2,{
	end;

OnTouch:
	if(atoi(#HOUSING$[0]) == 0)
		message strcharinfo(0),"What am I doing? I don't even have a house! ";
	else if(#HOUSING$[0] != strnpcinfo(2))
		message strcharinfo(0),"Omg! What am I doing? My house is number " + #HOUSING$[0];
	else
		callfunc "F_HouseInstancing",atoi(strnpcinfo(2));

	end;
}


// ********************************************************************
// Storage
// ********************************************************************

rentinb1,9,5,0	script	#Storage	844,{
	if (getcharid(0) == getpartyleader(getcharid(1),2)) {
		callfunc("F_CheckKafCode");	//check your storage password, if set
		openstorage;
	} else {
		dispbottom "I shouldn't be messying with my friend's stuff...";
	}
	end;

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
}


// ********************************************************************
// Beds
// ********************************************************************

rentinb1,26,34,0	script	#Beds	844,{
	if (getcharid(0) == getpartyleader(getcharid(1),2)) {
		switch(select("Rest:Cancel")) {
		case 1:
			message strnpcinfo(0), "Hope I have one of those dreams....";
			sleep2 5000;
			percentheal 100,100;
			specialeffect2 EF_BLESSING; sc_start SC_BLESSING,600000,10;
			specialeffect2 EF_INCAGILITY; sc_start SC_INCREASEAGI,600000,10;
			if (countitem(521) >= 1){
				delitem 521,1;
				warp "dreamland",128,132;
			}
			end;
			break;
		case 2:
			end;
			break;
		}
	} else {
		dispbottom "I shouldn't be messying with my friend's stuff...";
	}
	end;

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
}



// ********************************************************************
// Oven
// ********************************************************************

rentinb1,6,7,0	script	#Oven	844,{
	if (getcharid(0) == getpartyleader(getcharid(1),2)) {
		if(countitem(6251) > 0){
			delitem 6251,1;
			cooking 16;
		} else {
			message strcharinfo(0), "Hum... I am afraid I'll need some " + getitemname(6251) + " first.";
		}
		end;
	} else {
		dispbottom "I shouldn't be messying with my friend's stuff...";
	}
	end;

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;

}


// ********************************************************************
// Library
// ********************************************************************
-	script	Books#inscription	-1,{
	callfunc "Inscription_Info",InscriptionLvl;
	end;

OnInstanceInit:
OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;

}


// ** Duplications
// ********************************************************************


// Plaquinhas das casas
// ******************************************************************

// Midigardians Village
rent_mb,83,46,1	duplicate(House Plate#1)	House Plate#2	837
rent_mb,43,53,1	duplicate(House Plate#1)	House Plate#3	837
rent_mb,43,72,1	duplicate(House Plate#1)	House Plate#4	837
rent_mb,43,100,1	duplicate(House Plate#1)	House Plate#5	837
rent_mb,43,128,1	duplicate(House Plate#1)	 House Plate#6	837
rent_mb,43,156,1	duplicate(House Plate#1)	House Plate#7	837
rent_mb,43,184,1	duplicate(House Plate#1)	House Plate#8	837
rent_mb,44,222,1	duplicate(House Plate#1)	House Plate#9	837
rent_mb,72,222,1	duplicate(House Plate#1)	House Plate#10	837
rent_mb,100,222,1	duplicate(House Plate#1)	House Plate#11	837
rent_mb,128,222,1	duplicate(House Plate#1)	House Plate#12	837
rent_mb,156,222,1	duplicate(House Plate#1)	House Plate#13	837
rent_mb,184,222,1	duplicate(House Plate#1)	House Plate#14	837
rent_mb,212,222,1	duplicate(House Plate#1)	House Plate#15	837
rent_mb,222,193,1	duplicate(House Plate#1)	House Plate#16	837
rent_mb,222,165,1	duplicate(House Plate#1)	House Plate#17	837
rent_mb,222,137,1	duplicate(House Plate#1)	House Plate#18	837
rent_mb,222,109,1	duplicate(House Plate#1)	House Plate#19	837
rent_mb,222,81,1	duplicate(House Plate#1)	House Plate#20	837
rent_mb,222,53,1	duplicate(House Plate#1)	House Plate#21	837
rent_mb,193,45,1	duplicate(House Plate#1)	House Plate#22	837
rent_mb,165,45,1	duplicate(House Plate#1)	House Plate#23	837


// Portao da casa (main entrance warp)
// ******************************************************************

// Midgardian Village
rent_mb,106,42,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#1	45,2,2
rent_mb,78,42,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#2	45,2,2
rent_mb,40,49,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#3	45,2,2
rent_mb,40,77,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#4	45,2,2
rent_mb,40,105,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#5	45,2,2
rent_mb,40,133,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#6	45,2,2
rent_mb,40,161,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#7	45,2,2
rent_mb,40,189,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#8	45,2,2
rent_mb,49,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#9	45,2,2
rent_mb,77,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#10	45,2,2
rent_mb,105,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#11	45,2,2
rent_mb,133,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#12	45,2,2
rent_mb,161,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#13	45,2,2
rent_mb,189,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#14	45,2,2
rent_mb,217,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#15	45,2,2
rent_mb,225,188,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#16	45,2,2
rent_mb,225,160,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#17	45,2,2
rent_mb,225,132,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#18	45,2,2
rent_mb,225,104,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#19	45,2,2
rent_mb,225,76,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#20	45,2,2
rent_mb,225,48,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#21	45,2,2
rent_mb,189,42,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#22	45,2,2
rent_mb,161,42,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#23	45,2,2


// Shops
rent_mb,230,215,3	shop	McDonald	765,30033:15000,30034:15000,30035:15000,30036:15000,30037:15000,30038:15000,30039:15000,30040:15000,30041:15000,30042:15000;