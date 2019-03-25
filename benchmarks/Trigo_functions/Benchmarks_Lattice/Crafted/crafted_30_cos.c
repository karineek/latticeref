#include <math.h>
void main()
{
    double q; 
    double p;

    double val_cos_p = cos(p);
    double val_cos_q = cos(q);    

    double x = (p-q)/2;
    double val_cos_x = cos(x);   

    double y = (p+q)/2;
    double val_cos_y = cos(y);

    double res1 = 2 * val_cos_y * val_cos_x;   

    assert(res1 == val_cos_q + val_cos_p); // UNSAT
    assert(res1 != val_cos_q + val_cos_p); // SAT
    // cos p + cos q = 2 * cos ((p - q) / 2) * cos ((p + q) / 2)
}
