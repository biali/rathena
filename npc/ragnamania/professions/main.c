// Server will accumulate 139 focus points every 10 minutes through out the day (20k in 24 hours)
// and reset it to zero at midnight. Players need to connect at least ingame in order to collect them
// at least partially or will lose the focus farming of that day.
// there is a cap of 40k focus a player can hold
-	script	focus	-1,{
	end;

OnMinute01:
OnMinute11:
OnMinute21:
OnMinute31:
OnMinute41:
OnMinute51:
	$focus_batch = gettimetick(2);
	addrid(0);
OnPcLoginEvent:
	if(FOCUS >= .max_focus)
		end;
	.@f = gettimetick(2) - FOCUS_BATCH;			// gets the difference from last collection (in seconds)
	.@f /= 600; 								// gets number of batches ran since last collection (batches run every 10 minutes)
	.@f *= .focusPerBatch;						// gets the total focus accumulated since last collection
	
	FOCUS += .@f;
	if(FOCUS > .max_focus)
		FOCUS = .max_focus;

	FOCUS_BATCH = gettimetick(2);
	end;

OnClock0000:
	addrid(0);
	set FOCUS_BATCH, 0;
	end;

OnInit:
	if($focus_batch + 600 < gettimetick(2))
		$focus_batch = gettimetick(2);
	.focusPerBatch = 139;
	.max_focus = 40000;
	end;
}