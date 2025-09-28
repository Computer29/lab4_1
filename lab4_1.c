/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/

int close_to (double, double, double);

double mag(double , double, double);

double acceleration(double);

int movement (double, double, double);
/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	//double magnitude = mag (ax,ay,az);
	int moving;
	//remove below
	double tolerance;
	double point;
	double value;
	
    while (1) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
		//scanf(" %lf %lf %lf ", &tolerance, &point, &value);
        /* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */
        //printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);
		//printf("%lf is the tolerance and %lf is point  and %lf is value, and close to is %d\n", tolerance, point, value, close_to(tolerance, point, value));
        /* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */

        //printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az));
		moving = movement(ax, ay, az);
		
	}
	fflush(stdout);

    return 0;
}

/* Put your functions here */
int close_to(double tolerance, double point, double value)
// basically true or false
{
	if (fabs(point - value) > tolerance)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

double mag(double ax, double ay, double az)
{	
		return sqrt(ax*ax+ay*ay+az*az);
}

int movement(double ax, double ay, double az)
{
	if(close_to(0.02, 0, mag(ax,ay,az)) == 0)
	{
		printf("moving!\n");
		return 1;
	}
	else
	{
		printf("not moving!\n");
		return 0;
	}
}
//double acceleration(double magnitude)
// basically true or false but for acceleration
//{
	//if (magnitude >= 0.1) {
	//	return 1.0;
	//}
	//else (magnitude <= 0.0); {
		//return 0.0;
	//}
//}


