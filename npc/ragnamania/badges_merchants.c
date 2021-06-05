// Badges Exchange
// *********************************************************************
prontera,145,206,3	script	Erundek	109,{
	mes "[Erundek]";		
	mes "Welcome, mighty warrior.";
	mes "What can I do for you today ?";
	next;
	switch( select("Exchange Bravery Badges","Exchange Valor Badges","Exchange War Badges","Hmm, nothing I guess.") )
	{
		case 4:
			mes "[Erundek]";
			mes "As you wish.";
			mes "See you later.";
			close;
		case 1: // Bravery Badges
			mes "[Erundek]";
			mes "So you want to exchange ^0000FFBravery Badges 1^000000 from the Battle of Tierra Valley.";
			mes "Close this window to open shop.";
			close2;
			callshop "BraveryExchanger",0;
			end;
		case 2: // Valor Badges
			mes "[Erundek]";
			mes "So you want to exchange ^FF0000Valor Badges 2^000000 from the Battle of Flavius.";
			mes "Close this window to open shop.";
			close2;
			callshop "ValorExchanger",0;
			end;
		case 3: // Heroism Badges
			mes "[Erundek]";
			mes "So you want to exchange ^FFA500War Badges 3^000000 from the Battle of Kriger Von Midgard.";
			mes "Close this window to open shop.";
			close2;
			callshop "HeroismExchanger",0;
			end;
	}
}

-	itemshop	BraveryExchanger	-1,7828,7829:1,7773:2,13036:100,13411:100,1425:100,1632:100,1634:100,1543:100,1924:100,1978:100,1574:100,1824:100,1183:100,1380:100,13305:100,1279:100,1739:100,13108:100,13172:100,2538:50,2539:50,2540:50,2435:50,2436:50,2437:50,2376:80,2377:80,2378:80,2379:80,2380:80,2381:80,2382:80,2720:500,2721:500,2722:500,2723:500,2724:500,2725:500,2733:500
-	itemshop	ValorExchanger	-1,7829,7828:2,7773:3,13037:100,13410:100,1633:100,1635:100,1542:100,1923:100,1977:100,1575:100,1823:100,1184:100,1482:100,1379:100,13306:100,1280:100,1738:100,13171:100,13173:100,13174:100,2538:50,2539:50,2540:50,2435:50,2436:50,2437:50,2376:80,2377:80,2378:80,2379:80,2380:80,2381:80,2382:80,2720:500,2721:500,2722:500,2723:500,2724:500,2725:500,2733:500
-	itemshop	HeroismExchanger	-1,7773,7828:1,7829:1,1187:3000,1281:3000,1282:3000,1310:3000,1382:3000,1426:3000,1486:3000,1546:3000,1576:3000,1577:3000,1640:3000,1641:3000,1743:3000,1826:3000,1827:3000,1927:3000,1981:3000,2002:3000,13042:3000,13110:3000,13176:3000,13177:3000,13178:3000,13179:3000,13307:3000,13416:3000,13417:3000,13418:3000,2394:1500,2395:500,2396:100,2444:750,2445:150,2446:50,2549:1000,2772:1800,2773:500,2774:100


