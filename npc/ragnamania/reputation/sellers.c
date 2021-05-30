// Dummy shop to insert items into:
-	shop	dyn_shop1	-1,501:50.

prontera,181,200,4	script	Traveler Merchant	123,{
	function delete_arrays;
	@default$ = .default$;
    switch(getcharid(6)) {
        case 1:
        case 2:
        case 3:
        case 4:
            for(.@i=0;.@i<getarraysize(getd("$@rare_" + getcharid(6)));.@i=.@i+3 ) {
                @default$ += ",";
                @default$ += getd("$@rare_"+getcharid(6)+"["+.@i+"]"); // id
                @default$ += ":";
                @default$ += getd("$@rare_"+getcharid(6)+"["+(.@i+1)+"]"); // price
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
	mes .n$;
	for (.@i = 0; .@i < getarraysize(@bought_nameid); .@i++){
		if (@bought_quantity[.@i] <= 0){
			mes "Oops! Is everything alright with you?!";
			close;
		} else {
			// lets check if the item being sold is a limited-amount item or not:
			// We dont need to validade faction_id again here because it we've
			// done that already when creating the menu/shop list
			.@rindex = inarray(getd("$@rare_"+getcharid(6)), @bought_nameid[.@i]);
			if(.@rindex > -1) {
				.@qtt = .@rindex + 2;
				if (@bought_quantity[.@i] > getd("$@rare_"+getcharid(6)+"["+.@qtt+"]")) {
					mes getitemname(@bought_nameid[.@i]) + " ^CC0000 out of stock.^000000";
					mes "^0000FF"+getd("$@rare_"+getcharid(6)+"["+.@qtt+"]")+"x left.^000000";
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
				if(.@rareOk)
					set getd("$@rare_"+getcharid(6)+"["+.@qtt+"]"), getd("$@rare_"+getcharid(6)+"["+.@qtt+"]") - @bought_quantity[.@i];
				getitem @bought_nameid[.@i], @bought_quantity[.@i];
			} else {
				mes "I am sorry,";
				mes "It seems you don't have enough zeny to complete the transaction.";
				delete_arrays();
				close;
			}
		}
	}
	mes "All done,";
	mes "Thank you very much!";
	delete_arrays();
	close;

OnClock0400:
OnInit:
	.n$ = "^0000AC[ Traveller Merchant ]^000000";
    //TODO : maybe set a timer OnInit to randomize when the rare items will actually become available?

    //nameid, price, qtty of rare items available in limited qualities daily to honored players with their factions
    setarray $@rare_1[0],27232,100000,1,4048,5000,10;
    setarray $@rare_2[0],27232,100000,1,4048,5000,10;
    setarray $@rare_3[0],27232,100000,1,4048,5000,10;
    setarray $@rare_4[0],27232,100000,1,4048,5000,10;

    set .default$,"1750:2,611:100,501:100,502:100,506:100,645:100,601:100,602:100"; 
	end;

	function delete_arrays {
		deletearray @bought_quantity, getarraysize(@bought_quantity);
		deletearray @bought_nameid, getarraysize(@bought_nameid);
		deletearray @prods, getarraysize(@prods);
		deletearray @prices, getarraysize(@prices);
		return;
	}
}
