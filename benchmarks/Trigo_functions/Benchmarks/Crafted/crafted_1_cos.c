#include <math.h>
void main()
{
    double x = 0.1; double x_neg = -x;
    double val_cos = cos(x);
    double val_neg_cos = cos(x_neg);

    assert(val_neg_cos == val_cos); // UNSAT
    assert(val_neg_cos != val_cos); // SAT
    
    // cos (- x) = cos x
}
