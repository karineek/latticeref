#include <math.h>
void main()
{
    double x; double x_2 = M_PI/2 - x;

    double val_cos_x = cos(x);    

    double val_sin_x = sin(x_2);    

    assert(val_sin_x == val_cos_x); // UNSAT
    assert(val_sin_x != val_cos_x); // SAT
    // sin (PI / 2 - x) = cos x
}
