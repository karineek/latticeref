#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x;
    __CPROVER_assume(_M_PI <= x); 
    __CPROVER_assume(x <= 2*_M_PI); 
   
    double y;
    __CPROVER_assume(_M_PI <= y); 
    __CPROVER_assume(y <= _M_PI*2);

    double val_cos_x = cos(x);
    double val_cos_y = cos(y);
 
    __CPROVER_assume(x <= y);

    assert(val_cos_x <= val_cos_y); // UNSAT
    assert(val_cos_x > val_cos_y); // SAT
    assert(0); // SAT
    // PI <= x -> x <= 2 * PI -> PI <= y -> y <= 2 * PI -> x <= y -> cos x <= cos y.

}
