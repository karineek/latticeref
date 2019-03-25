#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x; double y = x + _M_PI/2;

    double val_cos_x = cos(y);
    double val_sin_x = sin(x);

    assert(val_cos_x == -val_sin_x); // UNSAT
    assert(val_cos_x != -val_sin_x); // SAT
    // cos(x+ PI/2) = -sin(x)
}
