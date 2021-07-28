event_01	mapflag	loadevent

event_01,0,0,0	script	intro	-1,{
	end;

OnPCLoadMapEvent:
	if(strcharinfo(3) == "event_01") {
		dispbottom "[Enliven] Please listen to Sumara's call... ";
		dispbottom "turn on the audio - you will be teleported to the Novice Grounds automatically.",0xFF0000;
		.@start = gettimetick(2) + 55;
		soundeffect "Sumara_intro.wav", 0;
		while(gettimetick(2) < .@start) {
			sleep2 1000;
		}
		warp "new_1-1",53,111;
		end;
	}
}