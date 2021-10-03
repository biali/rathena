-	script	heirloom	-1,{
	end;
OnPcBaseLvUpEvent:
	if(BaseLevel == 99) {
		if(getd("$first_" + getcharid(7)) <= 0) {
			setd("$first_" + getcharid(7)),getcharid(0);
			setarray .@item[0],24000;
			setarray .@amount[0],1;
			mail getcharid(0),"Ragnamania","Your First Heirloom Equip","Dear " + strcharinfo(0) + " congratulations on reaching the maximum level in Ragnamania Enliven! We've attached a special equipment to this mail, the first piece of your Heirloom Set. Please head to our Wiki to learn more about Heirloom equipments.",0,.@item,.@amount;
		}
	}
	end;
}