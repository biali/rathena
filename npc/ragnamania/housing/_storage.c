rentinb1,10,5,0	script	#housestor	844,{
	if(@instance == instance_id())
    	openstorage2 15,STOR_MODE_GET|STOR_MODE_PUT;
	end;

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
}