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

int is_moving(double, double, double);

void print_values (int t, int b1, int b2, int b3, int b4, double ax, double ay, double az, double gx, double gy, double gz);



/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	int moving;
	
    while (1) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );

        /* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */

        //printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);
		print_values(t, b1, b2, b3, b4, ax, ay, az, gx, gy, gz);

        /* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */


		// Print if moving or not
		moving = is_moving(ax, ay, az);

		if (moving == 0){
			// Controller not moving calculate orientation

			//printf("Orientation:", orientation);
		}

	}
	fflush(stdout);
    return 0;
}

/* Put your functions here */

int close_to(double tolerance, double point, double acc_value){
	if (fabs(point - acc_value) > tolerance){
		return 0;
	} else {
		return 1;
	}
}

double mag(double x, double y, double z){	
	return sqrt(pow(x,2)+pow(y,2)+pow(z,2)); 
}

void dir(double x, double y, double z){
	// Calculate Azimuth (angle in the X-Y plane)
	double azimuth = atan2(y,x);

	// Calculate the Elevation (angle from the horizontal plane)
	double elevation = atan2(z, sqrt(pow(x,2) + pow(y,2)));

	// Convert radians to degrees

	// interpret azimuth and elevation to find direction

	// return direction

}

void rad_to_deg(double radians){
	// TODO: Alex
}

int is_moving(double ax, double ay, double az){
	double tolerance = 0.02;

	if(close_to(tolerance, 0.0, mag(ax,ay,az)) == 0.0){
		printf("moving!\n");
		return 1;
	} else {
		printf("not moving!\n");
		return 0;
	}
}

/**
 * Prints the accelerometer and gyroscope values, as well as the time and magnitude.
 */
void print_values(int t, int b1, int b2, int b3, int b4,
    double ax, double ay, double az, double gx, double gy, double gz){
	// Print accelerometer values
	printf("Accelerometer values: ax: %lf, ay: %lf, az: %lf\n", ax, ay, az);

	// Print gyroscope values
	printf("Gyroscope values: gx: %lf, gy: %lf, gz: %lf\n", gx, gy, gz);

	// Print time and magnitude
    printf("At %d ms, the acceleration's magnitude was: %lf\n", t, mag(ax, ay, az));

}

