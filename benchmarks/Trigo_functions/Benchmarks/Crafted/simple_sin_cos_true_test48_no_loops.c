#include <math.h>
void main()
{
    double q=M_PI; 
    double p=M_PI_2;

    double val_sin_p = sin(p);
    double val_sin_q = sin(q);    

    double x = (p-q)/2;
    double val_cos_x = cos(x);   

    double y = (p+q)/2;
    double val_sin_y = sin(y);

    double res1 = 2 * val_sin_y * val_cos_x;   

    assert(res1 == val_sin_p + val_sin_q); // UNSAT
    assert(res1 != val_sin_p + val_sin_q); // SAT
    // sin p + sin q = 2 * cos ((p - q) / 2) * sin ((p + q) / 2).
}
