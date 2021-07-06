
-	script	#HuntingQuests	-1,{
    function eraseQuests; function checkQuests; function redirect;
    eraseQuests();
    // Looking for completed quests (2). One must collect rewards before taking another quest
    if((.@i = checkQuests(2)) > 0) {
        switch(.@i) {
            // Quests 11-25...
            case 11114: callsub L_DeliverCompletedQuest,.@i,"Hornet Hunting",900,100;
            case 11115: callsub L_DeliverCompletedQuest,.@i,"Condor Hunting",1800,200;
            case 11116: callsub L_DeliverCompletedQuest,.@i,"Grasshopper's Leg",1400,0,940,10;
            case 11117: callsub L_DeliverCompletedQuest,.@i,"Worm Tail Hunting",2600,340;
            case 11118: callsub L_DeliverCompletedQuest,.@i,"Spore Hunting",3900,400;
            case 11119: callsub L_DeliverCompletedQuest,.@i,"Extirpate Insects",2900,360,915,10;
            case 11120: callsub L_DeliverCompletedQuest,.@i,"Muka Hunting",3200,300;
            case 11121: callsub L_DeliverCompletedQuest,.@i,"Familiar Hunting",3200,300;
            case 11122: callsub L_DeliverCompletedQuest,.@i,"Collect Feathers",5400,300;
            case 11123: callsub L_DeliverCompletedQuest,.@i,"Collect Poison Spores",6000,500,7033,5;
            // Quests 26-40...
            case 8266: callsub L_DeliverCompletedQuest,.@i,"Hunting Poison Spore",4000,420;
            case 8267: callsub L_DeliverCompletedQuest,.@i,"Hunting Smokie",4000,420;
            case 8268: callsub L_DeliverCompletedQuest,.@i,"Hunting Elder Willow",4000,420;
            case 8269: callsub L_DeliverCompletedQuest,.@i,"Hunting Coco",4000,420;
            case 8270: callsub L_DeliverCompletedQuest,.@i,"Hunting Thara Frog",6500,560;
            // Quests 41-55
            case 12072: callsub L_DeliverCompletedQuest,.@i,"Thara Frog Hunting",9600,800;
            case 12073: callsub L_DeliverCompletedQuest,.@i,"Cruiser Hunting",7200,580;
            case 12074: callsub L_DeliverCompletedQuest,.@i,"Kukre Hunting",15750,6200;
            case 12075: callsub L_DeliverCompletedQuest,.@i,"Orc Baby Hunting",7875,610;
            case 12076: callsub L_DeliverCompletedQuest,.@i,"Orc Warrior Hunting",11100,5600;
            case 12077: callsub L_DeliverCompletedQuest,.@i,"Vadon Hunting",8550,780;
            case 12078: callsub L_DeliverCompletedQuest,.@i,"Megalodon Hunting",17100,6800;
            case 12079: callsub L_DeliverCompletedQuest,.@i,"Marse Hunting",9000,800;
            case 12080: callsub L_DeliverCompletedQuest,.@i,"Cornutus Hunting",12300,5800;
            case 12081: callsub L_DeliverCompletedQuest,.@i,"Myst Hunting",9900,880;
            case 12082: callsub L_DeliverCompletedQuest,.@i,"Shellfish Hunting",20250,9600;
            case 12083: callsub L_DeliverCompletedQuest,.@i,"Marine Sphere Hunting",10350,5000;
            case 12084: callsub L_DeliverCompletedQuest,.@i,"Phen Hunting",13800,4800;
            case 12085: callsub L_DeliverCompletedQuest,.@i,"Orc Skeleton Hunting",11025,3600;
            case 12086: callsub L_DeliverCompletedQuest,.@i,"Zenorc Hunting",22500,8000;
            case 12087: callsub L_DeliverCompletedQuest,.@i,"Mummy Hunting",11250,3600;
            // Quests 56-70
            case 3250: callsub L_DeliverCompletedQuest,.@i,"What is this Bandage?",15000,5000,930,30;
			case 3251: callsub L_DeliverCompletedQuest,.@i,"Dangerous Alligators.",16000,6000;
			case 3252: callsub L_DeliverCompletedQuest,.@i,"That wasn't a mermaid...",17000,8000;
            case 3255: callsub L_DeliverCompletedQuest,.@i,"Hunt Wild Boar",16000,7000;
			case 3257: callsub L_DeliverCompletedQuest,.@i,"A Woman's Grudge",17000,8000;
			case 3259: callsub L_DeliverCompletedQuest,.@i,"Puppet Master's Agony",17000,7000,1060,30;
            case 3260: callsub L_DeliverCompletedQuest,.@i,"Tiresome Flies",16000,6000;
			case 3261: callsub L_DeliverCompletedQuest,.@i,"Dangerous Munak",16000,7000;
            // Quests 71-85
            case 10107: callsub L_DeliverCompletedQuest,.@i,"Hunt 10 Requiems.",15000;
			case 10108: callsub L_DeliverCompletedQuest,.@i,"Hunt 10 Marduks.",15000;
			case 10109: callsub L_DeliverCompletedQuest,.@i,"Hunt 10 Pasanas.",15000;
            case 10110: callsub L_DeliverCompletedQuest,.@i,"Hunt 10 Dark Frames.",20000;
			case 10111: callsub L_DeliverCompletedQuest,.@i,"Hunt 10 Evil Druids.",20000;
			case 10112: callsub L_DeliverCompletedQuest,.@i,"Hunt 10 Wraiths.",20000;
			case 10113: callsub L_DeliverCompletedQuest,.@i,"Hunt 10 Raydric Archers.",20000;
            case 10114: callsub L_DeliverCompletedQuest,.@i,"Hunt 20 Grand Pecos.",30000;
			case 10115: callsub L_DeliverCompletedQuest,.@i,"Hunt 20 Sleepers.",30000;
			case 10116: callsub L_DeliverCompletedQuest,.@i,"Hunt 20 Goats.",30000;
			case 10117: callsub L_DeliverCompletedQuest,.@i,"Hunt 20 Harpies.",30000;
            case 10118: callsub L_DeliverCompletedQuest,.@i,"Hunt 15 Clocks before it breaks.",25000;
			case 10119: callsub L_DeliverCompletedQuest,.@i,"Hunt 15 Punks before it breaks.",25000;
			case 10120: callsub L_DeliverCompletedQuest,.@i,"Hunt 15 Ridewords before it breaks.",25000;
            case 10121: callsub L_DeliverCompletedQuest,.@i,"Hunt 15 Kikimoras in Moscovia!",30000;
			case 10122: callsub L_DeliverCompletedQuest,.@i,"Hunt 15 Miyabi Dolls in Amatsu!",30000;
			case 10123: callsub L_DeliverCompletedQuest,.@i,"Hunt 15 Mi Gaos in Luoyang!",30000;
            // Quest 86-90
            case 4167: callsub L_DeliverCompletedQuest,.@i,"Hunt Dragon Tail.",76000;
			case 4168: callsub L_DeliverCompletedQuest,.@i,"Hunt Spring Rabbit.",82000;
			case 4169: callsub L_DeliverCompletedQuest,.@i,"Hunt Pest.",82000;
            case 4170: callsub L_DeliverCompletedQuest,.@i,"Hunt Bathory.",72000;
			case 4171: callsub L_DeliverCompletedQuest,.@i,"Hunt Alarm.",76000;
			case 4172: callsub L_DeliverCompletedQuest,.@i,"Hunt Baba Yaga.",72000;
			case 4173: callsub L_DeliverCompletedQuest,.@i,"Hunt Yao Jun.",78000;
            case 4174: callsub L_DeliverCompletedQuest,.@i,"Hunt Firelock Soldier.",82000;
			case 4175: callsub L_DeliverCompletedQuest,.@i,"Hunt Zipper Bear.",80000;
			case 4176: callsub L_DeliverCompletedQuest,.@i,"Hunt Ground Petite.",72000;
			case 4177: callsub L_DeliverCompletedQuest,.@i,"Hunt Rafflesia.",72000;
            case 4178: callsub L_DeliverCompletedQuest,.@i,"Hunt Venomous.",72000;
			case 4179: callsub L_DeliverCompletedQuest,.@i,"Hunt Pitman.",86000;
			case 4180: callsub L_DeliverCompletedQuest,.@i,"Hunt Yellow Novus.",80000;
            // Quests 91-99
            case 4181: callsub L_DeliverCompletedQuest,.@i,"Hunt Solider.",90000;
			case 4182: callsub L_DeliverCompletedQuest,.@i,"Hunt Freezer.",94000;
			case 4183: callsub L_DeliverCompletedQuest,.@i,"Hunt Heater.",114000;
            case 4184: callsub L_DeliverCompletedQuest,.@i,"Hunt Injustice.",96000;
			case 4185: callsub L_DeliverCompletedQuest,.@i,"Hunt Rybio.",96000;
			case 4186: callsub L_DeliverCompletedQuest,.@i,"Hunt Dark Priest.",146000;
			case 4187: callsub L_DeliverCompletedQuest,.@i,"Hunt Stapo.",96000;
            case 4188: callsub L_DeliverCompletedQuest,.@i,"Hunt Roween.",102000;
			case 4189: callsub L_DeliverCompletedQuest,.@i,"Hunt Siroma.",110000;
			case 4190: callsub L_DeliverCompletedQuest,.@i,"Hunt Shinobi.",102000;
			case 4191: callsub L_DeliverCompletedQuest,.@i,"Hunt Evil Nymph.",108000;
            case 4192: callsub L_DeliverCompletedQuest,.@i,"Hunt Deviruchi.",110000;
			case 4193: callsub L_DeliverCompletedQuest,.@i,"Hunt Mineral.",138000;
			case 4194: callsub L_DeliverCompletedQuest,.@i,"Hunt Kaho.",118000;
            case 4195: callsub L_DeliverCompletedQuest,.@i,"Hunt Neraid.",96000;
            case 4196: callsub L_DeliverCompletedQuest,.@i,"Hunt Disguise.",134000;
        }

L_DeliverCompletedQuest:
        .@quest_id = getarg(0);
        .@item_req = getarg(4,0);
        .@req_amount = getarg(5,0);
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
        if(.@quest_id >= 3250 && .@quest_id <= 3261) // Quests 56-70
            setquest .@quest_id+20;
        else if(.@quest_id >= 4167 && .@quest_id <= 4180) // Quests 86-90
            setquest .@quest_id+31;
        else if(.@quest_id >= 4181 && .@quest_id <= 4196) // Quests 91-99
            setquest .@quest_id+31;
        else if(.@quest_id >= 8266 && .@quest_id <= 8270) // Quests 26-40
            setquest .@quest_id+100;
        else if(.@quest_id >= 10107 && .@quest_id <= 10123) // Quests 71-85
            setquest .@quest_id+20;
        else if(.@quest_id >= 11114 && .@quest_id <= 11123) // Quests 11-25
            setquest .@quest_id+10;
        else if(.@quest_id >= 12072 && .@quest_id <= 12087) // Quests 41-55
            setquest .@quest_id+300;

        getexp getarg(2,0),getarg(3,0);
        close;

    } else if((.@i = checkQuest(0)) > 0 || (.@i = checkQuest(1)) > 0) {
        mes .n$;
        mes "You can only request";
        mes "one mission at a time.";
        close;
    }

    switch(select("Quests 11-25:Quests 26-40:Quests 41-55:Quests 56-70:Quests 71-85:Quests 86-90:Quests 91-99:Cancel")) {
        case 1: //Quests 11-25
            @sub = 1;
L_Quests_1:
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
            switch(select("Hornet Hunting:Condor Hunting:Grasshopper's Leg:Worm Tail Hunting:Spore Hunting:Pest Control:Muka Hunting:Familiar Hunting:Collect Feathers:Collect Poison Spores:Cancel")) {
                case 1: callsub L_Quest,11114,"Hornet Hunting"," - Hunt 10 ^4d4dff'Hornets'^000000 - "," - northwest of Prontera. - ";
                case 2: callsub L_Quest,11115,"Condor Hunting"," - Hunt 20 ^4d4dff'Condors'^000000 - "," - south of Morocc. - ";
                case 3: callsub L_Quest,11116,"Grasshopper's Leg"," - Hunt 10 ^4d4dff'Rockers'^000000 - "," - southwest of Prontera and - "," - bring 10 ^4d4dff"+getitemname(940)+"^000000. - ";
                case 4: callsub L_Quest,11117,"Worm Tail Hunting"," - Hunt 20 ^4d4dff'Worm Tails'^000000 - "," - southeast of Payon.- ";
                case 5: callsub L_Quest,11118,"Spore Hunting"," - Hunt 30 ^4d4dff'Spores'^000000 - "," - around Payon. - ";
                case 6: callsub L_Quest,11119,"Pest Control"," - Hunt 20 ^4d4dffThief Bug Eggs^000000 - "," - in the Prontera Culvert - "," - and bring 10 ^4d4dff"+getitemname(915)+"^000000. - ";
                case 7: callsub L_Quest,11120,"Muka Hunting"," - Hunt 20 ^4d4dff'Muka'^000000 - "," - south of Prontera. - ";
                case 8: callsub L_Quest,11121,"Familiar Hunting"," - Hunt 20 ^4d4dffFamiliar^000000 - "," - in the Culvert Sewers - "," - west of Prontera. - ";
                case 9: callsub L_Quest,11122,"Collect Feathers"," - Hunt 30 ^4d4dff'Peco Pecos'^000000 - "," - south of Prontera. - ";
                case 10: callsub L_Quest,11123,"Collect Poison Spores"," - Hunt 30 ^4d4dffPoison Spores^000000 - "," - inside the Geffen Tower and - "," - bring 5 ^4d4dff"+getitemname(7033)+"^000000. - ";
                case 11:
                    mes "See you later!";
                    close;
            }

        case 2: // Quests 26-40
            @sub = 2;
L_Quests_2:
            mes .n$;
            if ((BaseLevel < 26) || (BaseLevel > 40)) {
                mes "Your level is not qualified. You can not do these missions.";
                close;
            }
            mes "Hunting Mission details:";
            switch(select("Hunting Poison Spore:Hunting Smokie:Hunting Elder Willow:Hunting Coco:Hunting Thara Frog:Cancel")) {
                case 1: callsub L_Quest,8266,"Hunting Poison Spore","Hunt 10 Poison Spores";
                case 2: callsub L_Quest,8267,"Hunting Smokie","Hunt 10 Smokies";
                case 3: callsub L_Quest,8268,"Hunting Elder Willow","Hunt 10 Elder Willows";
                case 4: callsub L_Quest,8269,"Hunting Coco","Hunt 10 Cocos";
                case 5: callsub L_Quest,8270,"Hunting Thara Frog","Hunt 10 Thara Frogs";
                case 6:
                    mes "See you later!";
                    close;
            }

        case 3: // Quests 41-55
            @sub = 3;
L_Quests_3:
            mes .n$;
            if ((BaseLevel < 41) || (BaseLevel > 55)) {
                mes "Your level is not qualified. You can not do these missions.";
                close;
            }

            mes "Hunting Mission details:";
            switch(select("Thara Frog Hunting:Cruiser Hunting:Kukre Hunting:Orc Baby Hunting:Orc Warrior Hunting:Vadon Hunting:Megalodon Hunting:Marse Hunting:Cornutus Hunting:Myst Hunting:Shellfish Hunting:Marine Sphere Hunting:Phen Hunting:Orc Skeleton Hunting:Zenorc Hunting:Mummy Hunting:Cancel")) {
                case 1: callsub L_Quest,12072,"Thara Frog Hunting",9600,800,"Have you seen a red frog? It is called Thara Frog and it's very rare. We are trying to verify where it inhabits. So please hunt 20 Thara Frogs.";
                case 2: callsub L_Quest,12073,"Cruiser Hunting",7200,580,"I heard of some toys attacking people. It is ridiculous! Let's show them our power! We have to hunt 15 Cruisers!";
                case 3: callsub L_Quest,12074,"Kukre Hunting",15750,6200,"Someone got robbed near the beach! The possible suspect is a criminal monster called Kukre. Please hunt 30 Kukre.";
                case 4: callsub L_Quest,12075,"Orc Baby Hunting",7875,610,"Orc Babies are getting more violent these days. Please hunt 15 Orc Babies.";
                case 5: callsub L_Quest,12076,"Orc Warrior Hunting",11100,5600,"Orc Warriors are increasing their aggression. Please hunt 20 Orc Warriors.";
                case 6: callsub L_Quest,12077,"Vadon Hunting",8550,780,"Have you seen crabs with thick shells? They are Vadons. Please hunt 15 Vadons.";
                case 7: callsub L_Quest,12078,"Megalodon Hunting",17100,6800,"Dead fish are all around the beach and it is getting worse. Please hunt 30 Megalodon.";
                case 8: callsub L_Quest,12079,"Marse Hunting",9000,800,"Can you hunt Marse? I need 15 Marse for my study. Please help me.";
                case 9: callsub L_Quest,12080,"Cornutus Hunting",12300,5800,"An idiot Cornutus bit the Mayor's foot. The Mayor is upset so we need to hunt 20 Cornutus to make him happy!";
                case 10: callsub L_Quest,12081,"Myst Hunting",9900,880,"People are freaking out because of Myst. It looks like a ghost so, it scares people. Please hunt 15 Myst.";
                case 11: callsub L_Quest,12082,"Shellfish Hunting",20250,9600,"Don't ask why, but please hunt 30 Shellfish. It is a secret mission!";
                case 12: callsub L_Quest,12083,"Marine Sphere Hunting",10350,5000,"Marine Sphere? Do you know what a Marine Sphere is? I got a mission for you to hunt 15 Marine Sphere, so please do so.";
                case 13: callsub L_Quest,12084,"Phen Hunting",13800,4800,"The mayor wants to eat a delicious fish dish. Phen will be the perfect ingredient for it. Please hunt 20 Phen!";
                case 14: callsub L_Quest,12085,"Orc Skeleton Hunting",11025,3600,"Dead Orc monsters got back to our town and they've revived as Orc Skeletons. We are in chaos! Please hunt 15 Orc Skeleton.";
                case 15: callsub L_Quest,12086,"Zenorc Hunting",22500,8000,"Some weird monsters called Zenorc are attacking us. Please hunt 30 Zenorc.";
                case 16: callsub L_Quest,12087,"Mummy Hunting",11250,3600,"Be prepared! It is a cruel mission! Hunt 15 Mummies!! I tried once, but I couldn't succeed. It is too scary!";
                case 17:
                    mes "See you later!";
                    close;
            }
        case 4: // Quests 56-70
            @sub = 4;
L_Quests_4:
            mes .n$;
            if ((BaseLevel < 56) || (BaseLevel > 70)) {
                mes "Your level is not qualified. You can not do these missions.";
                close;
            }

            mes "Hunting Mission details:";
            switch(select("What is this bandage for?:Dangerous Alligators:That wasn't a mermaid...:Hunt Wild Boar:A Woman's Grudge:Puppet Master's Agony:Tiresome Flies:Dangerous Munak:Cancel")) {
                case 1: callsub L_Quest,3250,"What is this bandage for?",15000,5000," - Hunt 30 ^4d4dff'Mummy'^000000 - "," - Collect 30 ^4d4dff'"+getitemname(930)+"'^000000 - ";
                case 2: callsub L_Quest,3251,"Dangerous Alligators",16000,6000," - Hunt 30 ^4d4dff'Alligator'^000000 - ";
                case 3: callsub L_Quest,3252,"That wasn't a mermaid...",17000,8000," - Hunt 30 ^4d4dff'Merman'^000000 - ";
                case 4: callsub L_Quest,3255,"Hunt Wild Boar",16000,7000," - Hunt 30 ^4d4dff'Savage'^000000 - ";
                case 5: callsub L_Quest,3257,"A Woman's Grudge",17000,8000," - Hunt 30 ^4d4dff'Sohee'^000000 - ";
                case 6: callsub L_Quest,3259,"Puppet Master's Agony",17000,7000," - Hunt 30 ^4d4dff'Marionette'^000000 - "," - Collect 30 ^4d4dff'"+getitemname(1060)+"'^000000 - ";
                case 7: callsub L_Quest,3260,"Tiresome flies",16000,6000," - Hunt 30 ^4d4dff'Hunter Fly'^000000 - ";
                case 8: callsub L_Quest,3261,"Dangerous Munak",16000,7000," - Hunt 30 ^4d4dff'Munak'^000000 - ";
                case 9:
                    mes "See you later!";
                    close;
            }
        case 5: // Quests 71-85
            @sub = 5;
L_Quests_5:
            mes .n$;
            if ((BaseLevel < 71) || (BaseLevel > 85)) {
                mes "Your level is not qualified. You can not do these missions.";
                close;
            }

            mes "Hunting Mission details:";
            switch(select("Hunt 10 Requiems:Hunt 10 Marduks:Hunt 10 Pasanas:Hunt 10 Dark Frames:Hunt 10 Evil Druids:Hunt 10 Wraiths:Hunt 10 Raydric Archers:Hunt 20 Grand Pecos:Hunt 20 Sleepers:Hunt 20 Goats:Hunt 20 Harpies:Hunt 15 Clocks:Hunt 15 Punks:Hunt 15 Ridewords:Hunt 15 Kikimoras:Hunt 15 Miyabi Dolls:Hunt 15 Mi Gaos:Cancel")) {
                case 1: callsub L_Quest,10107,"Hunt 10 Requiems",15000,0," - Hunt 10 ^4d4dff'Requiem'^000000 - ";
                case 2: callsub L_Quest,10108,"Hunt 10 Marduks",15000,0," - Hunt 10 ^4d4dff'Marduks'^000000 - ";
                case 3: callsub L_Quest,10109,"Hunt 10 Pasanas",15000,0," - Hunt 10 ^4d4dff'Pasanas'^000000 - ";
                case 4: callsub L_Quest,10110,"Hunt 10 Dark Frames",20000,0," - Hunt 10 ^4d4dff'Dark Frames'^000000 - ";
                case 5: callsub L_Quest,10111,"Hunt 10 Evil Druids",20000,0," - Hunt 10 ^4d4dff'Evil Druids'^000000 - ";
                case 6: callsub L_Quest,10112,"Hunt 10 Wraiths",20000,0," - Hunt 10 ^4d4dff'Wraiths'^000000 - ";
                case 7: callsub L_Quest,10113,"Hunt 10 Raydric Archers",20000,0," - Hunt 10 ^4d4dff'Raydric Archers'^000000 - ";
                case 8: callsub L_Quest,10114,"Hunt 20 Grand Pecos",30000,0," - Hunt 20 ^4d4dff'Grand Pecos'^000000 - ";
                case 9: callsub L_Quest,10115,"Hunt 20 Sleepers",30000,0," - Hunt 20 ^4d4dff'Sleepers'^000000 - ";
                case 10: callsub L_Quest,10116,"Hunt 20 Goats",30000,0," - Hunt 20 ^4d4dff'Goats'^000000 - ";
                case 11: callsub L_Quest,10117,"Hunt 20 Harpies",30000,0," - Hunt 20 ^4d4dff'Harpies'^000000 - ";
                case 12: callsub L_Quest,10118,"Hunt 15 Clocks before it breaks",25000,0," - Hunt 15 ^4d4dff'Clocks'^000000 - ";
                case 13: callsub L_Quest,10119,"Hunt 15 Punks before it breaks",25000,0," - Hunt 15 ^4d4dff'Punks'^000000 - ";
                case 14: callsub L_Quest,10120,"Hunt 15 Ridewords before it breaks",25000,0," - Hunt 15 ^4d4dff'Ridewords'^000000 - ";
                case 15: callsub L_Quest,10121,"Hunt 15 Kikimoras in Moscovia",30000,0," - Hunt 15 ^4d4dff'Kikimoras'^000000 - ";
                case 16: callsub L_Quest,10122,"Hunt 15 Miyabi Dolls in Amatsu",30000,0," - Hunt 15 ^4d4dff'Miyabi Dolls'^000000 - ";
                case 17: callsub L_Quest,10123,"Hunt 15 Mi Gaos in Luoyang",30000,0," - Hunt 15 ^4d4dff'Mi Gaos'^000000 - ";
                case 18:
                    mes "See you later!";
                    close;
            }
        case 6: // Quests 86-90
            @sub = 6;
L_Quests_6:
            mes .n$;
            if ((BaseLevel < 86) || (BaseLevel > 90)) {
                mes "Your level is not qualified. You can not do these missions.";
                close;
            }

            mes "Hunting Mission details:";
            mes "In these missions you're required to hunt down at least 30 exemplars of the given monster.";
            switch(select("Hunt Dragon Tail:Hunt Spring Rabbit:Hunt Pest:Hunt Bathory:Hunt Alarm:Hunt Baba Yaga:Hunt Yao Jun:Hunt Firelock Soldier:Hunt Zipper Bear:Hunt Ground Petite:Hunt Rafflesia:Hunt Venomous:Hunt Pitman:Hunt Yellow Novus:Cancel")) {
                case 1: callsub L_Quest,4167,"Hunt 30 Dragon Tail",76000,0,"There is a monster that only can be found on ^8B4513Turtle Island^000000.","s";
                case 2: callsub L_Quest,4168,"Hunt 30 Spring Rabbit",82000,0,"There is a monster that only can be found on ^8B4513Turtle Island^000000.","s";
                case 3: callsub L_Quest,4169,"Hunt 30 Pest",82000,0,"There is a monster that only can be found on ^8B4513Turtle Island^000000.","s";
                case 4: callsub L_Quest,4170,"Hunt 30 Bathory",72000,0,"The Clock Tower Dungeon is full of dangerous monsters.";
			    case 5: callsub L_Quest,4171,"Hunt 30 Alarm",76000,0,"The Clock Tower Dungeon is full of dangerous monsters.";
                case 6: callsub L_Quest,4172,"Hunt 30 Baba Yaga",72000,0,"The witch Baba Yaga can be found in the outskirts of Moscovia.";
                case 7: callsub L_Quest,4173,"Hunt 30 Yao Jun",117000,0,"There are human-like monsters that roam around the dungeon in Luoyang.";
                case 8: callsub L_Quest,4174,"Hunt 30 Firelock Soldier",82000,0,"There are human-like monsters that roam around the dungeon in Amatsu.","s";
                case 9: callsub L_Quest,4175,"Hunt 30 Zipper Bear",120000,0,"There are bear monsters swarming in the Kunlun dungeon.";
                case 10: callsub L_Quest,4176,"Hunt 30 Ground Petite",72000,0,"There are dragon type monsters swarming the western region of Geffen.";
                case 11: callsub L_Quest,4177,"Hunt 30 Rafflesia",72000,0,"There are plant type monsters infesting the fields of Lighthalzen.";
                case 12: callsub L_Quest,4178,"Hunt 30 Venomous",72000,0,"There are formless monsters floating around the fields of Einbroch.";
                case 13: callsub L_Quest,4179,"Hunt 30 Pitman",86000,0,"There are undead monsters pushing a cart around the fields and dungeons of Einbroch.";
                case 14: callsub L_Quest,4180,"Hunt 30 Yellow Novus",80000,0,"There are yellow dragon type monsters terrorizing the fields of Hugel.";
                case 15:
                    mes "See you later!";
                    close;
            }
        case 7: // Quests 91-99
            @sub = 7;
L_Quests_7:
            mes .n$;
            if ((BaseLevel < 91) || (BaseLevel > 99)) {
                mes "Your level is not qualified. You can not do these missions.";
                close;
            }

            mes "Hunting Mission details:";
            mes "In these missions you're required to hunt down at least 30 exemplars of the given monster.";
            switch(select("^0000FFSolider^000000:^0000FFFreezer^000000:^0000FFHeater^000000:^0000FFInjustice^000000:^0000FFRybio^000000:^0000FFDark Priest^000000:^0000FFStapo^000000:^0000FFRoween^000000:^0000FFSiroma^000000:0000FFShinobi^000000:^0000FFEvil Nymph^000000:^0000FFDeviruchi^000000:^0000FFMineral^000000:^0000FFKaho^000000:^0000FFNeraid^000000:^0000FFDisguise^000000:Cancel")) {
                case 1: callsub L_Quest,4181,"Hunt 30 Solider",90000,0,"There is a monster that only can be found on ^8B4513Turtle Island^000000.";
                case 2: callsub L_Quest,4182,"Hunt 30 Freezer",94000,0,"There is a monster that only can be found on ^8B4513Turtle Island^000000.";
                case 3: callsub L_Quest,4183,"Hunt 30 Heater",114000,0,"There is a monster that only can be found on ^8B4513Turtle Island^000000.";
     			case 4: callsub L_Quest,4184,"Hunt 30 Injustice",96000,0,"There is a monster only found in ^8B4513Glast Heim prison^000000.";
			    case 5: callsub L_Quest,4185,"Hunt 30 Rybio",96000,0,"There is a monster only found in ^8B4513Glast Heim prison^000000.";
		    	case 6: callsub L_Quest,4186,"Hunt 30 Dark Priest",146000,0,"There is a monster only found in ^8B4513Glast Heim prison^000000.";
                case 7: callsub L_Quest,4187,"Hunt 30 Stapo",96000,0,"There is a monster only found in ^8B4513Veins^000000.";
                case 8: callsub L_Quest,4188,"Hunt 30 Roween",102000,0,"There is a monster only found in ^8B4513Rachel^000000.";
                case 9: callsub L_Quest,4189,"Hunt 30 Siroma",110000,0,"There is a monster only found in ^8B4513Ice Dungeon^000000.";
                case 10: callsub L_Quest,4190,"Hunt 30 Shinobi",102000,0,"There is a monster only found in ^8B4513Amatsu Dungeon^000000.";
                case 11: callsub L_Quest,4191,"Hunt 30 Evil Nymph",108000,0,"There is a monster only found in ^8B4513Kunlun Dungeon^000000.";
                case 12: callsub L_Quest,4192,"Hunt 30 Deviruchi",110000,0,"There is a monster only found in ^8B4513Geffen Dungeon^000000.";
                case 13: callsub L_Quest,4193,"Hunt 30 Mineral",138000,0,"There is a monster only found in ^8B4513Einbech Dungeon^000000.";
                case 14: callsub L_Quest,4194,"Hunt 30 Kaho",118000,0,"There is a monster found in ^8B4513Nogg Road Magma 1^000000.";
                case 15: callsub L_Quest,4195,"Hunt 30 Neraid",96000,0,"There is a monster only found in ^8B4513Comodo Dungeon^000000.";
                case 16: callsub L_Quest,4196,"Hunt 30 Disguise",134000,0,"There is a monster only found in ^8B4513Niflheim^000000.";
                case 17:
                    mes "See you later!";
                    close;
            }
    }

