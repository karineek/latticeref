#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x = _M_PI; double y = x + 6 * _M_PI;
    double val_sin = sin(x);
    double val_sin_k = sin(y);

    assert(val_sin_k == val_sin); // UNSAT
    assert(val_sin_k != val_sin); // SAT
    assert(0); // SAT
    // Lemma sin_period : forall (x:R) (k:nat), sin (x + 2 * INR k * PI) = sin x. - LINEAR!
}
