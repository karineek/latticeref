#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

double M_PI_2_def() {}
double _M_PI_2 = M_PI_2_def();
void main()
{
    double x = _M_PI_2; int k; double y = x + (k * _M_PI);
    double val_cos = cos(x);
    double val_cos_k = cos(y);

    assert(val_cos_k == val_cos); // UNSAT - requires LIRA! then add K to summary ask (|sin...::k| Int)
    assert(val_cos == 0); // UNSAT
    assert(val_cos_k != val_cos); // SAT
    assert(0); // SAT
    // cos x = 0 -> exists k : Z, x = IZR k * PI + PI / 2.
    // (exists k : Z, x = IZR k * PI + PI / 2) -> cos x = 0.
}
