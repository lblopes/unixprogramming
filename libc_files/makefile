all: fchar fblock getline
	@echo "done............................................."

fchar:
	@echo "example: fopen, fgetc, fclosepy.................."
	gcc -Wall fchar.c -o fchar
	./fchar lusiadas.txt
	@echo

fblock:
	@echo "example: fopen, fread, fwrite, fclose............"
	gcc -Wall fblock.c -o fblock
	./fblock lusiadas.txt
	@echo

getline:
	@echo "example: fopen, getline, fclose.................." 
	gcc -Wall getline.c -o getline
	./getline lusiadas.txt
	@echo

clean:
	rm -f *~ fchar fblock getline

