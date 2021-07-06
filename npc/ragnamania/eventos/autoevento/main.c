-	script	Event_Management	-1,{
OnJoinEvent:
	switch($@CurrentEvent){
		default:	message strcharinfo(0),"Feira de Fim-de-M�s: N�o h� eventos ocorrendo no momento.";	end;
		case 1:	callfunc("JoinEvent","Apocalipse Zumbi",2,50,27,"silk_lair",198,189,10);	break;
		case 2:	callfunc("JoinEvent","Dado Da Morte",2,2,16,"quiz_01",205,92,100);			break;
		case 3:	callfunc("JoinEvent","Last Man Standing",2,120,18,"pvp_n_1-5",0,0,20);		break;
		case 4:	callfunc("JoinEvent","Labirinto Maldito",2,50,27,"maze",371,143,30);		break;
		case 5: callfunc("JoinEvent","Poring Hunt",2,50,17,"pvp_n_1-5",0,0,30);				break;
		case 6: callfunc("JoinEvent","Manhunt",2,120,82,"pvp_n_1-5",0,0,10);				break;
		case 7:	callfunc("JoinEvent","Clucky Cluckers",2,50,48,"prontera",156,219,0);		break;


		// Feature used for GM Customazation
		case 255: callfunc("JoinEvent",.EventName$,.Minplayers,.MinBase,.Conditions,.EventMap$,.MapX,.MapY,.Duration);	break;
	}
end;

OnRunEvent:
	if(getgmlevel() < 99) end; 
	if($@LastEvent) { 
		mes "Feira de Fim-de-M�s";
		mes "ATENCAO: Existe um evento em andamento ("+$@LastEvent+")! Se voce continuar ira interromper este evento! Deseja mesmo continuar?";
		if(select("N�O:Sim") == 1) {
			close;
		}
		next;
	}
	if(agitcheck()||agitcheck2()){
		mes "Feira de Fim-de-M�s";
		mes "Desculpa, nao posso fazer eventos durante a WoE.";  
		close;
	}
	deletearray $@EventPlayers[0],getarraysize($@EventPlayers);
	set $@CurrentEvent,0;
	set $@LastEvent,0;
	dispbottom "Feira de Fim-de-M�s: O evento anterior foi cancelado/interrompido.";

	mes "Feira de Fim-de-M�s";
	mes "Certo, chefe! Qual evento faremos agora?";
	close2;
	switch(select("Apocalipse Zumbi:Dado Da Morte:Last Man Standing:Labirinto Maldito:Poring Hunt:Manhunt:Clucky Cluckers")){
		case 1:	detachrid;
			callfunc("ZombieRUN",1);
			break;
		case 2:	detachrid;
			callfunc("1234RUN",2);
			break;
		case 3:	detachrid;
			callfunc("PvpEventRUN",3);
			break;
		case 4:	detachrid;
			callfunc("MazeRUN",4);
			break;
		case 5:	detachrid;
			callfunc("PoringRUN",5);
			break;
		case 6: detachrid;
			callfunc("ManHuntRUN",6);
			break;
		case 7: detachrid;
			callfunc("CluckersRun",7);
			break;
		default: close;
	}
	end;  

OnMinute30:
	//end; //DEBUG remover

	// A feira comeca dia 20 de cada mes e corre ate o ultimo dia do mes
	if(gettime(DT_DAYOFMONTH)<20)
		end;

	if($@LastEvent)
		$@LastEvent = 0;

	deletearray $@EventPlayers[0],getarraysize($@EventPlayers);

	if(agitcheck() || agitcheck2() || $@CurrentEvent) 
		end;

	switch(rand(1,7)) {
					//function,eventID
		case 1:		callfunc("ZombieRUN",1);	break;
		case 2:		callfunc("1234RUN",2);		break;
		case 3:		callfunc("PvpEventRUN",3);	break;
		case 4:		callfunc("MazeRUN",4);		break;
		case 5:		callfunc("PoringRUN",5);	break;
		case 6:		callfunc("ManHuntRUN",6);	break;
		case 7:		callfunc("CluckersRun",7);	break;

//		case :		//Mvp Arena			break;	//Summons a random mvp and turns pvp on
//		case :		//Rag-narok training		break;	//Summons random mvps (no drops) from list continuesly with pvp on, gives buffs to all after and prize 4 lms
//		case :		//X-O quiz_01 140 277		break;	//like 1234 but just 2 squares
//		case :		//Invasion			break;	//save old_morocc from satan morroc
//		case :		//lucky Pick			break;	//pick one person who enters map and gives them a prize
//		case :		//DB event			break:	//Auto summons monsters from dead branches (pvp on)
	}
	end;

OnPCDieEvent:
	if($@LastEvent > 0 && inarray($@EventPlayers,getcharid(3))) {
		switch($@LastEvent){
		case 1: // Apocalipse Zumbi
			if(strcharinfo(3) == "silk_lair"){
				warp "prontera",155,181;
			}
			break;
		case 3: // PvpEvent
			deletearray $@EventPlayers[inarray($@EventPlayers[0],getcharid(3))],1;
			warp "prontera",155,181;
			recovery 0,getcharid(0);
			break;
		case 6: // Manhunt
			if (getcharid(3) == $@EventPlayers[$@Target]) {
				//recovery(0,getcharid(0));
				warp "prontera",155,181;
				deletearray $@EventPlayers[inarray($@EventPlayers[0],getcharid(3))],1;
				if(isloggedin(killerrid)) {
					announce "Feira de Fim-de-M�s: Parab�ns, "+strcharinfo(0,getcharid(0,rid2name(killerrid)))+"! Um dos vencedores do evento Manhunt!",bc_all,0x00AA00;
					getitem 7859,2,killerrid;
       			}
       			// reverte a poha toda
       			atcommand "#size "+strcharinfo(0)+" 0";
       			atcommand "#killable "+strcharinfo(0)+"";
				set $@Target,1000;
			}
			break;
		default:
			break;
		}
	}
	end;

OnPCLogOutEvent:
	if($@LastEvent > 0){
		switch($@LastEvent){
		case 6:
			if(getcharid(3) == $@EventPlayers[$@Target]){
				mapannounce "pvp_n_1-5","Feira de Fim-de-M�s: Oh... Estraga prazeres! Nosso alvo deslogou. Este round sera anulado.",bc_map,0x00AAFF,0,16;
				set $@Target,1000;
			}
			break;
		default:
			break;
		}
	}
	end;

OnInit:
	bindatcmd("joinevent","Event_Management::OnJoinEvent",0,99);
	bindatcmd("runevent","Event_Management::OnRunEvent",99,99);
	set $@CurrentEvent,0;
	set $@LastEvent,0;
end;
}


