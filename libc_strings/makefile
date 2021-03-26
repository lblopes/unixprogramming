.PHONY: all strargs strbasic strstr strsep clean

all: strargs strbasic strstr strsep

strargs:
	gcc -Wall strargs.c -o strargs
	./strargs -u -l -f f1.txt
	./strargs -u -f f1.txt
	./strargs -l

strbasic:
	gcc -Wall strbasic.c -o strbasic
	./strbasic "to be or not to be" "to be both"

strstr:
	gcc -Wall strstr.c -o strstr
	./strstr "be" "to be or not to be or to be both"

strsep:
	gcc -Wall strsep.c -o strsep
	./strsep "to be or not to be or to be both"

clean:
	rm -f *~ strargs strbasic strstr strsep

