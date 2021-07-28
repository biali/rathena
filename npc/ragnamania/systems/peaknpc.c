
-	script	Highest Peak	-1,{

OnPCLoginEvent:
	debugmes "Entrou char com master_id = " + getcharid(7);
	.onlineusers++;
	goto Continue;

OnPCLogoutEvent:
	.onlineusers--;
	goto Continue;

Continue:
	if(.onlineusers > $peakusers)
		$peakusers = .onlineusers;
	
	if($peakusers < 0)
		$peakusers = 0;
	end;

OnClock0000:
	$peakusers = .onlineusers;
	end;
}