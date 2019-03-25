#include <math.h>
void main()
{
    double x; double y = x;

    double val_cos_x = cos(x);
    double val_cos_y = cos(y);
    double res_cos = val_cos_x * val_cos_y;
    
    double val_sin_x = sin(x);
    double val_sin_y = sin(y);
    double res_sin = val_sin_y * val_sin_x;

    assert(1 == (res_sin+res_cos)); // UNSAT
    assert(1 != (res_sin+res_cos)); // SAT
    // cos (x - y) = cos x * cos y + sin x * sin y.
    // gap == 0, cos(0) = 1
}
