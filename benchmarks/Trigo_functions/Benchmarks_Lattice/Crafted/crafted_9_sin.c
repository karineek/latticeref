#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x;
    __CPROVER_assume(0 <= x); 
    __CPROVER_assume(x <= _M_PI); 

    double val_sin = sin(x);

    assert(0 <= val_sin); // UNSAT
    assert(0 == val_sin); // UNSAT
    assert(0 > val_sin); // SAT
    // 0 <= x -> x <= PI -> 0 <= sin x.
}
