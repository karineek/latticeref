#include <math.h>

double M_PI_2_def() {}
double _M_PI_2 = M_PI_2_def();

void main()
{
    double x;

    double val_cos_x = cos(x);
    double res_cos = val_cos_x * val_cos_x;
    
    double val_sin_x = sin(x);
    double res_sin = val_sin_x * val_sin_x;

    double sin_res = sin(_M_PI_2);

    assert((res_cos+res_sin) == sin_res); // UNSAT
    assert((res_cos+res_sin) != sin_res); // SAT
    // forall x:R, Rsqr (sin x) + Rsqr (cos x) = 1.
}
