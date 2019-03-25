#include <math.h>
void main()
{
    double q=M_PI; 
    double p=M_PI_2;

    double val_cos_p = cos(p);
    double val_cos_q = cos(q);    

    double x = (p-q)/2;
    double val_sin_x = sin(x);   

    double y = (p+q)/2;
    double val_sin_y = sin(y);

    double res1 = -2 * val_sin_y * val_sin_x;   

    assert(res1 == val_cos_p - val_cos_q); // UNSAT
    assert(res1 != val_cos_p - val_cos_q); // SAT
    // cos p - cos q = -2 * sin ((p - q) / 2) * sin ((p + q) / 2).
}
