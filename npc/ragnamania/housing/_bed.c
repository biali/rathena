// ********************************************************************
// Beds
// ********************************************************************

rentinb1,33,33,0	script	#Bed1	844,{
	if (@instance == instance_id()) {
		switch(select("Rest:Cancel")) {
		case 1:
			message strnpcinfo(0), "Hope I have one of those dreams....";
			sit;
			progressbar 0xffffff,5;
			percentheal 100,100;
			specialeffect2 EF_BLESSING; sc_start SC_BLESSING,300000,10;
			specialeffect2 EF_INCAGILITY; sc_start SC_INCREASEAGI,300000,10;
			stand;
			if (countitem(521) >= 1){
				delitem 521,1;
				if(rand(3) == 0)
					warp "dreamland",128,132;
			}
			end;
			break;
		case 2:
			end;
			break;
		}
	} else {
		dispbottom "I shouldn't be messying with my friend's stuff...";
	}
	end;

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
}

rentinb1,26,33,0	duplicate(#Bed1)	#Bed2	844
rentinb1,6,33,0	duplicate(#Bed1)	#Bed3	844