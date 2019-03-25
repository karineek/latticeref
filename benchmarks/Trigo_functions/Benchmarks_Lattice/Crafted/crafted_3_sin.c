#include <math.h>
void main()
{
    double x = 0.1; double neg_x = -x;
    double val_sin = - sin(x);
    double val_neg_sin = sin(neg_x);

    assert(val_neg_sin == val_sin); // UNSAT
    assert(val_neg_sin != val_sin); // SAT
    assert(0);
    // sin (- x) = - sin x
}
