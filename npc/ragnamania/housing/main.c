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

	// HOUSING$[0]				: House Id
	// HOUSING$[1]				: Rent Due Date
	// HOUSING$[2]				: Services Level
	end;
}


rent_mb,134,58,4	script	Properties Manager::mngr	1902,{
	function BuyHouse; function ExtendContract; function ServiceType; function ExplainServices;
	if(atoi(HOUSING$[0]) > 0 && atoi(HOUSING$[1]) < gettimetick(2)) {
		mes .n$;
		mes "Are you wondering why I've changed the locks at number #" + HOUSING$[0] + "? Well, you haven't paid the Maintenance Fee, that is why! Do you want to do that now?";
		next;
		if(select("Yes, please.:No, I am good, thanks.") == 2)
			goto RentHouse;
		else
			close;
	} else {
		mes .n$;
		mes "Hello, "+strcharinfo(0);
		mes "How ya' doing today?";
		next;
		mes .n$;
		mes "Busy as usual, I can see...";
		mes "Well, how can I be of your help, then?";
		next;
	}
RentHouse:
	switch(select("I'd like to buy a house:I'd like to change the services I receive:I'd like to pay the maintenance fee:Cancel")) {	
		// Buying a house
		case 1:
			// already have a house
			if(atoi(HOUSING$[0]) > 0) {
				mes .n$;
				mes strcharinfo(0) + ", my dear, I am sorry but you can only have one house at the time.";
				next;
				mes .n$;
				mes "Your place at number ^AA11AA"+HOUSING$[0]+"^000000.";
				mes (atoi(HOUSING$[1]) > gettimetick(2))? " The maintenance fee is current ^AA11AA("+ callfunc("Time2Str",atoi(HOUSING$[1]))+")^000000." : "The maintenance fee is ^FF0000overdue^000000.";
				next;
				goto RentHouse;
			// dont have a house yet
			} else {
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
				next;
				mes .n$;
				mes "That one will cost you "+F_InsertComma(.HousePrice)+"z one-off plus maintenance fee you'd pay weekly.";
				mes "Maintenance fee varies as per the table below:";
				next;
				ExplainServices();
				next;
				mes .n$;
				mes "So, what would that be?";
				next;
				.@idx = select(ServiceType(0)+":"+ServiceType(1)+":"+ServiceType(2)) -1;
				mes .n$;
				mes "Right... the total for today includes the buying of the house and the maintenance fee of the next 7 days.";
				next;
				mes .n$;
				mes "I must remind you that, if you fail to pay the maintenance fee at any time, you will lose access to your house.";
				next;
				mes .n$;
				mes "We will make sure to keep everything as you left at least for a period of time but you won't have access to any of your stuff in there until you pay the fee, ok?";
				next;
				mes .n$;
				mes "The total is:";
				mes "House: " + callfunc("F_InsertComma",.HousePrice) + "z";
				mes "Maintenance Fee: " + callfunc("F_InsertComma",.Rent[.@idx]) + "z";
				.@total = .HousePrice + .Rent[.@idx];
				mes "Total: " + callfunc("F_InsertComma",.@total);
				next;
				if(select("That is fine, I will take it.:No, that is too much.") == 2) {
					mes .n$;
					mes "I understand... Just don't wait too much. They are limited, you know...";
					close;
				}
				mes .n$;
				mes "Fantastic!";
				next;
				if(select("Pay now:Cancel") == 2)
					close;

				BuyHouse();
				mes .n$;
				mes "Perfect!";
				mes "Your new place is ^AA5500house number " + HOUSING$[0] + "^000000.";
				next;
				mes .n$;
				mes "Are you excited to meet the place? I bet you gonna love it and this neighbourhood is so lively!";
				next;
				mes .n$;
				mes "Remember! Your rent is due to renew in ^5599AA" + callfunc("Time2Str",atoi(HOUSING$[1])) + "^000000.";
				next;
				mes .n$;
				mes "I'd appreciate if you paid before the deadline. I won't tolerate any delays and will take the house back the second after the expiration time.";
				next;
				mes .n$;
				mes "You can always pay the fees in advance, any time, just talk to me and we can extend your contract.";
				next;
				mes .n$;
				mes "Well, that covers every thing, I belive.";
				mes "Have a good day!";
				close;
			}
		// Changing the Service
		case 2:
			mes .n$;
			mes "Great... let me have a look...";
			next;
			mes .n$;
			mes "At the moment, this is what you've got:";
			mes "Service: " + ServiceType(atoi(HOUSING$[2])) + (atoi(HOUSING$[1])<gettimetick(2))?" ^FF0000 EXPIRED^000000" : "";
			mes "Maintenancy Fee: " + callfunc("F_InsertComma",.rent[atoi(HOUSING$[2])]);
			next;
	ServicesMenu:
			switch(select("The benefits of each service:I know what I want:Cancel")) {
				case 1:
					ExplainServices();
					next;
					goto ServicesMenu;
				case 2:
					mes .n$;
					mes "Great, which kind of house you are looking for, then?";
					mes "Please remember: if you you have any time left from your actual Maintenancy Fee, that will be lost and a new agreement will start now, ok?";
					next;
					.@idx = select(ServiceType(0)+":"+ServiceType(1)+":"+ServiceType(2)) -1;
					if(.@idx == atoi(HOUSING$[2])) {
						mes .n$;
						mes "So, that is the same model you actually have!";
						mes "No changes will be made...";
						close;
					}
					mes .n$;
					mes "House Number: " + HOUSING$[0];
					mes "Service: ^00AA00" + ServiceType(.@idx) +"^000000";
					mes "Maintenancy Fee: " + callfunc("F_InsertComma",.rent[.@idx]);
					mes " ";
					mes "Is that right? Should we proceed?";
					next;
					if(select("Yes, please:No Thank you") == 2)
						goto ServicesMenu;
					// I know, it is redundant but it is necessary as the changes below cant happen if the guy doesnt have the zeny to pay for it
					if(Zeny < .rent[.@idx])
						goto NoZeny;

					HOUSING$[1] = gettimetick(2);
					HOUSING$[2] = .@idx;
					ExtendContract();
					mes .n$;
					mes "It is all done!";
					mes "Your address keeps the same but I hope you like the improvements we've made to your house!";
					close;
				case 3:
					close;
			}

		// Paying Maintenance Fee
		case 3:
			if(getarraysize(HOUSING$) == 0) {
				mes .n$;
				mes "I am afraid I could not find anything on your name in my records...";
				close;
			}
			mes .n$;
			mes "House Number: " + HOUSING$[0];
			mes "Service: " + ServiceType(atoi(HOUSING$[2])) + (atoi(HOUSING$[1])<gettimetick(2))?" ^FF0000 EXPIRED^000000" : "";
			mes "Maintenancy Fee: " + callfunc("F_InsertComma",.rent[atoi(HOUSING$[2])]);
			next;
			switch(select("Pay Maintenancy Fee:Cancel")) {
				case 1:
					mes .n$;
					mes "Absolutely, that will be ^AA11AA"+F_InsertComma(.Rent[atoi(HOUSING$[2])])+"^000000z.";
					next;
					ExtendContract();
					mes .n$;
					mes "All done! Thank you very much!";
					mes "Your new contract ends in ^AA11AA" + callfunc("Time2Str",atoi(HOUSING$[1])) + "^000000.";
					close;

				case 2:
					mes .n$;
					mes "Understandable... See you around!";
					close;
			}
		case 4:
			close;
	}


OnNoZeny:
	mes .n$;
	mes "Oh, " + strcharinfo(0) + ", what is going on here? You don't seem to have enough Zeny for this.";
	close;


OnInit:
	.n$ 		= "^0000FF[ Properties Manager ]^000000";
	.HousePrice	= 5000000;
	.Period 	= 604800; 	// 7 dias
	setarray	.Rent[0], 50000,150000,500000;
	end;


	// returns description of service
	// .@service$[0] = service description
	function ServiceType {
		.@type = getarg(0);
		switch(.@type) {
			case 0: return "Working-Class";
			case 1: return "Mid-Class";
			case 2: return "High Standard";
		}
	}


	// Paying Maintenance Fee / Extending the contract
	function ExtendContract {
		
		if(Zeny < .rent[atoi(HOUSING$[2])])
			goto OnNoZeny;

		Zeny -= .rent[atoi(HOUSING$[2])];
		if(atoi(HOUSING$[1]) < gettimetick(2))
			HOUSING$[1] = gettimetick(2) + .Period;
		else
			HOUSING$[1] = atoi(HOUSING$[1]) + .Period;	// Rent amount
		return;
	}

	// Buy New House
	function BuyHouse {
		.@type = getarg(0,0);
		if(Zeny < .HousePrice)
			goto OnNoZeny;

		Zeny -= .HousePrice;

		set HOUSING$[0], rand(1,23);				// House Id
		set HOUSING$[1], gettimetick(2) + .Period;	// Countdown until renewal
		set HOUSING$[2], .@type; 					// House type (0=basic, 1=working class, 2=mid-class house)
		return;
	}

	function ExplainServices {
		mes .n$;
		mes " ";
		mes ServiceType(0);
		mes "A place to call home...";
		mes " - A garden to plant,";
		mes " - A bed to sleep,";
		mes " ";
		mes callfunc("F_InsertComma",.rent[0]) + "z per week";
		next;
		mes .n$;
		mes ServiceType(1);
		mes "The comfort you deserve...";
		mes " - A garden to plant,";
		mes " - A bed to sleep,";
		mes " - A storage to keep your stuff";
		mes " ";
		mes callfunc("F_InsertComma",.rent[1]) + "z per week";
		next;
		mes .n$;
		mes ServiceType(2);
		mes "The place of your dreams...";
		mes " - A garden to plant,";
		mes " - A bed to sleep,";
		mes " - A storage to keep your stuff";
		mes " - A diversified wardrobe";
		mes " ";
		mes callfunc("F_InsertComma",.rent[2]) + "z per week";

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
	warp strnpcinfo(2),$@HDRespMx[atoi(HOUSING$[0])-1],$@HDRespMy[atoi(HOUSING$[0])-1];
	instance_destroy;
	@instance = 0;
	end;
}


// ********************************************************************
// Front Gate of the House (outside -> in)

rent_mb,106,42,0	script	PortaoDaCasa#1	45,2,2,{
	end;

OnTouch:
	if(atoi(HOUSING$[0]) == 0)
		message strcharinfo(0),"What am I doing? I don't even have a house! ";
	else if(HOUSING$[0] != strnpcinfo(2))
		message strcharinfo(0),"Omg! What am I doing? My house is number " + HOUSING$[0];
	else
		callfunc "F_HouseInstancing",atoi(strnpcinfo(2));

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


// // Shops Old system seeds seller
// rent_mb,230,215,3	shop	McDonald	765,30033:15000,30034:15000,30035:15000,30036:15000,30037:15000,30038:15000,30039:15000,30040:15000,30041:15000,30042:15000;