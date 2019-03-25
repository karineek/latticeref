#include <math.h>
void main()
{
    double x = M_PI_2; int k; double y = x + (k * M_PI);
    double val_cos = cos(x);
    double val_cos_k = cos(y);

    assert(val_cos_k == val_cos); // UNSAT
    assert(val_cos == 0); // UNSAT
    assert(val_cos_k != val_cos); // SAT
     // SAT
    // cos x = 0 -> exists k : Z, x = IZR k * PI + PI / 2.
    // (exists k : Z, x = IZR k * PI + PI / 2) -> cos x = 0.
}
