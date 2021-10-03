// Inscription - Yuno
yuno,86,155,6	script	Illustrious Scribe	743,{
	if(PROFESSION) {
		if(PROFESSION != SCRIBE) {
			mes .n$;
			mes "Oh, hello!";
			mes "Do you wanna join us";
			mes "and become an honored";
			mes "Scribe of the Realm?";
			next;
			mes .n$;
			mes "We'd love to welcome you";
			mes "but first I am afraid";
			mes "you'd need to cease being";
			mes "a " + callfunc("F_GetProfName",PROFESSION) + ".";
			next;
			mes .n$;
			mes "In order to do that I am";
			mes "afraid you'd need to talk";
			mes "to the supreme representative";
			mes "of your Union.";
			close;
		} else {
			mes .n$;
			mes "Hello," + strcharinfo(0);
			mes "How can I help you?";
			next;
			mes .n$;
			if(select("I'd like to leave the Union:Nothing, thanks.") == 2) {
				mes "He he he...";
				mes "I guess you are just wasting some precious amount of time, then...";
				close;
			} else {
				mes "Oh, I am sorry to hear that!";
				mes "Are you well aware that you are gonna lose all the progress you've achieved so far?";
				next;
				mes .n$;
				mes "^ff0000By leaving the Union you will lose all the progression towards Inscription. Are you sure you want to continue?^000000";
				next;
				mes .n$;
				if(select("No, I've changed my mind:Yes, please go ahead") == 1){
					mes "Good! I am glad you've changed your mind.";
					close;
				} else {
					set PROFESSION, 0;
					deletearray PRO_INFO[0],getarraysize(PRO_INFO);
					mes "It is done... I've removed you from our records.";
					mes "Go in peace, " + strcharinfo(0);
					close;
				}
			}
		}
	} else {
		mes .n$;
		mes "Hello, stranger!";
		mes "Would you like to join";
		mes "our Union and learn the";
		mes "ways of becoming a";
		mes "Scribe of the Kingdom?";
		next;
		mes .n$;
		mes "Scribes are a very honored";
		mes "profession and certainly";
		mes "will bring you prestige and";
		mes "an some money too...";
		next;
		mes .n$;
		if(select("Make me a Scribe:No, Thank you") == 2 ) {
			mes "That is fine... maybe another day?";
			mes "Go in peace!";
			close;
		} else {
			mes "Oh! That is great!";
			next;
			PROFESSION = SCRIBE;
			atcommand "@effect 344";
			mes .n$;
			mes "We are always looking for";
			mes "people like you to join";
			mes "our cause! Welcome!";
			next;
			mes .n$;
			mes "Now, you are gonna need";
			mes "a Scribe Book in order";
			mes "to start... Please, talk";
			mes "to my pupil there and he will";
			mes "certainly help you with that.";
			close;
		}
	}

OnInit:
	.n$ = "^6600AA[ Illustrious Scribe ]^000000";
	end;
}

// Craft - Einbroch
// *********************************************

einbroch,210,82,4	script	Illustrious Craftsman	813,{
	if(PROFESSION) {
		if(PROFESSION != CRAFTSMAN) {
			mes .n$;
			mes "Hi!";
			mes "Looking to be part";
			mes "of our Union and become";
			mes "a Craftsman?";
			next;
			mes .n$;
			mes "We welcome all";
			mes "but first I am afraid";
			mes "you'd need to cease being";
			mes "a " + callfunc("F_GetProfName",PROFESSION) + ".";
			next;
			mes .n$;
			mes "Talk to the leader of";
			mes "your Union... You know where";
			mes "to find them, don't you?";
			close;
		} else {
			mes .n$;
			mes "Hi," + strcharinfo(0);
			mes "How can I help you?";
			next;
			mes .n$;
			if(select("I'd like to leave the Union:Nothing, thanks.") == 2) {
				mes "Good. Farewell.";
				close;
			} else {
				mes "What a boomer...";
				mes "Are you well aware that you are gonna lose all the progress you've achieved so far?";
				next;
				mes .n$;
				mes "^ff0000By leaving the Union you will lose all the progression towards Craftsman. Are you sure you want to continue?^000000";
				next;
				if(getd("$@f_"+getcharid(0)) > 0) {
					mes .n$;
					mes "I am sorry, but before we go ahead, you'll need to disassemble your furnace and return it to us.";
					close;
				}
				mes .n$;
				if(select("No, I've changed my mind:Yes, please go ahead") == 1){
					mes "Good choice.";
					close;
				} else {
					set PROFESSION, 0;
					if((.@c = countitem(CRAFTSMAN_FURNACE)) > 0)
						delitem CRAFTSMAN_FURNACE,.@c;
					deletearray PRO_INFO[0],getarraysize(PRO_INFO);
					mes "I guess that is it. I've removed you from our records.";
					mes "Farewell, " + strcharinfo(0);
					close;
				}
			}
		}
	} else {
		mes .n$;
		mes "Hello, stranger!";
		mes "Would you like to join";
		mes "our Union and learn the";
		mes "ways of becoming a";
		mes "Craftsman like me?";
		next;
		mes .n$;
		mes "Craftsmen are hard working";
		mes "people who enjoys having";
		mes "their hands dirty producing";
		mes "armor, weapons and tools.";
		next;
		mes .n$;
		if(select("Make me a Craftsman:No, Thank you") == 2 ) {
			mes "That is fine... maybe another day?";
			mes "Farewell.";
			close;
		} else {
			mes "Good stuff!";
			next;
			PROFESSION = CRAFTSMAN;
			atcommand "@effect 344";
			mes .n$;
			mes "We like the ones like you,";
			mes "people willing to help.";
			mes "Welcome!";
			next;
			mes .n$;
			mes "You are gonna need some tools";
			mes "in orther to gather resources";
			mes "from special trees and";
			mes "mineral veins.";
			mes "My friend there will help you.";
			close;
		}
	}

OnInit:
	.n$ = "^6600AA[ Grand-Master Craftsman ]^000000";
	end;
}


