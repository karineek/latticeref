#include <math.h>

double M_PI_def() {}
double _M_PI = M_PI_def();

void main()
{
    double x= _M_PI * 3/2 ;
    double x3 = 3 * x;
    double val_sin = sin(x);
    double val_3sin = sin(x3);
    double res = 3*val_sin - 4*val_sin*val_sin*val_sin;

    assert(val_3sin == res); // UNSAT
    assert(val_3sin != res); // SAT
    // sin(3x) = 3sinx - 4(sinx)^3
}