// -------------------------------
// Battlegrounds Consumibles
// -------------------------------
prt_in,44,113,3	script	BG Items Trader	56,{

Main:
	mes "^009999[BG Items Trader]^000000";
	mes "Welcome, mighty warrior.";
	mes "Are you looking for supplies?";
	mes "I have a vast range of ^FF0000" + .Target$ + "^000000 items in exchange for your ^AA00AA"+getitemname(7828)+"^000000.";
	next;

	set .@Menu$, "";
	for( .@i=0; .@i < getarraysize(.Items); .@i++ )
		set .@Menu$, .@Menu$ + .Amount[.@i] + " " + getitemname(.Items[.@i]) + " (" + .Value[.@i] + " badges):";
	set .@j, select(.@Menu$) - 1;

	mes "^009999[BG Items Trader]^000000";
	mes "Item: ^0000FF " + .Amount[.@j] + "x " + getitemname(.Items[.@j]) + "^000000";
	mes "Cost: ^0000FF " + .Value[.@j] + " " + getitemname(7828) + "^000000";
	mes " ";
	mes "--------------------------------";
	mes "^FF0000" + .Target$ + " Item^000000";
	mes "--------------------------------";

	while(!.@repeat) {
		if( countitem(7828) >= .Value[.@j] ) {
			if(select("^FF0000Pay ["+ .Value[.@j] + " / " + countitem(7828) + "] " + getitemname(7828)+"^000000:Cancel") == 2) {
				next;
				goto Main;
			} else {
				if( checkweight(.Items[.j],.Amount[.j]) == 0 ) {
					next;
					mes "^009999[BG Items Trader]^000000";
					mes "I am afraid you can't carry more items. Please free up some space in your inventory.";
					close;
				} else {
					delitem 7828,.Value[.@j];
					getitem2 .Items[.@j],.Amount[.@j],1,0,0,254,0,.cID&0xffff,(.cID>>16)&0xffff;
					logmes "Trocou " + .Value[.@j] + "x " + getitemname(7828) + " por " + .Amount[.@j] + " " + getitemname(.Item[.@j]);
					if(select("Continue:Leave") == 2) {
						next;
						goto Main;
					}
				}
			}
		} else {
			next;
			mes "^009999[BG Items Trader]^000000";
			mes "You do not have enough badges. Sorry...";
			mes "Participate the ^FF0000"+.Target$+"^000000 to earn more.";
			close;
		}
	}
	end;

OnInit:
	setarray .Items[0],   547,  504,  505,  678, 7135, 7136, 7137, 7138, 7139,  715,  716,  717,12016, 1025, 7321,  662,12072,12077,12082,12087,12092,12097,12215,12216;
	setarray .Amount[0],  150,  100,  100,   10,   40,   40,   30,   30,   25,   50,  100,  200,   10,   40,   25,   10,    3,    3,    3,    3,    3,    3,	10,	10;
	//setarray .Value[0],   6,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    1,    1,    1,    1,    1,    1;
	setarray .Value[0],     1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,	1,	1;
	set .cID, getbattleflag("bg_reserved_char_id");
	set .Target$, "Battleground";
	end;
}


// -------------------------------
// PvP Consumibles
// -------------------------------

prt_in,46,97,0	script	PvP Items Trader	730,{

Main:
	mes "^009999[PvP Items Trader]^000000";
	mes "Welcome, mighty warrior.";
	mes "Are you looking for supplies?";
	mes "I have a vast range of ^FF0000" + .Target$ + "^000000 items in exchange for your ^AA00AA"+getitemname(7829)+"^000000.";
	next;

	set .@Menu$, "";
	for( .@i=0; .@i < getarraysize(.Items); .@i++ )
		set .@Menu$, .@Menu$ + .Amount[.@i] + " " + getitemname(.Items[.@i]) + " (" + .Value[.@i] + " badges):";
	set .@j, select(.@Menu$) - 1;

	mes "^009999[PvP Items Trader]^000000";
	mes "Item: ^0000FF " + .Amount[.@j] + "x " + getitemname(.Items[.@j]) + "^000000";
	mes "Cost: ^0000FF " + .Value[.@j] + " " + getitemname(7829) + "^000000";
	mes " ";
	mes "--------------------------------";
	mes "^FF0000" + .Target$ + " Item^000000";
	mes "--------------------------------";

	while(!.@repeat) {
		if( countitem(7829) >= .Value[.@j] ) {
			if(select("^FF0000Pay ["+ .Value[.@j] + " / " + countitem(7829) + "] " + getitemname(7829)+"^000000:Cancel") == 2) {
				next;
				goto Main;
			} else {
				if( checkweight(.Items[.j],.Amount[.j]) == 0 ) {
					next;
					mes "^009999[PvP Items Trader]^000000";
					mes "I am afraid you can't carry more items. Please free up some space in your inventory.";
					close;
				} else {
					delitem 7829,.Value[.@j];
					getitem2 .Items[.@j],.Amount[.@j],1,0,0,254,0,.cID&0xffff,(.cID>>16)&0xffff;
					logmes "Trocou " + .Value[.@j] + "x " + getitemname(7829) + " por " + .Amount[.@j] + " " + getitemname(.Item[.@j]);
					if(select("Continue:Leave") == 2) {
						next;
						goto Main;
					}
				}
			}
		} else {
			next;
			mes "^009999[PvP Items Trader]^000000";
			mes "You do not have enough badges. Sorry...";
			mes "Participate the ^FF0000"+.Target$+"^000000 to earn more.";
			close;
		}
	}
	end;

OnInit:
	setarray .Items[0],   547,  504,  505,  678, 7135, 7136, 7137, 7138, 7139,  715,  716,  717,  662,12072,12077,12082,12087,12092,12097;
	setarray .Amount[0],   30,   50,   10,    3,   10,   10,   15,   15,    5,   20,   20,   20,    5,    5,    5,    5,    5,    5,    5;
	setarray .Value[0],     1,    1,    2,    1,    2,    2,    2,    2,    2,    1,    1,    1,    1,    3,    3,    3,    3,    3,    3;
	set .cID, getbattleflag("pvp_reserved_char_id");
	set .Target$, "PvP";
	end;
}


