// credits to Annieruru
function	script	ValueConvert	{
	set .@num, atoi(""+getarg(0));
	if ( .@num == 0 || .@num >= 2147483647 ) return getarg(0);
	set .@l, getstrlen(""+.@num);
	for ( set .@i,0; .@i < .@l; set .@i, .@i + 1 ) {
		set .@num$, .@num % pow(10,.@i+1) / pow(10,.@i) + .@num$;
			if ( (.@i+1) % 3 == 0 && .@i+1 != .@l ) set .@num$, ","+ .@num$;
	}
	return .@num$;
}

rentinb1,34,24,0	script	#wardrobe	844,{
 
    // Dont edit this bit
    setarray .@min_style,0,0,0;
    if(sex == SEX_MALE)
    	setarray .@max_style,95,127,700;
    else
    	setarray .@max_style,99,127,700;
	
	.@menu_size = getarraysize( .menu_name$ );
	.@cost_size = getarraysize( .cost );
	setarray .look_type,LOOK_HAIR,LOOK_HAIR_COLOR,LOOK_CLOTHES_COLOR;
	for( .@npc_menu$ = ""; .@i < .@menu_size; .@i++ )
		.@npc_menu$ = .@npc_menu$ + ( ( .npc_mode & ( 1 << .@i ) )? .menu_name$[.@i]:"" ) +":";

OnTalk:
	mes "[^0055FF ::: " + strcharinfo(0) + " ::: ^000000]";
	mes "Maybe I should change my look today...";
	if( .@cost_size ){
		mes " ";
		mes "^777777[ Rental Price List ]^000000";
		for( .@i = 0; .@i < .@menu_size; .@i++ )
			if( .npc_mode & ( 1 << .@i ) )
				mes "^0055FF"+.menu_name$[.@i]+" : ^777777"+ValueConvert( .cost[.@i] )+" z^000000";
	}
	next;
	@style = ( select( .@npc_menu$ ) - 1 );
	@style_value = getlook( .look_type[@style] );

	.@style_number = .@min_style[@style];

	if(getcharid(6) > 0 && @style == 2) { // style 2 = cloth color
		mes "[^0055FF ::: " + strcharinfo(0) + " ::: ^000000]";
		mes "I cannot change my styles while representing a City.";
		close;
	}

	addtimer 1000,strnpcinfo(0)+"::OnCancela";
	do{
		message strcharinfo(0),.menu_name$[@style]+" : "+.@style_number+"th";
		.@removed = 0;
		if( compare( .@blacklist$,","+.@style_number+"," ) ){
			message strcharinfo(0),"[ REMOVED ] "+.menu_name$[@style]+" : "+.@style_number+"th";
			.@removed = 1;
			setlook .look_type[@style],.@min_style[@style];
		}else{
			setlook .look_type[@style],.@style_number;
		}
		
        // 87 is ugly as fuck
		.@next = .@style_number + 1;
        if(sex == SEX_MALE && .@next == 88)
            .@next++;

		.@prev = .@style_number - 1;
                if(sex == SEX_MALE && .@prev == 88)
            .@prev--;


		if( .@next > .@max_style[@style] ) .@next = .@min_style[@style];
		if( .@prev < .@min_style[@style] ) .@prev = .@max_style[@style];
		
		@select = prompt( (( .@backward )?"Backward":"Forward" )+" - [ ^777777"+(( .@backward )? .@prev:.@next )+"th Style^000000 ]",
					(( !.@backward )?"Backward":"Forward" )+" - [ ^777777"+(( !.@backward )? .@prev:.@next )+"th Style^000000 ]",
					"Jump to a Style",
					( .@removed )?"":"^0055FFOkay, I want this "+.menu_name$[@style]+"^000000" );
					
		if( @select == 2 ) .@backward = !.@backward;
		
		switch( @select ){
			Case 1:	
			Case 2:
				.@style_number = (( .@backward )? .@prev:.@next );
				break;
			Case 3:	
				message strcharinfo(0),"Available Style : "+.@min_style[@style]+" ~ "+.@max_style[@style]+".";
				input .@style_number,.@min_style[@style],.@max_style[@style];
				break;
			Case 4:
				if( @style_value == .@style_number ){
					message strcharinfo(0),"Swt..that is your original hairstyles.";
					break;
				} else if( zeny >= .cost[@style] ){
					set zeny, zeny - .cost[@style];
					.@success = 1;
				}

				if( .@success ){
					message strcharinfo(0),"Enjoy your NEW "+.menu_name$[@style]+" !!";
					@style_value = .@style_number;
				}else{
					mes "You dont have enough Zeny to change your "+.menu_name$[@style]+".";
					mes "Cost : ^777777"+ValueConvert( .cost[@style] )+" z^000000";
					close2;
				}

			default:
				setlook .look_type[@style],@style_value;
				break;
		}
	} while( @select != 4 && @select != 255 );
	mes "Come back again next time. ^^";
	@select = 0;
	close2;
	deltimer strnpcinfo(0)+"::OnCancela";


OnCancela:
	if( @select )
		setlook .look_type[@style],@style_value;
	end;

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
	
OnInit:
	// NPC Mode ( Bitmask )
	//	1 - Enable Hairstyle
	//	2 - Enable Hair Color
	//	4 - Enable Cloth Color
	.npc_mode = 7;
	
	// Menu Name
	setarray .menu_name$,
		"Hair Style",
		"Hair Color",
		"Cloth Color";
		
	setarray .cost,
		50000,	//	Hairstyle ( 10,000 Zeny )
		110000,	//	Hair Color ( 10,000 Zeny )
		190000;	//	Cloth Color ( 10,000 Zeny )
	end;
}