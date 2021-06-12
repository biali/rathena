-	script	City Register::factions	-1,{
	end;

OnInit:
	if(atoi(strnpcinfo(2)) > 0) { 
		setmapflag strnpcinfo(4), mf_loadevent;
		setfactionmap atoi(strnpcinfo(2));
	}
	end;

OnPCLoadMapEvent:
	if(getcharid(6) == 0)
		if(strcharinfo(3) == strnpcinfo(4))
			announce "Welcome to the sanctuary of " + factioninfo(atoi(strnpcinfo(2)),0),bc_blue|bc_self;
	end;
	
}

geffen,0,0,4	duplicate(factions)	Geffen Register#1	4_F_KAFRA6
payon,0,0,4	duplicate(factions)	Payon Register#2	4_F_KAFRA6
morocc,0,0,4	duplicate(factions)	Morocc Register#3	4_F_KAFRA6
prontera,0,0,4	duplicate(factions)	Prontera Register#4	4_F_KAFRA6



// Flags Handler
prontera,183,213,3	script	Registrar#Prontera	25501,{
	if(getcharid(6)) { // player is already in a faction
		mes .n$;
		mes "I can see you are already enlisted... Good luck!";
		close;
	} else { // player is not in a faction yet
		mes .n$;
		mes "Hello, " + strcharinfo(0);
		mes "I am here representing the greatest authority of our city and, soon, the greatest authority in the entire kingdom.";
		next;
		mes .n$;
		mes "I am sure you are aware of the recent events in Rune-Middgard... We are convinced we can no longer trust anyone from the vicinity.";
		next;
		mes .n$;
		mes "So here we are, do you want to join the army and help us hunt the traitors down and give some closure to all those who lost their beloved ones?";
		next;
		mes .n$;
		mes "By enlisting:";
		mes "- Gain Reputation Points";
		mes "- Gain more XP from mobs";
		mes "- Better drop chances from mobs";
		next;
		mes .n$;
		mes "^AD0000You become a target to anyone representing a different city in most of the fields and dungeons.^000000";
		next;
		mes .n$;
		mes "^AD0000Dying to another player while holding a representation means losing all the items and equips in your inventory.^000000";
		next;
		mes .n$;
		mes "^AD0000The same way that killing anyone representing a different city will give you the oportunity to look all their belongings.^000000";
		next;
		mes .n$;
		mes "^AD0000To cancel a representation simply logout from the game and log back in. But be aware! if you force logout, your character will still be online for about one minute and completely vulnerable.^000000";
		next;
		mes .n$;
		mes "To learn more about City VS City and Full-Loot mechanics please visit our website/wiki.";
		next;
		mes .n$;
		mes "Do you want to go ahead and start your representation?";
		next;
		if(select("Yes please:No thank you") == 2) {
			mes .n$;
			mes "I understand. This is not for the faint of the heart.";
			close;
		}
		if(BaseLevel < 40) {
			mes .n$;
			mes "I am sorry but this is only to heroes at level 40 and more.";
			close;
		}

		for(.@i=1;.@i<=4;.@i++) {
			if(factioninfo(.@i,2) == strcharinfo(3)) {
				setfaction(.@i);
				break;
			}
		}
		mes "All Done. Good luck, and take care!";
		close;
	}


OnInit:
	questinfo QTYPE_CLICKME;
	.n$ = "^FF0000"+strnpcinfo(2)+" Registrar^000000";
	end;
}




// prontera,160,180,3	script	Faction Sample	100,{
//     mes "[Faction Sample]", "Hello!", "I'm the sample NPC for faction system script commands";
//     next;
//     mes "[Faction Sample]", "Let's start...", "Input faction ID 1~4 and i'll make you a faction member";
//     next;
//     input(@faction_id,1,2);
//     mes "[Faction Sample]"," Good choice.";
//     next;
// L_Menu:
//     mes "[Faction Sample]";
// 	switch(select("Make me a faction member of '"+@faction_id+"':FvF On:FvF Off:Spawn Faction Monster"))
// 	{
// 		case 1: callsub(S_FACTION_SET); break;
// 		case 2: callsub(S_FACTION_FVF_SET,1); break;
// 		case 3: callsub(S_FACTION_FVF_SET,0); break;
// 		case 4: callsub(S_FACTION_SPAWN); break;
// 	}
// close;

// S_FACTION_SPAWN:
// 	factionmonster(@faction_id,"this",159,180,strcharinfo(0),1002,1);
// 	close;

// S_FACTION_FVF_SET:
// 	.@map$ = strnpcinfo(4);
// 	.@s = getmapflag(.@map$,mf_hostile);
// 	switch(getarg(0))
// 	{
// 		case 1: if( !.@s ) fvfon(.@map$); break;
// 		default: if( .@s ) fvfoff(.@map$); break;
// 	}
// 	close;

// S_FACTION_SET:
// 	setfaction(@faction_id);
// 	mes "Now you're in Faction '"+@faction_id+"'";
// 	next;
// 	close;
// }

// /**
//  * Example shop
//  * Faction ID = 0, Discount -50% for Faction ID 1, Overcharge 50% for Faction ID 4
//  **/
// prontera,152,180,3,0,[1:-50,4:50]	shop	Example_Shop_0	100,7227:100;
// /**
//  * 'floating' shop
//  **/
// -,[1:15,4:-5,2:30]	shop	Example_Floating	100,7227:100;

// /**
//  * Example script
//  * Faction ID = 2
//  **/
// prontera,154,180,3,2	script	Example_Script_2	100,{
// 	mes "Hello!";
// 	close;
// }

// /**
//  * Example duplicate
//  * Duplicate of 'Example_Script_2' but with Faction ID = 3
//  **/
// prontera,156,180,5,3	duplicate(Example_Script_2)	Example_Script_3	100