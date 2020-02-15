.comment "just a basic living prog"
.name "zork"
l2:	sti	r9,:live,%:abc
	and	r15,%0,r7
abc:
live:	live%1
	zjmp %:live
