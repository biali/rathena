prontera,150,156,4	script	dmgadj	848,{
	mes " ";
	switch(select("Increase Player:Decrease player:Increase mob:Decrease mob: back to normal")){
		case 1:
			setmapflag "prontera",mf_atk_rate,DMGRATE_BL,BL_PC;
			setmapflag "prontera",mf_atk_rate,DMGRATE_SHORT,200;
			setmapflag "prontera",mf_atk_rate,DMGRATE_LONG,200;
			setmapflag "prontera",mf_atk_rate,DMGRATE_WEAPON,200;
			setmapflag "prontera",mf_atk_rate,DMGRATE_MAGIC,200;
			setmapflag "prontera",mf_atk_rate,DMGRATE_MISC,200;
			break;
		case 2:
			setmapflag "prontera",mf_atk_rate,DMGRATE_BL,BL_PC;
			setmapflag "prontera",mf_atk_rate,DMGRATE_SHORT,20;
			setmapflag "prontera",mf_atk_rate,DMGRATE_LONG,20;
			setmapflag "prontera",mf_atk_rate,DMGRATE_WEAPON,20;
			setmapflag "prontera",mf_atk_rate,DMGRATE_MAGIC,20;
			setmapflag "prontera",mf_atk_rate,DMGRATE_MISC,20;
			break;
		case 3:
			setmapflag "prontera",mf_atk_rate,DMGRATE_BL,2;
			setmapflag "prontera",mf_atk_rate,DMGRATE_SHORT,200;
			setmapflag "prontera",mf_atk_rate,DMGRATE_LONG,200;
			setmapflag "prontera",mf_atk_rate,DMGRATE_WEAPON,200;
			setmapflag "prontera",mf_atk_rate,DMGRATE_MAGIC,200;
			setmapflag "prontera",mf_atk_rate,DMGRATE_MISC,200;
			break;
		case 4:
			setmapflag "prontera",mf_atk_rate,DMGRATE_BL,2;
			setmapflag "prontera",mf_atk_rate,DMGRATE_SHORT,20;
			setmapflag "prontera",mf_atk_rate,DMGRATE_LONG,20;
			setmapflag "prontera",mf_atk_rate,DMGRATE_WEAPON,20;
			setmapflag "prontera",mf_atk_rate,DMGRATE_MAGIC,20;
			setmapflag "prontera",mf_atk_rate,DMGRATE_MISC,20;
			break;
		case 5:
			setmapflag "prontera",mf_atk_rate,DMGRATE_BL,3;
			setmapflag "prontera",mf_atk_rate,DMGRATE_SHORT,100;
			setmapflag "prontera",mf_atk_rate,DMGRATE_LONG,100;
			setmapflag "prontera",mf_atk_rate,DMGRATE_WEAPON,100;
			setmapflag "prontera",mf_atk_rate,DMGRATE_MAGIC,100;
			setmapflag "prontera",mf_atk_rate,DMGRATE_MISC,100;
			break;
	}
	mes "done.";
	close;
}