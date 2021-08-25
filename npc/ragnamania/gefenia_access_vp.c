geffen,112,149,6	script	Dark Mage	792,{
	if($GEFENIA_WARP_COUNT >= 5) {
		mes .n$;
		mes "Don't waste your breath";
		mes "Can't you see the portal is open?";
		mes "Leave me alone now";
		close;
	}

	mes .n$;
	mes "I am sure you have heard";
	mes "about the Ruins Of Gefenia";
	mes "already...";
	next;
	mes .n$;
	mes "It's certainly one of the";
	mes "most looked-after places";
	mes "in the entire realm";
	mes "... and beyound.";
	next;
	mes .n$;
	mes "I can get you there, but";
	mes "I will need something";
	mes "in return:";
	next;
	mes .n$;
	mes "I need "+ (5 - $GEFENIA_WARP_COUNT) +"/5x ^6600cc" + getitemname(VOTE_CERTIFICATE) + "^000000.";
	mes "But worry not...";
	mes "They don't need to come";
	mes "all from you.";
	next;
	mes .n$;
	mes "When I get all the 5 of them";
	mes "I will summon a portal to Gefenia";
	mes "right here next to me and anyone";
	mes "can then make use of it.";
	next;
	mes .n$;
	mes "The portal will stay open";
	mes "for 2 hours and then vanish.";
	next;
	mes .n$;
	mes " ";
	mes "^FF0000Gefenia is a full-loot map^000000";
	mes "^FF0000Gefenia is party-locked^000000";
	next;
	mes .n$;
	mes "So, would you like to";
	mes "contribute to my magic?";
	next;

	if(select("Yes:No") == 2) {
		mes .n$;
		mes "Understandable...";
		mes "...";
		close;
	}
	mes .n$;
	if(countitem(VOTE_CERTIFICATE) > 0) {
		delitem VOTE_CERTIFICATE, 1;
		set $GEFENIA_WARP_COUNT, $GEFENIA_WARP_COUNT + 1;
		if($GEFENIA_WARP_COUNT >= 5) {
			
			if(!.PortalIsOpen) {
				.PortalIsOpen = 1;
				initnpctimer;
				startnpctimer;
				donpcevent("warp_gefenia::OnEnable");
			}

			mes "There it is... Enjoy.";
			mes "HA HA HA HA";
			close;
		} else {
			mes "What a delight...";
			mes "Thank you... I guess";
			mes "I only need " + (5 - $GEFENIA_WARP_COUNT) + " more now...";
			close;
		}
	} else {
		mes "What a boomer..";
		mes "You don't have it!";
		mes "Be gone before I turn you";
		mes "into a stupid Thara Frog";
		close;
	}

OnTimer7200000: // 2 hours timer
	.PortalIsOpen = 0;
	stopnpctimer;
	donpcevent "warp_gefenia::OnDisable";
	end;

OnInit:
	.n$ = "^6600cc[ Dark Mage ]^000000";
	end;

}

geffen,108,147,0	script	warp_gefenia	45,2,2,{
	end;

OnTouch:
	mes " ";
	mes "^FF0000WARNING^000000";
	mes "^FF0000You are entering a^000000";
	mes "^FF0000Full-loot PK Area^000000";
	mes " ";
	mes "Do you wanna proceed?";
	if(select("No:Yes") == 1)
		close;
	if(getcharid(1) > 0) {
	//if they are in a party, try to teleport them to their party leader
		if(compare(getpartyleader(getcharid(1),4), "gefenia") == 1) {
			if(getmapxy(.@m$,.@x,.@y,BL_PC,strcharinfo(0,getpartyleader(getcharid(1),2))) >= 0) {
				warp .@m$,.@x,.@y;
				end;
			}
		}
	}
	warp "gefenia01",0,0;
	end;


OnDisable:
	$GEFENIA_WARP_COUNT = 0;
OnInit:
	disablenpc strnpcinfo(0);
	end;

OnEnable:
	enablenpc strnpcinfo(0);
	end;
}

gefenia01	mapflag	partylock
gefenia01	mapflag	rpk	RPK_FULLLOOT,1
gefenia02	mapflag	partylock
gefenia02	mapflag	rpk	RPK_FULLLOOT,1
gefenia03	mapflag	partylock
gefenia03	mapflag	rpk	RPK_FULLLOOT,1
gefenia04	mapflag	partylock
gefenia04	mapflag	rpk	RPK_FULLLOOT,1