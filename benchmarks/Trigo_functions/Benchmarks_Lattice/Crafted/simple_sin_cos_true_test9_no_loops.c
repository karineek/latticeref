#include <math.h>
void main()
{
    double x=1.1;

    double val_cos_x = cos(x);
    double res_cos = val_cos_x * val_cos_x;
    
    double val_sin_x = sin(x);
    double res_sin = val_sin_x * val_sin_x;

    double z = 2*x;
    double val_cos_z = cos(z);

    assert((res_cos-res_sin) == val_cos_z); // UNSAT
    assert((res_cos-res_sin) != val_cos_z); // SAT
    // cos (2 * x) = cos x * cos x - sin x * sin x
}
