function	script	F_HouseInstancing	{
	.@instance$ = "Home Sweet Home";
	if(@instance > 0) {
		instance_destroy @instance;
		sleep2 500;
	}

    .@create = instance_create(.@instance$, IM_NONE);
    if (.@create < 0) {
        mes "[Home Sweet Home]";
        switch (.@create) {
            case -1: mes "ERROR: Invalid type."; break;
            case -2: mes "ERROR: Party not found."; break;
            case -3: mes "ERROR: Instance already exists."; break;
            case -4: mes "ERROR: No free instances."; break;
        }
        mes " ";
        mes "Instance creation ^FF0000failed^000000.";
        emotion ET_HUK;
        close;
    }

	@instance = .@create;

	.@enter = instance_enter(.@instance$,-1,-1,getcharid(0),@instance);
	if (.@enter != 0) {
		mes "[Home Sweet Home]";
		switch (.@enter) {
			case 1: mes "ERROR: Party not found."; break;
			case 2: mes "ERROR: Party does not have an instance."; break;
			case 3: mes "ERROR: Unknown error."; break;
		}
		mes " ";
		mes "Instance entry ^FF0000failed^000000.";
		emotion ET_HUK;
		close;
	}
	set @house, atoi(#HOUSING$[0]);

	callfunc "F_SpawnCrops";
	callfunc "F_CheckServices";
	end;
}


function	script	F_CheckServices	{
	// #HOUSING$[0], rand(1,23);				// House Id
	// #HOUSING$[1], gettimetick(2) + .Period;	// Rent amount
	
	// #HOUSING$[4], 0; 						// Claning Lady
	// #HOUSING$[8], 0; 						// Wardrobe/Mirror
	
	// #HOUSING$[2], 0; // Gardener
	if(atoi(#HOUSING$[2])) donpcevent instance_npcname("Maia",@instance)+"::OnEnable";
	// #HOUSING$[3], 0; // Housekeeper
	if(atoi(#HOUSING$[3])) donpcevent instance_npcname("Alfonso",@instance)+"::OnEnable";
	// #HOUSING$[6], 0; // Storage
	if (HOUSE_STORAGE) donpcevent instance_npcname("#Storage",@instance)+"::OnEnable";
	// #HOUSING$[7], 0; // Beds
	if (HOUSE_BEDS) donpcevent instance_npcname("#Beds",@instance)+"::OnEnable";
	// #HOUSING$[5], 0; // Oven
	if (HOUSE_OVEN) donpcevent instance_npcname("#Oven",@instance)+"::OnEnable";

	return;	
}
