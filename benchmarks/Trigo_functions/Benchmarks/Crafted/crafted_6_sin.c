#include <math.h>
void main()
{
    double x;
    __CPROVER_assume(0 < x); 
    __CPROVER_assume(x < 2); 

    double val_sin = sin(x);

    assert(0 < val_sin); // UNSAT
    assert(0 == val_sin); // SAT
    assert(0 > val_sin); // SAT
    // 0 < x < 2 -> 0 < sin x
}
