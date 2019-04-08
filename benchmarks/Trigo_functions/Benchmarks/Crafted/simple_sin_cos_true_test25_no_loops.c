#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x=4;

    double val_cos_x = cos(x);    

    double x_2 = _M_PI/2 + x;
    double val_sin_x = sin(x_2);    

    assert(val_sin_x == val_cos_x); // UNSAT
    assert(val_sin_x != val_cos_x); // SAT
    // cos x = sin (PI / 2 + x)
}
