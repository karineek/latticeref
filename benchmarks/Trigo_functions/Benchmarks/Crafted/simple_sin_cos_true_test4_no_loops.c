#include <math.h>
void main()
{
    double x; double gap; double y = x + gap;

    double val_cos_x = cos(x);
    double val_cos_y = cos(y);
    double res_cos = val_cos_x * val_cos_y;
    
    double val_sin_x = sin(x);
    double val_sin_y = sin(y);
    double res_sin = val_sin_y * val_sin_x;

    double cos_gap = cos(gap);

    assert(cos_gap == (res_sin+res_cos)); // UNSAT
    assert(cos_gap != (res_sin+res_cos)); // SAT
    // cos (x - y) = cos x * cos y + sin x * sin y.
}
