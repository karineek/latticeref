#include <math.h>
void main()
{
    double x;
    double val_cos_x = cos(x);
	
    assert(val_cos_x <= 1); // UNSAT
    assert(val_cos_x >= -1); // UNSAT
    assert(val_cos_x < -1.1); // SAT
    assert(val_cos_x > 2); // SAT
}
