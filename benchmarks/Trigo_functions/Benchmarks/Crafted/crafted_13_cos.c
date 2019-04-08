#include <math.h>
void main()
{
    double x;
    double val_cos = cos(x);

    __CPROVER_assume(x >= 3*M_PI_2); 
    __CPROVER_assume(x <= 2*M_PI); 

    assert(0 <= val_cos); // UNSAT
    assert(0 == val_cos); // SAT
    assert(0 > val_cos); // SAT
     // SAT
    // forall x:R, x:R, 3 * (PI / 2) <= x -> x <= 2 * PI -> 0 <= cos x.
}
