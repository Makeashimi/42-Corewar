.name "Billyyyyyyyy"
.comment "yooooo bitchyyyyyyyy"

			and %42, %42, r2
			zjmp %500
start:		sti r1, %:live, %1
			sti r1, %:forklive, %1
			zjmp %2
			fork %:forklive
			lfork %2000
forklive:	live %42
			fork %:forklive
live:		live %42
			zjmp %:live
