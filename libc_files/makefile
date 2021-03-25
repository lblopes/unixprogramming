DATA=../data_files/lusiadas.txt

.PHONY: all fchar fblock getline clean

all: fchar fblock getline
	@echo done.............................................

fchar:
	@echo example: fopen, fgetc, fclose....................
	gcc -Wall fchar.c -o fchar
	./fchar ${DATA}
	@echo

fblock:
	@echo example: fopen, fread, fwrite, fclose............
	gcc -Wall fblock.c -o fblock
	./fblock ${DATA}
	@echo

getline:
	@echo example: fopen, getline, fclose..................
	gcc -Wall getline.c -o getline
	./getline ${DATA}
	@echo

clean:
	rm -f *~ fchar fblock getline

