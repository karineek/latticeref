#include <math.h>
void main()
{
    double x = 0.1;
    double val_cos = cos(x);
    double val_sin = sin(x);
    double x2 = x*2;
    double val_2sin = sin(x2);
    double sphere_x = 2*(val_cos*val_sin);

    assert(sphere_x == val_2sin); // UNSAT
    assert(sphere_x != val_2sin); // SAT
     // SAT
    // sin(2x) == 2*cos(x)*sin(x)
}
