#include <math.h>
void main()
{
    double x; double y = x;

    double val_sin_y = sin(y);
    double val_cos_x = cos(x);
    double val_cos_y = cos(y);
    double val_sin_x = sin(x);

    double res_sin_cos = val_sin_x * val_cos_y;
    double res_cos_sin = val_cos_x * val_sin_y;

    assert(0 == (res_sin_cos-res_cos_sin)); // UNSAT
    assert(0 != (res_sin_cos-res_cos_sin)); // SAT
    // sin (x - y) = sin x * cos y - cos x * sin y.
    // gap = x; sin(0) = 0
}
