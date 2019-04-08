#include <math.h>
void main()
{
    double x; int y;
    if (y) {
 	x = M_PI_2*3;
    } else {
 	x= M_PI_2;
    }
    
    double val_cos = cos(x);

    assert(val_cos == 0); // UNSAT
     // SAT
    // Lemma cos_eq_0_2PI_1 (x:R) : 0 <= x -> x <= 2 * PI -> x = PI / 2 \/ x = 3 * (PI / 2) -> cos x = 0. 
}
