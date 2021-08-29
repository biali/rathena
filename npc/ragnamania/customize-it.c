// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
// eAmod Project - Scripts
// --------------------------------------------------------------------------
// Script Name : Headgear to Costume converter
// --------------------------------------------------------------------------
// Description :
// Allows a user to convert the equipped headgear (on Top, Mid or Low) into a
// costume item. It will remove any card and refine of the Item.
// --------------------------------------------------------------------------

-	script	CostumeIT	-1,{
	mes "^0000ff[ Luna ]^000000";
	mes "Hi and welcome to my shop!";
	mes "I can help you in changing any piece of headgear into a costume.";
	next;
	mes "^0000ff[ Luna ]^000000";
	mes "I charge "+callfunc("F_InsertComma",.cost[0])+" Manias or " + .cost[1]+ " " +getitemname(VOTE_CERTIFICATE)+"s for that.";
	next;
	mes "^0000ff[ Luna ]^000000";
	mes "Please chose which piece of equipement you'd want converted.";
	mes "Please be aware that any cards or refining will get lost in the process!";
	next;

	setarray .@Position$[1],"Top","Mid","Low";
	setarray .@Position[1],6,5,4;

	set .@Menu$,"";
	for( set .@i, 1; .@i < 4; set .@i, .@i + 1 )
	{
		if( getequipisequiped(.@Position[.@i]) )
			set .@Menu$, .@Menu$ + .@Position$[.@i] + "-" + "[" + getequipname(.@Position[.@i]) + "]";

		set .@Menu$, .@Menu$ + ":";
	}

	set .@Part, .@Position[ select(.@Menu$) ];
	if( !getequipisequiped(.@Part) )
	{
		mes "^0000ff[ Luna ]^000000";
		mes "I can't see nothing equiped there...";
		close;
	}

	mes "^0000ff[ Luna ]^000000";
	mes "Do you want to transmorth your " + getitemname(getequipid(.@Part)) + " into a Costume?";
	mes "^ff0000WARNING:^000000";
	mes "^ff0000The item will be CONVERTED into a costume and lose all its attributes^000000";
	next;
	if( select("Yes, please:No, thank you.") == 2 )
	{
		mes "^0000ff[ Luna ]^000000";
		mes "Need some more time to think, huh?";
		mes "No problema at all!";
		close;
	}
	mes "^0000ff[ Luna ]^000000";
	mes "You can pay using Manias or "+ getitemname(VOTE_CERTIFICATE)+"s.";
	mes "Which option you are gonna chose?";
	next;
	if(select("Pay using Manias:Pay with "+getitemname(VOTE_CERTIFICATE)+"s") == 1) {
		if(#CASHPOINTS < .cost[0] ) {
			mes "^0000ff[ Luna ]^000000";
			mes "I am sorry but you don't seem to have enough Manias.";
			close;
		} else {
			set #CASHPOINTS, #CASHPOINTS - .cost[0];
			.@temp = getitemname(getequipid(.@Part));
			costume .@Part; // Convert the Headgear
			mes "^0000ff[ Luna ]^000000";
			mes "It is all done! Hope you like it!";
			logmes "[Luna] created  " + getitemname(.@temp) + " payment: Manias";
			close;
		}
	} else {
		if(countitem(VOTE_CERTIFICATE) < .cost[1] ) {
			mes "^0000ff[ Luna ]^000000";
			mes "I am sorry but you don't seem to have enough "+getitemname(VOTE_CERTIFICATE)+"s.";
			close;
		} else {
			delitem VOTE_CERTIFICATE, .cost[1];
			.@temp = getitemname(getequipid(.@Part));
			costume .@Part; // Convert the Headgear
			mes "^0000ff[ Luna ]^000000";
			mes "It's all done! Hope you like it!";
			logmes "[Luna] created " + getitemname(.@temp) + " payment: " + getitemname(VOTE_CERTIFICATE);
			close;
		}
	}
OnInit:
	setarray .cost[0],10000,15;
	end;
}

// --------------------------------------------------------------------------
// Use duplicates to put your npc on different cities
// --------------------------------------------------------------------------
prontera,166,201,6	duplicate(CostumeIT)	Luna#1	666
