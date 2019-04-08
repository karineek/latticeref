#include <math.h>
void main()
{
    double x;
    double val_sin = sin(x);
    
    assert(val_sin >= -1); // UNSAT
    assert(val_sin <= 1); // UNSAT
    assert(val_sin > 1.1); // SAT
    // -1 <= sin x <= 1.

}
