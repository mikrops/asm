.comment "just a basic living prog"
.name "zork"
l2:	sti	r9,%:live,%0
	and	r15,%0,r7

live:	live	%1
	zjmp %:live
