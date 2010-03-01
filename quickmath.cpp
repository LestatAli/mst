// quickmath.h: useful math functions
#include "quickmath.h"

float square(float x)
{
	return x*x;
}	

// create a random number between 0 and 1
// note: non-ideal
// http://stackoverflow.com/questions/686353/c-random-float
float myrand()
{
	float r = (float)rand()/(float)RAND_MAX;
	return r;
}
