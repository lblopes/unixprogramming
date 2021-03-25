.PHONY: all strbasic strstr strsep clean

all: strbasic strstr strsep
	@echo done.............................................

strbasic:
	@echo example: strdup, strcmp, strcpy..................
	gcc -Wall strbasic.c -o strbasic
	./strbasic "to be or not to be" "to be both"
	@echo

strstr:
	@echo example: strdup, strstr..........................
	gcc -Wall strstr.c -o strstr
	./strstr "be" "to be or not to be or to be both"
	@echo

strsep:
	@echo example: strdup, strsep..........................
	gcc -Wall strsep.c -o strsep
	./strsep "to be or not to be or to be both"
	@echo

clean:
	rm -f *~ strbasic strstr strsep

