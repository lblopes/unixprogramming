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
	gcc -Wall use_complex.c -o use_complex -L. -lcomplex -lm

clean:
	rm -f *.o *.a *.so *~ use_complex
