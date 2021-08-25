// mount seller
-	script	Iuri	-1,{
	mes .n$;
	mes "Howdy, " + strcharinfo(0);
	mes "How are you doing?";
	mes "Looking for mounts, huh?";
	close2;
	callshop "mount_shop",1;


Oninit:
	.n$ = "^0000FF[ Iuri ]^000000";
	end;
}

-	shop	mount_shop	-1,12622:50,30603:600,30604:3000

rent_mb,143,42,3	duplicate(Iuri)	Iuri#rent	964
prontera,218,223,4	duplicate(Iuri)	Iuri#prt	964
morocc,249,51,3	duplicate(Iuri)	Iuri#moc	964
geffen,57,129,3	duplicate(Iuri)	Iuri#gef	964
payon,224,160,3	duplicate(Iuri)	Iuri#pay	964