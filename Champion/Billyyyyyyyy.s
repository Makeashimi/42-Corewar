.name "Billyyyyyyyy"
.comment "yooooo bitchyyyyyyyy"

jump:	sti r1, %:flive, %1
		sti r1, %:live, %1
		and r1, %0, r2
		lfork %2025
flive:	live	%1
		fork	%:flive
live:	live	%1
		zjmp	%:live
