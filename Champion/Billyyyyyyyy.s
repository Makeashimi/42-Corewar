.name "Billyyyyyyyy"
.comment "yooooo bitchyyyyyyyy"

			
			and r2, %0, r2
			zjmp %512
start:		sti r1, %:live, %1
			sti r1, %:forklive, %1
			zjmp %2
			fork %:forklive
			lfork %2000
forklive:	live %42
			fork %:forklive
live:		live %42
			zjmp %:live
