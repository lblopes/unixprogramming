.PHONY: libs libd use clean

libs:   
	gcc -Wall -c complex.c
	ar -rc libcomplex.a complex.o
	nm -g libcomplex.a

libd:  
	gcc -Wall -fPIC -c complex.c -o complex.o
	gcc -shared complex.o -o libcomplex.so
	nm -g libcomplex.so

use:    
	gcc -Wall use_complex.c -o use_complex -L. -lcomplex
	@echo
	@echo IMPORTANT NOTE: before running use_complex for the first time
	@echo run the following shell command:
	@echo
	@echo $$ export LD_LIBRARY_PATH=.:\$$LD_LIBRARY_PATH
	@echo

clean:
	rm -f *.o *.a *.so *~ use_complex
