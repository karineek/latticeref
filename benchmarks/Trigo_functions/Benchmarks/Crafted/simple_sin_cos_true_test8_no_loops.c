#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x = _M_PI;

    double val_cos_x = cos(x);
    double res_cos = val_cos_x * val_cos_x;
    
    double val_sin_x = sin(x);
    double res_sin = val_sin_x * val_sin_x;

    assert((res_cos-res_sin) == 1); // UNSAT
    assert((res_cos-res_sin) != 1); // SAT
    // cos (2 * x) = cos x * cos x - sin x * sin x
}
