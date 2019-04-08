#include <math.h>
void main()
{
    double x; double y = 3*x;
    double val_sin = sin(x);
    double val_3sin = sin(y);
    double res = 3*val_sin - 4*val_sin*val_sin*val_sin;

    assert(val_3sin == res); // UNSAT
    assert(val_3sin != res); // SAT
    // sin(3x) = 3sinx - 4(sinx)^3
}
