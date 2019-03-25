#include <math.h>
void main()
{
    double x; double y = M_PI/2 - x;

    double val_cos_y = cos(y);
    double val_sin_x = sin(x);

    assert(val_cos_y == val_sin_x); // UNSAT
    assert(val_cos_y != val_sin_x); // SAT
    // cos (PI / 2 - x) = sin x.
}