// -------------------------------
// GvG/WoE Consumibles
// -------------------------------

prt_in,38,115,4	script	WoE Items Trader	65,{

Main:
	mes "^009999[WoE Items Trader]^000000";
	mes "Welcome, mighty warrior.";
	mes "Are you looking for supplies?";
	mes "I have a vast range of ^FF0000" + .Target$ + "^000000 items in exchange for your ^AA00AA"+getitemname(7773)+"^000000.";
	next;

	set .@Menu$, "";
	for( .@i=0; .@i < getarraysize(.Items); .@i++ )
		set .@Menu$, .@Menu$ + .Amount[.@i] + " " + getitemname(.Items[.@i]) + " (" + .Value[.@i] + " badges):";
	set .@j, select(.@Menu$) - 1;

	mes "^009999[WoE Items Trader]^000000";
	mes "Item: ^0000FF " + .Amount[.@j] + "x " + getitemname(.Items[.@j]) + "^000000";
	mes "Cost: ^0000FF " + .Value[.@j] + " " + getitemname(7773) + "^000000";
	mes " ";
	mes "--------------------------------";
	mes "^FF0000" + .Target$ + " Item^000000";
	mes "--------------------------------";

	while(!.@repeat) {
		if( countitem(7773) >= .Value[.@j] ) {
			if(select("^FF0000Pay ["+ .Value[.@j] + " / " + countitem(7773) + "] " + getitemname(7773)+"^000000:Cancel") == 2) {
				next;
				goto Main;
			} else {
				if( checkweight(.Items[.j],.Amount[.j]) == 0 ) {
					next;
					mes "^009999[WoE Items Trader]^000000";
					mes "I am afraid you can't carry more items. Please free up some space in your inventory.";
					close;
				} else {
					delitem 7773,.Value[.@j];
					getitem2 .Items[.@j],.Amount[.@j],1,0,0,254,0,.cID&0xffff,(.cID>>16)&0xffff;
					logmes "Trocou " + .Value[.@j] + "x " + getitemname(7773) + " por " + .Amount[.@j] + " " + getitemname(.Item[.@j]);
					if(select("Continue:Leave") == 2) {
						next;
						goto Main;
					}
				}
			}
		} else {
			next;
			mes "^009999[WoE Items Trader]^000000";
			mes "You do not have enough badges. Sorry...";
			mes "Participate the ^FF0000"+.Target$+"^000000 to earn more.";
			close;
		}
	}
	end;

OnInit:
	setarray .Items[0],   547,  504,  505,  678, 7135, 7136, 7137, 7138, 7139,  715,  716,  717,12016, 1025, 7321,  662,12072,12077,12082,12087,12092,12097,  522,  526,12029,12033,12031;
	setarray .Amount[0],  150,  100,  100,   10,   40,   40,   30,   30,   25,   50,  100,  200,   10,   40,   25,   10,    3,    3,    3,    3,    3,    3,   50,   50,    5,    5,    5;
	setarray .Value[0],     6,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    1,    1,    1,    1,    1,    1,    2,    3,    1,    6,    1;
	set .cID, getbattleflag("woe_reserved_char_id");
	set .Target$, "War of Emperium or GvG";
	end;
}



