#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

double M_PI_2_def() {}
double _M_PI_2 = M_PI_2_def();

void main()
{
    double x; double y = cos(x); // Just for this test
    // pi > 0.
    assert(_M_PI > 0); // UNSAT

    // pi/2 > 0.
    assert(_M_PI/2 > 0); // UNSAT
    assert(_M_PI_2 > 0); // UNSAT

    //  pi < 4
    assert(_M_PI < 4); // UNSAT

    //  pi <> 0
    assert(_M_PI != 0); // UNSAT
}
