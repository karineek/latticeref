#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x;
    __CPROVER_assume(0 <= x); 
    __CPROVER_assume(x <= 2 * _M_PI); 

    double val_sin = sin(x);
    __CPROVER_assume(val_sin == 0); 

    assert(x == 0 || x == _M_PI || x == 2 * _M_PI); // UNSAT
    assert(x == 1); // SAT
    // 0 <= x -> x <= 2 * PI -> sin x = 0 -> x = 0 \/ x = PI \/ x = 2 * PI.
}
