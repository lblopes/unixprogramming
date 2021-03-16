#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"

complex complex_new(double x, double y) {
  complex z;
  z.x = x;
  z.y = y;
  return z;
}

complex complex_add(complex z, complex w) {
  complex r;
  r.x = z.x + w.x;
  r.y = z.y + w.y;
  return r;
}

complex complex_sub(complex z, complex w) {
  complex r;
  r.x = z.x - w.x;
  r.y = z.y - w.y;
  return r;
}

complex complex_mul(complex z, complex w) {
  complex r;
  r.x = z.x * w.x - z.y * w.y;
  r.y = z.x * w.y + z.y * w.x;
  return r;
}

complex complex_div(complex z, complex w) {
  complex r;
  double d = w.x * w.x + w.y * w.y;
  r.x = (  z.x * w.x + z.y * w.y) / d;
  r.y = (- z.x * w.y + z.y * w.x) / d;
  return r;
}

complex complex_conj(complex z) {
  complex r;
  r.x =  z.x;
  r.y = -z.y;
  return r;
}

double complex_mod(complex z) {
  return sqrt(z.x * z.x + z.y * z.y);
}

double complex_arg(complex z) {
  return atan2(z.y, z.x);
}

double complex_re(complex z) {
  return z.x;
}

double complex_im(complex z){
  return z.y;
}

complex complex_exp(complex z) {
  complex r;
  r.x = exp(z.x) * cos(z.y);
  r.y = exp(z.x) * sin(z.y);
  return r;
}

complex complex_log(complex z) {
  complex r;
  r.x = log(complex_mod(z));
  r.y = complex_arg(z);
  return r;
}

complex complex_sin(complex z) {
  complex r;
  r.x = sin(z.x) * cosh(z.y);
  r.y = cos(z.x) * sinh(z.y);
  return r;
}

complex complex_cos(complex z) {
  complex r;
  r.x =   cos(z.x) * cosh(z.y);
  r.y = - sin(z.x) * sinh(z.y);
  return r;
}

complex complex_tan(complex z) {
  return complex_div(complex_sin(z),complex_cos(z));
}

complex complex_cot(complex z) {
  return complex_div(complex_cos(z),complex_sin(z));
}

#define MAXCHARS  256
static char buffer[MAXCHARS];

char* complex_print(complex z) {
  if (z.y == 0)
    sprintf(buffer, "%f", z.x);
  else if (z.x == 0)
    sprintf(buffer, "%fi", z.y);
  else if (z.y > 0)
    sprintf(buffer, "%f+%fi", z.x, z.y);
  else
    sprintf(buffer, "%f%fi", z.x, z.y);
  return buffer;
}
