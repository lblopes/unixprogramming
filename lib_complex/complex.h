/* definition of new type complex */
typedef
struct {
  double x;
  double y;
}
complex;

/* definition of the complex API */
complex complex_new(double, double);
char*   complex_print(complex);

complex complex_add(complex, complex);
complex complex_sub(complex, complex);
complex complex_mul(complex, complex);
complex complex_div(complex, complex);
complex complex_conj(complex);

double  complex_mod(complex);
double  complex_arg(complex);
double  complex_re(complex);
double  complex_im(complex);

complex complex_exp(complex);
complex complex_log(complex);
complex complex_sin(complex);
complex complex_cos(complex);
complex complex_tan(complex);
complex complex_cot(complex);

