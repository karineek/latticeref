#include <math.h>
void main()
{
    double x = 0.1; double y = 0.2;

    double val_cos_x = cos(x);
    double val_cos_y = cos(y);
    double res_cos = val_cos_x * val_cos_y;
    
    double val_sin_x = sin(x);
    double val_sin_y = sin(y);
    double res_sin = val_sin_x * val_sin_y;

    double gap = x-y;
    double cos_gap = cos(gap);

    assert(cos_gap == (res_cos+res_sin)); // UNSAT
    assert(cos_gap != (res_cos+res_sin)); // SAT
    // cos (x - y) = cos x * cos y + sin x * sin y.
}
