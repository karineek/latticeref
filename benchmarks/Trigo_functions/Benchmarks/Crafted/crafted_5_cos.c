#include <math.h>
void main()
{
    double x=1.1;
    double val_cos = cos(x);

    assert(0 < val_cos); // UNSAT
    assert(0 == val_cos); // SAT
    assert(0 > val_cos); // SAT
     // SAT
    // forall x:R, - (PI / 2) < x -> x < PI / 2 -> 0 < cos x.
}
