#include <math.h>
void main()
{
    double x = -5; double y = x + 4 * M_PI;
    double val_cos = cos(x);
    double val_cos_k = cos(y);

    assert(val_cos_k == val_cos); // UNSAT
    assert(val_cos_k != val_cos); // SAT
     // SAT
    // Lemma cos_period : forall (x:R) (k:nat), cos (x + 2 * INR k * PI) = cos x. - LINEAR!
}
