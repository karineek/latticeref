#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

double M_PI_2_def() {}
double _M_PI_2 = M_PI_2_def();

void main()
{
    // cos PI = -1.	
    double val_cos_x = cos(_M_PI);
    assert(val_cos_x == -1); // UNSAT
    assert(val_cos_x != -1); // SAT

    // cos (PI / 2) = 0.
    double x = _M_PI * 0.5;
    double val_cos_x_1 = cos(x);
    assert(val_cos_x_1 == 0); // UNSAT
    assert(val_cos_x_1 != 0); // SAT

    // cos (PI / 2) = 0.
    double val_cos_x_2 = cos(_M_PI_2);
    assert(val_cos_x_2 == 0); // UNSAT
    assert(val_cos_x_2 != 0); // SAT

    // TODO: will need error fact in the lattice for pi/2 test
}
