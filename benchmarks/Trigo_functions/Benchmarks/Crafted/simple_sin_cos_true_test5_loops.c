#include <math.h>
#include <assert.h>

int main()
{
	double theta = 3.14;
	double phi = 3.14;
	double sphere_x = 0.0;
   			
	double x_y = phi + theta;
	double temp = sin(x_y);

	// unwind 10 need
        for (int i = 0; i < M_PI; i++)
	{
	        for (int j = 0; j < M_PI; j++)
		{	
			double sin_x = sin(theta);
			double sin_y = sin(phi);
			double cos_x = cos(theta);
			double cos_y = cos(phi);
			double sum = (sin_x*cos_y + sin_y*cos_x);

			sphere_x += sum;
		}
	}


        // ALL UNSAT; 
	assert(sphere_x < 0); //UNSAT
	assert(sphere_x > 0); //SAT 
}