L_Quest:
    .@quest_id = getarg(0);
    // Again, we need to treat the ranges separately...
    if(.@quest_id >= 3250 && .@quest_id <= 3261) // Quests 56-70
        .@quest_status = checkquest(.@quest_id+20,PLAYTIME);
    else if(.@quest_id >= 4167 && .@quest_id <= 4180) // Quests 86-90
        .@quest_status = checkquest(.@quest_id+31,PLAYTIME);
    else if(.@quest_id >= 4181 && .@quest_id <= 4196) // Quests 91-99
        .@quest_status = checkquest(.@quest_id+31,PLAYTIME);
    else if(.@quest_id >= 8266 && .@quest_id <= 8270) // Quests 26-40
        .@quest_status = checkquest(.@quest_id+100,PLAYTIME);
    else if(.@quest_id >= 10107 && .@quest_id <= 10123) // Quests 71-85
        .@quest_status = checkquest(.@quest_id+20,PLAYTIME);
    else if(.@quest_id >= 11114 && .@quest_id <= 11123) // Quests 11-25
        .@quest_status = checkquest(.@quest_id+10,PLAYTIME);
    else if(.@quest_id >= 12072 && .@quest_id <= 12087) // Quests 41-55
        .@quest_status = checkquest(.@quest_id+300,PLAYTIME);


    if (.@quest_status == 0 || .@quest_status == 1) {
        mes .n$;
        mes "Mission ^4d4dff"+ getarg(1) +"^000000";
        mes " is already finished for today.";
        next;
        redirect(@sub);
    }

    if(checkquest(.@quest_id,PLAYTIME) > -1) {
        mes .n$;
        mes "Mission ^4d4dff"+ getarg(1) +"^000000";
        mes " is already in your quest log.";
        next;
        redirect(@sub); 
    } else {
        mes .n$;
        mes "Mission '"+ getarg(1) +"'";
        mes "Base Exp: '"+ getarg(2,0) +"'";
        mes "Job Exp: '"+ getarg(3,0) +"'";
        mes getitemname($@HUNTING_MEDAL) + ": '" + "1x'";
        for ( .@i = 4; .@i < getargcount(); .@i++ )
            mes getarg(.@i);

        if (select("I will do this mission.:Look for other missions.") == 2) {
            clear;
            mes .n$;
            mes "Let's search for";
            mes "other missions.";
            next;
            redirect(@sub);
        }

        setquest getarg(0);
        next;
        redirect(@sub);
    }
    end; 

