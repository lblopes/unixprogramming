#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

int main(int argc, char* argv[]) {
   complex z1 = complex_new(-2.16793, 5.23394);
   complex z2 = complex_new( 2.16793, -2.52236);
   complex z3 = complex_add(z1, z2);
   complex z4 = complex_sub(z1, z2);
   complex z5 = complex_mul(z1, z2);
   complex z6 = complex_div(z1, z2);
   double  x1 = complex_mod(z1);
   double  x2 = complex_re(z1);
   double  x3 = complex_im(z3);
   printf("z1 = %s\n", complex_print(z1));
   printf("z2 = %s\n", complex_print(z2));
   printf("z3 = %s\n", complex_print(z3));
   printf("z4 = %s\n", complex_print(z4));
   printf("z5 = %s\n", complex_print(z5));
   printf("z6 = %s\n", complex_print(z6));
   printf("x1 = %f\n", x1);
   printf("x2 = %f\n", x2);
   printf("x3 = %f\n", x3);
   exit(EXIT_SUCCESS);
}
