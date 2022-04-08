/*Lauren Vogel	COP3514 Section 2	Spring 2020                 *
* compile with gcc -Wall berries.c                              *
* The goal of this program is to prompt the user to enter the 	*
* berries they picked along with the weight of each type of 	  *
* berry picked. The program will only continue to cost 		    *
* calculation once the user enters '0', then they will be given *
* their total cost and prompted to enter they amount of cash 	*
* they will be using. The program will calculate their change	*
* then exit.							                                      *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <math.h>

#define STRAWBERRY_PER_LB (1.99 * lb)
#define BLUEBERRY_PER_LB (4.39 * lb)
#define BLACKBERRY_PER_LB (3.69 * lb)
#define RASPBERRY_PER_LB (5.99 * lb)

int main (){

  //initialized floats to 0 for simplicity 	
  float lb = 0, cash = 0, total = 0;
  int b_selection = 1;  //1 = true
	
  printf("Please select a product:\n"
	 "1. Strawberry - $1.99/lb\n"
	 "2. Blueberry - $4.39/lb\n"
   "3. Blackberry - $3.69/lb\n"
	 "4. Raspberry - $5.99/lb\n"
	 "Enter 0 to stop selection.\n");

// while loop to interate till 0 is entered
 while(b_selection != 0){
 
   printf("Enter product selection: ");
   scanf("%d", &b_selection);

// total = total + STRAWBERRY_PER_LB;
// and continuing to be a fan of switch statements
    switch (b_selection){
        //case 0 to end switch in order to not prompt for weight
        case 0:
        break;

        case 1:
         printf("Enter product weight: ");
         scanf("%f", &lb);
         total += STRAWBERRY_PER_LB;  
         break;

        case 2:
          printf("Enter product weight: ");
          scanf("%f", &lb);
          total += BLUEBERRY_PER_LB;
          break;

        case 3: 
          printf("Enter product weight: ");
          scanf("%f", &lb);
          total += BLACKBERRY_PER_LB;
          break;

        case 4:
          printf("Enter product weight: ");
          scanf("%f", &lb);
          total += RASPBERRY_PER_LB;
          break;

        default: printf("Invalid Selection, select 1 to 4, enter 0 to stop selection.\n"); 
    }
  }
  printf("Amount due ($): %.2f\n", total);
  printf("Enter cash recieved ($): ");
  scanf("%f", &cash);
  printf("Your change is $%.2f\n",(cash - total));

  return 0;
}
