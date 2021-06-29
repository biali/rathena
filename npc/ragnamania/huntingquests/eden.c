
prontera,164,169,3	script	HuntingQuests	859,{
    function eraseQuests; function checkQuests;

	// if (!callfunc("F_HasEdenGroupMark")) {
	// 	mes "- You need to have an -";
	// 	mes "- ^4d4dff'Eden Group Mark'^000000 -";
	// 	mes "- to receive these missions. -";
	// 	close;
	// }
    eraseQuests();

    // Looking for completed quests (2). One must collect rewards before taking another quest

    if((.@i = checkQuests(2)) > 0) {
        switch(.@i) {
            // Quests 11-25...
            case 11114: callsub L_DeliverCompletedQuest,.@i,"Hornet Hunting",900;
            case 11115: callsub L_DeliverCompletedQuest,.@i,"Condor Hunting",1800;
            case 11116: callsub L_DeliverCompletedQuest,.@i,"Grasshopper's Leg",1400,940,10;
            case 11117: callsub L_DeliverCompletedQuest,.@i,"Worm Tail Hunting",2600;
            case 11118: callsub L_DeliverCompletedQuest,.@i,"Spore Hunting",3900;
            case 11119: callsub L_DeliverCompletedQuest,.@i,"Extirpate Insects",2900,915,10;
            case 11120: callsub L_DeliverCompletedQuest,.@i,"Muka Hunting",3200;
            case 11121: callsub L_DeliverCompletedQuest,.@i,"Familiar Hunting",3200;
            case 11122: callsub L_DeliverCompletedQuest,.@i,"Collect Feathers",5400;
            case 11123: callsub L_DeliverCompletedQuest,.@i,"Collect Poison Spores",6000,7033,5;
            // Quests 26-40...
            case 8266: callsub L_DeliverCompletedQuest,.@i,"Hunting Poison Spore",1000;
            case 8267: callsub L_DeliverCompletedQuest,.@i,"Hunting Smokie",1000;
            case 8268: callsub L_DeliverCompletedQuest,.@i,"Hunting Elder Willow",1000;
            case 8269: callsub L_DeliverCompletedQuest,.@i,"Hunting Coco",1000;
            case 8270: callsub L_DeliverCompletedQuest,.@i,"Hunting Thara Frog",1500;
            // Quests 41-55
            case 12072: callsub L_DeliverCompletedQuest,.@i,"Thara Frog Hunting",9600;
            case 12073: callsub L_DeliverCompletedQuest,.@i,"Cruiser Hunting",7200;
            case 12074: callsub L_DeliverCompletedQuest,.@i,"Kukre Hunting",15750;
            case 12075: callsub L_DeliverCompletedQuest,.@i,"Orc Baby Hunting",7875;
            case 12076: callsub L_DeliverCompletedQuest,.@i,"Orc Warrior Hunting",11100;
            case 12077: callsub L_DeliverCompletedQuest,.@i,"Vadon Hunting",8550;
            case 12078: callsub L_DeliverCompletedQuest,.@i,"Megalodon Hunting",17100;
            case 12079: callsub L_DeliverCompletedQuest,.@i,"Marse Hunting",9000;
            case 12080: callsub L_DeliverCompletedQuest,.@i,"Cornutus Hunting",12300;
            case 12081: callsub L_DeliverCompletedQuest,.@i,"Myst Hunting",9900;
            case 12082: callsub L_DeliverCompletedQuest,.@i,"Shellfish Hunting",20250;
            case 12083: callsub L_DeliverCompletedQuest,.@i,"Marine Sphere Hunting",10350;
            case 12084: callsub L_DeliverCompletedQuest,.@i,"Phen Hunting",13800;
            case 12085: callsub L_DeliverCompletedQuest,.@i,"Orc Skeleton Hunting",11025;
            case 12086: callsub L_DeliverCompletedQuest,.@i,"Zenorc Hunting",22500;
            case 12087: callsub L_DeliverCompletedQuest,.@i,"Mummy Hunting",11250;

            default:
                dispbottom "ERROR! Please report this to the staff";
                end;
        }
L_DeliverCompletedQuest:
        .@quest_id = getarg(0);
        .@item_req = getarg(3,0);
        .@req_amount = getarg(4,0);
        if (.@item_req) {
            if (countitem(.@item_req) < .@req_amount) {
                mes .n$;
                mes "You don't have enough "+ getitemname(.@item_req) +".";
                mes "You need to bring "+ .@req_amount +" "+ getitemname(.@item_req) +".";
                close;
            }
        }
        mes .n$;
        mes "Hmm... let me see~";
        mes "You have completed the '"+ getarg(1) +"' mission.";
        next;
        mes .n$;
        mes "Good work~!!";
        mes "Our client is so happy with your work. He will appreciate what you have done.";
        mes "Please help us again. Thanks!";
        if (.@item_req)
            delitem .@item_req,.@req_amount;
        erasequest .@quest_id;

        // We need to treat the completed quests ids differently for each range
        // beause rA guys sometimes do stupid things :/ 
        if(.@quest_id >= 8266 && .@quest_id <= 8270) // Quests 26-40
            setquest .@quest_id+100;
        else if(.@quest_id >= 11114 && .@quest_id <= 11123) // Quests 11-25
            setquest .@quest_id+10;
        else if(.@quest_id >= 12072 && .@quest_id <= 12087) // Quests 41-55
            setquest .@quest_id+300;

        getexp getarg(2),0;
        close;

    } else if((.@i = checkQuest(0)) > 0 || (.@i = checkQuest(1)) > 0) {
        mes .n$;
        mes "You can only request";
        mes "one mission at a time.";
        close;
    }

    switch(select("Quests 11-25:Quests 26-40:Quests 41-55:Quests 56-70:Quests 71-85:Quests 86-90:Quests 91-99:Cancel")) {
        case 1: //Quests 11-25
            mes .n$;
            if (BaseLevel < 11) {
                mes "There are no tasks";
                mes "open for you right now.";
                close;
            }
            if (BaseLevel > 25) {
                mes "These missions are too";
                mes "easy for your caliber";
                mes "search for a more level";
                mes "appropriate mission.";
                close;
            }
            mes "Hunting quests";
            mes "for beginners.";
            next;
            switch(select("Hornet Hunting:Condor Hunting:Grasshopper's Leg:Worm Tail Hunting:Spore Hunting:Pest Control:Muka Hunting:Familiar Hunting:Collect Feathers:Collect Poison Spores:Cancel")) {
                case 1: callsub L_Quest,11114,"Hornet Hunting"," - Hunt 10 ^4d4dff'Hornets'^000000 - "," - northwest of Prontera. - ";
                case 2: callsub L_Quest,11115,"Condor Hunting"," - Hunt 20 ^4d4dff'Condors'^000000 - "," - south of Morocc. - ";
                case 3: callsub L_Quest,11116,"Grasshopper's Leg"," - Hunt 10 ^4d4dff'Rockers'^000000 - "," - southwest of Prontera and - "," - bring 10 ^4d4dffGrasshopper's Legs^000000. - ";
                case 4: callsub L_Quest,11117,"Worm Tail Hunting"," - Hunt 20 ^4d4dff'Worm Tails'^000000 - "," - southeast of Payon.- ";
                case 5: callsub L_Quest,11118,"Spore Hunting"," - Hunt 30 ^4d4dff'Spores'^000000 - "," - around Payon. - ";
                case 6: callsub L_Quest,11119,"Pest Control"," - Hunt 20 ^4d4dffThief Bug Eggs^000000 - "," - in the Prontera Culvert - "," - and bring 10 ^4d4dffChrysalis^000000. - ";
                case 7: callsub L_Quest,11120,"Muka Hunting"," - Hunt 20 ^4d4dff'Muka'^000000 - "," - south of Prontera. - ";
                case 8: callsub L_Quest,11121,"Familiar Hunting"," - Hunt 20 ^4d4dffFamiliar^000000 - "," - in the Culvert Sewers - "," - west of Prontera. - ";
                case 9: callsub L_Quest,11122,"Collect Feathers"," - Hunt 30 ^4d4dff'Peco Pecos'^000000 - "," - south of Prontera. - ";
                case 10: callsub L_Quest,11123,"Collect Poison Spores"," - Hunt 30 ^4d4dffPoison Spores^000000 - "," - inside the Geffen Tower and - "," - bring 5 ^4d4dffPoison Spores^000000. - ";
                case 11:
                    mes .n$;
                    mes "See you later!";
                    close;
            }

        case 2: // Quests 26-40
            mes .n$;
            if ((BaseLevel < 26) || (BaseLevel > 40)) {
                mes "Your level is not qualified. You can not do these missions.";
                close;
            }

            mes "Hunting Mission details:";
            next;
            switch(select("Hunting Poison Spore:Hunting Smokie:Hunting Elder Willow:Hunting Coco:Hunting Thara Frog:Cancel")) {
                case 1: callsub L_Quest,8266,"Hunting Poison Spore","Hunt 10 Poison Spores";
                case 2: callsub L_Quest,8267,"Hunting Smokie","Hunt 10 Smokies";
                case 3: callsub L_Quest,8268,"Hunting Elder Willow","Hunt 10 Elder Willows";
                case 4: callsub L_Quest,8269,"Hunting Coco","Hunt 10 Cocos";
                case 5: callsub L_Quest,8270,"Hunting Thara Frog","Hunt 10 Thara Frogs";
                case 6:
                    mes .n$;
                    mes "See you later!";
                    close;
            }
        case 3: // Quests 41-55
            mes .n$;
            if ((BaseLevel < 41) || (BaseLevel > 55)) {
                mes "Your level is not qualified. You can not do these missions.";
                close;
            }

            mes "Hunting Mission details:";
            next;
            switch(select("Thara Frog Hunting:Cruiser Hunting:Kukre Hunting:Orc Baby Hunting:Orc Warrior Hunting:Vadon Hunting:Megalodon Hunting:Marse Hunting:Cornutus Hunting:Myst Hunting:Shellfish Hunting:Marine Sphere Hunting:Phen Hunting:Orc Skeleton Hunting:Zenorc Hunting:Mummy Hunting:Cancel")) {
                case 1: callsub L_Quest,12072,"Have you seen a red frog? It is called Thara Frog and it's very rare. We are trying to verify where it inhabits. So please hunt 20 Thara Frogs.";
                case 2: callsub L_Quest,12073,"I heard of some toys attacking people. It is ridiculous! Let's show them our power! We have to hunt 15 Cruisers!";
                case 3: callsub L_Quest,12074,"Someone got robbed near the beach! The possible suspect is a criminal monster called Kukre. Please hunt 30 Kukre.";
                case 4: callsub L_Quest,12075,"Orc Babies are getting more violent these days. Please hunt 15 Orc Babies.";
                case 5: callsub L_Quest,12076,"Orc Warriors are increasing their aggression. Please hunt 20 Orc Warriors.";
                case 6: callsub L_Quest,12077,"Have you seen crabs with thick shells? They are Vadons. Please hunt 15 Vadons.";
                case 7: callsub L_Quest,12078,"Dead fish are all around the beach and it is getting worse. Please hunt 30 Megalodon.";
                case 8: callsub L_Quest,12079,"Can you hunt Marse? I need 15 Marse for my study. Please help me.";
                case 9: callsub L_Quest,12080,"An idiot Cornutus bit the Mayor's foot. The Mayor is upset so we need to hunt 20 Cornutus to make him happy!";
                case 10: callsub L_Quest,12081,"People are freaking out because of Myst. It looks like a ghost so, it scares people. Please hunt 15 Myst.";
                case 11: callsub L_Quest,12082,"Don't ask why, but please hunt 30 Shellfish. It is a secret mission!";
                case 12: callsub L_Quest,12083,"Marine Sphere? Do you know what a Marine Sphere is? I got a mission for you to hunt 15 Marine Sphere, so please do so.";
                case 13: callsub L_Quest,12084,"The mayor wants to eat a delicious fish dish. Phen will be the perfect ingredient for it. Please hunt 20 Phen!";
                case 14: callsub L_Quest,12085,"Dead Orc monsters got back to our town and they've revived as Orc Skeletons. We are in chaos! Please hunt 15 Orc Skeleton.";
                case 15: callsub L_Quest,12086,"Some weird monsters called Zenorc are attacking us. Please hunt 30 Zenorc.";
                case 16: callsub L_Quest,12087,"Be prepared! It is a cruel mission! Hunt 15 Mummies!! I tried once, but I couldn't succeed. It is too scary!";
                case 17:
                    mes .n$;
                    mes "See you later!";
                    close;
            }
    }

L_Quest:
    .@quest_id = getarg(0);
    // Again, we need to treat the ranges separately...
    if(.@quest_id >= 8266 && .@quest_id <= 8270) // Quests 26-40
        .@quest_status = checkquest(.@quest_id+100,PLAYTIME);
    else if(.@quest_id >= 11114 && .@quest_id <= 11123) // Quests 11-25
        .@quest_status = checkquest(.@quest_id+10,PLAYTIME);
    else if(.@quest_id >= 12072 && .@quest_id <= 12087) // Quests 41-55
        .@quest_status = checkquest(.@quest_id+300,PLAYTIME);


    if (.@quest_status == 0 || .@quest_status == 1) {
        mes .n$;
        mes "Mission ^4d4dff"+ getarg(1) +"^000000";
        mes " is already finished for today.";
        close;
    }
    mes .n$;
    mes "Mission '"+ getarg(1) +"'";
    for ( .@i = 2; .@i < getargcount(); .@i++ )
        mes getarg(.@i);
    next;
    if (select("I will do this mission.:Look for other missions.") == 2) {
        mes "Let's search for";
        mes "other missions.";
        close;
    }
    for ( .@i = 2; .@i < getargcount(); .@i++ )
        mes getarg(.@i);
    setquest getarg(0);
    close;

OnInit:
    .n$ = "^FF0000[ Hunting Quests ]^000000";
    setarray .quests_1[0],11114,11115,11116,11117,11118,11119,11120,11121,11122,11123;
    setarray .quests_2[0],8266,8267,8268,8269,8270;
    setarray .quests_2[0],12072,12073,12074,12075,12076,12077,12078,12079,12080,12081,12082,12083,12084,12085,12086,12087;
    end;



    function checkQuests {
        .@filter = getarg(0);
        for(.@k=1; .@k<=7;.@k++) { 
            for(.@i=0;.@i<getarraysize(getd(".quests_"+.@k));.@i++) {
                .@quest_id = getd(".quests_"+.@k+"["+.@i+"]");
                .@j = checkquest(.@quest_id,HUNTING);
                if(.@j == .@filter)
                    return .@quest_id;
            }
        }
        return -1;
    }



    // This is executed every time one talks to the npc.
    // It will remove any expired hunting quest from the player's quest log
    function eraseQuests {
        for(.@k=1; .@k<=7;.@k++) { 
            for(.@i=0;.@i<getarraysize(getd(".quests_"+.@k));.@i++) {
                .@quest_id = getd(".quests_"+.@k+"["+.@i+"]") + 10;
                if (checkquest(.@quest_id,PLAYTIME) == 2) 
                    erasequest .@quest_id;
            }
        }
        return;
    }
}