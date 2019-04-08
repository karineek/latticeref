#include <math.h>

double M_PI_2_def() {}
double _M_PI_2 = M_PI_2_def();

void main()
{
    double x=3*_M_PI_2;
    double val_cos = cos(x);

    assert(val_cos==0); // UNSAT
    assert(0); // SAT
    // Lemma cos_eq_0_2PI_1 (x:R) : 0 <= x -> x <= 2 * PI -> x = PI / 2 \/ x = 3 * (PI / 2) -> cos x = 0. 
}
