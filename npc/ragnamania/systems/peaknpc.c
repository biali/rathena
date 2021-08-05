
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
	
	if($peakusers < 0)
		$peakusers = 0;
	end;

OnMinute00:
OnMinute30:
	if (gettime(DT_HOUR) == 0 && gettime(DT_MINUTE) == 0) {
		.onlineusers = getusers(1);
		$peakusers = .onlineusers;
		end;
	}

	.onlineusers = getusers(1);
	goto Continue;

	end;

OnInit:
	.onlineusers = 0;
}