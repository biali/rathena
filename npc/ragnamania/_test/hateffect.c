prontera,155,179,5	script	frost_teste	810,{
end;
	
OnMy:
	input .@number;
	hateffect .@number,true;
	end;
	
OnMy2:
hateffect 218,true;
end;
	
OnInit:
	bindatcmd "efc",strnpcinfo(3)+"::OnMy";
	bindatcmd "ef",strnpcinfo(3)+"::OnMy2";
	
}