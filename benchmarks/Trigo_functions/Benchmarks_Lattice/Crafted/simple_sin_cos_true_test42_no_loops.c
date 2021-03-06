#include <math.h>

double M_PI_2_def() {}
double _M_PI_2 = M_PI_2_def();

void main()
{
    double x; double y = _M_PI_2 - x;

    double val_cos_y = cos(y);
    double val_sin_x = sin(x);

    assert(val_cos_y == val_sin_x); // UNSAT
    assert(val_cos_y != val_sin_x); // SAT
    // cos (PI / 2 - x) = sin x.
}