OnInit:
    .n$ = "^FF0000[ Hunting Quests ]^000000";
    setarray .quests_1[0],11114,11115,11116,11117,11118,11119,11120,11121,11122,11123; // 11-25
    setarray .quests_2[0],8266,8267,8268,8269,8270; // 26-40
    setarray .quests_3[0],12072,12073,12074,12075,12076,12077,12078,12079,12080,12081,12082,12083,12084,12085,12086,12087; // 41-55
    setarray .quests_4[0],3250,3251,3252,3255,3257,3259,3260,3261; // 56-70
    setarray .quests_5[0],10107,10108,10109,10110,10111,10112,10113,10114,10115,10116,10117,10118,10119,10120,10121,10122,10123; // 71-85
    setarray .quests_6[0],4167,4168,4169,4170,4171,4172,4173,4174,4175,4176,4177,4178,4179,4180; // 86-90
    setarray .quests_6[0],4181,4182,4183,4184,4185,4186,4187,4188,4189,4190,4191,4192,4193,4194,4195,4196; // 91-99
    end;


    function redirect {
        switch(getarg(0)){
            case 1: goto L_Quests_1; break;
            case 2: goto L_Quests_2; break;
            case 3: goto L_Quests_3; break;
            case 4: goto L_Quests_4; break;
            case 5: goto L_Quests_5; break;
            case 6: goto L_Quests_6; break;
            case 7: goto L_Quests_7; break;
        }
    }



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

// Duplicates
prontera,164,169,3	duplicate(#HuntingQuests)	Hunting Quests#prt	859
geffen,111,65,6	duplicate(#HuntingQuests)	Hunting Quests#gef	859
morocc,183,95,3	duplicate(#HuntingQuests)	Hunting Quests#moc	859
payon,164,87,7	duplicate(#HuntingQuests)	Hunting Quests#pay	859
aldebaran,131,103,5	duplicate(#HuntingQuests)	Hunting Quests#ald	859
alberta,128,45,2	duplicate(#HuntingQuests)	Hunting Quests#alb	859
yuno,175,75,4	duplicate(#HuntingQuests)	Hunting Quests#yun	859
hugel,100,119,1	duplicate(#HuntingQuests)	Hunting Quests#hug	859
lighthalzen,142,112,4	duplicate(#HuntingQuests)	Hunting Quests#lhz	859
rachel,129,145,5	duplicate(#HuntingQuests)	Hunting Quests#rac	859
brasilis,180,221,7	duplicate(#HuntingQuests)	Hunting Quests#bra	859
louyang,228,99,3	duplicate(#HuntingQuests)	Hunting Quests#lou	859
ayothaya,221,191,4	duplicate(#HuntingQuests)	Hunting Quests#ayo	859