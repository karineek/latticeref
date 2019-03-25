#include <math.h>

double M_PI_2_def() {}
double _M_PI_2 = M_PI_2_def();

void main()
{
    double x;

    __CPROVER_assume(-(_M_PI_2) <= x); 
    __CPROVER_assume(x <= _M_PI_2); 

    double val_cos = cos(x);

    assert(0 <= val_cos); // UNSAT
    assert(0 > val_cos); // SAT
    assert(0); // SAT
    // forall x:R, - (PI / 2) <= x -> x <= PI / 2 -> 0 <= cos x.
}
