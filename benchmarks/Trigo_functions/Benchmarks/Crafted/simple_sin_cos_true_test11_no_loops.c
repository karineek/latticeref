#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x=1.1;

    double val_cos_x = cos(x);
    double res_cos = val_cos_x * val_cos_x;
    
    double val_sin_x = sin(x);
    double res_sin = val_sin_x * val_sin_x;

    double z = 2*_M_PI;
    double cos_res = cos(z);

    assert((res_cos+res_sin) == cos_res); // UNSAT
    assert((res_cos+res_sin) != cos_res); // SAT
    assert(0); // SAT
    // forall x:R, Rsqr (sin x) + Rsqr (cos x) = 1.
}
