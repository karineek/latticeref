#include <math.h>
void main()
{
    double x=4;
    double val_cos = cos(x);

    assert(0 > val_cos); // UNSAT
    assert(0 == val_cos); // SAT
    assert(0 < val_cos); // SAT
    assert(0); // SAT
    // forall x:R, PI / 2 < x -> x < 3 * (PI / 2) -> cos x < 0
}
