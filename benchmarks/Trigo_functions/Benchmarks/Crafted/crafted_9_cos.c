#include <math.h>
void main()
{
    double x;
    __CPROVER_assume(x >= M_PI_2); 
    __CPROVER_assume(x <= 3*M_PI_2); 

    double val_cos = cos(x);

    assert(0 >= val_cos); // UNSAT
    assert(0 < val_cos); // SAT
     // SAT
    // forall x:R, PI / 2 <= x -> x <= 3 * (PI / 2) -> cos x <= 0
}
