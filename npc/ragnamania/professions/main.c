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
	$focus_batch++;
	addrid(0);
OnPcLoginEvent:
	if(FOCUS >= .max_focus)
		end;
	.@multiplier = $focus_batch - FOCUS_BATCH;
	.@total_focus = .focusPerBatch * .@multiplier;
	set FOCUS, FOCUS + .@total_focus;
	if(FOCUS > .max_focus)
		set FOCUS, .max_focus;
	set FOCUS_BATCH, $focus_batch;
	end;

OnClock0000:
	set $focus_batch,0;
	addrid(0);
	set FOCUS_BATCH, 0;
	end;

OnInit:
	.focusPerBatch = 139;
	.max_focus = 40000;
	end;
}