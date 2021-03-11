DATA=../data_files/lusiadas.txt

all: fbasic fstat fdir
	@echo "done............................................."

fbasic:
	@echo "example: open, read, write, close................"
	gcc -Wall fbasic.c -o fbasic
	./fbasic ${DATA}
	@echo

fstat:
	@echo "example: stat...................................."
	gcc -Wall fstat.c -o fstat
	./fstat ${DATA}
	@echo

fdir:
	@echo "example: opendir, readdir, closedir.............." 
	gcc -Wall fdir.c -o fdir
	./fdir .
	@echo

clean:
	rm -f *~ fbasic fstat fdir

