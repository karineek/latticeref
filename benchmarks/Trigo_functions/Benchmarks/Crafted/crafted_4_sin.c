#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x = 0.1; double y = x + _M_PI;
    double val_sin = sin(y);
    double val_neg_sin = - sin(x);

    assert(val_neg_sin == val_sin); // UNSAT
    assert(val_neg_sin != val_sin); // SAT
    assert(0);
    // sin (x + PI) = - sin x
}