function	script	JoinEvent	{
//callfunc("JoinEvent",<eventname>,<minplayers>,<minbase>,<conditions>,<eventmap>,<mapx>,<mapy>,<length>);

	.eventname$ = getarg(0,"Desconhecido");
	.minplayers = getarg(1,1);
	.minbase	= getarg(2,1);
	.conditions	= getarg(3,0);
	.eventmap$ 	= getarg(4,"prontera");
	.eventx 	= getarg(5,0);
	.eventy 	= getarg(6,0);
	.length		= getarg(7,0);

	if($@CurrentEvent <= 0 ) { 
		message strcharinfo(0),"Feira de Fim-de-M�s: N�o h� eventos dispon�veis no momento."; 
		close;
	} else {
		mes "Feira de Fim-de-M�s";
		mes "Evento: ^0000AA[ " + .eventname$ + " ] ^000000";
		mes "Level M�nimo: ^0000AA[ "+ .minbase +" ] ^000000";
		mes "M�nimo de Jogadores: ^0000AA[ "+ .minplayers +" ] ^000000";
		mes "Ingresso: ^0000AA[ 1x " + getitemname(7539) + " ] ^000000";
		next;

		callfunc "DE_Rules", $@CurrentEvent;

		mes "Feira de Fim-de-M�s";
		mes "Mandei as regras do evento ^0000FF"+ .eventname$ +"^000000 pra voce.";
		mes "E a�, vem brincar com a gente?";
		next;
		mes "Feira de Fim-de-M�s";
		if(select("^00AA00Sim, claro!:^AA0000N�o, agora n�o.^000000") == 2){
			mes "Sem problemas! Vejo voc� mais tarde, ent�o!";
			close;
		} 

		if(BaseLevel < .minbase) {
			mes "Desculpa mas este evento � apenas para jogadores com level " + .minbase + " ou superior."; 
			close;
		} 

		if(countitem(7539) < 1 ){ 
			mes "Desculpa, voce precisa de 1x "+getitemname(7539)+" para participar."; 
			close;
		} else {
			if(.conditions&16) {
				if(inarray($@EventPlayers[0],getcharid(3)) >= 0) {
					mes "Voce ja est� inscrito para este evento! heh."; 
					close; 
				} else {
					setarray $@EventPlayers[getarraysize($@EventPlayers)],getcharid(3);
					delitem 7539,1;	// Poring Coin da Inscricao
					getitem 7859,1;	// Premio de participacao
				}	
			}

			if (.conditions&1 && (checkfalcon() || checkcart() || checkriding() || ismounting())) {
				if(checkfalcon()) setfalcon 0;
				if(checkcart()) setcart 0;
				if(checkriding()) setriding 0; 
				if(ismounting()) setmounting;
			}

			if(.conditions&1) callfunc "F_Dispell";
			if(.conditions&2) percentheal 100,100;
			if(.conditions&4) sc_start SC_DECREASEAGI,300000+getarg(15,0)*60000,10;
			if(.conditions&8) atcommand "@storeall";
			if(.conditions&32) end;
			if(.conditions&64) Hp = 5000;

			warp .eventmap$,.eventx,.eventy;
			end;
		}
		mes "Oops! Algo saiu errado. Por favor, informe a staff.";
		logmes "ERROR: Eventos dinamicos @joinevent";
		close;
	}
}


