/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 05
-          
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

//void print_values (double t, double gx, double gy, double gz); // testing stuff
/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    double t;
    double gx, gy, gz;
	
	// Starting, and stopping
	double initial_X = 0.0;	// take time from here to drop end
	double initial_V= 0.0; // m/s
	double gravity = 9.8; //m/s^2
	double start_time; // start time
	double end_time;	// resulting time
	double End_X;	// end of drop in meters


	// Milliseconds to seconds
	double Second= 1.0 * t/1000;
	

		printf("<Alex De Santiago>\n");

		printf("<a51756>\n");

	while (scanf("%lf, %lf, %lf, %lf", &t, &gx, &gy, &gz)){
		printf("Ok, I'm now receiving data.\n");
			printf("I'm Waiting.\n");
		break;
	}
    while(1){
        scanf("%lf, %lf, %lf, %lf", &t, &gx, &gy, &gz);
		//printf("Echoing output: %lf, %lf, %lf, %lf \n", t, gx, gy, gz);
		if (mag(gx,gy,gz)<0.9 && mag(gx,gy,gz)>0.001){
			printf("Help me! I'm Falling!\n");
			
		}
		else {
			if (start_time > 0){
				end_time = (t -start_time)/1000.0;
			}
		}
		

		while (mag(gx,gy,gz)<0.9 && mag(gx,gy,gz)>0.001){
			//calculate velocity, and time
			scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
			End_X = initial_X + (initial_V * end_time) + ((1.0/2.0) * gravity * end_time * end_time);
			
			printf("Ouch! I fell %.3lf meters in %.3lf seconds.", End_X, end_time);
			
			break;
		}
	
	}	
	fflush(stdout);
    return 0;
}
	




	
	// Meters


//-----------------------------------------------------------------------------//
	









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



int is_moving(double ax, double ay, double az){
	double tolerance = 0.02;

	if(close_to(tolerance, 0.0, mag(ax,ay,az)) == 0.0){
		//printf("moving!\n");
		return 1.0;
	} else {
		//printf("not moving!\n");
		return 0.0;
	}
}

/**
 * Prints the accelerometer and gyroscope values, as well as the time and magnitude.
 */
//void print_values(int t, double gx, double gy, double gz){
	// Print accelerometer values
	//printf("Accelerometer values: ax: %lf, ay: %lf, az: %lf\n", ax, ay, az);

	//Print gyroscope values
	//printf("Gyroscope values: gx: %lf, gy: %lf, gz: %lf\n", gx, gy, gz);

	// Print time and magnitude
   //printf("At %d ms\n", t);

   
//}

