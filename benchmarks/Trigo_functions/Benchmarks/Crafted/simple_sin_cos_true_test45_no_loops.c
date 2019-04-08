#include <math.h>
void main()
{
    double x; double y = x + M_PI_2;

    double val_cos_y = cos(y);
    double val_sin_x = - sin(x);

    assert(val_cos_y == val_sin_x); // UNSAT
    assert(val_cos_y != val_sin_x); // SAT
    // cos(x+ PI/2) = -sin(x).
}
