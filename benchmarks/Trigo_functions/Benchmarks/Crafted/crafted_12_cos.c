#include <math.h>
void main()
{
    double x=6;
    double val_cos = cos(x);

    assert(0 < val_cos); // UNSAT
    assert(0 == val_cos); // SAT
    assert(0 > val_cos); // SAT
     // SAT
    // forall x:R, x:R, 3 * (PI / 2) <= x -> x <= 2 * PI -> 0 <= cos x.
}
