#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    int k;
    double x = k * _M_PI; 
    double val_sin = sin(x);

    assert(val_sin == 0); // UNSAT
    assert(val_sin != 0); // SAT
    assert(0); // SAT
    // (exists k : Z, x = IZR k * PI) -> sin x = 0
}
