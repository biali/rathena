-	script	CardRemover	-1,{
	if(!vip_status(1) && getgmlevel()<10) end;
	mes .n$;
	mes "Oh, hello, " + strcharinfo(0);
	mes "Please don't mind the mess,";
	mes "I will have everything back";
	mes "in their place once I am finished.";
	next;
	mes .n$;
	mes "I am trying to improve my skills";
	mes "on removing cards from equipments.";
	mes "Is this the reason why you are here?";
	next;
	mes .n$;
	mes "Please, let me know which";
	mes "piece of equipment we are";
	mes "talking about...";
	next;
	setarray .@indices[1], EQI_HEAD_TOP, EQI_ARMOR, EQI_HAND_L, EQI_HAND_R, EQI_GARMENT, EQI_SHOES, EQI_ACC_L, EQI_ACC_R, EQI_HEAD_MID, EQI_HEAD_LOW;
	for( set .@i,1; .@i <= 10; set .@i,.@i+1 ) {
		if( getequipisequiped(.@indices[.@i]) )
			set .@menu$, .@menu$ + F_getpositionname(.@indices[.@i]) + "-[" + getequipname(.@indices[.@i]) + "]";
		set .@menu$, .@menu$ + ":";
	}
	set .@part, .@indices[ select(.@menu$) ];
	if(!getequipisequiped(.@part)) {
		mes .n$;
		mes "Oh, but you are not wearing anything there that I can remove cards from...";
		close;
	}
	if(getequipcardcnt(.@part) == 0) {
		mes .n$;
		mes "Excuse me, but there are no cards compounded on this item. I can do nothing with it, I'm afraid.";
		close;
	}
	set .@cardcount,getequipcardcnt(.@part);
	mes .n$;
	mes "In order to have the cards";
	mes "removed from your ^0000AA" + getequipname(.@part)+ "^000000";
	mes "we will need:";
	.@material = getequiprefinecost(.@part,REFINE_COST_ENRICHED,REFINE_MATERIAL_ID);
	mes "^0000FF1x " + getitemname(.@material) +"^000000";
	mes "^0000FF3x " + getitemname(VOTE_CERTIFICATE) +"^000000";
	mes "Plus a small fee of ^0000FF" +callfunc("F_InsertComma",15000)+"z^000000 to cover my studies.";
	mes "Do you want to go ahead with this? I guarantee my services. No risks envolved.";
	if(select("^FF0000No, I've changed my mind:^00AA00Yes, please go ahead^000000") == 1 ){
		clear;
		mes .n$;
		mes "No problem, I understand...";
		close;
	}
	clear;
	mes .n$;
	if(Zeny < 15000) {
		mes "Sorry, you don't seem to have enough Zeny. I can't do this for free.";
		close;
	}
	if(countitem(.@material) < 1) {
		mes "Sorry, I can't find your  ^FF0000" + getitemname(.@material) +"^000000.";
		close;
	}
	if(countitem(VOTE_CERTIFICATE) < 3) {
		mes "Sorry, I can't find your  ^FF0000" + getitemname(VOTE_CERTIFICATE) +"^000000.";
		close;
	}


	Zeny -= 15000;
	delitem .@material,1;
	delitem VOTE_CERTIFICATE,3;

	successremovecards .@part;
	mes "Perfect! Success, again! I am just so good at this!";
	close;

OnInit:
	.n$ = "^DAAADA[ Sage Apprentice ]^000000";
	end;
}

//sala_premmy,107,143,6	script	Sage Apprentice#2	755,{
prontera,128,194,0	duplicate(CardRemover)	Sage Apprentice#2	755