#include <math.h>
void main()
{
    double sphere_x = 0.0;
    for(double theta = 1; theta <= M_PI ; theta+=0.25)
    {

        for(double phi = 1; phi <= M_PI ; phi+=0.25)
        {
            double sin_x = sin(theta);
            double cos_x = cos(theta);
            double sin_y = sin(phi);
            double cos_y = cos(phi);

            sphere_x += (sin_x*cos_y + cos_x*sin_y);
	}
    }

    // happens when x+y > M_PI
    assert(sphere_x < 0);
}
