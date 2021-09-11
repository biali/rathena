
-	script	inscription	-1,{
	end;
// Player var PRO_INFO[0],level, current_exp;
// Scribes can convert 100 random cards into an OCA

OnInit:
	.n$ = "^0055DD[ Inscription ] ^000000";
	// Player Settings
	set .Xp2LvlUp, 1000;
	setarray .InscriptionTitle$[0],		"Apprentice","Journeyman","Skilled","Expert","Artisan","Master","Grand Master","Illustrious";
	setarray .InscriptionDyeID[0],     	         975,         976,      978,     979,      970,     981,           982,          983;
	setarray .Inscription_Lvl[0],	               0,           1,        2,       3,        4,       5,             6,            7; // * Required Lvl to Work on It
	setarray .Inscription_Exp[0],                 50,          40,       20,      10,        8,       5,             4,            2; // * Experience gained per craft
	setarray .Inscription_Dye[0],                975,         979,      976,     980,      982,     978,           981,          983; // Dyestuff necessary

	// a player can level up when they gain 1000 points in their current level

	// Cartas de Apprentice 
	// 4032 - Ambernite Card
	// 4013 - Andre Egg Card
	// 4023 - Baby Desert Wolf Card
	// 4009 - Chonchon Card
	// 4015 - Condor Card
	// 4070 - Eggyra Card
	// 4002 - Fabre Card
	// 4020 - Familiar Card
	// 4026 - Female Thief Bug Card
	// 4072 - Golem Card
	// 4019 - Hornet Card
	// 4027 - Kukre Card
	// 4006 - Lunatic Card
	// 4196 - Marin Card
	// 4067 - Megalodon Card
	// 4341 - Metaling Card
	// 4339 - Mineral Card
	// 4008 - Picky Card
	// 4011 - Picky Egg Card
	// 4073 - Pirate Skeleton Card
	// 4024 - Plankton Card
	// 4001 - Poring Card
	// 4003 - Pupa Card
	// 4021 - Rocker Card
	// 4014 - Roda Frog Card
	// 4025 - Skeleton Card
	// 4016 - Thief Bug Card
	// 4012 - Thief Bug Egg Card
	// 4053 - Vitata Card
	setarray .Cartas_0_ID[0],	 4032,4013,4023,4009,4015,4070,4002,4020,4026,4072,4019,4027,4006,4196,4067,4341,4339,4008,4011,4073,4024,4001,4003,4021,4014,4025,4016,4012,4053;
	setarray .Cartas_0_RT_ID[0],  935, 938, 920, 935, 916, 911, 949, 913, 935,1003, 935, 935, 949, 938, 932,4001,1003, 949, 949, 932, 938, 938, 938, 935, 938, 932, 935, 938, 911; // Reagent
	setarray .Cartas_0_RT_QT[0],  200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200,   2, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200; // Reagent quantity 
	setarray .Cartas_0_BS_ID[0],    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0; // Base id
	setarray .Cartas_0_BS_QT[0],    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0; // Base Qt

	// Cartas de Journeyman 
	// 4327 - Bloody Butterfly Card
	// 4293 - Cookie Card
	// 4061 - Cornutus Card
	// 4153 - Crab Card
	// 4082 - Desert Wolf Card
	// 4266 - Eclipse Card
	// 4152 - Galapago Card
	// 4150 - Goat Card
	// 4162 - Grizzly Card
	// 4343 - Holden Card
	// 4050 - Male Thief Bug Card
	// 4030 - Mandragora Card
	// 4197 - Mastering Card
	// 4036 - Muka Card
	// 4090 - Munak Card
	// 4420 - Muscipular Card
	// 4066 - Orc Warrior Card
	// 4071 - Orc Zombie Card
	// 4033 - Poporing Card
	// 4337 - Porcellio Card
	// 4294 - Quve Card
	// 4185 - Rideword Card
	// 4037 - Snake Card
	// 4022 - Spore Card
	// 4424 - Stapo Card
	// 4042 - Steel Chonchon Card
	// 4028 - Tarou Card
	// 4369 - Venatu Card
	// 4333 - Venomous Card
	// 4211 - Vocal Card
	// 4010 - Willow Card
	// 4029 - Wolf Card
	// 4051 - Yoyo Card
	// 4038 - Zombie Card
	setarray .Cartas_1_ID[0],	  4327, 4293, 4061, 4153, 4082, 4266, 4152, 4150, 4162, 4343, 4050, 4030, 4197, 4036, 4090, 4420, 4066, 4071, 4033, 4337, 4294, 4185, 4037, 4022, 4424, 4042, 4028, 4369, 4333, 4211, 4010, 4029, 4051, 4038;
	setarray .Cartas_1_RT_ID[0], 30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152;
	setarray .Cartas_1_RT_QT[0],     2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2;
	setarray .Cartas_1_BS_ID[0],     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0; // Base id
	setarray .Cartas_1_BS_QT[0],     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0; // Base Qt

	// Cartas de Skilled 
	// 4062 - Anacondaq Card
	// 4240 - Arclouze Card
	// 4075 - Argos Card
	// 4247 - Aster Card
	// 4233 - Baby Leopard Card
	// 4307 - Beetle King Card
	// 4289 - Caterpillar Card
	// 4452 - Centipede Larva Card
	// 4285 - Choco Card
	// 4041 - Coco Card
	// 4296 - Cramp Card
	// 4122 - Deviruchi Card
	// 4182 - Diabolic Card
	// 4069 - Drainliar Card
	// 4180 - Driller Card
	// 4004 - Drops Card
	// 4052 - Elder Willow Card
	// 4217 - Enchanted Peach Tree Card
	// 4141 - Evil Druid Card
	// 4165 - Gig Card
	// 4157 - Goblin Archer Card
	// 4155 - Goblin Leader Card
	// 4156 - Goblin Steamrider Card
	// 4164 - Gullinbursti Card
	// 4331 - Heater Card
	// 4322 - High Orc Card
	// 4287 - Kapha Card
	// 4286 - Karakasa Card
	// 4350 - Laurell Weinder Card
	// 4195 - Leaf Cat Card
	// 4191 - Loli Ruri Card
	// 4193 - Lude Card
	// 4432 - Magmaring Card
	// 4105 - Marc Card
	// 4046 - Martin Card
	// 4208 - Miyabi Doll Card
	// 4106 - Mummy Card
	// 4167 - Nereid Card
	// 4159 - Nine Tail Card
	// 4255 - Orc Lady Card
	// 4237 - Owl Duke Card
	// 4031 - Peco Peco Card
	// 4314 - Penomena Card
	// 4329 - Phendark Card
	// 4048 - Poison Spore Card
	// 4186 - Raggler Card
	// 4017 - Savage Babe Card
	// 4078 - Savage Card
	// 4068 - Scorpion Card
	// 4039 - Stainer Card
	// 4226 - Sting Card
	// 4340 - Teddy Bear Card
	// 4306 - Toad Card
	// 4308 - Tri Joint Card
	// 4210 - Wanderer Card
	// 4102 - Whisper Card
	// 4257 - Wild Rose Card
	// 4034 - Wormtail Card
	// 4096 - Zenorc Card
	// 4272 - Zhu Po Long Card
	setarray .Cartas_2_ID[0],	 4062, 4240, 4075, 4247, 4233, 4307, 4289, 4452, 4285, 4041, 4296, 4122, 4182, 4069, 4180, 4004, 4052, 4217, 4141, 4165, 4157, 4155, 4156, 4164, 4331, 4322, 4287, 4286, 4350, 4195, 4191, 4193, 4432, 4105, 4046, 4208, 4106, 4167, 4159, 4255, 4237, 4031, 4314, 4329, 4048, 4186, 4017, 4078, 4068, 4039, 4226, 4340, 4306, 4308, 4210, 4102, 4257, 4034, 4096, 4272;
	setarray .Cartas_2_RT_ID[0],30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152; // Reagent Id
	setarray .Cartas_2_RT_QT[0],    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5; // Reagent quantity
	setarray .Cartas_2_BS_ID[0],    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0; // Base id
	setarray .Cartas_2_BS_QT[0],    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0; // Base Qt

	// Cartas de Expert
	// 4244 - Alarm Card
	// 4252 - Alligator Card
	// 4243 - Antonio Card
	// 4443 - Aqua Elemental Card
	// 4371 - Archdam Card
	// 4450 - Banshee Master Card
	// 4074 - Bigfoot Card
	// 4215 - Blazer Card
	// 4379 - Blue Acidus Card
	// 4213 - Brilight Card
	// 4063 - Caramel Card
	// 4299 - Clock Card
	// 4298 - Creamy Fear Card
	// 4170 - Dark Frame Card
	// 4388 - Death Word Card
	// 4173 - Demon Pungus Card
	// 4125 - Deviace Card
	// 4181 - Disguise Card
	// 4421 - Drosera Card
	// 4056 - Dustiness Card
	// 4279 - Earth Deleter Card
	// 4410 - Echio Card
	// 4258 - Evil Nymph Card
	// 4316 - False Angel Card
	// 4418 - Gazeti Card
	// 4110 - Ghoul Card
	// 4270 - Giant Spider Card
	// 4087 - Giearth Card
	// 4378 - Gold Acidus Card
	// 4161 - Grand Peco Card
	// 4283 - Greatest General Card
	// 4163 - Gryphon Card
	// 4345 - Hill Wind Card
	// 4116 - Isis Card
	// 4351 - Kavach Icarus Card
	// 4301 - Killer Mantis Card
	// 4292 - Kobold Archer Card
	// 4295 - Kraben Card
	// 4055 - Marina Card
	// 4084 - Marine Sphere Card
	// 4113 - Marionette Card
	// 4095 - Marse Card
	// 4317 - Mobster Card
	// 4334 - Noxious Card
	// 4093 - Obeaune Card
	// 4085 - Orc Skeleton Card
	// 4309 - Parasite Card
	// 4335 - Pitman Card
	// 4175 - Poisonous Toad Card
	// 4083 - Rafflesia Card
	// 4383 - Red Novus Card
	// 4192 - Rotar Zairo Card
	// 4422 - Roween Card
	// 4194 - Rybio Card
	// 4005 - Santa Poring Card
	// 4273 - Shell Fish Card
	// 4222 - Skeleton Prisoner Card
	// 4404 - Skogul Card
	// 4158 - Sky Deleter Card
	// 4225 - Stone Shooter Card
	// 4218 - Succubus Card
	// 4172 - The Paper Card
	// 4183 - Vagabond Wolf Card
	// 4332 - Waste Stove Card
	// 4189 - Wraith Dead Card
	// 4328 - Yao Jun Card
	// 4382 - Yellow Novus Card
	setarray .Cartas_3_ID[0],    4244, 4252, 4243, 4443, 4371, 4450, 4074, 4215, 4379, 4213, 4063, 4299, 4298, 4170, 4388, 4173, 4125, 4181, 4421, 4056, 4279, 4410, 4258, 4316, 4418, 4110, 4270, 4087, 4378, 4161, 4283, 4163, 4345, 4116, 4351, 4301, 4292, 4295, 4055, 4084, 4113, 4095, 4317, 4334, 4093, 4085, 4309, 4335, 4175, 4083, 4383, 4192, 4422, 4194, 4005, 4273, 4222, 4404, 4158, 4225, 4218, 4172, 4183, 4332, 4189, 4328, 4382;
	setarray .Cartas_3_RT_ID[0],30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152;
	setarray .Cartas_3_RT_QT[0],    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5;
	setarray .Cartas_3_BS_ID[0],30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154;
	setarray .Cartas_3_BS_QT[0],    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2;

	// Cartas de Artisan 
	// 4400 - Aliza Card
	// 4248 - Ancient Mummy Card
	// 4043 - Andre Card
	// 4234 - Anolian Card
	// 4344 - Anopheles Card
	// 4242 - Apocalipse Card
	// 4094 - Archer Skeleton Card
	// 4347 - Armeyer Dinze Card
	// 4246 - Assaulter Card
	// 4438 - Banshee Card
	// 4391 - Baroness of Retribution Card
	// 4214 - Bloody Murderer Card
	// 4390 - Breeze Card
	// 4288 - Carat Card
	// 4300 - Chimera Card
	// 4262 - Cloud Hermit Card
	// 4040 - Creamy Card
	// 4297 - Cruiser Card
	// 4171 - Dark Priest Card
	// 4370 - Dimik Card
	// 4098 - Dokebi Card
	// 4444 - Draco Card
	// 4385 - Dragon Egg Card
	// 4177 - Dryad Card
	// 4176 - Dullahan Card
	// 4154 - Dumpling Child Card
	// 4118 - Earth Petite Card
	// 4360 - Eremes Guile Card
	// 4080 - Flora Card
	// 4149 - Gargoyle Card
	// 4280 - Geographer Card
	// 4278 - Gibbet Card
	// 4373 - Green Maiden Card
	// 4355 - Gremlin Card
	// 4377 - Grove Card
	// 4232 - Hermit Plant Card
	// 4081 - Hode Card
	// 4115 - Hunter Fly Card
	// 4321 - Hylozoist Card
	// 4417 - Ice Titan Card
	// 4269 - Incubus Card
	// 4265 - Jing Guai Card
	// 4394 - Lady Solace Card
	// 4076 - Magnolia Card
	// 4201 - Majoruros Card
	// 4200 - Megalith Card
	// 4205 - Mimic Card
	// 4204 - Mini Demon Card
	// 4203 - Mutant Dragonoid Card
	// 4206 - Myst Case Card
	// 4166 - Nightmare Terror Card
	// 4338 - Obsidian Card
	// 4256 - Orc Archer Card
	// 4007 - Peco Peco Egg Card
	// 4311 - Permeter Card
	// 4389 - Plasma Card
	// 4187 - Raydric Archer Card
	// 4380 - Red Ferus Card
	// 4353 - Remover Card
	// 4219 - Sage Worm Card
	// 4101 - Sandman Card
	// 4326 - Sea-Otter Card
	// 4312 - Seal Card
	// 4117 - Sidewinder Card
	// 4406 - Skeggiold Card
	// 4120 - Sky Petite Card
	// 4228 - Sleeper Card
	// 4415 - Snowier Card
	// 4100 - Sohee Card
	// 4086 - Soldier Skeleton Card
	// 4220 - Solider Card
	// 4227 - Spring Rabbit Card
	// 4224 - Stem Worm Card
	// 4111 - Strouf Card
	// 4304 - Tamruan Card
	// 4282 - Tengu Card
	// 4264 - Wind Ghost Card
	// 4259 - Wooden Golem Card
	// 4190 - Wraith Card
	// 4277 - Zealotus Card
	// 4064 - Zerom Card
	// 4274 - Zombie Master Card
	setarray .Cartas_4_ID[0],	 4400, 4248, 4043, 4234, 4344, 4242, 4094, 4347, 4246, 4438, 4391, 4214, 4390, 4288, 4300, 4262, 4040, 4297, 4171, 4370, 4098, 4444, 4385, 4177, 4176, 4154, 4118, 4360, 4080, 4149, 4280, 4278, 4373, 4355, 4377, 4232, 4081, 4115, 4321, 4417, 4269, 4265, 4394, 4076, 4201, 4200, 4205, 4204, 4203, 4206, 4166, 4338, 4256, 4007, 4311, 4389, 4187, 4380, 4353, 4219, 4101, 4326, 4312, 4117, 4406, 4120, 4228, 4415, 4100, 4086, 4220, 4227, 4224, 4111, 4304, 4282, 4264, 4259, 4190, 4277, 4064, 4274;
	setarray .Cartas_4_RT_ID[0],30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154;
	setarray .Cartas_4_RT_QT[0],   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10;
	setarray .Cartas_4_BS_ID[0], 4244, 4252, 4243, 4443, 4371, 4450, 4074, 4215, 4379, 4213, 4063, 4299, 4298, 4170, 4388, 4173, 4125, 4181, 4421, 4056, 4279, 4410, 4258, 4316, 4418, 4110, 4270, 4087, 4378, 4161, 4283, 4163, 4345, 4116, 4351, 4301, 4292, 4295, 4055, 4084, 4113, 4095, 4317, 4334, 4093, 4085, 4309, 4335, 4175, 4083, 4383, 4192, 4422, 4194, 4005, 4273, 4222, 4404, 4158, 4225, 4218, 4172, 4183, 4332, 4189, 4328, 4382, 4244, 4252, 4243, 4443, 4371, 4450, 4074, 4215, 4379, 4213, 4063, 4299, 4298, 4170, 4192;
	setarray .Cartas_4_BS_QT[0],    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1;

	// Cartas de Master 
	// 4401 - Alicel Card
	// 4402 - Aliot Card
	// 4138 - Anubis Card
	// 4129 - Bapho Jr. Card
	// 4356 - Beholder Card
	// 4320 - Bloody Knight Card
	// 4212 - Bongun Card
	// 4368 - Cecil Damon Card
	// 4284 - Chepet Card
	// 4397 - Despero of Thanatos Card
	// 4398 - Dolor of Thanatos Card
	// 4178 - Dragon Tail Card
	// 4251 - Elder Card
	// 4349 - Errende Ebecee Card
	// 4319 - Freezer Card
	// 4405 - Frus Card
	// 4423 - Galion Card
	// 4271 - Giant Hornet Card
	// 4060 - Goblin Card
	// 4437 - Hell Poodle Card
	// 4413 - Hodremlin Card
	// 4045 - Horn Card
	// 4103 - Horong Card
	// 4362 - Howard Alt-Eisen Card
	// 4109 - Jakk Card
	// 4065 - Kaho Card
	// 4431 - Kasa Card
	// 4091 - Kobold Card
	// 4291 - Kobold Leader Card
	// 4184 - Lava Golem Card
	// 4188 - Leib Olmai Card
	// 4395 - Maero of Thanatos Card
	// 4079 - Mantis Card
	// 4202 - Mao Guai Card
	// 4199 - Merman Card
	// 4108 - Myst Card
	// 4127 - Nightmare Card
	// 4254 - Ogretooth Card
	// 4238 - Owl Baron Card
	// 4310 - Panzer Goblin Card
	// 4099 - Pasana Card
	// 4315 - Pest Card
	// 4077 - Phen Card
	// 4313 - Punk Card
	// 4104 - Requiem Card
	// 4216 - Sasquatch Card
	// 4044 - Smokie Card
	// 4223 - Stalactic Golem Card
	// 4427 - Sword Guardian Card
	// 4336 - Ungoliant Card
	// 4049 - Vadon Card
	// 4209 - Violy Card
	// 4348 - Wickebine Tres Card
	// 4261 - Wootan Fighter Card
	// 4260 - Wootan Shooter Card
	// 4435 - Zombie Slaughter Card
	setarray .Cartas_5_ID[0],	 4401, 4402, 4138, 4129, 4356, 4320, 4212, 4368, 4284, 4397, 4398, 4178, 4251, 4349, 4319, 4405, 4423, 4271, 4060, 4437, 4413, 4045, 4103, 4362, 4109, 4065, 4431, 4091, 4291, 4184, 4188, 4395, 4079, 4202, 4199, 4108, 4127, 4254, 4238, 4310, 4099, 4315, 4077, 4313, 4104, 4216, 4044, 4223, 4427, 4336, 4049, 4209, 4348, 4261, 4260, 4435;
	setarray .Cartas_5_RT_ID[0],30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154;
	setarray .Cartas_5_RT_QT[0],   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,   18;
	setarray .Cartas_5_BS_ID[0], 4177, 4176, 4154, 4118, 4360, 4080, 4149, 4280, 4278, 4373, 4355, 4377, 4232, 4081, 4115, 4321, 4417, 4269, 4265, 4394, 4076, 4201, 4200, 4205, 4204, 4203, 4206, 4166, 4338, 4256, 4007, 4311, 4389, 4187, 4380, 4353, 4219, 4101, 4326, 4312, 4117, 4406, 4120, 4228, 4415, 4100, 4086, 4220, 4227, 4224, 4111, 4304, 4282, 4264, 4259, 4190;
	setarray .Cartas_5_BS_QT[0],    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1;

	// Cartas de Grand Master
	// id - name_japanese
	// 4409 - Agav Card
	// 4245 - Am Mut Card
	// 4387 - Ancient Mimic Card
	// 4249 - Ancient Worm Card
	// 4119 - Bathory Card
	// 4235 - Christmas Cookie Card
	// 4346 - Egnigem Cenia Card
	// 4451 - Entweihen Crothen Card
	// 4250 - Executioner Card
	// 4267 - Explosion Card
	// 4160 - Firelock Soldier Card
	// 4439 - Flame Skull Card
	// 4088 - Frilldora Card
	// 4151 - Gajomart Card
	// 4303 - Giant Whisper Card
	// 4325 - Harpy Card
	// 4323 - Hatii Babe Card
	// 4433 - Imp Card
	// 4268 - Injustice Card
	// 4239 - Iron Fist Card
	// 4412 - Isilla Card
	// 4139 - Joker Card
	// 4366 - Kathryne Keyron Card
	// 4364 - Margaretha Sorin Card
	// 4124 - Medusa Card
	// 4057 - Metaller Card
	// 4231 - Mi Gao Card
	// 4126 - Minorous Card
	// 4393 - Mistress of Shelter Card
	// 4207 - Mysteltainn Card
	// 4440 - Necromancer Card
	// 4375 - Orc Baby Card
	// 4414 - Seeker Card
	// 4358 - Seyren Windsor Card
	// 4230 - Shinobi Card
	// 4416 - Siroma Card
	// 4221 - Skeleton General Card
	// 4089 - Swordfish Card
	// 4411 - Vanberk Card
	// 4281 - Zipper Bear Card
	// 4275 - Zombie Prisoner Card
	setarray .Cartas_6_ID[0],	 4409, 4245, 4387, 4249, 4119, 4235, 4346, 4451, 4250, 4267, 4160, 4439, 4088, 4151, 4303, 4325, 4323, 4433, 4268, 4239, 4412, 4139, 4366, 4364, 4124, 4057, 4231, 4126, 4393, 4207, 4440, 4375, 4414, 4358, 4230, 4416, 4221, 4089, 4411, 4281, 4275;
	setarray .Cartas_6_RT_ID[0],30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154;
	setarray .Cartas_6_RT_QT[0],   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,   25;
	setarray .Cartas_6_BS_ID[0],30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151;
	setarray .Cartas_6_BS_QT[0],   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10;

	// Cartas de Illustrious 
	// 4253 - Alice Card
	// 4114 - Argiope Card
	// 4428 - Bow Guardian Card
	// 4447 - Centipede Card
	// 4448 - Cornus Card
	// 4392 - Dame of Sentinel Card
	// 4169 - Dark Illusion Card
	// 4449 - Dark Shadow Card
	// 4354 - Gemini-S58 Card
	// 4381 - Green Ferus Card
	// 4035 - Hydra Card
	// 4384 - Hydrolancer Card
	// 4136 - Khalitzburg Card
	// 4434 - Knocker Card
	// 4445 - Luciola Vespa Card
	// 4112 - Marduk Card
	// 4097 - Matyr Card
	// 4396 - Odium of Thanatos Card
	// 4436 - Ragged Zombie Card
	// 4133 - Raydric Card
	// 4092 - Skeleton Worker Card
	// 4442 - Tatacho Card
	// 4058 - Thara Frog Card
	// 4229 - Tower Keeper Card
	// 4107 - Verit Card
	setarray .Cartas_7_ID[0],	 4253,4114,4428,4447,4229,4448,4169,4449,4381,4354,4035,4384,4136,4434,4445,4112,4097,4392,4436,4133,4092,4442,4396,4058,4107;
	setarray .Cartas_7_RT_ID[0],30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152,30153,30154,30151,30152;
	setarray .Cartas_7_RT_QT[0],   40,   40,   40,   40,   40,   40,   40,   40,   40,   40,   40,   40,   40,   40,   40,   40,   40,   40,   40,   40,   40;
	setarray .Cartas_7_BS_ID[0], 4160, 4439, 4088, 4151, 4303, 4325, 4323, 4433, 4268, 4239, 4412, 4139, 4366, 4364, 4124, 4057, 4231, 4126, 4393, 4346, 4451;
	setarray .Cartas_7_BS_QT[0],   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,   24;



// ---------------- old system -------
	// // Cartas de Apprentice 
	// setarray .Cartas_0_ID[0],	 4032,4013,4009,4015,4023,4070,4002,4020,4072,4019,4027,4006,4196,4067,4341,4339,4008,4011,4073,4024,4001,4003,4021,4014,4025,4016,4012,4026,4053;
	// setarray .Cartas_0_RT_ID[0],  935, 938, 935, 916, 920, 911, 949, 913,1003, 935, 935, 949, 938, 932,4001,1003, 949, 949, 932, 938, 938, 938, 935, 938, 932, 935, 938, 935, 911; // Reagent
	// setarray .Cartas_0_RT_QT[0],  200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200; // Reagent quantity 
	// setarray .Cartas_0_BS_ID[0],    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0; // Base id
	// setarray .Cartas_0_BS_QT[0],    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0; // Base Qt


	// // Cartas de Journeyman 
	// setarray .Cartas_1_ID[0],	 4327,4293,4061,4153,4082,4266,4152,4150,4162,4030,4197,4343,4036,4090,4420,4066,4071,4033,4337,4294,4185,4037,4022,4424,4042,4028,4050,4369,4333,4211,4010,4029,4051,4038;
	// setarray .Cartas_1_RT_ID[0], 4003, 722, 911, 911, 920,4006, 916,7107, 919, 711,4001, 919, 711,7205, 711,1063,1063,4196,1052,7205,7015, 937,7033,4072, 943, 919, 943,7094,7154,4021,1066, 920, 919,7205;
	// setarray .Cartas_1_RT_QT[0],    3,  18, 200, 200, 200,   3, 200, 100, 200, 200,   5, 200, 200, 100, 200, 200, 200,   1, 120, 100,  80, 200, 160,   3, 200, 200, 200, 120, 120,   5, 200, 200, 200, 100;
	// setarray .Cartas_1_BS_ID[0], 7163,   0,   0,   0,   0, 727,   0,   0,   0,   0,7126,   0,   0,   0,   0,   0,   0, 910,   0,   0,   0,   0,   0,7312,   0,   0,   0,   0,   0, 721,   0,   0,   0,   0; // Base id
	// setarray .Cartas_1_BS_QT[0],   60,   0,   0,   0,   0,  20,   0,   0,   0,   0, 120,   0,   0,   0,   0,   0,   0, 200,   0,   0,   0,   0,   0, 120,   0,   0,   0,   0,   0,   5,   0,   0,   0,   0; // Base Qt

	end;
}


