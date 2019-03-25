#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x; double y = _M_PI - x;
    double val_sin = sin(x);
    double val_neg_sin = sin(y);

    assert(val_neg_sin == val_sin); // UNSAT
    assert(val_neg_sin != val_sin); // SAT
    assert(0);
    // sin (PI - x) = sin x.
}