function	script	DE_Rules	{
	if(!$@CurrentEvent) {
		mes "Feira de Fim-de-M�s";
		mes "Oops! Parece que demoramos um pouco demais... o evento j� come�ou!";
		next;
		mes "Feira de Fim-de-M�s";
		mes "Mas n�o se preocupe, teremos outros! O pr�ximo evento acontecer� dentro de uma hora.";
		close;
	} else{
		switch(getarg(0)){
		case 1:
			dispbottom "Feira de Fim-de-M�s: --- Apocalipse Zumbi ---";
			dispbottom "Feira de Fim-de-M�s: Seus �tens ser�o enviados para o armaz�m e Peco, Falcao, Carrinho e Montaria removidos assim como todos os buffs.";
			dispbottom "Feira de Fim-de-M�s: A cada minuto ser�o invocadas ondas de mortos-vivos,";
			dispbottom "Feira de Fim-de-M�s: Sua miss�o � permanecer vivo at� o final.";
			dispbottom "Feira de Fim-de-M�s: Os vencedores ganhar�o tr�s " +getitemname(7859)+" e os demais participantes ganhar�o um.";
			dispbottom "Feira de Fim-de-M�s: Ser�o dez ondas de monstros. N�o ataque os monstros";
			dispbottom "Feira de Fim-de-M�s: Ou voc� perder� HP e SP.";
			break;
		case 2:
			dispbottom "Feira de Fim-de-M�s: --- Dado Da Morte ---";
			dispbottom "Feira de Fim-de-M�s: Cada jogador escolhe uma caixa: 1, 2, 3 ou 4.";
			dispbottom "Feira de Fim-de-M�s: Come�aremos uma contagem regressiva de 10 at� 0.";
			dispbottom "Feira de Fim-de-M�s: Quando chegarmos a 0, um dado da morte com quatro lados ser� lan�ado.";
			dispbottom "Feira de Fim-de-M�s: Aquele(s) que estiver(em) na caixa com o numero sorteado ser�(o) eliminado(s)";
			dispbottom "Feira de Fim-de-M�s: assim como todos os que estiverem nas escadas ou na plataforma.";
			dispbottom "Feira de Fim-de-M�s: O numero de jogadores remanecentes ser� anunciado";
			dispbottom "Feira de Fim-de-M�s: e o processo se repete ate que tenhamos um �nico vencedor.";
			dispbottom "Feira de Fim-de-M�s: O vencedor ganha tr�s " +getitemname(7859)+" e os participantes ganhar�o apenas um.";
			break;
		case 3:
			dispbottom "Feira de Fim-de-M�s: --- Last Man Standing  ---";
			dispbottom "Feira de Fim-de-M�s: Esta � uma arena PvP livre onde o �ltimo sobrevivente ser� o vencedor.";
			dispbottom "Feira de Fim-de-M�s: H� um limite de 20 minutos e se n�o tivermos um vencedor at� l� o evento termina.";
			dispbottom "Feira de Fim-de-M�s: O vencedor ganha tr�s " +getitemname(7859)+" e os participantes ganhar�o apenas um.";
			break;
		case 4:
			dispbottom "Feira de Fim-de-M�s: --- Labirinto Maldito  ---";
			dispbottom "Feira de Fim-de-M�s: Seus �tens ser�o enviados para o armaz�m e Peco, Falcao, Carrinho e Montaria removidos assim como todos os buffs.";
			dispbottom "Feira de Fim-de-M�s: As regras s�o s�mples: O primeiro a encontrar e tocar no meu ajudante, ganha.";
			dispbottom "Feira de Fim-de-M�s: Mas para isso voc� precisar� atravessar um labirinto insano!";
			dispbottom "Feira de Fim-de-M�s: O vencedor ganha tr�s " +getitemname(7859)+" e os participantes ganhar�o apenas um.";
			break;
		case 5:
			dispbottom "Feira de Fim-de-M�s: --- Poring Hunt ---";
			dispbottom "Feira de Fim-de-M�s: As regras sao simples: Mate o 'Poring' com o nome certo para ser levado de volta a Prontera com seu pr�mio.";
			dispbottom "Feira de Fim-de-M�s: Mate o poring errado e voc� ganha apenas o pr�mio de participa��o.";
			dispbottom "Feira de Fim-de-M�s: Os vencedores ganham tr�s " +getitemname(7859)+" e os participantes ganhar�o apenas um.";
			dispbottom "Feira de Fim-de-M�s: Existem 2 Porings com o nome certo e um limite de 30 minutos para encontr�-los.";
			break;
		case 6:
			dispbottom "Feira de Fim-de-M�s: --- Manhunt ---";
			dispbottom "Feira de Fim-de-M�s: O objetivo neste evento � matar o jogador alvo em 60 segundos.";
			dispbottom "Feira de Fim-de-M�s: Aquele que der o last hit no alvo, ganha tr�s " +getitemname(7859)+".";
			dispbottom "Feira de Fim-de-M�s: Mas se o alvo sobreviver, ele � quem ganha o pr�mio.";
			dispbottom "Feira de Fim-de-M�s: Se o jogador alvo morrer, ele ser� mandado de volta para Prontera.";
			dispbottom "Feira de Fim-de-M�s: Todos os participantes ganhar�o um " +getitemname(7859)+" ao entrar na arena.";
			dispbottom "Feira de Fim-de-M�s: O evento tem dura��o de 10 rounds ou termina quando tivermos menos de 3 participantes.";
			dispbottom "Feira de Fim-de-M�s: N�o se esque�a de confirmar se voc� esta com o /ns (/noshift) ativado!!";
			break;
		case 7:
			dispbottom "Feira de Fim-de-M�s: --- Clucky Cluckers ---";
			dispbottom "Feira de Fim-de-M�s: Este evento � super simples!";
			dispbottom "Feira de Fim-de-M�s: Ao norte de Prontera voce j� deve ter visto nossa galinha de estima��o, a Clucky.";
			dispbottom "Feira de Fim-de-M�s: Ela � um doce! Menos durante o evento...";
			dispbottom "Feira de Fim-de-M�s: A id�ia � tentarmos acalm�-la novamente fazendo-lhe carinho.";
			dispbottom "Feira de Fim-de-M�s: Para isso, voc� clica nela.";
			dispbottom "Feira de Fim-de-M�s: Com um pouco de sorte e pr�tica voc� conseguir� e ganhar� tr�s " +getitemname(7859)+"!";
			dispbottom "Feira de Fim-de-M�s: Mas se n�o der certo, s� Deus sabe do que uma galinha enfurecida � capaz!";
			dispbottom "Feira de Fim-de-M�s: O evento termina em 10 minutos ou assim que tivermos um vencedor.";
			dispbottom "Feira de Fim-de-M�s: Todos os participantes ganham um " +getitemname(7859)+".";
			break;
		default:
			dispbottom "Feira de Fim-de-M�s: Ouch! Tivemos um erro aqui! Por favor, informe a staff.";
			logmes "ERROR: Eventos Dinamicos.";
			end;
		}
	}
	return;
}


