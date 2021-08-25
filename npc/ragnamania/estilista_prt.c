-	script	Stylist	-1,{
OnTalk:
	mes "[^0055FF ::: Adv. Stylist ::: ^000000]";
	mes "I can change your appearance.";
	if( .cost_size ){
		mes " ";
		mes "^777777[ SERVICES PAYMENT ]^000000";
		for( .@i = 0; .@i < .menu_size; .@i++ )
			if( .npc_mode & ( 1 << .@i ) )
				if( .cost[.@i] && !vip_status(1) )
					mes "^0055FF"+.menu_name$[.@i]+" : ^777777"+ValueConvert( .cost[.@i] )+"z^000000";
				else
					mes "^0055FF"+.menu_name$[.@i]+" : ^777777Free of Charge^000000";
	}
	next;
	@style = ( select( .npc_menu$ ) - 1 );

	if(getcharid(6) > 0 && @style == 2) { // style 2 = cloth color
		mes "[^0055FF ::: Adv. Stylist ::: ^000000]";
		mes "I cannot help you while you are representing a City.";
		close;
	}

	@style_value = getlook( .look_type[@style] );
	deletearray .@blacklist;
	switch( @style ){
		Case 0: .@blacklist$ = ","+getd( ".blacklist_hairstyle_"+Sex+"$" )+","; break;
		Case 1: .@blacklist$ = ","+getd( ".blacklist_haircolor_"+Sex+"$" )+","; break;
		Case 2: .@blacklist$ = ","+getd( ".blacklist_cloth_"+Sex+"$" )+","; break;
		default: break;
	}

	.@style_number = .min_style[@style];

	addtimer 1000,strnpcinfo(0)+"::OnCancela";
	do{
		message strcharinfo(0),.menu_name$[@style]+" : "+.@style_number+"th";
		.@removed = 0;
		if( compare( .@blacklist$,","+.@style_number+"," ) ){
			message strcharinfo(0),"[ REMOVED ] "+.menu_name$[@style]+" : "+.@style_number+"th";
			.@removed = 1;
			// setlook .look_type[@style],.min_style[@style];
		}else{
			setlook .look_type[@style],.@style_number;
		}
		
		.@next = .@style_number + 1;
		.@prev = .@style_number - 1;
		if( .@next > .max_style[@style] ) .@next = .min_style[@style];
		if( .@prev < .min_style[@style] ) .@prev = .max_style[@style];
		
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
				message strcharinfo(0),"Available Style : "+.min_style[@style]+" ~ "+.max_style[@style]+".";
				input .@style_number,.min_style[@style],.max_style[@style];
				break;
			Case 4:
				// .@atoi_currency = atoi( .currency$[@style] );
				if( @style_value == .@style_number ){
					message strcharinfo(0),"Swt..that is your original hairstyles.";
					break;
				} else if( vip_status(1) ) {
					.@success = 1;
				} else if( zeny >= .cost[@style] ){
					.@success = 1;
				}

				if( .@success ){
					message strcharinfo(0),"Enjoy your NEW "+.menu_name$[@style]+" !!";
					set zeny, zeny - .cost[@style];
					@style_value = .@style_number;
				}else{
					mes "You dont have enough Zeny to change this "+.menu_name$[@style]+".";
					mes "Cost : ^777777"+ValueConvert( .cost[@style] )+"z^000000";
					close2;
				}

			default:
				setlook .look_type[@style],@style_value;
				break;
		}
	}while( @select != 4 && @select != 255 );
	mes "Come back again next time. ^^";
	@select = 0;
	close2;
	deltimer strnpcinfo(0)+"::OnCancela";


OnCancela:
OnPCLogoutEvent:
	if( @select )
		setlook .look_type[@style],@style_value;
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
	
	// Payment Currency + Cost
	// Can be ITEM ID or Any Variable.
	// setarray .currency$,
	// 	Zeny,	//	Hairstyle - Ex. need Zeny
	// 	Zeny,	//	Hair Color - Ex. need Zeny
	// 	Zeny;	//	Cloth Color - Ex. need Zeny
		
	setarray .cost,
		10000,	//	Hairstyle ( 10,000 Zeny )
		20000,	//	Hair Color ( 10,000 Zeny )
		100000;	//	Cloth Color ( 10,000 Zeny )
		

	// Dont edit
	setarray .min_style,0,0,0;
	setarray .max_style,23,9,5;
	.menu_size = getarraysize( .menu_name$ );
	.cost_size = getarraysize( .cost );
	setarray .look_type,LOOK_HAIR,LOOK_HAIR_COLOR,LOOK_CLOTHES_COLOR;
	for( .npc_menu$ = ""; .@i < .menu_size; .@i++ )
		.npc_menu$ = .npc_menu$ + ( ( .npc_mode & ( 1 << .@i ) )? .menu_name$[.@i]:"" ) +":";
	// for( .@i = 0; .@i < .cost_size; .@i++ ){
	// 	.@atoi = atoi( .currency$[.@i] );
	// 	.currency_name$[.@i] = ( ( !.@atoi || getitemname( .@atoi ) == "null" )? .currency$[.@i]:getitemname( .@atoi ) );
	// }
	end;

}


// NPC Lists
// prontera,170,288,5	script	WagStylist#main	878,{
// 	doevent "Stylist::OnTalk";
// }

prontera,170,288,5	duplicate(Stylist)	Adv. Stylist#1	878
//prontera,115,181,5	duplicate(Adv. Stylist#main)	Adv. Stylist#2	878
//prontera,115,181,5	duplicate(Adv. Stylist#main)	Adv. Stylist#3	878


