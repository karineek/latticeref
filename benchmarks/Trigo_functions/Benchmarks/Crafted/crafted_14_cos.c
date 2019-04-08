#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

double M_PI_2_def() {}
double _M_PI_2 = M_PI_2_def();

void main()
{
    double x;
    double val_cos = cos(x);

    __CPROVER_assume(val_cos == 0);
    __CPROVER_assume(x >= 0); 
    __CPROVER_assume(x <= 2*_M_PI);

    assert((x == _M_PI_2*3) || (x == _M_PI_2)); // UNSAT
    assert(0); // SAT
    // Lemma cos_eq_0_2PI_0 (x:R) : 0 <= x -> x <= 2 * PI -> cos x = 0 ->  x = PI / 2 \/ x = 3 * (PI / 2).
}
