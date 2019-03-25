#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x = _M_PI/2;
    double val_sin_x = sin(x);    

    assert(val_sin_x == 1); // UNSAT
    assert(val_sin_x != 1); // SAT
    // sin (PI / 2 - x) = cos x
}
