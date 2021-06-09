
// ********************************************************************
// Oven
// ********************************************************************

rentinb1,6,7,0	script	#Cooker	844,{
	if (@instance == instance_id()) {
		if(countitem(6251) > 0){
			delitem 6251,1;
			cooking 16;
		} else {
			message strcharinfo(0), "Hum... I am afraid I'll need some " + getitemname(6251) + " first.";
		}
		end;
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
