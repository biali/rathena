// Dummy shop to insert items into:
-	shop	dyn_shop1	-1,501:50.

-	script	repDealer	-1,{
	function delete_arrays;
	@default$ = .default$;
    switch(getcharid(6)) {
        case 1:
        case 2:
        case 3:
        case 4:
			.@rep = callfunc("F_rep",getcharid(6));
			debugmes ""+.@rep;
			if( .@rep > 0 ) {
				for(.@i=0;.@i<getarraysize(getd("$@unc_" + getcharid(6)+strnpcinfo(2)));.@i=.@i+3 ) {
					@default$ += ",";
					@default$ += getd("$@unc_"+getcharid(6)+strnpcinfo(2)+"["+.@i+"]"); // id
					@default$ += ":";
					@default$ += getd("$@unc_"+getcharid(6)+strnpcinfo(2)+"["+(.@i+1)+"]"); // price
				}
			}
			if( .@rep > 1 ) {
				for(.@i=0;.@i<getarraysize(getd("$@rare_" + getcharid(6)+strnpcinfo(2)));.@i=.@i+3 ) {
					@default$ += ",";
					@default$ += getd("$@rare_"+getcharid(6)+strnpcinfo(2)+"["+.@i+"]"); // id
					@default$ += ":";
					@default$ += getd("$@rare_"+getcharid(6)+strnpcinfo(2)+"["+(.@i+1)+"]"); // price
				}
			}
            break;
    }
	
	explode(.@pairs$,@default$,",");
	for(.@i=0;.@i<getarraysize(.@pairs$);.@i++) {
		explode(.@item$,.@pairs$[.@i],":");
		if(.@i == 0)
			npcshopitem "dyn_shop1", atoi(.@item$[0]),atoi(.@item$[1]); //id
		else
			npcshopadditem "dyn_shop1", atoi(.@item$[0]),atoi(.@item$[1]); //price

		// lets make it easy to find an item in the seller's cart later on
		setarray @prods[.@i], atoi(.@item$[0]);
		setarray @prices[.@i], atoi(.@item$[1]);
	}

	callshop "dyn_shop1",1;
	npcshopattach "dyn_shop1";
	end;

OnBuyItem:
	for (.@i = 0; .@i < getarraysize(@bought_nameid); .@i++){
		if (@bought_quantity[.@i] <= 0){
			mes .n$;
			mes "Oops! Is everything alright with you?!";
			close;
		} else {
			// lets check if the item being sold is a limited-amount item or not:
			// We dont need to validade faction_id again here because it we've
			// done that already when creating the menu/shop list
			
			// Uncommon Items - Friendly
			.@idx = inarray(getd("$@unc_"+getcharid(6)+strnpcinfo(2)), @bought_nameid[.@i]);
			if(.@idx> -1) {
				.@qtt = .@idx+ 2;
				if (@bought_quantity[.@i] > getd("$@unc_"+getcharid(6)+strnpcinfo(2)+"["+.@qtt+"]")) {
					if(!.@uncOk && !.@rareOk)
						mes .n$;
					mes getitemname(@bought_nameid[.@i]) + " ^CC0000 out of stock.^000000";
					mes "^0000FF"+getd("$@unc_"+getcharid(6)+strnpcinfo(2)+"["+.@qtt+"]")+"x left.^000000";
					continue;
				}
				// lets mark this check as passed:
				.@uncOk = true;
			}
			
			// Rare Items - Honored
			.@idx = inarray(getd("$@rare_"+getcharid(6)+strnpcinfo(2)), @bought_nameid[.@i]);
			if(.@idx> -1) {
				.@qtt = .@idx+ 2;
				if (@bought_quantity[.@i] > getd("$@rare_"+getcharid(6)+strnpcinfo(2)+"["+.@qtt+"]")) {
					if(!.@uncOk && !.@rareOk)
						mes .n$;
					mes getitemname(@bought_nameid[.@i]) + " ^CC0000 out of stock.^000000";
					mes "^0000FF"+getd("$@rare_"+getcharid(6)+strnpcinfo(2)+"["+.@qtt+"]")+"x left.^000000";
					continue;
				}
				// lets mark this check as passed:
				.@rareOk = true;
			}

			// calculate the total cost of the item
			.@bought_item_index = inarray(@prods[0], @bought_nameid[.@i]);
			.@totalCost = @prices[.@bought_item_index] * @bought_quantity[.@i];

			if (Zeny >= .@totalCost)
				.@zenyOk = true;

			if(.@zenyOk) {
				Zeny -= .@totalCost;
				if(.@rareOk){
					set getd("$@rare_"+getcharid(6)+strnpcinfo(2)+"["+.@qtt+"]"), getd("$@rare_"+getcharid(6)+strnpcinfo(2)+"["+.@qtt+"]") - @bought_quantity[.@i];
					getitembound @bought_nameid[.@i],@bought_quantity[.@i],Bound_Account;
					continue;
				} else if (.@uncOk) {
					set getd("$@unc_"+getcharid(6)+strnpcinfo(2)+"["+.@qtt+"]"), getd("$@unc_"+getcharid(6)+strnpcinfo(2)+"["+.@qtt+"]") - @bought_quantity[.@i];
				}
				getitem @bought_nameid[.@i], @bought_quantity[.@i];
			} else {
				mes .n$;
				mes "I am sorry,";
				mes "It seems you don't have enough zeny to complete the transaction.";
				delete_arrays();
				close;
			}
		}
	}
	// mes "All done,";
	// mes "Thank you very much!";
	delete_arrays();
	if(.@rareOk && .@uncOk)
		close;
	else
		end;

OnClock0400:
OnInit:
	.n$ = "^0000AC[ Traveller Merchant ]^000000";
    //TODO : maybe set a timer OnInit to randomize when the rare items will actually become available?

    //nameid, price, qtty of rare items available in limited qualities daily to honored players with their factions
    //Honored
	setarray getd("$@rare_1"+strnpcinfo(2)+"["+0+"]"),27232,100000,1;
    setarray getd("$@rare_2"+strnpcinfo(2)+"["+0+"]"),27232,100000,1;
    setarray getd("$@rare_3"+strnpcinfo(2)+"["+0+"]"),27232,100000,1;
    setarray getd("$@rare_4"+strnpcinfo(2)+"["+0+"]"),27232,100000,1;

	//Friendly
	setarray getd("$@unc_1"+strnpcinfo(2)+"["+0+"]"),12004,500,500,12005,500,500,12008,500,300,12009,500,300;
    setarray getd("$@unc_2"+strnpcinfo(2)+"["+0+"]"),12004,500,500,12005,500,500,12008,500,300,12009,500,300;
    setarray getd("$@unc_3"+strnpcinfo(2)+"["+0+"]"),12004,500,500,12005,500,500,12008,500,300,12009,500,300;
    setarray getd("$@unc_4"+strnpcinfo(2)+"["+0+"]"),12004,500,500,12005,500,500,12008,500,300,12009,500,300;

    set .default$,"1750:2,611:100,645:100,601:100,602:100"; 
	end;

	function delete_arrays {
		deletearray @bought_quantity, getarraysize(@bought_quantity);
		deletearray @bought_nameid, getarraysize(@bought_nameid);
		deletearray @prods, getarraysize(@prods);
		deletearray @prices, getarraysize(@prices);
		return;
	}
}


prontera,57,194,0	duplicate(repDealer)	Traveller Merchant#prt1	654
prontera,270,193,0	duplicate(repDealer)	Traveller Merchant#prt2	654
morocc,172,51,4	duplicate(repDealer)	Traveller Merchant#moc1	654
payon,67,154,5	duplicate(repDealer)	Traveller Merchant#pay1	654
pay_arche,141,34,2	duplicate(repDealer)	Traveller Merchant#pay2	654
gef_fild07,295,206,5	duplicate(repDealer)	Traveller Merchant#gef1	654
comodo,114,258,4	duplicate(repDealer)	Traveller Merchant#cmd1	654
moc_fild13,155,259,7	duplicate(repDealer)	Traveller Merchant#moc2	654

// brasilis,155,175,4	duplicate(repDealer)	Duplicate Test2	654
// ayothaya,155,175,4	duplicate(repDealer)	Duplicate Test2	654
// yuno,155,175,4	duplicate(repDealer)	Duplicate Test2	654
// izlude,155,175,4	duplicate(repDealer)	Duplicate Test2	654
// alberta,155,175,4	duplicate(repDealer)	Duplicate Test2	654