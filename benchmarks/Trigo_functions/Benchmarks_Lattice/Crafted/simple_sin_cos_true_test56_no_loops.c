#include <math.h>
#include <assert.h>

int main()
{
	double theta = 3.14;
	double phi = 3.14;
	double sphere_x = 0.0;
	double sin_x = sin(theta);
	double cos_x = cos(theta);
	double cos_y = cos(phi);
	double sin_y = sin(phi);
	double sum = (sin_x*cos_y + cos_x*sin_y);

	sphere_x += sum;

	double x_y = phi + theta;
	double temp = sin(x_y);

	assert(sum == temp); // UNSAT
	assert(sphere_x < 0); // UNSAT
}
