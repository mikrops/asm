.comment "just a
basic living
 prog"

.name "z
o
rk"

l2:	sti	r1,%:live,%0
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live
