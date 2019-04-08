#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x = _M_PI; double y = x + 6 * _M_PI;
    double val_cos = cos(x);
    double val_cos_k = cos(y);

    assert(val_cos_k == val_cos); // UNSAT
    assert(val_cos_k != val_cos); // SAT
    assert(0); // SAT
    // Lemma cos_period : forall (x:R) (k:nat), cos (x + 2 * INR k * PI) = cos x. - LINEAR!
}
