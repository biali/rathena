prontera,56,355,5	script	Stable Master	526,{
    mes .n$;
    mes "Howdy, " + strcharinfo(0);
    mes "Looking for a faster to move around?";
    next;
    mes .n$;
    mes "We can borrow you one of our marvelous creators to help you with that.";
    next;
    mes .n$;
    mes "Prizes are as follow:";
    mes " ";
    if(vip_status(1)) {
        mes "7 days rental : 200x " + getitemname($@HUNTING_MEDAL)  +"s.";
        mes "30 days rental : 500x" + getitemname($@HUNTING_MEDAL) +"s."; 
    } else {
        mes "7 days rental : 400x " + getitemname($@HUNTING_MEDAL)  +"s.";
        mes "30 days rental : 1000x " + getitemname($@HUNTING_MEDAL) +"s."; 
    }
    
    next;
    switch(select("Rent for 7 days:Rent for 30 days:Cancel")) {
        case 3:
            mes .n$;
            mes "No problem! See you 'round!";
            close;
        case 1:
            mes .n$;
            mes "Good choice!, let me prepare one for you.";
            next;
            mes .n$;
            if((!vip_status(1) && countitem($@HUNTING_MEDAL) < 400) || (vip_status(1) && countitem($@HUNTING_MEDAL) < 200))
                goto OnNoZeny;

            mes "Here it is!";
            mes "Please take good care of her...";
            if(!vip_status(1))
                delitem $@HUNTING_MEDAL,400;
            else 
                delitem $@HUNTING_MEDAL,200;
            rentitem 12622,604800;
            logmes strcharinfo(0) + "rented a mount at the stable master for 7 days";
            close;
        case 2:
            mes .n$;
            mes "Good choice!, let me prepare one for you.";
            next;
            mes .n$;
            if((!vip_status(1) && countitem($@HUNTING_MEDAL) < 1000) || (vip_status(1) && countitem($@HUNTING_MEDAL) < 500))
                goto OnNoZeny;

            mes "Here it is!";
            mes "Please take good care of her...";
            if(!vip_status(1))
                delitem $@HUNTING_MEDAL,1000;
            else
                delitem $@HUNTING_MEDAL,500;
            rentitem 12622,2592000;
            logmes strcharinfo(0) + "rented a mount at the stable master for 30 days";
            close;
    }
    end;

OnNoZeny:
    mes "Cat's whiskers!";
    mes "You don't have enough "+getitemname($@HUNTING_MEDAL)+"s!";
    mes "Sorry but I can't help you, then";
    close;

OnInit:
    .n$ = "^0000AA[ Stable Master]^000000";
    end;

}

prontera,53,355,5	script	Everto	938,{
    npctalk "...";
    end;
}

prontera,54,358,6	script	Malhada	957,{
    npctalk "Muuu...";
    end;
}

prontera,57,358,6	script	Nitro	955,{
    npctalk "Muuu...";
    end;
}
