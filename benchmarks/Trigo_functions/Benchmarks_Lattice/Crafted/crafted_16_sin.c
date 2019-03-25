#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x;
    __CPROVER_assume(x == 0 || x == _M_PI || x == 2 * _M_PI); 

    double val_sin = sin(x);
    
    assert(val_sin == 0); // UNSAT
    assert(val_sin != 0); // SAT
    //  0 <= x -> x <= 2 * PI -> x = 0 \/ x = PI \/ x = 2 * PI -> sin x = 0.

}
