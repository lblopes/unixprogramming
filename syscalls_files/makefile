DATA=../data_files/lusiadas.txt

.PHONY: all fbasic fstat fdir clean

all: fbasic fstat fdir

fbasic:
	gcc -Wall fbasic.c -o fbasic
	./fbasic ${DATA}

fstat:
	gcc -Wall fstat.c -o fstat
	./fstat ${DATA}

fdir:
	gcc -Wall fdir.c -o fdir
	./fdir .

clean:
	rm -f *~ fbasic fstat fdir

