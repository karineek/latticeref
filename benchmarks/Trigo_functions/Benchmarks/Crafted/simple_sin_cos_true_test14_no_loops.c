#include <math.h>
void main()
{
    double x; double x2 = M_PI_2 + x;
    double val_cos_x = cos(x2);
    double val_sin_x = sin(x);

    assert(val_sin_x == -val_cos_x); // UNSAT
    // sin_cos : forall x:R, sin x = - cos (PI / 2 + x).
}