function	script	InscriptionEngine	{
	function getTitle; function checkBook; function buildMenu; function updateXP;
	.@lv = getarg(0,0);
	.n$ = getvariableofnpc(.n$,"inscription");

	if(PROFESSION != SCRIBE) {
		mes .n$;
		mes "Only personel registered";
		mes "with the Union of the";
		mes "Scribes of the Kingdom";
		mes "can actually access this";
		mes "book and its content.";
		close;
	}

	mes .n$;
	mes "Title: ^0000FF" + getTitle(PRO_INFO[0]) + "^000000";
	mes "Exp: ^0000FF" +  PRO_INFO[1] + "/1000^000000";
	mes "Book: " + checkBook();

	if(.@lv > PRO_INFO[0]) {
		mes " ";
		mes "^FF0000This book is far too advanced for my current skills.^000000";
		close;
	}
	next;

L_Menu:
	mes .n$;
	switch(select("Craft Cards:Create Dyestuffs:Open Shop:Cancel")) {
		case 4: // close
			close;
		case 3: // open shop
			close2;
			callshop "Inscription Shop",1;
			end;
			break;
		case 2: // Create dyestuff
			if ((MaxWeight-Weight) < 200 || checkweight(1201,1) == 0) {
				mes "- Wait a moment! -";
				mes "- Currently you're carrying -";
				mes "- too many items with you. -";
				close;
			}
			switch(select("Make Dyestuffs:Back")) {
				case 2:
					clear;
					goto L_Menu;
					break;
				case 1:
					switch(select("Scarlet Dyestuffs:Lemon Dyestuffs:Cobaltblue Dyestuffs:Darkgreen Dyestuffs:Orange Dyestuffs:Violet Dyestuffs:White Dyestuffs:Black Dyestuffs:Cancel")) {
						case 1: callsub S_MakeDye,1; break;
						case 2: callsub S_MakeDye,2; break;
						case 3: callsub S_MakeDye,3; break;
						case 4: callsub S_MakeDye,4; break;
						case 5: callsub S_MakeDye,5; break;
						case 6: callsub S_MakeDye,6; break;
						case 7: callsub S_MakeDye,7; break;
						case 8: callsub S_MakeDye,8; break;
						case 9:
							clear;
							goto L_Menu;
							break;
					}
			}

		case 1: // Craft cards
			.@menu$ = buildMenu(.@lv);
			explode(.@cardnames$,.@menu$,":");
			.@menu$ += "^:ff0000< Back^000000";
L_REDO:
			.@index = select(.@menu$) -1;

			if(.@index == getarraysize(getvariableofnpc(getd(".Cartas_"+.@lv+"_ID"),"inscription")))
				goto L_Menu;

			.@cardid = getvariableofnpc(getd(".Cartas_"+.@lv+"_ID["+.@index+"]"),"inscription");
			
			query_sql("SELECT strip_tags(REPLACE(`itemdesc`,'<br />',' | ')) FROM `cp_itemdesc` WHERE `itemid` = " + .@cardid + " LIMIT 1;",.@desc$);
			
			mes "Craft: ^FF6600" + .@cardnames$[.@index] + "^000000";
			mes .@desc$[0];
			next;
			mes .n$;
			mes "Craft: ^FF6600" + .@cardnames$[.@index] + "^000000";
			mes "Resource List:";

			// Blank scroll
			if(countitem(BLANK_SCROLL) > 0)
				mes "^0055001x " + getitemname(BLANK_SCROLL) + "^000000";
			else
				mes "^5500001x " + getitemname(BLANK_SCROLL) + "^000000";

			// Dyestuff
			.@dye = getvariableofnpc(.Inscription_Dye[.@lv],"inscription");
			if(countitem(.@dye) > 0 )
				mes "^0055001x " + getitemname(.@dye) + "^000000";
			else
				mes "^5500001x " + getitemname(.@dye) + "^000000";

			.@pass = 0;
			.@fail = 0;

			// Reagent
			if(countitem((.@rtid = getvariableofnpc(getd(".Cartas_"+.@lv+"_RT_ID["+.@index+"]"),"inscription"))) >= (.@rtqt = getvariableofnpc(getd(".Cartas_"+.@lv+"_RT_QT["+.@index+"]"),"inscription"))) {
				mes "^005500"+.@rtqt + "x " + getitemname(.@rtid)+"^000000";
				.@pass = 1;
			} else 
				mes "^550000"+.@rtqt + "x " + getitemname(.@rtid)+"^000000";

			// Base
			if((.@bsid = getvariableofnpc(getd(".Cartas_"+.@lv+"_BS_ID["+.@index+"]"),"inscription")) > 0) {
				if(countitem(.@bsid) >= (.@bsqt = getvariableofnpc(getd(".Cartas_"+.@lv+"_BS_QT["+.@index+"]"),"inscription")))
					mes "^005500"+ .@bsqt + "x " + getitemname(.@bsid) +"^000000";
				else {
					mes "^550000"+ .@bsqt + "x " + getitemname(.@bsid) +"^000000";
					.@pass = 0;
				}
			}

			if(.@pass && countitem(BLANK_SCROLL) >= 1 && countitem(.@dye) >= 1) {
				if(select("Craft:Cancel") == 2) {
					next;
					goto L_MENU;
				} else {
					if(.@bsid > 0)
						if(countitem(.@bsid) < .@bsqt)
							.@fail = 1;
					
					if(.@fail || countitem(.@rtid) < .@rtqt || countitem(BLANK_SCROLL) < 1 || countitem(.@dye) < 1) {
						mes "^ff0000Item(s) not found. This will be reported to the staff.^000000";
						logmes "Cheater. Inscription";
						close;
					}
					close2;
					dispbottom "Crafting.... Please don't move or you will lose all your resources",0xff6600;
					delitem BLANK_SCROLL,1;
					delitem .@dye,1;
					delitem .@rtid, .@rtqt;
					if(.@bsid > 0)
						delitem .@bsid,.@bsqt;

					progressbar "0xffffff",.@lv +2;
					getitem .@cardid,1;

					updateXP();

					mes .n$;
					mes "^0066FFSuccess!^000000";
					mes " ";
					mes "Title: ^0000FF" + getTitle(PRO_INFO[0]) + "^000000";
					mes "Exp: ^0000FF" +  PRO_INFO[1] + "/1000^000000";
					if(select("Continue:Close") == 2)
						close;
					else {
						clear;
						mes .n$;
						goto L_REDO;
					}
				}
			} else {
				mes " ";
				mes "^ff0000** Missing Materials **^000000";
				next;
				goto L_MENU;
			}
	}

S_MakeDye:
	switch(getarg(0)) {
	case 1:
		setarray .@item[0], 507, 973, 713;
		setarray .@count[0], 30,   1,   1;
		set .@dyestuff,975;
		break;
	case 2:
		setarray .@item[0], 508, 973, 713;
		setarray .@count[0], 30,   1,   1;
		set .@dyestuff,976;
		break;
	case 3:
		setarray .@item[0], 510, 973, 713;
		setarray .@count[0], 20,   1,   1;
		set .@dyestuff,978;
		break;
	case 4:
		setarray .@item[0], 510, 511, 508, 974, 973, 713;
		setarray .@count[0],  5,  20,  20,   1,   1,   1;
		set .@dyestuff,979;
		break;
	case 5:
		setarray .@item[0], 507, 508, 974, 973, 713;
		setarray .@count[0], 20,  20,   1,   1,   1;
		set .@dyestuff,980;
		break;
	case 6:
		setarray .@item[0], 510, 507, 974, 973, 713;
		setarray .@count[0], 10,  30,   1,   1,   1;
		set .@dyestuff,981;
		break;
	case 7:
		setarray .@item[0], 509, 973, 713;
		setarray .@count[0], 30,   1,   1; 
		set .@dyestuff,982;
		break;
	case 8:
		setarray .@item[0], 507, 508, 511, 510, 974, 973, 713;
		setarray .@count[0], 30,  30,  30,   5,   1,   1,   1;
		set .@dyestuff,983;
		break;
	}
	next;
	mes .n$;
	mes "Ingredients:";
	for(.@i=0;.@i<getarraysize(.@item);.@i++) {
		mes .@count[.@i] + "x " + getitemname(.@item[.@i]);
	}
	next;

	if (select("Make Dyestuffs:Cancel") == 1) {
		set .@size, getarraysize(.@item);
		// check requirements
		for(.@i=0; .@i < .@size;.@i++ )
			if( countitem(.@item[.@i]) < .@count[.@i] )
				break;
		if( .@i < .@size) {
			mes .n$;
			mes "^ff0000** Missing Materials **^000000";
			next;
			clear;
			goto L_Menu;
		}
		// delete items
		for (.@i=0; .@i < .@size; .@i++)
			delitem .@item[.@i], .@count[.@i];
		// get dyestuff
		getitem .@dyestuff,1;
		updateXP(1);
		mes .n$;
		mes "^0066FFSuccess!^000000";
		mes " ";
		mes "Title: ^0000FF" + getTitle(PRO_INFO[0]) + "^000000";
		mes "Exp: ^0000FF" +  PRO_INFO[1] + "/1000^000000";
		if(select("Continue:Close") == 2)
			close;
		else {
			clear;
			mes .n$;
			goto L_Menu;
		}
	}
	mes .n$;
	close;


	function getTitle {
		.@p = getarg(0,0);
		return getvariableofnpc(.InscriptionTitle$[.@p], "inscription");
	}

	function checkBook {
		.@p = PRO_INFO[0];
		.@id = 26560 + .@p;
		if(countitem(.@id) > 0)
			return "^005500" + getitemname(.@id) + "^000000";
		else
			return "^550000" + getitemname(.@id) + "^000000";
	}

	function buildMenu {
		.@j = getarg(0,0);
		for( .@i=0; .@i < getarraysize(getvariableofnpc(getd(".Cartas_" + .@j + "_ID"),"inscription")); .@i++ )
			setd (".@Cartas_" + .@j + "_NM$["+ .@i +"]"), getitemname(getvariableofnpc(getd(".Cartas_" + .@j + "_ID["+ .@i +"]"),"inscription"));
		.@cardnames$ = implode(getd(".@Cartas_" + .@j + "_NM$[0]"), ":");
		return .@cardnames$;
	}

	function updateXP {
		.@lv = PRO_INFO[0];
		if(.@lv == (getarraysize(getvariableofnpc(.Inscription_Exp$,"inscription")) -1))
			return;
		if(getarg(0,0) > 0) 
			PRO_INFO[1] += getvariableofnpc(.Inscription_Exp[.@lv],"inscription")/5; // 1/5 of the xp for doing dyestuffs
		else
			PRO_INFO[1] += getvariableofnpc(.Inscription_Exp[.@lv],"inscription");
		if(PRO_INFO[1] >= getvariableofnpc(.Xp2LvlUp,"inscription") && .@lv < (getarraysize(getvariableofnpc(.InscriptionTitle$,"inscription")) -1)) {
			.@lv++;
			setarray PRO_INFO[0], .@lv;
			setarray PRO_INFO[1], 0;
			specialeffect2 999;
			soundeffect "bijou_die.wav", 0;
			announce "INSCRIPTION LEVEL UP!",bc_blue|bc_self;
			dispbottom "You are now a " + getvariableofnpc(.InscriptionTitle$[.@lv],"inscription") + " Scribe. Congratulations!";
			.@bookid = 26560 + .@lv;
			dispbottom "You can now craft cards from the " + getitemname(.@bookid) +".";
		}
		return;
	}

}

// SHOPS
-	shop	Inscription Shop	-1,7433:-1,26560:-1,26561:-1,26562:-1,26563:-1,26564:-1,26565:-1,26566:-1,26567:-1

//duplicate

yuno,92,170,4	script	Apprentice Scribe	755,{
	mes " [Apprentice Scribe] ";
	mes "Hi! Nice weather, huh?";
	mes "Wanna have a look into the shop?";
	close2;
	callshop "Inscription Shop",0;
	end;
}


//will need this mysql function if using cp_itemdesc

// DROP FUNCTION IF EXISTS strip_tags; DELIMITER | CREATE FUNCTION 
// strip_tags($str text) RETURNS text BEGIN DECLARE $start, $end INT DEFAULT 1;
//  LOOP SET $start = LOCATE("<", $str, $start); IF (!$start) THEN RETURN $str;
//   END IF; SET $end = LOCATE(">", $str, $start);
//    IF (!$end) THEN SET $end = $start; END IF;
//     SET $str = INSERT($str, $start, $end - $start + 1, "");
// 	 END LOOP; END;
// 	  | DELIMITER ;