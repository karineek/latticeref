#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x=0.1; double y = x+_M_PI;
    double val_cos = cos(x);
    double val_pi_cos = cos(y);

    assert(val_pi_cos == -val_cos); // UNSAT
    assert(val_pi_cos != -val_cos); // SAT
    assert(0); // SAT
    // cos (x + PI) = - cos x.
}
