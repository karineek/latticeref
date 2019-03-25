#include <math.h>
void main()
{
    double x;
    double val_cos = cos(x);

    __CPROVER_assume(val_cos == 0);
    __CPROVER_assume(x >= 0); 
    __CPROVER_assume(x <= 2*M_PI);

    assert((x == M_PI_2*3) || (x == M_PI_2)); // UNSAT
     // SAT
    // Lemma cos_eq_0_2PI_0 (x:R) : 0 <= x -> x <= 2 * PI -> cos x = 0 ->  x = PI / 2 \/ x = 3 * (PI / 2).
}
