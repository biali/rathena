-	script	rmc	-1,{
	end;

OnInit:
	.n$ = "^DD10DD[ Ragnamania Cash ]^000000";
	.rmcCost = 1; // custo em reais para 1 rmc
	.rmcMania = 1000; // Custo em Manias para cada 1 RMC
	.rmcMin = 100; // qtde minima de rmc no inventario para iniciar uma transferencia
	bindatcmd("rmc",strnpcinfo(0)+"::OnCommand",0,100);

	// create tables
	query_sql "CREATE TABLE IF NOT EXISTS `rmc_info` (`id` INT NOT NULL AUTO_INCREMENT, `masterid` INT NOT NULL, `pix_type` VARCHAR(10) NOT NULL, `pix_key` VARCHAR(150) NOT NULL, PRIMARY KEY (id));";
	query_sql "CREATE TABLE IF NOT EXISTS `rmc_requests` (`id` INT NOT NULL AUTO_INCREMENT, `datetime` DATETIME NOT NULL, `masterid` INT NOT NULL, `value` INT NOT NULL, `status` SMALLINT(1) NOT NULL DEFAULT '0', PRIMARY KEY (id));";
	end;

OnCommand:
L_MENU:
	mes .n$;
	mes "Hello, " +strcharinfo(0);
	mes "How can I be of your help?";
	switch(select("My RMC Account:Buy RMC:Withdraw:Informations:Close")) {
		case 1:
L_CHANGEINFO:
			clear;
			.@c = query_sql("SELECT `masterid`, `pix_type`, `pix_key` FROM `rmc_info` WHERE `masterid` = " + getcharid(7) + " LIMIT 1",.@masterid, .@pixtype$, .@pixkey$);

			if(.@c == 0) {
				mes .n$;
				mes "It seems like you have not registered your PIX details yet. Do you want to do it now?";
				if(select(" - Yes, please: - No, thank you") == 2) {
					clear;
					mes .n$;
					mes "No problem. See you around.";
					close;
				}
L_INPUTTYPE:
				clear;
				mes .n$;
				mes "Inform your Pix Type:";
				mes "[ 1 ] CPF";
				mes "[ 2 ] CNPJ";
				mes "[ 3 ] Email Address";
				mes "[ 4 ] Phone Number";
				mes "[ 5 ] Random-Generated Key";
				input .@type;
				if(.@type < 1 || .@type > 5) {
					dispbottom "Invalid option. Please try again",0xFF6600;
					goto L_INPUTTYPE;
				}
				switch(.@type) {
					case 1: .@t$ = "CPF"; break;
					case 2: .@t$ = "CNPJ"; break;
					case 3: .@t$ = "Email"; break;
					case 4: .@t$ = "Telefone"; break;
					case 5: .@t$ = "Random"; break;
				}
L_INPUTKEY:
				clear;
				mes .n$;
				mes "Perfect!";
				mes "Now, please, your Pix Key:";
				input .@key$;
				.@str$ = "abcdefghijklmnopqrstuvwxyz0123456789+-_@.";
				.@s1 = getstrlen(.@key$);
				.@s2 = getstrlen(.@str$);
				freeloop(0);
				for(.@i=0; .@i<.@s1; .@i++) {
					for(.@j=0; .@j<.@s2; .@j++) {
						if(charat(.@str$,.@j) == charat(.@key$,.@i))
							break;
						if(.@j == (.@s2 -1)) {
							dispbottom "We've found invalid characters in your input. Please try again",0xFF6600;
							goto L_INPUTKEY;
						}
					}
				}
				query_sql("INSERT INTO `rmc_info` (`masterid`,`pix_type`,`pix_key`) VALUES ("+getcharid(7)+",'"+.@t$+"','"+.@key$+"');");
				next;
				query_sql("SELECT `pix_type`,`pix_key` FROM `rmc_info` WHERE `masterid` = " + getcharid(7) + " LIMIT 1;", .@pixtype$, .@pixkey$);
				mes .n$;
				mes "Your Pix Details:";
				mes "Pix Type: ^0000FF" + .@pixtype$[0] + "^000000";
				mes "Pix: ^0000FF" + .@pixkey$[0] + "^000000";
				next;
				goto L_MENU;
			}
			mes .n$;
			mes "Confirm your Pix Type:";
			mes "Pix Type: ^0000FF"+ .@pixtype$[0] +"^000000";
			if(select("^00AA00It is correct^000000:^AA0000Change it^000000") == 2) {
L_LOOP:
				clear;
				mes .n$;
				mes "Enter the number according to your Pix Type:";
				mes "[ 1 ] CPF";
				mes "[ 2 ] CNPJ";
				mes "[ 3 ] Email Address";
				mes "[ 4 ] Phone Number";
				mes "[ 5 ] Random-Generated Key";
				input .@type;
				if(.@type < 1 || .@type > 5)
					goto L_LOOP;
				switch(.@type) {
					case 1: .@t$ = "CPF"; break;
					case 2: .@t$ = "CNPJ"; break;
					case 3: .@t$ = "Email"; break;
					case 4: .@t$ = "Telefone"; break;
					case 5: .@t$ = "Random"; break;
				}
				query_sql("UPDATE `rmc_info` SET  `type` = '"+ .@t$ +"' WHERE `masterid` = " + getcharid(7) + " LIMIT 1;");
				setarray .@pixtype$[0], .@type;
			}
			next;
			mes .n$;
			mes "Confirm your Pix:";
			mes "Pix: ^0000FF"+ .@pixkey$[0] +"^000000";
			if(select("^00AA00It is correct^000000:^AA0000Change it^000000") == 2) {
				input .@key$;
				.@str$ = "abcdefghijklmnopqrstuvwxyz0123456789+-_@.";
				.@s1 = getstrlen(.@key$);
				.@s2 = getstrlen(.@str$);
				freeloop(0);
				for(.@i=0; .@i<.@s1; .@i++) {
					for(.@j=0; .@j<.@s2; .@j++) {
						if(charat(.@str$,.@j) == charat(.@key$,.@i))
							break;
						if(.@j == (.@s2 -1)) {
							mes "Sorry, we've found invalid characters in your input.";
							close;
						}
					}
				}
				freeloop(1);
				query_sql("UPDATE `rmc_info` SET  `key` = '" +.@key$ + "' WHERE `masterid` = " + getcharid(7) + " LIMIT 1");
				setarray .@pixkey$[0], .@key$;
			}
			next;
			mes .n$;
			mes "Your details:";
			mes "Pix Type: ^0000FF" + .@pixtype$[0] + "^000000";
			mes "Pix: ^0000FF" + .@pixkey$[0] + "^000000";
			next;
			goto L_MENU;

		case 2:
			clear;
			mes .n$;
			mes "Mania$ Available: " + (#CASHPOINTS > 0 ? callfunc("F_InsertComma",#CASHPOINTS) : "0.00");
			next;
			if(#CASHPOINTS <= 0)
				goto L_MENU;

			if(select(" > Buy RMC: > Cancel") == 2)
				goto L_MENU;

			mes .n$;
			mes "How Many RMC you'd like to buy?";
			mes "Maximum: " + #CASHPOINTS / .rmcMania;
			input .@qtde;

			if(.@qtde < #CASHPOINTS / .rmcMania) {
				mes "^FF0000Invalid Amount.^000000";
				next;
				goto L_MENU;
			}

			if(select(" > Confirm: > Cancel") == 2) {
				clear;
				goto L_MENU;
			}

			if(.@qtde < #CASHPOINTS / .rmcMania) {
				mes "^FF0000Something went wrong. Manias not found. This incident will be reported to the staff.^000000";
				logmes "Cheater. Trying to buy RMC but removed the Manias in between menus.";
				close;
			}

			set #CASHPOINTS, #CASHPOINTS - (.@qtde * .rmcMania);
			getitem RMC, .@qtde;

			clear;
			mes .n$;
			mes "It is all done.";
			mes "Thank you very much";
			mes "for your custom.";
			next;
			goto L_MENU;
		case 3:
			clear;
			query_sql("SELECT `masterid`,`pix_type`,`pix_key` FROM `rmc_info` WHERE `masterid` = " + getcharid(7) + " LIMIT 1",.@masterid, .@pixtype$, .@pixkey$);
			mes .n$;
			mes "Please confirm your details:";
			mes "Pix Type: ^0000FF" + .@pixtype$[0] + "^000000";
			mes "Pix: ^0000FF" + .@pixkey$[0] + "^000000";
			if(select("My info is right:Change my info") == 2) {
				clear;
				goto L_CHANGEINFO;
			}
			if(countitem(RMC) < .rmcMin) {
				clear;
				mes .n$;
				mes "I am sorry but it seems like you don't have enough RMCs in your inventory. Please remember you'll need at least " + .rmcMin + " RMCs to request a withdraw.";
				next;
				goto L_MENU;
			}
			delitem RMC,.rmcMin;
			logmes "RMC : Collected " + .rmcMin + " from  master account " + getcharid(7);
			query_sql("INSERT INTO `rmc_requests` (`datetime`, `masterid`, `value`, `status`) VALUES (NOW(), "+getcharid(7)+","+ (.rmcMin * 90)/100 +",0)");
			clear;
			mes .n$;
			mes "It is all done.";
			mes "Please allow 24 hours for the staff to proccess your request.";
			next;
			goto L_MENU;
		case 4:
			clear;
			mes .n$;
			mes "RMC stands for Ragnamania Cash.";
			mes "It is a system where you can safely sell equipments ingame to another player and convert it back to real money transferred directly into your bank account.";
			next;
			mes .n$;
			mes "At the moment RMC is only available for those with a PIX account.";
			next;
			mes .n$;
			mes "One can buy RMC using my services at the rate of 1 RMC = " + .rmcCost + ".00 BRL.";
			next;
			mes .n$;
			mes "One can request to withdraw their RMC in multiples of 100.";
			mes "This means that, anytime, whenever you have 100 or more RMC in your account you can call me and request a withdraw.";
			next;
			mes .n$;
			mes "Ragnamania usually process payments Monday to Friday towards the end of the day.";
			next;
			mes .n$;
			mes "It means it could take up to 24 hours  (excluding weekends and holidays) for you to receive your money into your bank account via PIX.";
			next;
			clear;
			goto L_MENU;
		case 5:
			close;
	}
	end;
}