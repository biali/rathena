-	script	craftsman	-1,{
	end;

OnInit:
	set .Xp2LvlUp, 1000;
	set .metalid, 30361; // first metal, copper, as base for the rest
	setarray .CraftsmanTitle$[0],		"Apprentice","Journeyman","Skilled","Expert","Artisan","Master","Grand Master","Illustrious";
	setarray .Craftsman_Lvl[0],	                   0,           1,        2,       3,        4,       5,             6,            7; // * Required Lvl to Work on It
	setarray .Craftsman_Exp[0],   	              50,          40,       20,      10,        8,       5,             4,            2; // * Experience gained per craft


	// list of materials to create any of the equips that dont have a tailored items list
	for(.@i=0;.@i<=7;.@i++) {
		.@v$ = ".default_" + .@i +"[0]";
		.@qt = 4 * (1 + .@i);
		setarray getd(.@v$),(.metalid+.@i),4;
	}

	// Tailored list of resources;
	// these arrays list the resource materials id,qtty to craft a particular item and ignore the default array
	setarray .item_30361[0],30351,2;					// copper bar
	setarray .item_30362[0],30361,1,30352,2;			// bronze bar
	setarray .item_30363[0],30362,1,30353,2;			// Steel bar
	setarray .item_30364[0],30363,1,30354,2;			// Titanium Steel bar
	setarray .item_30365[0],30364,1,30355,2;			// Runite Steel bar
	setarray .item_30366[0],30365,1,30356,2;			// Meteorite Steel bar
	setarray .item_30367[0],30366,1,30357,2;			// Adamantium Steel bar
	setarray .item_30368[0],30367,1,30358,2;			// Bradium Steel bar

	// 30361 Copper Bar
	// 2227, 1, 256,Cap
	// 2221, 1, 256,Hat
	// 2229, 1, 256,Helm
	// 2607, 1, 136,Clip
	// 2402, 1, 64,Sandals
	// 2404, 1, 64,Shoes
	// 2507, 0, 4,Ancient Cape
	// 2502, 1, 4,Hood
	// 2514, 1, 4,Pauldron
	// 2104, 1, 32,Buckler
	// 2102, 1, 32,Guard
	// 2306, 1, 16,Adventurer's Suit
	// 2308, 1, 16,Mantle
	// 2329, 1, 16,Wooden Mail
	// 1302,	4,	1,	Axe
	// 1702,	4,	1,	Bow
	// 1502,	4,	1,	Club
	// 1105,	4,	1,	Falchion
	// 1402,	4,	1,	Javelin
	// 1202,	4,	1,	Knife
	// 1602,	4,	1,	Rod
	// 1951,	4,	1,	Rope
	setarray .Menu_0[0][0],30361,2227,2221,2229,2607,2402,2404,2507,2502,2514,2104,2102,2306,2308,2329,1302,1702,1502,1105,1402,1202,1602,1951;
	setarray .item_2404[0],30361,4,919,20;				// 2404, 1, 64,Shoes
	setarray .item_2507[0],30361,4,1059,10,930,10;		// 2507, 0, 4,Ancient Cape
	setarray .item_2514[0],30361,6,999,10;				// 2514, 1, 4,Pauldron
	setarray .item_2104[0],30361,4,919,10;				// 2104, 1, 32,Buckler
	setarray .item_2329[0],30361,6,2328,1;				// 2329, 1, 16,Wooden Mail
	setarray .item_1302[0],30361,4,999,10,1301,1;		// 1302,	4,	1,	Axe
	setarray .item_1702[0],30361,4,1025,10,1701,1;		// 1702,	4,	1,	Bow
	setarray .item_1502[0],30361,6,1501,1;				// 1502,	4,	1,	Club
	setarray .item_1105[0],30361,4,999,10,1104,1;		// 1105,	4,	1,	Falchion
	setarray .item_1402[0],30361,4,1067,10,1401,1;		// 1402,	4,	1,	Javelin
	setarray .item_1202[0],30361,4,999,10,1201,1;		// 1202,	4,	1,	Knife
	setarray .item_1602[0],30361,4,1067,10,1601,1;		// 1602,	4,	1,	Rod
	setarray .item_1951[0],30361,4,1025,10,1950,1;		// 1951,	4,	1,	Rope

	// 30362 Bronze Bar
	// 5045, 0, 256,Magician Hat
	// 2289, 0, 256,Poo Poo Hat
	// 5014, 0, 512,Fin Helm
	// 2617, 0, 136,Celebrant's Mitten
	// 2622, 1, 136,Earring
	// 2618, 0, 136,Matyr's Leash
	// 2621, 1, 136,Ring
	// 2626, 1, 136,Rosary
	// 2406, 1, 64,Boots
	// 2506, 1, 4,Manteau
	// 2504, 1, 4,Muffler
	// 2508, 0, 4,Ragamuffin Manteau
	// 2116, 1, 32,Angelic Guard
	// 2109, 0, 32,Memory Book
	// 2106, 1, 32,Shield
	// 2310, 1, 16,Coat
	// 2313, 1, 16,Padded Armor
	// 2322, 1, 16,Silk Robe
	// 1352,	4,	1,	Battle Axe
	// 1108,	4,	1,	Blade
	// 1205,	4,	1,	Cutter
	// 1505,	4,	1,	Mace
	// 1802,	4,	1,	Waghnak	
	setarray .Menu_1[0][0],30362,5045,2289,5014,2617,2622,2618,2621,2626,2406,2506,2504,2508,2116,2109,2106,2310,2313,2322,1352,1108,1205,1505,1802;
	setarray .item_2289[0],30362,4,919,20;				// 2289, 0, 256,Poo Poo Hat
	setarray .item_2622[0],30362,2,2602,1;				// 2622, 1, 136,Earring
	setarray .item_2621[0],30362,2,2601,1;				// 2621, 1, 136,Ring
	setarray .item_2626[0],30362,2,2608,1;				// 2626, 1, 136,Rosary
	setarray .item_2406[0],30362,4,2405,1;				// 2406, 1, 64,Boots
	setarray .item_2506[0],30362,4,2505,1;				// 2506, 1, 4,Manteau
	setarray .item_2504[0],30362,4,2503,1;				// 2504, 1, 4,Muffler
	setarray .item_2106[0],30362,4,943,60,7054,5;		// 2106, 1, 32,Shield
	setarray .item_2310[0],30362,4,7065,30;			// 2310, 1, 16,Coat
	setarray .item_2313[0],30362,8,2312,1;				// 2313, 1, 16,Padded Armor
	setarray .item_2322[0],30362,4,2321,1,7166,20;		// 2322, 1, 16,Silk Robe
	setarray .item_1352[0],30362,6,1351,1,999,10;		// 1352,	4,	1,	Battle Axe
	setarray .item_1108[0],30362,6,1107,1,999,10;		// 1108,	4,	1,	Blade
	setarray .item_1205[0],30362,6,1204,1,999,10;		// 1205,	4,	1,	Cutter
	setarray .item_1505[0],30362,6,1504,1,1067,10;		// 1505,	4,	1,	Mace
	setarray .item_1802[0],30362,6,1801,1,999,10;		// 1802,	4,	1,	Waghnak	

	// 30363 Steel Bar
	// 2285, 0, 256,Apple of Archer
	// 2225, 1, 768,Goggles
	// 2625, 1, 136,Brooch
	// 2624, 1, 136,Glove
	// 2614, 0, 136,Eye of Dullahan
	// 2420, 1, 64,Angel's Reincarnation
	// 2418, 0, 64,Vidar's Boots
	// 2520, 0, 4,Goibne's Spaulders
	// 2517, 0, 4,Vali's Manteau
	// 2108, 1, 32,Mirror Shield
	// 2114, 1, 32,Stone Buckler
	// 2315, 1, 16,Chain Mail
	// 2337, 0, 16,Ninja Suit
	// 2333, 1, 16,Silver Robe
	// 1705,	4,	1,	Composite Bow
	// 1117,	4,	1,	Katana
	// 1208,	4,	1,	Main Gauche
	// 1485,	4,	2,	Battle Fork
	// 1550,	3,	2,	Book
	// 13103,	2,	2,	Crimson Bolt
	// 1214,	3,	2,	Dagger
	// 1355,	3,	2,	Hammer
	// 1251,	3,	2,	Jur
	// 1904,	3,	2,	Mandolin
	// 1806,	3,	2,	Studded Knuckles
	// 1605,	3,	2,	Wand
	setarray .Menu_2[0][0],30363,2285,2225,2285,2225,2625,2624,2614,2420,2418,2520,2517,2108,2114,2315,2337,2333,1705,1117,1208,1705,1117,1208,1485,1550,13103,1214,1355,1251,1904,1806,1605;
	setarray .item_2285[0],30363,12,619,1;					// 2285, 0, 256,Apple of Archer
	setarray .item_2625[0],30363,8,2605,1;					// 2625, 1, 136,Brooch
	setarray .item_2624[0],30363,8,2604,1;					// 2624, 1, 136,Glove
	setarray .item_2418[0],30363,8,2406,1,7065,10,715,5;	// 2418, 0, 64,Vidar's Boots
	setarray .item_2520[0],30363,8,2514,1,919,20,715,5;		// 2520, 0, 4,Goibne's Spaulders
	setarray .item_2517[0],30363,8,2506,1,7166,20,715,5;	// 2517, 0, 4,Vali's Manteau
	setarray .item_2108[0],30363,8,2106,1,7095,20;			// 2108, 1, 32,Mirror Shield
	setarray .item_2114[0],30363,8,2104,1,640,5;			// 2114, 1, 32,Stone Buckler
	setarray .item_2315[0],30363,12,2314,1,999,20;			// 2315, 1, 16,Chain Mail
	setarray .item_2337[0],30363,8,2306,1,1059,10,715,5;	// 2337, 0, 16,Ninja Suit
	setarray .item_2333[0],30363,8,2332,1,7166,50;			// 2333, 1, 16,Silver Robe
	setarray .item_1705[0],30363,8,1704,1,1025,20,1067,20;	// 1705,	4,	1,	Composite Bow
	setarray .item_1117[0],30363,12,1116,1,999,20;			// 1117,	4,	1,	Katana
	setarray .item_1208[0],30363,12,1207,1,999,20;			// 1208,	4,	1,	Main Gauche
	setarray .item_1485[0],30363,20,999,20,1067,20;			// 1485,	4,	2,	Battle Fork
	setarray .item_1550[0],30363,8,1097,20,919,10;			// 1550,	3,	2,	Book
	setarray .item_13103[0],30363,12,13102,1,7093,10;		// 13103,	2,	2,	Crimson Bolt
	setarray .item_1214[0],30363,12,1213,1,999,20;			// 1214,	3,	2,	Dagger
	setarray .item_1355[0],30363,12,1354,1,999,20;			// 1355,	3,	2,	Hammer
	setarray .item_1251[0],30363,20,1250,1,999,10,1067,10;	// 1251,	3,	2,	Jur
	setarray .item_1904[0],30363,12,1903,1,1066,20;			// 1904,	3,	2,	Mandolin
	setarray .item_1806[0],30363,8,1802,1,999,20;			// 1806,	3,	2,	Studded Knuckles
	setarray .item_1605[0],30363,12,1604,1,1066,20;			// 1605,	3,	2,	Wand

	// 30364 Titanium Steel Bar
	// 5017, 0, 256,Bone Helm
	// 2252, 0, 256,Wizard Hat
	// 2680, 0, 136,Lesser Elemental Ring
	// 2726, 0, 136,Icarus Wings
	// 2425, 0, 64,Black Leather Boots
	// 2422, 1, 64,High Fashion Sandals
	// 2521, 1, 4,Angelic Cardigan
	// 2527, 1, 4,Dragon Breath
	// 2544, 1, 4,Leather of Tendrilion
	// 2135, 1, 32,Shadow Guard
	// 2355, 1, 16,Angelic Protection
	// 2366, 1, 16,Divine Cloth
	// 2354, 0, 16,Goibne's Armor
	// 2353, 1, 16,Odin's Blessing
	// 1155,	3,	2,	Bastard Sword
	// 1711,	3,	2,	Crossbow
	// 13152,	2,	2,	Cyclone
	// 1211,	3,	2,	Dirk
	// 1511,	3,	2,	Flail
	// 13104,	1,	2,	Garrison
	// 1455,	3,	2,	Glaive
	// 1708,	3,	2,	Great Bow
	// 1608,	3,	2,	Staff
	// 1307,	0,	2,	Windhawk
	setarray .Menu_3[0][0],30364,5017,2252,2680,2726,2425,2422,2521,2527,2544,2135,2355,2366,2354,2353,1155,1711,13152,1211,1511,13104,1455,1708,1608,1307;
	setarray .item_5017[0],30364,16,2229,1,5014,1,932,50;				// 5017, 0, 256,Bone Helm
	setarray .item_2252[0],30364,16,5045,1,7166,50,1059,50;				// 2252, 0, 256,Wizard Hat
	setarray .item_2680[0],30364,16,2601,1,30151,10;					// 2680, 0, 136,Lesser Elemental Ring
	setarray .item_2726[0],30364,16,2601,1,30151,10,30152,10;			// 2726, 0, 136,Icarus Wings
	setarray .item_2425[0],30364,16,2606,1,919,20,30153,10;				// 2425, 0, 64,Black Leather Boots
	setarray .item_2422[0],30364,16,2402,1,1059,20,30153,10;			// 2422, 1, 64,High Fashion Sandals
	setarray .item_2527[0],30364,16,2506,1,7265,20,30153,10;			// 2527, 1, 4,Dragon Breath
	setarray .item_2544[0],30364,16,2506,1,919,20,30152,10;				// 2544, 1, 4,Leather of Tendrilion
	setarray .item_2135[0],30364,16,2104,1,999,20,7317,30;				// 2135, 1, 32,Shadow Guard
	setarray .item_2355[0],30364,25,2102,1,30151,10,30152,10,30153,10;	// 2355, 1, 16,Angelic Protection
	setarray .item_2366[0],30364,25,2306,1,1059,50,523,20;				// 2366, 1, 16,Divine Cloth
	setarray .item_2354[0],30364,20,2315,1,30154,20;					// 2354, 0, 16,Goibne's Armor
	setarray .item_2353[0],30364,16,2322,1,30151,20;					// 2353, 1, 16,Odin's Blessing
	setarray .item_1155[0],30364,16,1154,1,999,20,30152,20;				// 1155,	3,	2,	Bastard Sword
	setarray .item_1711[0],30364,16,1710,1,1067,50,30153,10;			// 1711,	3,	2,	Crossbow
	setarray .item_13152[0],30364,16,13151,1,7093,10,30154,10;			// 13152,	2,	2,	Cyclone
	setarray .item_1211[0],30364,25,1210,1,30154,10;					// 1211,	3,	2,	Dirk
	setarray .item_1511[0],30364,25,1510,1,30151,10;					// 1511,	3,	2,	Flail
	setarray .item_13104[0],30364,25,13102,1,7093,5,7317,5;				// 13104,	1,	2,	Garrison
	setarray .item_1455[0],30364,25,1454,1,999,20;						// 1455,	3,	2,	Glaive
	setarray .item_1708[0],30364,16,1707,1,1067,50,30152,10;			// 1708,	3,	2,	Great Bow
	setarray .item_1608[0],30364,20,1607,1,30153,10,30154,10;			// 1608,	3,	2,	Staff
	setarray .item_1307[0],30364,20,1302,1,999,20,30153,10;				// 1307,	0,	2,	Windhawk

	// 30365 Runite Steel Bar
	// 5164, 1, 512,Tiara
	// 2703, 1, 136,Expert Ring
	// 2783, 1, 136,Eye Stone Ring
	// 2717, 0, 136,Pocket Watch
	// 2417, 0, 64,Fricco's Shoes
	// 2409, 0, 64,High Heels
	// 2518, 0, 4,Morpheus's Shawl
	// 2545, 1, 4,Musika
	// 2531, 1, 4,Ulfhedinn
	// 2125, 1, 32,Strong Shield
	// 2124, 1, 32,Thorny Buckler
	// 2316, 0, 16,Full Plate
	// 2344, 0, 16,Lucius's Fierce Armor of Volcano
	// 2336, 1, 16,Thief Clothes
	// 1904,	3,	2,	Mandolin
	// 13013,	2,	2,	Murasame
	// 1715,	2,	3,	Arbalest
	// 1611,	2,	3,	Arc Wand
	// 1551,	2,	3,	Bible
	// 1553,	0,	3,	Book of Billows
	// 1556,	0,	3,	Book of Gust of Wind
	// 1554,	0,	3,	Book of Mother Earth
	// 1555,	0,	3,	Book of the Blazing Sun
	// 1730,	1,	3,	Burning Bow
	// 1163,	0,	3,	Claymore
	// 1226,	2,	3,	Damascus
	setarray .Menu_4[0][0],30365,5164,2703,2786,2717,2417,2409,2518,2545,2531,2125,2124,2316,2344,2336,1904,13013,1715,1611,1551,1553,1556,1554,1555,1730,1163,1226;
	setarray .item_2286[0],30365,25,2234,1;								// 5164, 1, 512,Tiara
	setarray .item_2703[0],30365,20,2621,1,30152,20;					// 2703, 1, 136,Expert Ring
	setarray .item_2783[0],30365,20,2621,1,30153,20;					// 2783, 1, 136,Eye Stone Ring
	setarray .item_2717[0],30365,20,2621,1,7093,20,746,50;				// 2717, 0, 136,Pocket Watch
	setarray .item_2417[0],30365,20,2406,1,30151,20,30154,20;			// 2417, 0, 64,Fricco's Shoes
	setarray .item_2409[0],30365,20,2406,1,30152,20,30153,20;			// 2409, 0, 64,High Heels
	setarray .item_2518[0],30365,20,2506,1,30151,20,30152,20;			// 2518, 0, 4,Morpheus's Shawl
	setarray .item_2545[0],30365,20,2506,1,7166,50,1060,20;				// 2545, 1, 4,Musika
	setarray .item_2531[0],30365,20,2507,1,722,20,1060,20;				// 2531, 1, 4,Ulfhedinn
	setarray .item_2125[0],30365,20,2106,1,999,20,30151,10,30154,10;	// 2125, 1, 32,Strong Shield
	setarray .item_2124[0],30365,30,2104,1,1027,100,30151,40;			// 2124, 1, 32,Thorny Buckler
	setarray .item_2316[0],30365,40,2313,1,999,50,30154,20;				// 2316, 0, 16,Full Plate
	setarray .item_2344[0],30365,40,2313,1,7122,50,30151,40;			// 2344, 0, 16,Lucius's Fierce Armor of Volcano
	setarray .item_2336[0],30365,40,2306,1,1059,100;					// 2336, 1, 16,Thief Clothes
	setarray .item_1904[0],30365,20,1903,1,1066,100,30152,10;			// 1904,	3,	2,	Mandolin
	setarray .item_13013[0],30365,20,13012,1,30153,20;					// 13013,	2,	2,	Murasame
	setarray .item_1715[0],30365,20,1713,1,1067,30,30153,20;			// 1715,	2,	3,	Arbalest
	setarray .item_1611[0],30365,40,1610,1,30152,20;					// 1611,	2,	3,	Arc Wand
	setarray .item_1551[0],30365,20,1550,1,523,20,7449,20;				// 1551,	2,	3,	Bible
	setarray .item_1553[0],30365,30,1550,1,995,30;						// 1553,	0,	3,	Book of Billows
	setarray .item_1556[0],30365,30,1550,1,996,30;						// 1556,	0,	3,	Book of Gust of Wind
	setarray .item_1554[0],30365,30,1550,1,997,30;						// 1554,	0,	3,	Book of Mother Earth
	setarray .item_1555[0],30365,30,1550,1,994,30;						// 1555,	0,	3,	Book of the Blazing Sun
	setarray .item_1730[0],30365,20,1708,1,7122,50;						// 1730,	1,	3,	Burning Bow
	setarray .item_1163[0],30365,30,1108,1,30154,10,30152,10;			// 1163,	0,	3,	Claymore
	setarray .item_1226[0],30365,30,1205,1,30152,10,30153,10;			// 1226,	2,	3,	Damascus


	// 30366 Meteorite Steel Bar
	// 5172, 0, 256,Beret
	// 2652, 0, 136,Goddess of Fortune's Cursed Brooch
	// 2719, 0, 136,Iron Wrist
	// 2716, 1, 136,Librarian Glove
	// 2426, 0, 64,Shadow Walk
	// 2418, 0, 64,Vidar's Boots
	// 2516, 0, 4,Falcon Muffler
	// 2111, 0, 32,Sacred Mission
	// 2134, 1, 32,Shield of Naga
	// 2311, 1, 16,Mink Coat
	// 2331, 1, 16,Tights
	// 1732,	1,	3,	Earth Bow
	// 1820,	3,	3,	Electric Fist
	// 1564,	2,	3,	Encyclopedia
	// 1615,	0,	3,	Evil Bone Wand
	// 1812,	2,	3,	Finger
	// 1967,	0,	3,	Gaia Whip
	// 1716,	2,	3,	Gakkung Bow
	// 1220,	3,	3,	Gladius
	// 1908,	1,	3,	Guitar
	// 1464,	2,	3,	Halberd
	// 1625,	0,	3,	Healing Staff
	// 1255,	1,	3,	Jamadhar
	// 1818,	3,	3,	Magma Fist
	// 1514,	2,	3,	Morning Star
	// 1304,	0,	3,	Orcish Axe
	// 1417,	1,	3,	Pole Axe
	setarray .Menu_5[0][0],30366,5172,2652,2719,2716,2426,2418,2516,2111,2134,2311,2331,1732,1820,1564,1615,1812,1967,1726,1220,1908,1464,1625,1255,1818,1514,1304,1417;
	setarray .item_2652[0],30366,24,2625,1;							// 2652, 0, 136,Goddess of Fortune's Cursed Brooch
	setarray .item_2719[0],30366,24,2625,1;							// 2719, 0, 136,Iron Wrist
	setarray .item_2716[0],30366,24,2624,1,7166,50;					// 2716, 1, 136,Librarian Glove
	setarray .item_2426[0],30366,24,2406,1,7161,100;				// 2426, 0, 64,Shadow Walk
	setarray .item_2418[0],30366,24,2426,1,999,50,919,50;			// 2418, 0, 64,Vidar's Boots
	setarray .item_2516[0],30366,24,2504,1,1060,50;					// 2516, 0, 4,Falcon Muffler
	setarray .item_2111[0],30366,30,2106,17562,2;					// 2111, 0, 32,Sacred Mission
	setarray .item_2134[0],30366,24,2106,936,100,30153,20;			// 2134, 1, 32,Shield of Naga
	setarray .item_2311[0],30366,24,2310,1,7065,100,30152,20;		// 2311, 1, 16,Mink Coat
	setarray .item_2331[0],30366,30,2330,1,30151,20,30152,20;		// 2331, 1, 16,Tights
	setarray .item_1732[0],30366,24,1708,1,997,50,30154,10;			// 1732,	1,	3,	Earth Bow
	setarray .item_1820[0],30366,24,1802,1,7116,50;					// 1820,	3,	3,	Electric Fist
	setarray .item_1564[0],30366,24,1550,1,1097,100,30154,20;		// 1564,	2,	3,	Encyclopedia
	setarray .item_1615[0],30366,30,1605,1,7752,50;					// 1615,	0,	3,	Evil Bone Wand
	setarray .item_1812[0],30366,50,1802,1,999,50;					// 1812,	2,	3,	Finger
	setarray .item_1967[0],30366,30,1951,1,905,100;					// 1967,	0,	3,	Gaia Whip
	setarray .item_1716[0],30366,50,1708,1;							// 1716,	2,	3,	Gakkung Bow
	setarray .item_1220[0],30366,50,1219,1;							// 1220,	3,	3,	Gladius
	setarray .item_1908[0],30366,24,1907,1,1066,50,1025,50;			// 1908,	1,	3,	Guitar
	setarray .item_1464[0],30366,50,1463,1;							// 1464,	2,	3,	Halberd
	setarray .item_1625[0],30366,40,1608,1;							// 1625,	0,	3,	Healing Staff
	setarray .item_1255[0],30366,40,1254,1;							// 1255,	1,	3,	Jamadhar
	setarray .item_1818[0],30366,24,1802,1,7096,50;					// 1818,	3,	3,	Magma Fist
	setarray .item_1514[0],30366,50,1513,1;							// 1514,	2,	3,	Morning Star
	setarray .item_1304[0],30366,24,1302,1,922,100;					// 1304,	0,	3,	Orcish Axe
	setarray .item_1417[0],30366,50,1352,1;							// 1417,	1,	3,	Pole Axe



	// 30367 Adamantium Steel Bar
	// 5124,	Fricca's Circlet
	// 5128		Goibne's Helm
	// 2749, 1, 136,Linen Glove
	// 2718, 1, 136,Lunatic Brooch
	// 2440, 1, 64,Sprint Shoes
	// 2532, 1, 4,Mithril Magic Cape
	// 2536, 1, 4,Skin of Ventus
	// 2123, 1, 32,Orleans's Server
	// 2365, 1, 16,Orleans's Gown
	// 2387, 1, 16,Sprint Mail
	// 13414,	3,	3,	Elemental Sword
	// 1723,	2,	3,	Luna Bow
	// 1613,	0,	3,	Mighty Staff
	// 1965,	0,	3,	Red Flame Whip
	// 1620,	1,	3,	Survivor's Rod
	// 1461,	3,	3,	Trident
	// 1120,	2,	3,	Tsurugi
	// 1361,	2,	3,	Two-Handed Axe
	// 1158,	2,	3,	Two-Handed Sword
	// 1306,	1,	3,	War Axe
	// 13107,	2,	3,	Wasteland's Outlaw
	// 1980,	3,	3,	Whip of Balance
	setarray .Menu_6[0][0],30367,5124,5128,2749,2718,2440,2532,2536,2123,2135,2365,2387,13414,1723,1613,1965,1620,1461,1120,1361,1158,1306,13107,1980;
	setarray .item_5124[0],30367,28,2322,1,30151,50;					// 5124,	Fricca's Circlet
	setarray .item_5128[0],30367,50,2229,1;								// 5128		Goibne's Helm
	setarray .item_2749[0],30367,28,2624,2,1059,100;					// 2749, 1, 136,Linen Glove
	setarray .item_2718[0],30367,28,2625,1,4006,3;						// 2718, 1, 136,Lunatic Brooch
	setarray .item_2440[0],30367,40,2404,1,996,10;						// 2440, 1, 64,Sprint Shoes
	setarray .item_2532[0],30367,50,2507,1;								// 2532, 1, 4,Mithril Magic Cape
	setarray .item_2536[0],30367,28,2506,1,7798,5;						// 2536, 1, 4,Skin of Ventus
	setarray .item_2123[0],30367,50,2104,1,30151,20,30152,20;			// 2123, 1, 32,Orleans's Server
	setarray .item_2365[0],30367,40,2333,1,30151,20,30152,20;			// 2365, 1, 16,Orleans's Gown
	setarray .item_2387[0],30367,40,2315,1,30152,20,30154,20;			// 2387, 1, 16,Sprint Mail
	setarray .item_13414[0],30367,28,1108,1,997,40,30153,20;			// 13414,	3,	3,	Elemental Sword
	setarray .item_1723[0],30367,40,1708,1,7441,50;						// 1723,	2,	3,	Luna Bow
	setarray .item_1613[0],30367,40,1608,1;								// 1613,	0,	3,	Mighty Staff
	setarray .item_1965[0],30367,35,1951,1,994,50;						// 1965,	0,	3,	Red Flame Whip
	setarray .item_1620[0],30367,40,1619,1,30152,50;					// 1620,	1,	3,	Survivor's Rod
	setarray .item_1461[0],30367,40,1460,1,30152,50;					// 1461,	3,	3,	Trident
	setarray .item_1120[0],30367,40,1119,1,30151,50;					// 1120,	2,	3,	Tsurugi
	setarray .item_1361[0],30367,40,1360,1,30151,50;					// 1361,	2,	3,	Two-Handed Axe
	setarray .item_1158[0],30367,40,1157,1,30153,50;					// 1158,	2,	3,	Two-Handed Sword
	setarray .item_1306[0],30367,40,1352,1,1067,50,999,50;				// 1306,	1,	3,	War Axe
	setarray .item_13107[0],30367,60;									// 13107,	2,	3,	Wasteland's Outlaw
	setarray .item_1980[0],30367,50,1951,1;								// 1980,	3,	3,	Whip of Balance



	// 30368 Bradium Steel Bar
	// 2202, 1, 512,Sunglasses
	// 2656, 0, 136,Armor Charm
	// 2747, 0, 136,Black Cat
	// 2619, 0, 136,Bow Thimble
	// 2701, 1, 136,Orleans's Glove
	// 2419, 0, 64,Goibne's Greaves
	// 2411, 0, 64, Greaves
	// 2424, 1, 64,Tidal Shoes
	// 2528, 1, 4,Wool Scarf
	// 2138, 1, 32,Bradium Shield	
	// 2115, 1, 32,Valkyrja's Shield
	// 2390, 1, 16,Improved Tights
	// 2364, 1, 16,Meteo Plate Armor
	// 2367, 1, 16,Sniping Suit
	// 1270,	1,	4,	Drill Katar
	// 1972,	2,	4,	Electric Eel
	// 1223,	0,	4,	Fortune Sword
	// 1364,	0,	4,	Great Axe
	// 1561,	1,	4,	Hardcover Book
	// 1926,	2,	4,	Harp of Nepenthes
	// 1376,	1,	4,	Heart Breaker
	// 1261,	0,	4,	Infiltrator
	// 1164,	0,	4,	Muramasa
	// 1740,	2,	4,	Nepenthes Bow
	// 1473,	0,	4,	Wizardry Staff
	setarray .Menu_7[0][0],30368,2202,2656,2747,2619,2701,2419,2411,2424,2528,2138,2115,2390,2364,2367,1270,1972,1223,1364,1561,1926,1376,1261,1164,1740,1473;
	setarray .item_[0],30368,20,2201,5;							// 2202, 1, 512,Sunglasses
	setarray .item_[0],30368,32,2607,2,7319,50;					// 2656, 0, 136,Armor Charm
	setarray .item_[0],30368,32,2607,2,7206,50;					// 2747, 0, 136,Black Cat
	setarray .item_[0],30368,20,2624,2;							// 2619, 0, 136,Bow Thimble
	setarray .item_[0],30368,32,2624,2,7166,100;				// 2701, 1, 136,Orleans's Glove
	setarray .item_[0],30368,32,2406,1,7319,50;					// 2419, 0, 64,Goibne's Greaves
	setarray .item_[0],30368,32,2406,1,7319,50,999,50;			// 2411, 0, 64, Greaves
	setarray .item_[0],30368,32,2404,1,7752,10,30152,10;		// 2424, 1, 64,Tidal Shoes
	setarray .item_[0],30368,32,2506,1,1060,100;				// 2528, 1, 4,Wool Scarf
	setarray .item_[0],30368,32,2108,1,969,1;					// 2138, 1, 32,Bradium Shield
	setarray .item_[0],30368,32,2108,1,7510,5;					// 2115, 1, 32,Valkyrja's Shield
	setarray .item_[0],30368,50,2331,1;							// 2390, 1, 16,Improved Tights
	setarray .item_[0],30368,50,2316,1;							// 2364, 1, 16,Meteo Plate Armor
	setarray .item_[0],30368,50,2331,1;							// 2367, 1, 16,Sniping Suit
	setarray .item_[0],30368,32,1252,1,30151,20;				// 1270,	1,	4,	Drill Katar
	setarray .item_[0],30368,32,1951,1,30152,20;				// 1972,	2,	4,	Electric Eel
	setarray .item_[0],30368,32,1108,1,30153,20;				// 1223,	0,	4,	Fortune Sword
	setarray .item_[0],30368,32,1302,1,30154,20;				// 1364,	0,	4,	Great Axe
	setarray .item_[0],30368,32,1550,1,30151,20;				// 1561,	1,	4,	Hardcover Book
	setarray .item_[0],30368,32,1909,1,30152,20;				// 1926,	2,	4,	Harp of Nepenthes
	setarray .item_[0],30368,32,1302,1,30153,20;				// 1376,	1,	4,	Heart Breaker
	setarray .item_[0],30368,32,1255,1,30154,20;				// 1261,	0,	4,	Infiltrator
	setarray .item_[0],30368,32,1117,1,30151,20;				// 1164,	0,	4,	Muramasa
	setarray .item_[0],30368,32,1708,1,30152,20;				// 1740,	2,	4,	Nepenthes Bow
	setarray .item_[0],30368,32,1608,1,30153,20;				// 1473,	0,	4,	Wizardry Staff
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
	function getTitle; function getResources; function updateXP; function craftItem; function green; function red;
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

	.@menu$ = "Craft Gear:Disassemble Furnace:^FF0000Close^000000";
	switch(select(.@menu$)) {
		case 1:
			// build the menu with craftable items according to profession level
			.@menu$ = "";
			for(.@i=0;.@i<=.@lv;.@i++)
				.@menu$ += " - " + callfunc("F_GetProfLevel",.@i) + " Gear:";
			.@menu$ += " - ^ff0000Back^000000";
			.@c = prompt(.@menu$) -1;

			if(.@c == 255 || .@c == (.@lv+1)) {
				clear;
				goto L_MENU;
			}

			clear;
			mes .n$;
			.@menu$ = "";
			for(.@i=0;.@i<(.@size = getarraysize(getvariableofnpc(getd(".Menu_"+.@c),"craftsman")));.@i++)
				.@menu$ += getitemname(getvariableofnpc(getd(".Menu_"+.@c+"["+.@i+"]"),"craftsman")) + ":";
			.@menu$ += "^ff0000Back^000000";

			.@op = prompt(.@menu$) -1;
			if(.@op == 255 || .@op == .@size) {
				clear;
				goto L_MENU;
			}

			.@id = getvariableofnpc(getd(".Menu_"+.@c+"["+.@op+"]"),"craftsman");
			query_sql("SELECT strip_tags(REPLACE(`itemdesc`,'<br />',' | ')), `item_db`.`slots` FROM `cp_itemdesc`,`item_db` WHERE `itemid` = " + .@id + " AND `item_db`.`id` = `cp_itemdesc`.`itemid` LIMIT 1;",.@desc$, .@slots);
			mes "Craft: ^FF6600" + getitemname(.@id) + "^000000";
			mes "^0000ffDescription:^000000 " + .@desc$[0];
			mes "^0000ffSlots:^000000 " + .@slots[0];
			next;
			mes .n$;
			mes "Craft: ^FF6600" + getitemname(.@id) + "^000000";

			.@cost = .cost - (.@c * 40);
			// if we are producing bars, that sould cost less focus
			if(getiteminfo(.@id,2) == 3)
				.@cost /= 2; // bars cost 1/2 of the focus for that level
			mes "Focus: ^0000FF" + callfunc("F_InsertComma",FOCUS) + "/" + callfunc("F_InsertComma",.@cost) + "^000000";
			mes "Resource List:";
			// this will populate the array @craftmats with the id,qtty for each item necessary to craft this .@id item
			getResources(.@id);

			.@pass = 1;
			while(.@pass == 1 && FOCUS >= .@cost) {
				.@all++;
				for(.@i=0;.@i<getarraysize(@craftmats);.@i+=2) {
					if(countitem(@craftmats[.@i]) >= @craftmats[(.@i+1)] * .@all) {
						if(.@all == 1)
							mes "  " + green(@craftmats[(.@i+1)] + "x " + getitemname(@craftmats[.@i]));
					} else {
						if(.@all == 1)
							mes "  " + red(@craftmats[(.@i+1)] + "x " + getitemname(@craftmats[.@i]));
						.@pass = 0;
					}
				}
			}

			.@all -= 1; // we need to fix the .@all amount because it gets incremented before the .@pass fails
			if(.@all > 0)
				.@pass = 1;

			if(!.@pass) {
				mes "^FF0000** Missing Materials **^000000";
				next;
				goto L_MENU;
			}

			if(FOCUS < .@cost) {
				mes "^ff0000 ** Not enough Focus **^000000";
				next;
				goto L_MENU;
			}

			if(.@pass) {
				switch(select("Craft now:Craft All("+.@all+"):^AA0000Cancel^000000")) {
					case 3:
						clear;
						goto L_MENU;
						break;
					case 2:
						craftItem(.@id,.@all,.@cost);
						break;
					case 1:
						craftItem(.@id,1,.@cost);
						break;
				}
				next;
				goto L_MENU;
			}
			break;

		case 2: // Dismantle Furnace
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
		case 3: // close
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
		return getvariableofnpc(.CraftsmanTitle$[.@p], "craftsman") + " Craftsman";
	}

	function green {
		return "^00AA00" + getarg(0) + "^000000";
	}

	function red {
		return "^AA0000" + getarg(0) + "^000000";
	}

	function getResources {
		.@id = getarg(0,0);
		.@lv = PRO_INFO[0];

		deletearray @craftmats[0],getarraysize(@craftmats);

		if(.@id == 0) {
			dispbottom "ERROR: Please inform the staff about this.",0xff0000;
			end;
		}

		if(getarraysize(getvariableofnpc(getd(".item_"+.@id),"craftsman")) == 0) {
			// no particular requests to craft this item.
			// use standard for this level
			copyarray @craftmats[0],getvariableofnpc(getd(".default_"+.@lv+"[0]"),"craftsman"),getarraysize(getvariableofnpc(getd(".default_"+.@lv),"craftsman"));
		} else {
			// otherwise load the tailor-made list of materials for this particular item
			copyarray @craftmats[0],getvariableofnpc(getd(".item_"+.@id+"[0]"),"craftsman"),getarraysize(getvariableofnpc(getd(".item_"+.@id),"craftsman"));
		}

		// if it is an ETC item, return
		if(getiteminfo(.@id,2) == 3)
			return;

		.@wlv = getiteminfo(.@id,13);
		if(.@wlv)
			// if it is an weapon, add oridecon x weapon level to the resources list
			setarray @craftmats[getarraysize(@craftmats)],984,.@wlv;
		else
			// if it is an armor, add an elunium to the list
			setarray @craftmats[getarraysize(@craftmats)],985,1;
			
		return;
	}


	function craftItem {
		.@id = getarg(0,0);
		.@qt = getarg(1,1);
		.@cost = getarg(2,1000);
		
		for(.@j=0;.@j<.@qt;.@j++) {
			.@check = 1;
			for(.@i=0; .@i<getarraysize(@craftmats); .@i+=2)
				if(countitem(@craftmats[.@i]) < @craftmats[(.@i+1)])
					.@check = 0;

			if(FOCUS < .@cost)
				.@check = 0;

			if(.@check) {
				for(.@i=0; .@i<getarraysize(@craftmats); .@i+=2)
					delitem @craftmats[.@i], @craftmats[(.@i+1)];

				FOCUS -= .@cost;

				cutin "c_f_00",2; sleep2 200; 
				cutin "c_f_01",2; sleep2 200;
				cutin "c_f_02",2; sleep2 200; specialeffect2 457;
				cutin "c_f_03",2; sleep2 200;
				cutin "c_f_04",2; sleep2 200;
				cutin "c_f_05",2; sleep2 200; specialeffect2 457;
				cutin "c_f_06",2; sleep2 200; 
				cutin "c_f_07",2; sleep2 200; 
				cutin "c_f_ok",2; sleep2 500; 
				cutin "",255; specialeffect2 610; //success!
				getitem .@id, 1;
				updateXP();
			} else {
				mes "ERROR: Cant find the items or Focus not enough. This will be reported to the staff.";
				logmes "Cheater detected.";
				close;
			}
		}
		mes " ";
		mes "Got " + .@qt +"x " + getitemname(.@id);
		next;
		goto L_MENU;

		return;
	}

	function updateXP {
		.@lv = PRO_INFO[0];
		if(.@lv == (getarraysize(getvariableofnpc(.Craftsman_Exp$,"craftsman")) -1))
			return;
		setarray PRO_INFO[1], PRO_INFO[1] + getvariableofnpc(.Craftsman_Exp[.@lv],"craftsman");
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
}

// SHOPS
-	shop	Craftsman Shop	-1,30311:-1,30312:-1,30313:-1,30314:-1,30315:-1,30316:-1,30317:-1,30318:-1,24502:8000;
