#include <math.h>
void main()
{
    double x=1.57;

    double val_cos_x = cos(x);    
    double res_2cos = 2 * val_cos_x * val_cos_x - 1;

    double x_2 = 2*x;
    double res_cos_2x = cos(x_2);

    assert(res_cos_2x == res_2cos); // UNSAT
    assert(res_cos_2x != res_2cos); // SAT
    // cos (2 * x) = cos x * cos x - sin x * sin x.
    // cos (2 * x) = 2 * cos x * cos x - 1.
    // cos (2 * x) = 1 - 2 * sin x * sin x
}
