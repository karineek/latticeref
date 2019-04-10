#include <math.h>
void main()
{
    double x;
    __CPROVER_assume(x > - M_PI_2); 
    __CPROVER_assume(x < M_PI_2); 

    double val_cos = cos(x);

    assert(0 < val_cos); // UNSAT
    assert(0 == val_cos); // SAT
    //assert(0 > val_cos); // SAT
     // SAT
    // forall x:R, - (PI / 2) < x -> x < PI / 2 -> 0 < cos x.
}
