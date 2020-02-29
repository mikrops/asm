.name "zork"
.comment "just a basic living prog"

	#jg
	ld %0, 
    st r4, 56
    st r5, 510
    zjmp %501
    restgf:
		 l2:
	sti	r9,%:live, r7
	and	r15,%0,r7
live:	live	%1
	zjmp%:live
