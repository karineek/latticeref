#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x;
    __CPROVER_assume(0 <= x); 
    __CPROVER_assume(x <= _M_PI); 
   
    double y;
    __CPROVER_assume(0 <= y); 
    __CPROVER_assume(y <= _M_PI);

    double val_cos_x = cos(x);
    double val_cos_y = cos(y);
 
    __CPROVER_assume(x < y);

    assert(val_cos_x > val_cos_y); // UNSAT
    assert(val_cos_x < val_cos_y); // SAT
    assert(0); // SAT
    // 0 <= x -> x <= PI -> 0 <= y -> y <= PI -> x < y -> cos y < cos x
}
