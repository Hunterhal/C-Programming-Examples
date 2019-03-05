#include <custom.h>
#include <math.h>

/*This function calculates the free fall time
in params: float height
out params: float time
*/
float calculate_free_fall_time(float height)
{
	float time, temp;
	temp = 2 * GRAVITY * height;
	time = sqrt(temp);
	/*sqrt takes square root, this function defined in math.h*/
	return(time);
}