#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

double M_PI_2_def() {}
double _M_PI_2 = M_PI_2_def();

void main()
{
    double x;
    __CPROVER_assume(-_M_PI_2 <= x); 
    __CPROVER_assume(x <= _M_PI_2); 
   
    double y;
    __CPROVER_assume(-_M_PI/2 <= y); 
    __CPROVER_assume(y <= _M_PI/2);

    double val_sin_x = sin(x);
    double val_sin_y = sin(y);
 
    __CPROVER_assume(x < y);

    assert(val_sin_x < val_sin_y); // UNSAT
    assert(val_sin_x > val_sin_y); // SAT
    assert(0); // SAT
    // - (PI / 2) <= x -> x <= PI / 2 -> - (PI / 2) <= y -> y <= PI / 2 -> x < y -> sin x < sin y.
}