function	script	DE_WarmUp	{

	//callfunc("DE_WarmUp",.eventname$, .eventmap$, .minplayers) < 1) {
	.eventname$ = getarg(0,"Desconhecido");
	.eventmap$ 	= getarg(1,"none");
	.minplayers = getarg(2,1);
	.eventid	= getarg(3);

	.halt = 0;

	if($@CurrentEvent || agitcheck() || agitcheck2())
		end;
	if(.eventmap$ != "none")
		mapwarp .eventmap$,"prontera",155,181;
	set $@CurrentEvent,.eventid;
	set $@LastEvent,$@CurrentEvent;

	for(set .@i,2; .@i > 0; .@i--){
		announce "Feira de Fim-de-M�s: O evento " + .eventname$ + " comecar� em " + .@i + " " + ((.@i > 1)?"minutos":"minuto") + ".",bc_all,0x00AAFF;
		announce "Para participar, basta digitar agora @joinevent",bc_yellow|bc_all;
		sleep 60000;
	}

	if(getmapusers(.eventmap$) < .minplayers) {
		mapannounce .eventmap$,"Feira de Fim-de-M�s: Ouch... Parece que n�o temos jogadores o suficiente para iniciarmos o evento.",bc_yellow|bc_all;
		sleep 3000;
		announce "Feira de Fim-de-M�s: O evento "+ .eventname$ +" terminou. O pr�ximo evento ser� em aproximadamente uma hora!",bc_all,0x00AAFF;
		set $@LastEvent,0;
		deletearray $@EventPlayers[0],getarraysize($@EventPlayers);
		mapwarp .eventmap$,"prontera",155,181;
		.halt = 1;
	} else {
		announce "Feira de Fim-de-M�s: O evento "+ .eventname$ +" come�ou! Bom divertimento e boa sorte a todos!",bc_all,0x00AAFF;
	}
	set $@CurrentEvent,0;
	return .halt;
}



