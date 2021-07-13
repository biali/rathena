
-	script	Highest Peak	-1,{

OnPCLoginEvent:
	.onlineusers++;
	goto Continue;

OnPCLogoutEvent:
	.onlineusers--;
	goto Continue;

Continue:
	if(.onlineusers > $peakusers)
		$peakusers = .onlineusers;
	end;

OnClock0000:
	$peakusers = .onlineusers;
	end;
}