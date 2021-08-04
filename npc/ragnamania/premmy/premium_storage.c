sala_premmy,81,10,0	script	Premium Storage#1	47,{
	if(!vip_status(1) && getgmlevel()<10) 
		end;
	mes "[ Premium Storage ]";
	mes "Hello! These are your items in the Premium Storage...";
	close2;
	openstorage2 10,STOR_MODE_GET|STOR_MODE_PUT;
	end;
}

sala_premmy,78,10,0	script	Premium Storage#2	75,{
	if(!vip_status(1) && getgmlevel()<10) 
		end;
	mes "[ Premium Storage ]";
	mes "Hello! These are your items in the Premium Storage...";
	close2;
	openstorage2 10,STOR_MODE_GET|STOR_MODE_PUT;
	end;
}