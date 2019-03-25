#include <math.h>
void main()
{
    double x=0;

    double val_cos_x = cos(x);    
    double val_sin_x = sin(x);

    double res_cos_sin = 2 * val_cos_x * val_sin_x;

    double x_2 = 2*x;
    double res_sin_2x = sin(x_2);

    assert(res_sin_2x == res_cos_sin); // UNSAT
    assert(res_sin_2x != res_cos_sin); // SAT
    // sin (2 * x) = 2 * sin x * cos x
}
