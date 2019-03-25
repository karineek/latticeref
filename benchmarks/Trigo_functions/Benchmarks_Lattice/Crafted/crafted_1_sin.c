#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

double M_PI_2_def() {}
double _M_PI_2 = M_PI_2_def();

void main()
{
    // sin PI = 0.
    double val_sin_x = sin(_M_PI);
    assert(val_sin_x == 0); // UNSAT
    assert(val_sin_x != 0); // SAT

    //  sin (PI / 2) = 1.
    double x = _M_PI / 2;
    double val_sin_x1 = sin(x);
    assert(val_sin_x1 == 1); // UNSAT
    assert(val_sin_x1 != 1); // SAT

    //  sin (PI / 2) = 1.
    double val_sin_x2 = sin(_M_PI_2);
    assert(val_sin_x2 == 1); // UNSAT
    assert(val_sin_x2 != 1); // SAT


    // TODO: will need error fact in the lattice for pi/2 test
}
