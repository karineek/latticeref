#include <math.h>
void main()
{
    double x; double y = 0;

    double val_cos_x = cos(x);
    double val_cos_y = cos(y);
    double res_cos = val_cos_x * val_cos_y;
    
    double val_sin_x = sin(x);
    double val_sin_y = sin(y);
    double res_sin = val_sin_y * val_sin_x;

    assert((res_cos-res_sin) == (res_sin+res_cos)); // UNSAT
    assert((res_cos-res_sin) != (res_sin+res_cos)); // SAT
    // cos (x - y) = cos x * cos y + sin x * sin y.
    // cos (x + y) = cos x * cos y - sin x * sin y.
}
