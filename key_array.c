/*Lauren Vogel    COP3514 Section 2 Spring 2020   *
* The purpose of this program is to take an array *
* of 10 digits that range from 0-9 and randomly   *
* swapping the digits positions 10 times.         *
* Swap function required with the rand() and      *
* srand() functions to generate different         *
* sequence of random numbers.                     *
* * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_DIGITS 10

void swap (int a[], int n);

int main (){
        int index, a[NUM_DIGITS] = {0,1,2,3,4,5,6,7,8,9}; //Not sure if these initial 10 values are supposed to be randomized
        srand(time(NULL)); //Seed random number generator
        swap(a, NUM_DIGITS); //call function swap
        
        for(index = 0; index < NUM_DIGITS; index++)
                printf("%d ", a[index]);

        putchar('\n');

        return 0;

}

// Swap two random members of array a 10 times. n represents the size of array a
void swap (int a[], int n){

        int position_1, position_2, index, temp = 0;

        for(index = 0; index < n; index++) {
                // Generate first random position between 0 and 9
                position_1 = (rand()%(9 - 0 + 1)) + 0;
                // Generate second random index between 0 and 9
                position_2 = (rand()%(9 - 0 + 1)) + 0;
                // Swap positions
                temp = a[position_1];
                a[position_1] = a[position_2];
                a[position_2] = temp;
        }
        

}
