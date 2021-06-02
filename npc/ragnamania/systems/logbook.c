-	script	DiarioDeBordo	-1,{
	end;

OnPcLoginEvent:
	if(strcharinfo(3) == "new_1-1") end;
	if(countitem(24501) < 1 )
		getitem 24501,1;
		end;
}

function	script	isVs	{
	.@m$ = getarg(0);
	for(.@i=0;.@i<getarraysize($@MF_VS);.@i++)
		if(getmapflag(.@m$,$@MF_VS[.@i]))
			return 1;
	return 0;
}

function	script	RM_DiarioDeBordo	{
	function CalcRep; function Red; function Orange; function Green; function Acqua; function Blue;

	if(inarray($@EventPlayers[0],getcharid(3)) >= 0) {
		mes "^0000FF[ Logbook ]^000000";
		mes "Sorry, the use of the Logbook is temporarily disabled during the event.";
		close;
	}

	// if(callfunc("isVs",strcharinfo(3))) {
	// 	mes "^0000FF[ Logbook ]^000000";
	// 	mes "Sorry, the use of the Logbook is not allowed in this map.";
	// 	close;
	// }

	set .SG_RESET_COST, getvariableofnpc(.SG_RESET_COST,"DiarioDeBordo");
	getmapxy(.@mapName$,.@mapX,.@mapY,BL_PC,strcharinfo(0));

L_Menu:
	mes "^0000FF[ Logbook ]^000000";
	if( vip_status(1) ) mes "Account: ^00CCAA[ Premium ]^000000";
	else mes "Account: ^00AAFF[ Regular ]^000000";
	mes (#CASHPOINTS)?"Mania$: ^0000FF" +#CASHPOINTS+ "^000000.":"Mania$: ^FF000000.00^000000.";
	mes " ";
	if(getcharid(6)) {
		mes "^0000FFCitie Representation^000000";
		mes factioninfo(getcharid(6),0);
		mes " ";
	}

	mes "Personal Vote Points: ^0000FF[" + #VP_VOTEPOINTS + "/" + getvariableofnpc(.MinVotes4Reward,"v4p") + "]^000000";
	if(gettime(DT_DAYOFMONTH) < getvariableofnpc(.ThirdDday,"v4p"))	
		mes "Global VP: ^0000FF[" + $vp_totalVotePoints + "/" + getvariableofnpc(.VotePointsTarget,"v4p") + "]^000000";
	else if(gettime(DT_DAYOFMONTH) > getvariableofnpc(.ThirdDday,"v4p") && $vp_totalVotePoints > getvariableofnpc(.ThirdTarget,"v4p"))
		mes "Global Donation: ^0000FF[" + callfunc("F_InsertComma",$vp_donations) + "/" + callfunc("F_InsertComma",getvariableofnpc(.ExtensionCost,"v4p")) + "]^000000";
	.@days = (gettime(DT_DAYOFMONTH)>=getvariableofnpc(.ThirdDday,"v4p")?getvariableofnpc(.dayOfMonth,"v4p")-gettime(DT_DAYOFMONTH):(gettime(DT_DAYOFMONTH)>=getvariableofnpc(.SecondDday,"v4p")?getvariableofnpc(.ThirdDday,"v4p")-gettime(DT_DAYOFMONTH):getvariableofnpc(.SecondDday,"v4p")-gettime(DT_DAYOFMONTH)));
	mes "Voting Event ends in ^FF0000" + .@days + "^000000 days.";
	next;

L_Loop:
	switch(select("^f5b041Premium^000000 Services:Teleport Services:Battlelog:Cities Reputation:Adventurer's Quest:Cities Flags:^dd0000Close^000000")) {
		case 1: // PREMMY SERVICES
			if( vip_status(1) || getgmlevel() >= 10) {
				if(inarray($@EventPlayers,getcharid(3)) >= 0 || .@vs = callfunc("F_isVSmap") == 1 || compare(strcharinfo(3),"new_") == 1) { 
					mes "^0000FF[ Premium Services ]^000000";
					mes "Sorry, this service is not available now.";
					close;
				}
L_PremmyMenu:
				switch(select("Activate/Extend Premium:Repairs:Purify Ore:Utility Stores:Close")) {
					case 1:
						mes "^0000FF[ Premium Services ]^000000";
						mes "Do you want to activate or extend ^f5b041Premium^000000 on your account?";
						next;
						if(select("Not now:Yes, please") == 2) {
							callfunc "F_Premmy";
							end;
						} else {
							mes "^0000FF[ Premium Services ]^000000";
							mes "Not a problem. Have a good day.";
							next;
							goto L_PremmyMenu;
						}
						break;
					case 2: // Repair all
						if(getbrokenid(1) == 0) {
							mes "^0000FF[ Premium Services ]^000000";
							mes "All your equipments seem fine. No repairs are needed.";
							next;
							goto L_PremmyMenu;
						}
						mes "^0000FF[ Premium Services ]^000000";
						mes "We have some equipments in the inventory that need repairing. Repairs cost ^ff0000500z^000000 per equipment. Do you want to continue?";
						next;
						if(select("Yes, please:No, cancel it") == 2) {
							close2;
							goto L_PremmyMenu;
						} else {
							while (.@id = getbrokenid(1)) {
								if(Zeny < 500) {
									dispbottom "Logbook: Not enough Zeny to continue. Aborting";
									break;
								}
								Zeny -= 500;
								.@cost += 500;
								repair(1);
								set .@i, .@i +1;
								dispbottom "Logbook: Equipment repaired ["+getitemname(.@id)+"]";
							}
							if (.@i) dispbottom "Logbook: " + .@i + " equipments repaired. Total cost: " + callfunc("F_InsertComma",.@cost)+"z.";
						}
						next;
						goto L_PremmyMenu;
						break;
					case 3: // Purify ores
						mes "^0000FF[ Premium Services ]^000000";
						mes "Connecting to the Legendary Smith system...";
						next;
						callfunc "massPurify","Legenday Smith";
						break;
					case 4: // Utility Stores
						mes "^0000FF[ Premium Services ]^000000";
						mes "Select the store.";
						next;
						switch(select("^FF0000Sell Items^000000:Consumables:Miscellaneous:Arrows:Kunais:Ammo:Pet Foods:Pet Accessories")) {
							close2;
							case 1: callshop "Tools", 2; end;
							case 2: callshop "Consumables", 1; end;
							case 3: callshop "Miscellaneous", 1; end;
							case 4: callshop "Arrows", 1; end;
							case 5: callshop "Ninja", 1; end;
							case 6: callshop "Gunslinger", 1; end;
							case 7: callshop "Pet Foods", 1; end;
							case 8: callshop "Pet Accessories", 1; end;
						}
						end;
						break;
				}
			} else {
				mes "I am afraid these options are available for ^f5b041Premium^000000 accounts only.";
				mes "Find more about our ^f5b041Premium^000000 system in our website.";
				next;
				goto L_Menu;
			}
		case 2: // TELEPORTE
			if(inarray($@EventPlayers,getcharid(3)) >= 0 || .@vs = callfunc("F_isVSmap") == 1 || compare(strcharinfo(3),"new_") == 1) { 
				mes "Sorry, this service is not available now.";
				close;
			}
			switch(select("Cities:Specials")){
				case 1:
					menu "Prontera",T1, 
					"Alberta",T2, 
					"Aldebaran",T3, 
					"Amatsu",T4, 
					"Comodo",T7, 
					"Geffen",T13, 
					"Izlude",T16, 
					"Jawaii",T17, 
					"Morroc",T26, 
					"Payon",T30,
					"Yuno",T36;

					T1: warp "prontera",155,183; end;
					T2: warp "alberta",28,234; end;
					T3: warp "aldebaran",140,131; end;
					T4: warp "amatsu",198,84; end;
					T7: warp "comodo",209,143; end;
					T13: warp "geffen",119,59; end;
					T16: warp "izlude",128,114; end;
					T17: warp "jawaii",251,132; end;
					T26: warp "morocc",156,93; end;
					T30: warp "payon",179,100; end;
					T36: warp "yuno",157,51; end;
					break;
				case 2:
					menu "^f5b041Premium^000000 Room";//,X1,"Timeless Dungeons",X2;
					X1: warp "sala_premmy",40,38; end;
					//X2: warp "yuno",282,288; end;
					break;
			}
		case 3: // Battlelog
			mes "^0000DDBattlelog^000000";
			mes "Infamy: ^0000FF" + callfunc("F_InsertComma",readparam(136)) + " (+"+callfunc("F_InsertComma",readparam(136)/10000)+"% bonus)^000000";
			mes " ";
			mes "Total PK Kills: ^0000FF" + callfunc("F_InsertComma",readparam(137)) + "^000000";
			mes "Total PK Deaths: ^0000FF" + callfunc("F_InsertComma",readparam(138)) + "^000000";
			mes "Total PK Score: ^0000FF" + callfunc("F_InsertComma",readparam(139)) + "^000000";
			mes " ";
			mes "Total PvP Kills: ^0000FF" + callfunc("F_InsertComma",readparam(140)) + "^000000";
			mes "Total PvP Deaths: ^0000FF" + callfunc("F_InsertComma",readparam(141)) + "^000000";
			mes "Total PvP Score: ^0000FF" + callfunc("F_InsertComma",readparam(142)) + "^000000";
			mes " ";
			mes "Total BG Wins: ^0000FF" + callfunc("F_InsertComma",readparam(143)) + "^000000";
			mes "Total BG Losses: ^0000FF" + callfunc("F_InsertComma",readparam(144)) + "^000000";
			mes "Total BG Ties: ^0000FF" + callfunc("F_InsertComma",readparam(145)) + "^000000";
			mes " ";
			mes "Total WoE Score: ^0000FF" + callfunc("F_InsertComma",readparam(146)) + "^000000";
			next;
			goto L_Loop;
			break;
		case 4: // Cities Reputation
			mes "^0000DDCities' Reputation^000000";
			for(.@i=1;.@i<=getvariableofnpc(.totalfac,"reputation");.@i++) {
				.@rep$ = CalcRep(.@i);
				mes factioninfo(.@i,0) + " : " + .@rep$;
			}
			next;
			goto L_Loop;
		case 5: // Adventurer's Quest
				mes "^0000DDAdventurer's Challenge^000000";
				mes "Daily: " + F_DailyBar();
				mes "Weekly: " + F_WeeklyBar();
				mes "Monthly: " + F_MonthlyBar();
				next;
				goto L_Loop;
		case 6: // Empire Flags Options
			if(getcharid(6)) { // player is already in a faction
				mes "^0000FF[ Logbook ]^000000";
				mes "Would you like to stop representing " + factioninfo(getcharid(6),0) + "?";
				next;
				mes "^0000FF[ Logbook ]^000000";
				if(select("Yes:No") == 2) {
					mes "No problem";
					close;
				} else {
					factionleave();
					mes "Changes made.";
					close;
				}
			} else { // player is not in a faction yet
				mes "^0000FF[ Cities Flags ]^000000";
				for(.@i=1;.@i<=4;.@i++) {
					if(factioninfo(.@i,2) == strcharinfo(3)) {
						mes "Should we start representing ^0000FF"+strcharinfo(3)+"?";
						if(select("Yes:No") == 2)
							close;
						else {
							setfaction(.@i);
							mes "All Done. Good luck and please read the book about the Empire Flags";
							close;
						}
					}
				}
				mes "I am afraid you'll need to head to the town of your choice to start a representation.";
				close;
			}
		case 7:	
		default:
			close;
			break;
	}

	function CalcRep {
		.@faction = getarg(0,0);
		if(.@faction == 0)
			return -1;
		
		.@rep = getreputation(.@faction);
		if(.@rep >= getvariableofnpc(.honored,"reputation")) return Blue("[ Honored ]");
		else if(.@rep >= getvariableofnpc(.friendly,"reputation")) return Acqua("[ Friendly ]");
		else if(.@rep > getvariableofnpc(.unfriendly,"reputation") && .@rep < getvariableofnpc(.friendly,"reputation")) return Green("[ Normal ]");
		else if(.@rep <= getvariableofnpc(.hated,"reputation")) return Red("[ Hated ]");
		else if(.@rep <= getvariableofnpc(.unfriendly,"reputation")) return Orange("[ Unfriendly ]");
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

// Sellers are now in premmy_quickmall.c
// -	shop	Utilities	-1,601:-1,602:-1,501:-1,502:-1,503:-1,504:-1,522:-1,523:-1,525:-1,610:-1,645:-1,656:-1,657:-1,1065:-1,611:-1
// -	shop	Arrows		-1,1750:1,1751:3,1752:3,1753:4,1770:2,1754:5,1755:5,1756:5,1757:5,1758:10,1759:10,1760:10,1761:10,1762:10,1763:10,1764:20,1765:25,1766:40,1767:5,1768:10,1772:5
// -	shop	Ammo	-1,13200:1,13201:15,13202:30,13203:80,13204:80,13205:80,13206:80,13207:80
// -	shop	Kunais		-1,13256:10,13294:100,13259:10,13258:10,13257:10,13255:10
// -	shop	Gemstones	-1,717:-1,716:-1,715:1200
// -	shop	Stones		-1,7521:-1,7522:-1,7523:-1,7524:-1
// -	shop	Alchemy		-1,657:-1,713:-1,937:-1,939:-1,952:-1,972:-1,7033:-1,905:-1,1092:-1,1059:-1,1061:2000,929:2000,1044:2000