
// Used by the item 12622 ITEMID_REINS_OF_MOUNT
function	script	F_Mounting	{
    if(!ismounting()) {
		.@cast = mountinfo(1,10); 
		progressbar("0xfffff",.@cast);
	} 
	setmounting(1)
}