#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x;
    __CPROVER_assume(_M_PI < x); 
    __CPROVER_assume(x < 2*_M_PI); 

    double val_sin = sin(x);

    assert(0 > val_sin); // UNSAT
    assert(0 == val_sin); // SAT
    assert(0 < val_sin); // SAT
    assert(0); // SAT
    // PI < x -> x < 2 * PI -> sin x < 0.
}
