#include <math.h>
void main()
{
    double val_cos_x = cos(0);    

    double x = M_PI/2;
    double val_sin_x = sin(x);    

    assert(val_sin_x == val_cos_x); // UNSAT
    assert(val_sin_x != val_cos_x); // SAT
    // sin (PI / 2 - x) = cos x
}
