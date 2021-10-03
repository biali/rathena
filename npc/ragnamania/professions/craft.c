-	script	craftsman	-1,{
	end;

OnInit:
	// Player Settings
									//				,wlvl 1				   ,wlvl 2			  		  ,wlvl 3		 , wlvl 4
	set .Xp2LvlUp, 1000;			  //Headgear	,Accessory	 ,shoes	   ,garment ,shields  ,chest  ,more armors   , TODO:MVP SETS
	setarray .CraftsmanTitle$[0],		"Apprentice","Journeyman","Skilled","Expert","Artisan","Master","Grand Master","Illustrious";
	setarray .Craftsman_Lvl[0],	                   0,           1,        2,       3,        4,       5,             6,            7; // * Required Lvl to Work on It
	setarray .Craftsman_Exp[0],   	              50,          40,       20,      10,        8,       5,             4,            2; // * Experience gained per craft


	// Headgear
	// 2285, 0, 256,Apple of Archer
	// 2211, 0, 256,Bandana
	// 5172, 0, 256,Beret
	// 5017, 0, 256,Bone Helm
	// 2227, 1, 256,Cap
	// 2221, 1, 256,Hat
	// 2229, 1, 256,Helm
	// 5045, 0, 256,Magician Hat
	// 2289, 0, 256,Poo Poo Hat
	// 2252, 0, 256,Wizard Hat
	// 2286, 0, 512,Elven Ears
	// 5014, 0, 512,Fin Helm
	// 2225, 1, 768,Goggles

	// 10 eluniums			  985
	// 20 fine animal pelt	30350
	// 20 fabric			 1059
	setarray .Craftsman_HG$[0],2285,2211,5172,5017,2227,2221,2229,5045,2289,2252,2286,5014,2225;
	setarray .Craftsman_HGx[0],   3,   1,   4,   2,   1,   1,   1,   2,   2,   3,   5,   2,   1;
	setarray .Craftsman_HGr[0],985,10,30350,20,1059,20; // resources id,qty...


	// Accessories
		// 2743, 0, 136,Angelic Ring
		// 2656, 0, 136,Armor Charm
		// 2747, 0, 136,Black Cat
		// 2619, 0, 136,Bow Thimble
	// 2727, 0, 136,Bowman Scarf
	// 2625, 1, 136,Brooch
	// 2617, 0, 136,Celebrant's Mitten
	// 2607, 1, 136,Clip
	// 2746, 0, 136,Cold Heart
		// 2728, 1, 136,Cursed Hand
	// 2748, 0, 136,Cursed Star
		// 2729, 1, 136,Diabolus Ring
	// 2622, 1, 136,Earring
	// 2703, 1, 136,Expert Ring
	// 2614, 0, 136,Eye of Dullahan
	// 2783, 1, 136,Eye Stone Ring
	// 2624, 1, 136,Glove
	// 2652, 0, 136,Goddess of Fortune's Cursed Brooch
	// 2726, 0, 136,Icarus Wings
	// 2719, 0, 136,Iron Wrist
	// 2680, 0, 136,Lesser Elemental Ring
		// 2716, 1, 136,Librarian Glove
		// 2749, 1, 136,Linen Glove
		// 2718, 1, 136,Lunatic Brooch
	// 2618, 0, 136,Matyr's Leash
	// 2603, 0, 136,Necklace
		// 2701, 1, 136,Orleans's Glove
	// 2745, 1, 136,Pinguicula Corsage
	// 2717, 0, 136,Pocket Watch
	// 2621, 1, 136,Ring
		// 2620, 0, 136,Rogue's Treasure
	// 2626, 1, 136,Rosary
	// 2654, 0, 136,Shinobi Sash
		// 2744, 0, 136,Sprint Ring

	// Journeyman - Accessory
	// 12 eluniums			  985
	//  2 sardonyx			  725
	// 20 silk				30400
	setarray .Craftsman_AC$[0],2727,2625,2617,2607,2746,2748,2622,2703,2614,2783,2783,2624,2652,2726,2719,2680,2618,2603,2745,2717,2621,2626,2654;
	setarray .Craftsman_ACp$[0],2743,2656,2747,2619,2727,2625,2617,2607,2746,2728,2748,2729,2622,2703,2614,2783,2624,2652,2726,2719,2680,2716,2749,2718,2618,2603,2701,2745,2717,2621,2620,2626,2654,2744;
	setarray .Craftsman_ACx[0],    2,   3,   3,   3,   1,   1,   1,   1,   1,   2,   1,   4,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   2,   2,   1,   1,   4,   1,   1,   1,   2,   1,   1,   3;
	setarray .Craftsman_ACr[0],985,12,725,2,30400,20; // resources id,qty...


	// footgear
		// 2420, 1, 64,Angel's Reincarnation
	// 2425, 0, 64,Black Leather Boots
	// 2406, 1, 64,Boots
	// 2417, 0, 64,Fricco's Shoes
		// 2419, 0, 64,Goibne's Greaves
	// 2411, 0, 64, Greaves
	// 2422, 1, 64,High Fashion Sandals
		// 2409, 0, 64,High Heels
	// 2402, 1, 64,Sandals
		// 2426, 0, 64,Shadow Walk
	// 2404, 1, 64,Shoes
		// 2440, 1, 64,Sprint Shoes
	// 2424, 1, 64,Tidal Shoes
	// 2418, 0, 64,Vidar's Boots

	// Skilled - shoes
	// 16 thick animal pelt 30351
	// 12 cotton			30401
	// 14 Heart of * (use arrayindex % 4. depending on the rest of the division (0 to 3) will determinate the heart necessary)
	setarray .Craftsman_SH$[0] ,2425,2406,2417,2411,2422,2402,2404,2424,2418;
	setarray .Craftsman_SHp$[0],2420,2425,2406,2417,2419,2411,2422,2409,2402,2426,2404,2440,2424,2418;
	setarray .Craftsman_SHx[0] ,   3,   3,   1,   2,   4,   2,   2,   3,   1,   4,   1,   5,   3,   2;
	setarray .Craftsman_SHr[0] ,30351,16,30401,12,-1,14; // resources id,qty...


	// garment
	// 2507, 0, 4,Ancient Cape
	// 2521, 1, 4,Angelic Cardigan
		// 2537, 1, 4,Diabolus Manteau
	// 2527, 1, 4,Dragon Breath
		// 2516, 0, 4,Falcon Muffler
	// 2520, 0, 4,Goibne's Spaulders
	// 2502, 1, 4,Hood
	// 2544, 1, 4,Leather of Tendrilion
	// 2506, 1, 4,Manteau
		// 2532, 1, 4,Mithril Magic Cape
		// 2518, 0, 4,Morpheus's Shawl
	// 2504, 1, 4,Muffler
	// 2545, 1, 4,Musika
	// 2514, 1, 4,Pauldron
	// 2508, 0, 4,Ragamuffin Manteau
	// 2530, 1, 4,Rider Insignia
		// 2536, 1, 4,Skin of Ventus
	// 2531, 1, 4,Ulfhedinn
	// 2522, 0, 4,Undershirt
	// 2517, 0, 4,Vali's Manteau
		// 2528, 1, 4,Wool Scarf
	
	// Expert - garment
	// 22 fine animal pelt 30350
	//  4 emerald        	 721
	// 18 Heart of * (use arrayindex % 4. depending on the rest of the division (0 to 3) will determinate the heart necessary)
	setarray .Craftsman_GA$[0] ,2507,2521,2527,2520,2502,2544,2506,2504,2545,2514,2508,2530,2531,2522,2517;
	setarray .Craftsman_GAp$[0],2507,2521,2537,2527,2516,2520,2502,2544,2506,2532,2518,2504,2545,2514,2508,2530,2536,2531,2522,2517,2528;
	setarray .Craftsman_GAx[0] ,   2,   2,   4,   3,   3,   2,   1,   3,   1,   4,   4,   1,   2,   2,   1,   2,   4,   2,   2,   3,   5;
	setarray .Craftsman_GAr[0] ,30350,22,721,4,-1,18; // resources id,qty...


	// Shields
	// 2116, 1, 32,Angelic Guard
		// 2138, 1, 32,Bradium Shield
	// 2104, 1, 32,Buckler
		// 2130, 1, 32,Cross Shield
		// 2129, 0, 32,Exorcism Bible
	// 2102, 1, 32,Guard
	// 2109, 0, 32,Memory Book
	// 2108, 1, 32,Mirror Shield
		// 2123, 1, 32,Orleans's Server
		// 2122, 0, 32,Platinum Shield
		// 2111, 0, 32,Sacred Mission
		// 2135, 1, 32,Shadow Guard
	// 2106, 1, 32,Shield
		// 2134, 1, 32,Shield of Naga
	// 2114, 1, 32,Stone Buckler
	// 2125, 1, 32,Strong Shield
		// 2124, 1, 32,Thorny Buckler
		// 2133, 1, 32,Tournament Shield
		// 2115, 1, 32,Valkyrja's Shield

	// Artisan - shields
	// 18 Eluniums			   985
	// 20 Exquisite ani pelt 30400
	// 25 Heart of * (use arrayindex % 4. depending on the rest of the division (0 to 3) will determinate the heart necessary)
	setarray .Craftsman_SD$[0] ,2116,2104,2102,2109,2108,2106,2114,2125;
	setarray .Craftsman_SDp$[0],2116,2138,2104,2130,2129,2102,2109,2108,2123,2122,2111,2135,2106,2134,2114,2125,2124,2133,2115;
	setarray .Craftsman_SDx[0] ,   1,   5,   1,   3,   3,   1,   1,   1,   4,   5,   4,   4,   1,   5,   1,   1,   3,   5,   4;
	setarray .Craftsman_SDr[0] ,985,18,30400,20,-1,25; // resources id,qty...


	// chest
	// 2306, 1, 16,Adventurer's Suit
		// 2355, 1, 16,Angelic Protection
		// 2389, 1, 16,Armor of Naga
	// 2315, 1, 16,Chain Mail
		// 2386, 0, 16,Chameleon Armor
	// 2310, 1, 16,Coat
	// 2366, 1, 16,Divine Cloth
	// 2316, 0, 16,Full Plate
	// 2354, 0, 16,Goibne's Armor
		// 2390, 1, 16,Improved Tights
	// 2304, 1, 16,Jacket
	// 2388, 1, 16,Kandura
	// 2391, 1, 16,Life Link
	// 2344, 0, 16,Lucius's Fierce Armor of Volcano
	// 2308, 1, 16,Mantle
		// 2364, 1, 16,Meteo Plate Armor
	// 2311, 1, 16,Mink Coat
		// 2337, 0, 16,Ninja Suit
		// 2353, 1, 16,Odin's Blessing
		// 2365, 1, 16,Orleans's Gown
	// 2313, 1, 16,Padded Armor
	// 2326, 1, 16,Saint's Robe
		// 2324, 1, 16,Scapulare
	// 2322, 1, 16,Silk Robe
	// 2333, 1, 16,Silver Robe
		// 2367, 1, 16,Sniping Suit
	// 2387, 1, 16,Sprint Mail
		// 2336, 1, 16,Thief Clothes
		// 2331, 1, 16,Tights
	// 2329, 1, 16,Wooden Mail

	// Master - Chest
	// 22 Eluniums			  985
	// 30 Silk				30400
	// 25 Heart of * (use arrayindex % 4. depending on the rest of the division (0 to 3) will determinate the heart necessary)
	setarray .Craftsman_CH$[0] ,2306,2315,2310,2366,2316,2354,2304,2388,2391,2344,2308,2311,2313,2339,2326,2322,2333,2387,2329;
	setarray .Craftsman_CHp$[0],2306,2355,2389,2315,2386,2310,2366,2316,2354,2390,2304,2388,2391,2344,2308,2364,2311,2337,2353,2365,2313,2326,2324,2322,2333,2367,2387,2336,2331,2329;
	setarray .Craftsman_SDx[0] ,   2,   2,   4,   1,   4,   1,   2,   4,   2,   5,   1,   1,   2,   3,   1,   5,   3,   4,   3,   5,   1,   2,   3,   1,   1,   4,   1,   3,   3,   1;
	setarray .Craftsman_SDr[0] ,985,22,30400,30,-1,25; // resources id,qty...


	// weapons lvl 1
	// 13011,	3,	1,	Asura
	// 1302,	4,	1,	Axe
	// 1352,	4,	1,	Battle Axe
	// 1108,	4,	1,	Blade
	// 1702,	4,	1,	Bow
	// 13150,	3,	1,	Branch
	// 1502,	4,	1,	Club
	// 1705,	4,	1,	Composite Bow
	// 1205,	4,	1,	Cutter
	// 1105,	4,	1,	Falchion
	// 1402,	4,	1,	Javelin
	// 1117,	4,	1,	Katana
	// 1202,	4,	1,	Knife
	// 1505,	4,	1,	Mace
	// 1208,	4,	1,	Main Gauche
	// 1408,	4,	1,	Pike
	// 1602,	4,	1,	Rod
	// 1951,	4,	1,	Rope
	// 13101,	2,	1,	Six Shooter
	// 1405,	4,	1,	Spear
	// 1264,	4,	1,	Specialty Jur
	// 1902,	4,	1,	Violin
	// 1802,	4,	1,	Waghnak	

	// Journeyman - Weapon lv 1
	//  6 oridecon			  984
	//  3 ruby				  723
	// 20 thick animal pelt	30400
	setarray .Craftsman_W1$[0],13011,1302,1352,1108,1702,13150,1502,1705,1205,1105,1402,1117,1202,1505,1208,1408,1602,1951,13101,1405,1264,1902,1802;
	setarray .Craftsman_W1x[0],    1,   1,   2,   1,   2,    1,   1,   2,   1,   1,   1,   2,   1,   3,   2,   1,   2,   1,    1,   1,   1,   2,   1;
	setarray .Craftsman_W1r[0],984,6,723,3,30400,20; // resources id,qty...


	// weapons lvl 2
	// 1155,	3,	2,	Bastard Sword
	// 1485,	4,	2,	Battle Fork
	// 1550,	3,	2,	Book
	// 1519,	2,	2,	Chain
	// 13103,	2,	2,	Crimson Bolt
	// 1711,	3,	2,	Crossbow
	// 13152,	2,	2,	Cyclone
	// 1214,	3,	2,	Dagger
	// 13034,	2,	2,	Desert Twilight
	// 13161,	1,	2,	Destroyer
	// 1211,	3,	2,	Dirk
	// 13157,	1,	2,	Drifter
	// 13153,	1,	2,	Dusk
	// 1511,	3,	2,	Flail
	// 13104,	1,	2,	Garrison
	// 13156,	0,	2,	Gate Keeper
	// 1455,	3,	2,	Glaive
	// 1708,	3,	2,	Great Bow
	// 1452,	3,	2,	Guisarme
	// 1355,	3,	2,	Hammer
	// 13008,	1,	2,	Jitte
	// 1251,	3,	2,	Jur
	// 1906,	3,	2,	Lute
	// 1904,	3,	2,	Mandolin
	// 13013,	2,	2,	Murasame
	// 1458,	2,	2,	Partizan
	// 1111,	3,	2,	Rapier
	// 1125,	3,	2,	Ring Pommel Saber
	// 13035,	4,	2,	Sandstorm
	// 1114,	3,	2,	Scimitar
	// 1152,	3,	2,	Slayer
	// 1508,	3,	2,	Smasher
	// 1608,	3,	2,	Staff
	// 1217,	3,	2,	Stiletto
	// 1806,	3,	2,	Studded Knuckles
	// 1605,	3,	2,	Wand
	// 1307,	0,	2,	Windhawk

	// Expert - weapon lvl 2 --------
	//  8 oridecon			   984
	// 10 exquisite ani pelt 30352
	//  8 Heart of * (use arrayindex % 4. depending on the rest of the division (0 to 3) will determinate the heart necessary)
	setarray .Craftsman_W2$[0],1155,1485,1550,1519,13103,1711,13152,1214,13034,13161,1211,13157,13153,1511,13104,13156,1455,1708,1452,1355,13008,1251,1906,1904,13013,1458,1111,1125,13035,1114,1152,1508,1608,1217,1806,1605,1307;
	setarray .Craftsman_W2x[0],   1,   1,   1,   1,    1,   1,    1,   1,    1,    1,   1,    1,    1,   1,    1,    1,   1,   1,   1,   1,    1,   1,   1,   1,    1,   1,   1,   1,    1,   1,   1,   1,   1,   1,   1,   1,   1;
	setarray .Craftsman_W2r[0],984,25,30352,30,-1,20; // resources id,qty...


	// weapons lvl 3
	// 1573,	2,	3,	Ancient Magic
	// 1715,	2,	3,	Arbalest
	// 1611,	2,	3,	Arc Wand
	// 1919,	1,	3,	Bass Guitar
	// 1375,	2,	3,	Berdysz
	// 1551,	2,	3,	Bible
	// 1553,	0,	3,	Book of Billows
	// 1556,	0,	3,	Book of Gust of Wind
	// 1554,	0,	3,	Book of Mother Earth
	// 1555,	0,	3,	Book of the Blazing Sun
	// 1162,	2,	3,	Broad Sword
	// 1730,	1,	3,	Burning Bow
	// 1914,	0,	3,	Burning Passion Guitar
	// 1358,	2,	3,	Buster
	// 13159,	1,	3,	Butcher
	// 1925,	3,	3,	Cello
	// 1246,	2,	3,	Cinquedea
	// 1810,	2,	3,	Claw
	// 1163,	0,	3,	Claymore
	// 1822,	4,	3,	Combo Battle Glove
	// 13004,	2,	3,	Cowardice Blade
	// 1647,	1,	3,	Croce Staff
	// 13038,	3,	3,	Dagger of Hunter
	// 1226,	2,	3,	Damascus
	// 1736,	3,	3,	Double Bound
	// 1732,	1,	3,	Earth Bow
	// 1820,	3,	3,	Electric Fist
	// 1971,	0,	3,	Electric Wire
	// 13414,	3,	3,	Elemental Sword
	// 1564,	2,	3,	Encyclopedia
	// 1615,	0,	3,	Evil Bone Wand
	// 1745,	2,	3,	Falken Blitz
	// 1812,	2,	3,	Finger
	// 1731,	1,	3,	Frozen Bow
	// 1967,	0,	3,	Gaia Whip
	// 1716,	2,	3,	Gakkung Bow
	// 1917,	0,	3,	Gentle Breeze Guitar
	// 1220,	3,	3,	Gladius
	// 13106,	0,	3,	Gold Lux
	// 1916,	0,	3,	Green Acre Guitar
	// 1908,	1,	3,	Guitar
	// 1733,	1,	3,	Gust Bow
	// 13015,	1,	3,	Hakujin
	// 1464,	2,	3,	Halberd
	// 1910,	2,	3,	Harp
	// 1625,	0,	3,	Healing Staff
	// 1825,	3,	3,	Horn of Hillslion
	// 13304,	2,	3,	Huuma Calm Mind
	// 1622,	2,	3,	Hypnotist's Staff
	// 1819,	3,	3,	Icicle Fist
	// 1966,	0,	3,	Icicle Whip
	// 13039,	2,	3,	Ivory Knife
	// 1483,	1,	3,	Ivory Lance
	// 1255,	1,	3,	Jamadhar
	// 1253,	2,	3,	Katar
	// 1256,	0,	3,	Katar of Frozen Icicle
	// 1259,	0,	3,	Katar of Piercing Wind
	// 1257,	0,	3,	Katar of Quaking
	// 1258,	0,	3,	Katar of Raging Blaze
	// 13006,	0,	3,	Khukri
	// 1284,	2,	3,	Krishna
	// 1646,	2,	3,	La'cryma Stick
	// 13170,	2,	3,	Lever Action Rifle
	// 1624,	2,	3,	Lich's Bone Wand
	// 1262,	0,	3,	Loki's Nail
	// 1915,	0,	3,	Loner's Guitar
	// 13164,	1,	3,	Long Barrel
	// 1723,	2,	3,	Luna Bow
	// 1544,	3,	3,	Lunakaligo
	// 1818,	3,	3,	Magma Fist
	// 1613,	0,	3,	Mighty Staff
	// 1514,	2,	3,	Morning Star
	// 1734,	0,	3,	Orc Archer Bow
	// 1304,	0,	3,	Orcish Axe
	// 1626,	0,	3,	Piercing Staff
	// 1239,	0,	3,	Poison Knife
	// 1417,	1,	3,	Pole Axe
	// 1572,	2,	3,	Principles of Magic
	// 1957,	1,	3,	Rante Whip
	// 1965,	0,	3,	Red Flame Whip
	// 1630,	0,	3,	Release of Wish
	// 13421,	1,	3,	Ruber
	// 1127,	3,	3,	Saber
	// 1821,	3,	3,	Seismic Fist
	// 1260,	0,	3,	Sharpened Legbone of Ghoul
	// 1968,	0,	3,	Skipping Rope
	// 1472,	0,	3,	Soul Staff
	// 1620,	1,	3,	Survivor's Rod
	// 1517,	1,	3,	Sword Mace
	// 13169,	2,	3,	Thunder P
	// 1147,	2,	3,	Town Sword
	// 1461,	3,	3,	Trident
	// 1120,	2,	3,	Tsurugi
	// 1361,	2,	3,	Two-Handed Axe
	// 1158,	2,	3,	Two-Handed Sword
	// 1311,	2,	3,	Vecer Axe
	// 1384,	2,	3,	Veteran Axe
	// 1548,	2,	3,	Veteran Hammer
	// 1614,	0,	3,	Wand of Occult
	// 1306,	1,	3,	War Axe
	// 13107,	2,	3,	Wasteland's Outlaw
	// 1980,	3,	3,	Whip of Balance

	// Grand-Master - Weapon lvl 3  and plus* armor pieces ------
	// 10 Oridecon			  984
	// 12 Heavy anim Pelt   30400
	// 14 Heart of * (use arrayindex % 4. depending on the rest of the division (0 to 3) will determinate the heart necessary)
	setarray .Craftsman_W3$[0],1573,1715,1611,1919,1375,1551,1553,1556,1554,1555,1162,1730,1914,1358,13159,1925,1246,1810,1163,1822,13004,1647,13038,1226,1736,1732,1820,1971,13414,1564,1615,1745,1812,1731,1967,1716,1917,1220,13106,916,1908,1733,13015,1464,1910,1625,1825,13304,1622,1819,1966,13039,1483,1255,1253,1256,259,1257,1258,3006,1284,1646,13170,1624,1262,1915,13164,1723,1544,1818,1613,1514,1734,1304,1626,1239,1417,1572,1957,1965,1630,13421,1127,1821,1260,1968,1472,1620,1517,13169,1147,1461,1120,1361,1158,1311,1384,1548,1614,1306,13107,1980;
	setarray .Craftsman_W3x[0],   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,    1,   1,   1,   1,   1,   1,    1,   1,    1,   1,   1,   1,   1,   1,    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,    1,   1,   1,   1,   1,   1,   1,   1,   1,    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,    1,   1,   1,   1,    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,    1,   1,   1,   1,   1,   1,    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,    1,   1;
	setarray .Craftsman_W3r[0],984,10,30400,12,-1,14; // resources id,qty...


	// weapons lvl 4
	// 1478,	0,	4,	Ahlspiess
	// 1421,	1,	4,	Battle Hook
	// 1920,	0,	4,	Berserk Guitar
	// 1969,	0,	4,	Blade Whip
	// 1271,	2,	4,	Blood Tears
	// 1182,	2,	4,	Bloody Eater
	// 1265,	0,	4,	Bloody Roar
	// 1484,	1,	4,	Cardo
	// 1974,	0,	4,	Carrot Whip
	// 1964,	0,	4,	Chemeti Whip
	// 1741,	1,	4,	Cursed Lyre
	// 13405,	2,	4,	Curved Sword
	// 1186,	2,	4,	Death Guidance
	// 2001,	0,	4,	Divine Cross
	// 1370,	0,	4,	Doom Slayer
	// 13001,	0,	4,	Dragon Killer
	// 1270,	1,	4,	Drill Katar
	// 1972,	2,	4,	Electric Eel
	// 1637,	0,	4,	Eraser
	// 1223,	0,	4,	Fortune Sword
	// 13167,	0,	4,	Gate Keeper-DD
	// 1629,	1,	4,	Gentleman's Staff
	// 13002,	0,	4,	Ginnungagap
	// 1558,	1,	4,	Girl's Diary
	// 1364,	0,	4,	Great Axe
	// 1561,	1,	4,	Hardcover Book
	// 1926,	2,	4,	Harp of Nepenthes
	// 1376,	1,	4,	Heart Breaker
	// 13303,	0,	4,	Huuma Blaze Shuriken
	// 13302,	4,	4,	Huuma Giant Wheel Shuriken
	// 13300,	0,	4,	Huuma Wing Shuriken
	// 1261,	0,	4,	Infiltrator
	// 1269,	0,	4,	Inverse Scale
	// 13009,	0,	4,	Kamaitachi
	// 1170,	0,	4,	Katzbalger
	// 1229,	0,	4,	Kitchen Knife
	// 1962,	0,	4,	Lariat Whip
	// 1559,	0,	4,	Legacy of Dragon
	// 1420,	1,	4,	Long Horn
	// 1164,	0,	4,	Muramasa
	// 1176,	2,	4,	Muscle Cutter
	// 1541,	0,	4,	Nemesis
	// 1740,	2,	4,	Nepenthes Bow
	// 1918,	0,	4,	Oriental Lute
	// 13404,	1,	4,	Platinum Shotel
	// 1970,	0,	4,	Queen's Whip
	// 13027,	3,	4,	Scalpel
	// 1973,	1,	4,	Sea Witch's Foot
	// 1523,	0,	4,	Spike
	// 1148,	1,	4,	Star Dust Blade
	// 1979,	2,	4,	Stem of Nepenthes
	// 13028,	1,	4,	Tooth Blade
	// 1263,	0,	4,	Unholy Touch
	// 1188,	1,	4,	Veteran Sword
	// 1268,	1,	4,	Wild Beast Claw
	// 1616,	0,	4,	Wing Staff
	// 1473,	0,	4,	Wizardry Staff
	// 1168,	0,	4,	Zweihander

	// Grand-Master - Weapon lvl 3  and plus* armor pieces ------
	//  3 enriched Oridecon	 7620
	// 18 exquisite ani pelt 30352
	// 20 Heart of * (use arrayindex % 4. depending on the rest of the division (0 to 3) will determinate the heart necessary)
	setarray .Craftsman_W4$[0],1478,1421,1920,1969,1271,1182,1265,1484,1974,1964,1741,13405,1186,2001,1370,13001,1270,1972,1637,1223,13167,1629,13002,1558,1364,1561,1926,1376,13303,13302,13300,1261,1269,13009,1170,1229,1962,1559,1420,1164,1176,1541,1740,1918,13404,1970,13027,1973,1523,1148,1979,13028,1263,1188,1268,1616,1473,1168;
	setarray .Craftsman_W4x[0],   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,    1,   1,   1,    1,   1,   1,   1,   1,   1,    1,   1,    1,   1,   1,   1,   1,   1,    1,    1,    1,   1,   1,    1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,    1,   1,    1,   1,   1,   1,   1,    1,   1,   1,   1,   1,   1,   1;
	setarray .Craftsman_W4r[0],7620,3,30352,18,-1,20; // resources id,qty...
	end;
}