// Farm - Hugel
// *********************************************
hugel,149,188,2	script	Illustrious Farmer	570,{
	if(PROFESSION) {
		if(PROFESSION != FARMER) {
			mes .n$;
			mes "Howdy, stranger!";
			mes "Heard you may be interested";
			mes "in joining us to become";
			mes "a proud Farmer?";
			next;
			mes .n$;
			mes "We'd love to welcome you";
			mes "but first I am afraid";
			mes "you'd need to cease being";
			mes "a " + callfunc("F_GetProfName",PROFESSION) + ".";
			next;
			mes .n$;
			mes "In order to do that I am";
			mes "afraid you'd need to talk";
			mes "to the leader";
			mes "of your Union.";
			close;
		} else {
			mes .n$;
			mes "Hello," + strcharinfo(0);
			mes "How can I help you?";
			next;
			mes .n$;
			if(select("I'd like to leave the Union:Nothing, thanks.") == 2) {
				mes "* Gasps *";
				mes "You scared me... don't do that ever again!";
				close;
			} else {
				mes "I am sorry... mainly for you.";
				mes "Are you well aware that you are gonna lose all the progress you've achieved so far?";
				next;
				mes .n$;
				mes "^ff0000By leaving the Union you will lose all the progression towards Farming. Are you sure you want to continue?^000000";
				next;
				mes .n$;
				if(select("No, I've changed my mind:Yes, please go ahead") == 1){
					mes "Good! I am glad you've changed your mind.";
					close;
				} else {
					set PROFESSION, 0;
					deletearray PRO_INFO[0],getarraysize(PRO_INFO);
					query_sql "DELETE FROM `farm` WHERE `char_id` = "+getcharid(0);
					mes "It is done... I've removed you from our records.";
					mes "Have a blessed day, " + strcharinfo(0);
					close;
				}
			}
		}
	} else {
		mes .n$;
		mes "Hello, stranger!";
		mes "Would you like to join";
		mes "our Union and hopefuly";
		mes "become a wealthy";
		mes "Farmer of the Kingdom?";
		next;
		mes .n$;
		mes "Farmers are a must this days";
		mes "and will certainly bring you";
		mes "lots of joy and prestige.";
		next;
		mes .n$;
		if(select("Make me a Farmer:No, Thank you") == 2 ) {
			mes "That is fine... maybe another day?";
			mes "Blessed day!";
			close;
		} else {
			mes "Oh! That is great!";
			next;
			PROFESSION = FARMER;
			atcommand "@effect 344";
			mes .n$;
			mes "We are always looking for";
			mes "people like you to join";
			mes "our cause! Welcome!";
			next;
			mes .n$;
			mes "Now, you are gonna need";
			mes "some tools in order";
			mes "to start... Please, talk";
			mes "to my friend there and he will";
			mes "certainly help you with that.";
			close;
		}
	}

OnInit:
	.n$ = "^6600AA[ Illustrious Farmer ]^000000";
	end;
}


// functions
function	script	F_GetProfName	{
	.@p = getarg(0,PROFESSION);
	switch(.@p) {
		case SCRIBE: return "Scribe";
		case FARMER: return "Farmer";
		case CRAFTSMAN: return "Craftsman";
		default: return "";
	}
}

function	script	F_GetProfLevel	{
	.@p = getarg(0,PRO_INFO[0]);
	switch(.@p) {
		case 0: return "Apprentice";
		case 1: return "Journeyman";
		case 2: return "Skilled";
		case 3: return "Expert";
		case 4: return "Artisan";
		case 5: return "Master";
		case 6: return "Grand-Master";
		case 7: return "Illustrious";
		default: return "";
	}
}