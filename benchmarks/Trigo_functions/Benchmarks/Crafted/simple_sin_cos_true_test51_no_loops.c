#include <math.h>
void main()
{
    double x;
    __CPROVER_assume(0 < x);
    __CPROVER_assume(x < 1);
    // Is in LIA always UNSAT, as no value exists in LIA between 0 to 1!!

    double val_sin = sin(x);
    double val_cos = cos(x);    

    double res1 = x*val_cos;

    assert(0 < res1); // UNSAT
    assert(0 < val_sin); // UNSAT
    assert(res1 < x); // UNSAT
    assert(val_sin < x); // UNSAT
    assert(res1 < val_sin); // UNSAT
    assert(res1 > val_sin); // SAT
    // 0<x<1: 0 < xcosx < sinx < x
}
