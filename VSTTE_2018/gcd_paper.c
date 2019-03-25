#include <assert.h>

int gcd(int x, int y);
int main(void)
{
	int x=45;
	int y=18;
	int g = gcd(x,y);
	
	assert(g <= x);
        assert(g > x);
}

int gcd(int x, int y)
{ 
  	int tmp;	
	while(y != 0) {
	  tmp = x%y;
		x=y;	
	  y=tmp; }
	return x; 
}
