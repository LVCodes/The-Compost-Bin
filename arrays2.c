/*Lauren Vogel    COP3514 Section 2   Spring 2020
* Prompts the user to enter the an array and array size
* then adds the first and last elements of the integer array,
* deleting the last element, and stores that new added value
* in the first element slot and so on moving in through the
* array. If the array as an odd set of numbers, the central
* integer in the original array will not be changed.
* Compile with gcc -Wall
*/

#include <stdio.h>

//Required function to be implemented per the project guidelines
void compute(int *a1, int n1, int *a2, int n2);

int main (){
        
        int i, n1 = 0;
        int n2 = 0;
        printf("Enter the length of the array: ");
        scanf("%d", &n1);

        int a1[n1];
        
        // If a1 has an even number of elements
        if (n1 % 2 == 0)
                n2 = n1 / 2;
        // If a1 is odd, then add extra element for center
        else
                n2 = n1 / 2 + 1;

        int a2[n2];

        printf("Enter the elements of the array: ");
        for (i = 0; i < n1; i++)
                scanf("%d", &a1[i]);
        
        // Compute output to a2
        compute(a1, n1, a2, n2);
 
        printf("Output:\n");
        
        // Print out output array
        for (i = 0; i < n2; i++)
                printf("%d\n", a2[i]);

        return 0;
}

void compute(int *a1, int n1, int *a2, int n2){

        int *p, *q, *r;
        for (p = a1, q = (a1 + n1 - 1), r = a2; p < (a1 + n1 / 2); p++, q--, r++)
        {
                *r = *p + *q;
        }
        
        // Check if a1 has an odd number of elements, if so, add center element to a2
        if (n1 % 2 != 0) 
        {
                r = (a2 + n1 / 2);
                *r = *(a1 + n1 / 2);
        } 
}