function	script	DE_Rewards	{
	//callfunc "DE_Rewards", .eventname$,.eventmap$,2;
	.eventname$ = getarg(0,"Desconhecido");
	.eventmap$ 	= getarg(1,"prontera");
	.reward 	= getarg(2,2);

	mapannounce .eventmap$,"Feira de Fim-de-M�s: O evento "+.eventname$+" terminou!",bc_map,0x00AAFF;
	killmonsterall .eventmap$;
	sleep 3000;
	freeloop(1);
	while(getmapusers(.eventmap$)){
		for(.@i = 0; .@i < getarraysize($@EventPlayers); .@i++){
			if(isloggedin($@EventPlayers[.@i])) {
				if(strcharinfo(3,getcharid(0,rid2name($@EventPlayers[.@i]))) == .eventmap$) {
					announce "Parab�ns, "+strcharinfo(0,getcharid(0,rid2name($@EventPlayers[.@i])))+"! Vencedor do evento "+ .eventname$ +".",bc_yellow|bc_all;
					getitem 7859,.reward,$@EventPlayers[.@i];
					warp "prontera",155,181, getcharid(0,rid2name($@EventPlayers[.@i]));
				}
			}
		}
	}
	freeloop(0);
	sleep 3000;
	announce "Feira de Fim-de-M�s: O evento "+.eventname$+" terminou. Muito obrigado a todos que participaram!",bc_all,0x00AAFF;
	set $@LastEvent,0;
	deletearray $@EventPlayers[0],getarraysize($@EventPlayers);

	return;
}


function	script	DE_Failed	{

	.eventname$ = getarg(0,"Desconhecido");
	.eventmap$ 	= getarg(1,"prontera");

	killmonsterall .eventmap$;
	sleep 3000;
	announce "Feira de Fim-de-M�s: O evento "+ .eventname$ +" terminou sem um vencedor. Muito obrigado a todos que participaram!",bc_all,0x00AAFF;
	set $@LastEvent,0;
	deletearray $@EventPlayers[0],getarraysize($@EventPlayers);

	mapwarp .eventmap$,"prontera",155,181;

	return;
}


