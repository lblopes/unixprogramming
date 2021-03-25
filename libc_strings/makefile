.PHONY: all strbasic strstr strsep clean

all: strbasic strstr strsep

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
	rm -f *~ strbasic strstr strsep

