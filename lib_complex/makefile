libs:   
	gcc -Wall -c complex.c
	ar -rc libcomplex.a complex.o
	nm -g libcomplex.a

libd:  
	gcc -c -Wall -fPIC -o complex.o complex.c
	gcc -shared -o libcomplex.so complex.o
	nm -g libcomplex.so

use:    
	gcc -Wall use_complex.c -o use_complex -L. -lcomplex

clean:
	rm -f *.o *.a *.so *~ use_complex