einbroch,207,69,5	script	Craftsman Dealer	731,{
	mes " [Craftsman Dealer] ";
	mes "Howdy, Stranger!";
	mes "Lookin' for somethin' special?";
	close2;
	callshop "Craftsman Shop",0;
	end;
}

function	script	F_BuildFurnace	{

	if(getd("$@f_"+getcharid(0)) > 0) {
		dispbottom "You left the furnace mounted somewhere. Please disassenble it first.",0xFF6600;
		end;
	}

	getmapxy(.@map$,.@x,.@y,BL_PC);
	set .@y,.@y-2;

	if(checknonearnpc(.@map$,3) < 1) {
		dispbottom "You cannot assemble it here as it's too close to another NPC. Please find another location.",0xFF0000;
		end;
	}
	
	showscript "Assembling Furnace...";
	progressbar "0xFFFFFF",3;
	setd "$@f_" + getcharid(0), getcharid(0);
	.@id$ = "f"+getcharid(0);
	duplicatenpc("CraftingEngine",strcharinfo(0)+"'s Furnace",""+.@id$,.@map$,.@x,.@y,DIR_SOUTH,CRAFTSMAN_FURNACE);
	end;
}


-	script	CraftingEngine	-1,{
	function getTitle; function buildMenu; function listResources; function updateXP; function checkPermit; function craft;
	if(PROFESSION != CRAFTSMAN) {
		dispbottom "This furnace can only be used by craftsman.",0xff6600;
		end;
	}
L_MENU:
	deletearray @res[0],getarraysize(@res);
	.@lv = PRO_INFO[0];
	.@p$ = "";
	mes .n$;
	mes "Title: ^0000FF" + getTitle(PRO_INFO[0]) + "^000000";
	mes "Exp: ^0000FF" +  PRO_INFO[1] + "/1000^000000";
	mes "Focus: ^0000FF" + callfunc("F_InsertComma",FOCUS) + "/" + callfunc("F_InsertComma",getvariableofnpc(.max_focus, "focus")) + "^000000";
	next;
	mes .n$;

	.@menu$ = "Craft Gear:Craft Weapon:Disassemble Furnace:^FF0000Close^000000";
	switch(select(.@menu$)) {
		case 1:
			.@c = select(" - Craft Headgear: - Craft Accessories: - Craft Footgear: - Craft Garments: - Craft Shields: - Craft Armors: - ^ff0000Back^000000");

			if(.@c == 7) {
				clear;
				goto L_MENU;
			}

			checkPermit(.@c);
		
			switch(.@c){
				case 1: .@mn$ = "HG"; break;
				case 2: .@mn$ = "AC"; break;
				case 3: .@mn$ = "SH"; break;
				case 4: .@mn$ = "GA"; break;
				case 5: .@mn$ = "SD"; break;
				case 6: .@mn$ = "CH"; break;
			}
		
			.@op = select(buildMenu(.@mn$)) -1;
			if(.@lv > 5) .@p$ = "p";
			if(.@op == getarraysize(getvariableofnpc(getd(".Craftsman_"+.@mn$+.@p$+"$"),"craftsman"))) {
				clear;
				goto L_MENU;
				break;
			}

			if(.@lv > 5).@p$ = "p";

			.@id = getvariableofnpc(getd(".Craftsman_"+.@mn$+.@p$+"$["+.@op+"]"),"craftsman");
			query_sql("SELECT strip_tags(REPLACE(`itemdesc`,'<br />',' | ')), `item_db`.`slots` FROM `cp_itemdesc`,`item_db` WHERE `itemid` = " + .@id + " AND `item_db`.`id` = `cp_itemdesc`.`itemid` LIMIT 1;",.@desc$, .@slots);
			mes "Craft: ^FF6600" + getitemname(.@id) + "^000000";
			mes "^0000ffDescription:^000000 " + .@desc$[0];
			mes "^0000ffSlots:^000000 " + .@slots[0];
			next;
			mes .n$;
			mes "Craft: ^FF6600" + getitemname(.@id) + "^000000";
			mes "Resource List:";
			// for those gears with two arrays (normal/advanced) look for the item index in the second array, the full one (lvl 6+)
			if(getarraysize(getvariableofnpc(getd(".Craftsman_"+.@mn$+"p$["+.@op+"]"),"craftsman")) > 0 )
				.@op = inarray(getvariableofnpc(getd(".Craftsman_"+.@mn$+"p$["+.@op+"]"),"craftsman"), .@id);

			listResources(.@op, .@mn$); //index na array, qual array usar. Ja tras as qtde atualizadas com o multiplicador
			.@pass = 1;
			for(.@i=0; .@i<getarraysize(@res); .@i+=2) {
				if(countitem(@res[.@i]) > @res[(.@i+1)])
					mes " ^00AA00" + @res[(.@i+1)] + "x " + getitemname(@res[.@i]) +"^000000";
				else {
					mes " ^AA0000" + @res[(.@i+1)] + "x " + getitemname(@res[.@i]) +"^000000";
					.@pass = 0;
				}
			}

			.@cost = .cost - (.@lv * 10);
			mes "Focus: ^0000FF" + callfunc("F_InsertComma",FOCUS) + "/" + callfunc("F_InsertComma",.@cost) + "^000000";

			if(FOCUS < .@cost) {
				mes "^ff0000 ** Not enough Focus **^000000";
				next;
				goto L_MENU;
			}

			if(.@pass) {
				if(select("Craft now:^AA0000Cancel^000000") == 2) {
					clear;
					goto L_MENU;
				}
				set FOCUS, FOCUS - .@cost;
				craft(.@id);
			} 
			mes "^ff0000 ** Missing Materials **^000000";
			next;
			goto L_MENU;
			break;

		case 2: // Craft Weapons
			.@c = select(" - Craft Weapons Lv1: - Craft Weapons Lv2: - Craft Weapons Lv3: - Craft Weapons Lv4: - ^ff0000Back^000000");

			if(.@c == 5) {
				clear;
				goto L_MENU;
			}

			checkPermit(.@c,1);
		
			switch(.@c){
				case 1: .@mn$ = "W1"; break;
				case 2: .@mn$ = "W2"; break;
				case 3: .@mn$ = "W3"; break;
				case 4: .@mn$ = "W4"; break;
			}
		
			.@op = select(buildMenu(.@mn$)) -1;
			if(.@op == getarraysize(getvariableofnpc(getd(".Craftsman_"+.@mn$+"$"),"craftsman"))) {
				clear;
				goto L_MENU;
				break;
			}

			.@id = getvariableofnpc(getd(".Craftsman_"+.@mn$+"$["+.@op+"]"),"craftsman");
			query_sql("SELECT strip_tags(REPLACE(`itemdesc`,'<br />',' | ')), `item_db`.`slots` FROM `cp_itemdesc`,`item_db` WHERE `itemid` = " + .@id + " AND `item_db`.`id` = `cp_itemdesc`.`itemid` LIMIT 1;",.@desc$, .@slots);
			mes "Craft: ^FF6600" + getitemname(.@id) + "^000000";
			mes "^0000ffDescription:^000000 " + .@desc$[0];
			mes "^0000ffSlots:^000000 " + .@slots[0];
			next;
			mes .n$;
			mes "Craft: ^FF6600" + getitemname(.@id) + "^000000";
			mes "Resource List:";

			listResources(.@op, .@mn$); //index na array, qual array usar. Ja tras as qtde atualizadas com o multiplicador
			.@pass = 1;
			for(.@i=0; .@i<getarraysize(@res); .@i+=2) {
				if(countitem(@res[.@i]) > @res[(.@i+1)])
					mes " ^00AA00" + @res[(.@i+1)] + "x " + getitemname(@res[.@i]) +"^000000";
				else {
					mes " ^AA0000" + @res[(.@i+1)] + "x " + getitemname(@res[.@i]) +"^000000";
					.@pass = 0;
				}
			}

			.@cost = .cost - (.@lv * 10);
			mes "Focus: ^0000FF" + callfunc("F_InsertComma",FOCUS) + "/" + callfunc("F_InsertComma",.@cost) + "^000000";

			if(FOCUS < .@cost) {
				mes "^ff0000 ** Not enough Focus **^000000";
				next;
				goto L_MENU;
			}

			if(.@pass) {
				if(select("Craft now:^AA0000Cancel^000000") == 2) {
					clear;
					goto L_MENU;
				}
				set FOCUS, FOCUS - .@cost;
				craft(.@id);

			} 
			mes "^ff0000 ** Missing Materials **^000000";
			next;
			goto L_MENU;
			break;

		case 3: // Dismantle Furnace
			if( compare(strnpcinfo(3), "f"+getcharid(0)) == 0 ) {
				mes "Only the owner can disassemble this furnace.";
				next;
				goto L_MENU;
			}
			close2;
			duplicateremove(strnpcinfo(0));
			setd "$@f_" + getcharid(0), 0;
			end;
			break;
		case 4: // close
			close;
			break;
	}

OnPCLogoutEvent:
	if(getd("$@f_"+getcharid(0)) > 0){
		duplicateremove(strcharinfo(0)+"'s Furnace#f"+getcharid(0));
		setd "$@f_" + getcharid(0), 0;
	}
	end;

OnInit:
	.n$ = "^ff6600[ Craftsman Furnace ]^000000";
	.cost = 1000; // base cost in focus
	end;


	function getTitle {
		.@p = getarg(0,0);
		return getvariableofnpc(.CraftsmanTitle$[.@p], "craftsman");
	}


	function buildMenu {
		.@j$ = getarg(0,"");
		if(.@j$ == "") {
			dispbottom "Something went wrong. Please report this to the staff.",0xff0000;
			close;
		}
		.@tmp$ = "";
		if(.@lv > 5) .@p$ = "p";

		for( .@i=0; .@i < getarraysize(getvariableofnpc(getd(".Craftsman_"+.@j$+.@p$+"$"),"craftsman")); .@i++ )
			.@tmp$ += getitemname(atoi(getvariableofnpc(getd(".Craftsman_"+.@j$+.@p$+"$["+.@i+"]"),"craftsman")))+":";
		.@tmp$ += "^ff0000Back^000000";

		return .@tmp$;
	}


	function listResources {
		.@index = getarg(0,-1);
		.@ar$ = getarg(1,"");

		if(.@lv > 5) .@p$ = "p";

		if(.@index < 0 || .@ar$ == "") {
			dispbottom "Something went wrong. Please report this to the staff.",0xff0000;
			close;
		}
		.@x = getvariableofnpc(getd(".Craftsman_"+.@ar$+"x["+.@index+"]"),"craftsman"));
		for(.@i=0;.@i < getarraysize(getvariableofnpc(getd(".Craftsman_"+.@ar$+"r"),"craftsman")); .@i+=2) {
			if(getvariableofnpc(getd(".Craftsman_"+.@ar$+"r["+.@i+"]"),"craftsman") < 0) {
				// Define which heart to use
				.@k = .@index % 4;
				@res[.@i] = HEART_GEFFEN + .@k;
				setarray @res[(.@i+1)], getvariableofnpc(getd(".Craftsman_"+.@ar$+"r["+(.@i+1)+"]"),"craftsman") * .@x;
			} else {
				setarray @res[.@i], getvariableofnpc(getd(".Craftsman_"+.@ar$+"r["+.@i+"]"),"craftsman");
				setarray @res[(.@i+1)], getvariableofnpc(getd(".Craftsman_"+.@ar$+"r["+(.@i+1)+"]"),"craftsman") * .@x;
			}
			
		}
		return;
	}

	function craft {
		.@id = getarg(0,0);
		
		.@check = 1;
		for(.@i=0; .@i<getarraysize(@res); .@i+=2)
			if(countitem(@res[.@i]) < @res[(.@i+1)])
				.@check = 0;

		if(.@check) {
			for(.@i=0; .@i<getarraysize(@res); .@i+=2)
				delitem @res[.@i], @res[(.@i+1)];

			cutin "c_f_00",2; sleep2 200; 
			cutin "c_f_01",2; sleep2 200;
			cutin "c_f_02",2; sleep2 200; specialeffect2 457;
			cutin "c_f_03",2; sleep2 200;
			cutin "c_f_04",2; sleep2 200;
			cutin "c_f_05",2; sleep2 200; specialeffect2 457;
			cutin "c_f_06",2; sleep2 200; 
			cutin "c_f_07",2; sleep2 200; 
			cutin "c_f_ok",2; sleep2 500; cutin "",255; 

			mes " ";
			mes "Got 1x " + getitemname(.@id);
			updateXP();
			next;
			goto L_MENU;
		} else {
			mes "ERROR: Cant find the items. This will be reported to the staff.";
			logmes "Cheater detected.";
			close;
		}

		return;
	}

	function updateXP {
		.@lv = PRO_INFO[0];
		if(.@lv == (getarraysize(getvariableofnpc(.Craftsman_Exp$,"craftsman")) -1))
			return;
		PRO_INFO[1] += getvariableofnpc(.Craftsman_Exp[.@lv],"craftsman");
		if(PRO_INFO[1] >= getvariableofnpc(.Xp2LvlUp,"craftsman") && PRO_INFO[0] < (getarraysize(getvariableofnpc(.Craftsman_Exp,"craftsman")) -1)) {
			.@lv++;
			setarray PRO_INFO[0], .@lv;
			setarray PRO_INFO[1], 0;
			specialeffect2 999;
			soundeffect "bijou_die.wav", 0;
			
			announce "CRAFTSMAN LEVEL UP!",bc_blue|bc_self;
			dispbottom "You are now a " + getvariableofnpc(.Craftsman_Exp$[.@lv],"craftsman") + " Craftsman. Congratulations!";
		}
		return;
	}

	function checkPermit {
		.@menu = getarg(0,0);
		.@type = getarg(1,0);
		.@lv = PRO_INFO[0];

		if(.@menu <= 0) {
			mes "ERROR: Please contact the staff about this.";
			close;
		}
		if(type) { // type 1 = weapons and need different treatment
			switch(.@menu) {
				case 1: if(.@lv >= 1) return; break;
				case 2: if(.@lv >= 3) return; break;
				case 3: if(.@lv >= 6) return; break;
				case 4: if(.@lv >= 7) return; break;
			}
		} else
			if(.@lv >= (.@menu - 1)) return;
		
		clear;
		mes .n$;
		mes "You don't have access to this option yet.";
		next;
		clear;
		goto L_MENU;
	}

}

// SHOPS
-	shop	Craftsman Shop	-1,30311:-1,30312:-1,30313:-1,30314:-1,30315:-1,30316:-1,30317:-1,30318:-1,24502:8000;
