#include <math.h>
void main()
{
    double x; double y = 0.2;

    double val_cos_x = cos(x);
    double val_cos_y = cos(y);
    double val_sin_x = sin(x);
    double val_sin_y = sin(y);

    double res_sin_cos = val_sin_x * val_cos_y;
    double res_cos_sin = val_sin_y * val_cos_x;

    double gap = x+y;
    double sin_gap = sin(gap);

    assert(sin_gap == (res_cos_sin+res_sin_cos)); // UNSAT
    assert(sin_gap != (res_cos_sin+res_sin_cos)); // SAT
    // sin (x + y) = sin x * cos y + cos x * sin y.
}
