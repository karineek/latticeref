#include <math.h>
void main()
{
    double x; double y = x+M_PI;
    double val_cos = cos(x);
    double val_pi_cos = cos(y);

    assert(val_pi_cos == -val_cos); // UNSAT
    assert(val_pi_cos != -val_cos); // SAT
    
    // cos (x + PI) = - cos x.
}
