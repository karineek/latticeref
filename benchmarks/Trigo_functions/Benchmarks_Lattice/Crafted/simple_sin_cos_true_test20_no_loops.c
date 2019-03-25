#include <math.h>
void main()
{
    double x;

    double val_cos_x = cos(x);    
    double res_2cos = 2 * val_cos_x * val_cos_x - 1;

    double val_sin_x = sin(x);    
    double res_2sin = 1 - 2 * val_sin_x * val_sin_x;

    assert(res_2sin == res_2cos); // UNSAT
    assert(res_2sin != res_2cos); // SAT
    // cos (2 * x) = cos x * cos x - sin x * sin x.
    // cos (2 * x) = 2 * cos x * cos x - 1.
    // cos (2 * x) = 1 - 2 * sin x * sin x
}
