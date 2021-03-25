DATA=../data_files/lusiadas.txt

.PHONY: all fchar fblock getline clean

all: fchar fblock getline

fchar:
	gcc -Wall fchar.c -o fchar
	./fchar ${DATA}

fblock:
	gcc -Wall fblock.c -o fblock
	./fblock ${DATA}

getline:
	gcc -Wall getline.c -o getline
	./getline ${DATA}

clean:
	rm -f *~ fchar fblock getline

