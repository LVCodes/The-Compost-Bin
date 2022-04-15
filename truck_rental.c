/* Lauren Vogel	COP3514 Section 2     Spring 2020
 * Full marks no points lost
 * Compile and run with gcc -Wall -lm truck_rental.c
 * The purpose of this program is to provide a truck rental menu where a
 * user can select a moving vehicle that can be rented for a maximum 24 hours
 * and the program calculates the cost of the different truck rentals by hour and minutes. */

#include <stdio.h>
#include <math.h>

//Decided to make all static values macros along with the individual rates
#define TOTAL_MINUTES ((hours*60) + minutes)
#define T1_RATE (15 + 4 * ceil((TOTAL_MINUTES - 75) / 15.0))
#define T1_MAX 49
#define T1_MIN 15
#define T2_RATE (19 + 5 * ceil((TOTAL_MINUTES - 75) / 15.0))
#define T2_MAX 69
#define T2_MIN 19
#define T3_RATE (25 + 8 * ceil((TOTAL_MINUTES - 75) / 15.0))
#define T3_MAX 89
#define T3_MIN 25
#define T4_RATE (29 + 10 * ceil((TOTAL_MINUTES - 75) / 15.0))
#define T4_MAX 99
#define T4_MIN 29

int main (void){
	//initilized all variables to 0 incase funky addresses get pulled somehow
	int truck = 0, hours = 0, minutes = 0, total = 0;

	printf("Please select desired truck fromt he following menu:\n"
		"Enter 1 if you would like to rent an 5.5-ft Flatbed Pick-up Truck.\n"
		"Enter 2 if you would like to rent an 8-ft Flatbed Pick-up Truck.\n"
		"Enter 3 if you would like to rent a Cargo Van.\n"
		"Enter 4 if you would like to rent a Moving Box Truck.\n"
		"Enter truck selection: ");
	scanf("%d", &truck);
	printf("How many hours renting? ");
	scanf("%d", &hours);
	printf("How many minutes renting? ");
	scanf("%d", &minutes);

//went with a switch statment with if else in each case cuz i like'em
	switch (truck){
  case 1:
	  if(TOTAL_MINUTES  <= 75)
      total = T1_MIN;
    else if (T1_RATE > T1_MAX)
      total = T1_MAX;
    else
      total = T1_RATE;
    printf("Amount due ($): %d.\n", total);
    break;

  case 2:
	  if(TOTAL_MINUTES  <= 75)
      total = T2_MIN;
    else if (T2_RATE > T2_MAX)
      total = T2_MAX;
    else
      total = T2_RATE;
    printf("Amount due ($): %d.\n", total);
    break;

 case 3:
   if(TOTAL_MINUTES  <= 75)
     total = T3_MIN;
   else if (T3_RATE > T3_MAX)
     total = T3_MAX;
   else
     total = T3_RATE;
   printf("Amount due ($): %d.\n", total);
   break;

 case 4:
   if(TOTAL_MINUTES  <= 75)
     total = T4_MIN;
   else if (T4_RATE > T4_MAX)
     total = T4_MAX;
   else
     total = T4_RATE;
   printf("Amount due ($): %d.\n", total);
   break;

  default: printf("The truck value is invalid. Please try again.");

	}

  return 0;

}
