#include <math.h>
#include <assert.h>

int main()
{
	double theta = 2.14;
	double phi=theta;
	double sphere_x = 0.0;
   
	// unwind 17 need
        // Loops in Cprover can only be in jumps of +1 - else cannot prove UNSAT - TODO
	//for(double theta = 0.5; theta <= _M_PI ; theta+=0.1)
        for (int i = 3; i < M_PI; i++)
	{
		//for(double phi = 0.5; phi <= _M_PI ; phi+=0.1)
	        for (int j = 1; j < M_PI; j++)
		{	
			double sin_x = sin(theta);
			double cos_x = cos(theta);
			double cos_y = cos(phi);
			double sin_y = sin(phi);
			double sum = (sin_x*cos_y + cos_x*sin_y);

			sphere_x += sum;

			double x_y = phi + theta;
			double temp = sin(x_y);

			phi += 0.5;
		}
		phi = 2.14;
		//theta += 0.5;
	}

	assert(sphere_x < 0); //UNSAT
	assert(sphere_x > 0); //SAT 
}
