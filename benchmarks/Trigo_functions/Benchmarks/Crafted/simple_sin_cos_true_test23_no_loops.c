#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double val_cos_x = cos(0);    

    double x = _M_PI/2;
    double val_sin_x = sin(x);    

    assert(val_sin_x == val_cos_x); // UNSAT
    assert(val_sin_x != val_cos_x); // SAT
    assert(0);
    // sin (PI / 2 - x) = cos x
}
