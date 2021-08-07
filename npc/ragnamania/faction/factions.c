// Flags Handler
-	script	Registrar	-1,{
	.@n$ = "^FF0000"+strnpcinfo(2)+" Registrar^000000";
	.@heartid = 30150 + getfactionmap(strtolower(strnpcinfo(2)));
	mes .@n$;
	mes "Hello, " + strcharinfo(0);
	mes "I am here representing the greatest authority of our city and, soon, the greatest authority in the entire kingdom.";
	next;
main_menu:
	mes .@n$;
	mes "How can I help you today?";
	next;
	switch(select("What is going on?:Enlist to "+strnpcinfo(2)+" forces:Trade "+ strnpcinfo(2) +" Reputation Points:Transport "+ strnpcinfo(2) +" Heart Stones")){
		case 1:
			mes .@n$;
			mes "I am sure you are aware of the recent events in Rune-Middgard... We are convinced we can no longer trust anyone from the vicinity.";
			next;
			mes .@n$;
			mes "So here we are, do you want to join the army and help us hunt the traitors down and give some closure to all those who lost their beloved ones?";
			next;
			mes .@n$;
			mes "By enlisting:";
			mes "- Gain Reputation Points";
			mes "- Gain more XP from mobs";
			mes "- Better drop chances from mobs";
			next;
			mes .@n$;
			mes "^AD0000You become a target to anyone representing a different city in most of the fields and dungeons.^000000";
			next;
			mes .@n$;
			mes "^AD0000Dying to another player while holding a representation means losing all the items and equips in your inventory.^000000";
			next;
			mes .@n$;
			mes "^AD0000The same way that killing anyone representing a different city will give you the oportunity to look all their belongings.^000000";
			next;
			mes .@n$;
			mes "^AD0000To cancel a representation simply logout from the game and log back in. But be aware! if you force logout, your character will still be online for about one minute and completely vulnerable.^000000";
			next;
			mes .@n$;
			mes "To learn more about City VS City and Full-Loot mechanics please visit our website/wiki.";
			next;
			mes .@n$;
			mes "Do you want to go ahead and start your representation?";
			next;
			goto main_menu;
			break;
		case 2:
			if(getcharid(6)) { // player is already in a faction
				mes .@n$;
				mes "I can see you are already enlisted... Good luck!";
				close;
			}
			mes .@n$;
			mes "Do you want to go ahead and start your representation?";
			next;
			mes .@n$;
			if(select("Yes please:No thank you") == 2) {
				mes "I understand. This is not for the faint of the heart.";
				close;
			}
			if(BaseLevel < 40) {
				mes "I am sorry but this is only to heroes at level 40 and more.";
				close;
			}

			for(.@i=1;.@i<=4;.@i++) {
				if(factioninfo(.@i,2) == strcharinfo(3)) {
					.@result = setfaction(.@i);
					break;
				}
			}

			if(.@result == 1) 
				mes "All Done. Good luck, and take care!";
			else
				mes "Hum... We can't go ahead with this, I am sorry. Maybe you are in a party? Remember you cannot enlist to a City and be in a party with people not enlisted to the same city.";
			close;

			break;
		case 3:
			mes .@n$;
			if((.@points = getreputationpoints(getfactionmap(strtolower(strnpcinfo(2))))) <= 0) {
				mes "I am really sorry to disapoint you but you don't seem to have enough Reputation Points.";
				mes "Please do some hunting representing our beloved Town and come back later.";
				close;
			}
			mes "Each " + getitemname(.@heartid) + " costs ^0000ff" + .heart_price + " " + strnpcinfo(2) + " RP^000000.";
			mes "You have ^0000FF"+ callfunc("F_InsertComma",.@points) +" "+ strnpcinfo(2) + " RP^000000.";

			if(.@points < .heart_price) {
				mes "Which means you don't have enough ^0000FFRP^000000 to trade for a " + getitemname(.@heartid) + ".";
				next;
				mes .@n$;
				mes "Please do some hunting representing our beloved Town and come back later.";
				close;
			} else {
				.@qt = .@points / .heart_price;
				mes "Which means you could get yourself ^0000ff" + .@qt + " " + getitemname(.@heartid) + "^000000.";
				mes "Do you want to go ahead with the deal?";
				next;

				if(select("yes:no") == 2) {
					mes .@n$;
					mes "Fair enough.";
					mes "See you around, then.";
					close;
				}

				.@qt = .@points / .heart_price;
				if(.@qt) {
					.@points = takereputationpoints(getfactionmap(strtolower(strnpcinfo(2))),.@qt * .heart_price);
					getitem .@heartid, .@qt;
				} else {
					mes .@n$;
					mes "Something's fishy here... We have to abort.";
					mes "This incident has been reported to the staff.";
					logmes "Faction Heart Trade : Cheater Detected";
					close;
				}

				mes .@n$;
				mes "It is all done.";
				mes "Your new balance is:";
				mes strnpcinfo(2) + " Reputation Points: ^000000" + callfunc("F_InsertComma",.@points);
				mes " ";
				mes "'Til next time!";
				close;
			}
			break;
		case 4:
			mes .@n$;
			mes "comming soon";
			close;
			break;
	}

OnInit:
	.heart_price = 500; // cost in reputation points 
	//Add here the maps to be sanctuary for a certain faction
	if(strnpcinfo(2) == "Geffen") 			.@f = 1;
	else if(strnpcinfo(2) == "Payon") 		.@f = 2;
	else if(strnpcinfo(2) == "Morocc") 		.@f = 3;
	else if(strnpcinfo(2) == "Prontera")	.@f = 4;
	
	if(.@f > 0) { 
		setmapflag strnpcinfo(4), mf_loadevent;
		setfactionmap .@f;
	}
	end;

OnPCLoadMapEvent:
	if(getcharid(6) == 0)
		if(strcharinfo(3) == strnpcinfo(4))
			announce "Welcome to the sanctuary of " + factioninfo(getfactionmap(strtolower(strcharinfo(3))),0),bc_blue|bc_self;

	// if(getcharid(6) > 0 && getcharid(6) != getfactionmap(strcharinfo(3))) {
	// 	setfaction(0);
	// 	dispbottom "City representation has been removed because this map is a sanctuary of a different City.";
	// }
	end;
}

prontera,183,213,3	duplicate(Registrar)	Registrar#Prontera	25501
morocc,141,102,5	duplicate(Registrar)	Registrar#Morocc	25501
payon,191,132,4	duplicate(Registrar)	Registrar#Payon	25501
geffen,127,115,5	duplicate(Registrar)	Registrar#Geffen	25501




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