#include <math.h>
void main()
{
    double x=1.1; double x3=3.3;

    double val_cos_x = cos(x);
    double res_cos=4 * val_cos_x * val_cos_x * val_cos_x - 3 * val_cos_x;

    double val_cos_3 = cos(x3);

    assert(res_cos == val_cos_3); // UNSAT
    assert(res_cos != val_cos_3); // SAT
    // cos (3 * x) = 4 * cos x * cos x * cos x - 3 * cos x
}
