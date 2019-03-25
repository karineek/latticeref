#include <math.h>

double M_PI_2_def() {}
double _M_PI_2 = M_PI_2_def();

void main()
{
    double val_cos_x = cos(_M_PI_2);
    double val_sin_x = sin(0);

    assert(val_sin_x == -val_cos_x); // UNSAT
    assert(val_sin_x != -val_cos_x); // SAT
    // sin_cos : forall x:R, sin x = - cos (PI / 2 + x).
}
