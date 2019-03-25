#include <math.h>
void main()
{
    double x; double y = 0;

    double val_sin_x = sin(x);
    double val_cos_y = cos(y);
    double res1 = val_cos_y * val_sin_x;
    
    double val_cos_x = cos(x);
    double val_sin_y = sin(y);
    double res2 = val_cos_x * val_sin_y;

    assert((res1-res2) == (res1+res2)); // UNSAT
    assert((res1-res2) != (res1+res2)); // SAT
    // sin (x + y) = sin x * cos y + cos x * sin y.
    // sin (x - y) = sin x * cos y - cos x * sin y.
}