prontera,146,161,6	script	Feira de Fim-de-Mes	954,{
	mes "[^FFA500Feira de Fim-de-M�s^000000]";
	mes "Ol�! Tenho chap�is maravilhosos para trocar pelos seus ^00AAFF "+getitemname(7859)+" ^000000 Venha e d� uma olhada, n�o custa nada!";
	close2;
	callshop "EventHeadgear",1;
	end;

OnInit:
	if(gettime(DT_DAYOFMONTH)<20)
 		disablenpc strnpcinfo(0);
 	end;

OnHour00:
	if(gettime(DT_DAYOFMONTH) == 20) {
		enablenpc strnpcinfo(0);
		announce "A Feira de Fim-de-M�s chegou em Prontera!",bc_blue|bc_all;
	} else if(gettime(DT_DAYOFMONTH) == 1){
		announce "A Feira de Fim-de-M�s se despede de Prontera. At� o m�s que vem, pessoal!",bc_blue|bc_all;
		disablenpc strnpcinfo(0);
	}
	end;

}

prontera,143,161,6	script	Assistente da Feira	770,{
	mes "[^FFA500Assistente da Feira^000000]";
	mes "Ol�! Para participar da Feira de Fim-de-M�s voc� precisar� de ^00AAFF "+getitemname(7539)+"s^000000.";
	mes "Eu posso trocar 10x " +getitemname(7539)+ "s por 1x " + getitemname($@HUNTING_MEDAL);
	mes "Deseja trocar?";
	next;
	if(select("Sim, por favor:N�o, obrigado") == 1) {
		if(countitem(7539) < 10) {
			mes "[^FFA500Assistente da Feira^000000]";
			mes "Desculpa mas voc� n�o tem "+getitemname(7539)+" o suficiente.";
			close;
		} else {
			delitem 7539,10;
			getitem $@HUNTING_MEDAL,1;
			next;
			mes "[^FFA500Assistente da Feira^000000]";
			mes "Prontinho! Muito obrigada e bom divertimento!!";
			close;
		}
	} else {
		mes "[^FFA500Assistente da Feira^000000]";
		mes "Sem problemas! At� mais!";
		close;
	}

OnInit:
	if(gettime(DT_DAYOFMONTH)<20)
 		disablenpc strnpcinfo(0);
 	end;

OnHour00:
	if(gettime(DT_DAYOFMONTH) == 20) {
		enablenpc strnpcinfo(0);
	} else if(gettime(DT_DAYOFMONTH) == 1){
		disablenpc strnpcinfo(0);
	}
	end;

}

-	itemshop	EventHeadgear	-1,7859,5381:50,5214:100,5380:100,5226:100,5227:100,5228:100,5229:100,5230:100,5231:100,5232:100,5233:100,5234:100,5235:100,5236:100,5237:100,5283:100,5313:100,5324:100,5376:100,5505:100,5286:125,5263:125,5098:125,5382:125,5238:175,5239:175,5240:175,5241:175,5242:175


//mapflags
silk_lair	mapflag	nobranch
silk_lair	mapflag	nomemo
silk_lair	mapflag	noreturn
silk_lair	mapflag	nosave
silk_lair	mapflag	noskill
silk_lair	mapflag	noteleport

quiz_01	mapflag	nobranch
quiz_01	mapflag	nomemo
quiz_01	mapflag	noreturn
quiz_01	mapflag	nosave
quiz_01	mapflag	noskill
quiz_01	mapflag	noteleport

maze	mapflag	nobranch
maze	mapflag	nomemo
maze	mapflag	noreturn
maze	mapflag	nosave
maze	mapflag	noskill
maze	mapflag	noteleport

pvp_n_1-5	mapflag	noteleport
pvp_n_1-5	mapflag	noreturn
pvp_n_1-5	mapflag	nomemo
pvp_n_1-5	mapflag	nobranch
pvp_n_1-5	mapflag	nosave
pvp_n_1-5	mapflag	noskill
pvp_n_1-5	mapflag	skillnorequirements	15