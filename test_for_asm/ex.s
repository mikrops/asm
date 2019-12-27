.comment "Dust a basicliving prog" #der
.name "zork"    #sdf



l2: sti	r1,%:live,%0    #ldkf
	and	r1,%0,r1
live:	live	%1
	zjmp %:live
