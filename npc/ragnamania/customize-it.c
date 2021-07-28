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
	mes "[Luna]";
	mes "Hi and welcome to my shop!";
	mes "I can help you in changing any piece of headgear into a costume.";
	next;
	mes "[Luna]";
	mes "I charge 10.000 Manias or 100 "+getitemname($@HUNTING_MEDAL)+"s for that.";
	next;
	mes "[Luna]";
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
		mes "[Luna]";
		mes "I can't see nothing equiped there...";
		close;
	}

	mes "[Luna]";
	mes "Do you want to transmorth your " + getitemname(getequipid(.@Part)) + " into a Costume?";
	next;
	if( select("Yes, please:No, thank you.") == 2 )
	{
		mes "[Luna]";
		mes "Need some more time to think, huh?";
		mes "No problema at all!";
		close;
	}
	mes "[Luna]";
	mes "You can pay using Manias or "+ getitemname($@HUNTING_MEDAL)+"s.";
	mes "Which option you are gonna chose?";
	next;
	if(select("Pay using Manias:Pay with "+getitemname($@HUNTING_MEDAL)+"s") == 1) {
		if(#CASHPOINTS < 10000 ) {
			mes "[Luna]";
			mes "I am sorry but you don't seem to have enough Manias.";
			close;
		} else {
			set #CASHPOINTS, #CASHPOINTS - 10000;
			.@temp = getitemname(getequipid(.@Part));
			costume .@Part; // Convert the Headgear
			mes "[Luna]";
			mes "It is all done! Hope you like it!";
			logmes "[Luna] created  " + getitemname(.@temp) + " payment: Manias";
			close;
		}
	} else {
		if(countitem($@HUNTING_MEDAL) < 100 ) {
			mes "[Luna]";
			mes "I am sorry but you don't seem to have enough "+getitemname($@HUNTING_MEDAL)+"s.";
			close;
		} else {
			delitem $@HUNTING_MEDAL, 100;
			.@temp = getitemname(getequipid(.@Part));
			costume .@Part; // Convert the Headgear
			mes "[Luna]";
			mes "It's all done! Hope you like it!";
			logmes "[Luna] created " + getitemname(.@temp) + " payment: " + getitemname($@HUNTING_MEDAL);
			close;
		}
	}
}

// --------------------------------------------------------------------------
// Use duplicates to put your npc on different cities
// --------------------------------------------------------------------------
prontera,166,201,6	duplicate(CostumeIT)	Luna#1	666
