/*Lauren Vogel    COP3514 Section 2    Spring 2020
* The purpose of this code is to take in two arrays of the
* same size and compare the values in each array on corresponding
* indexs element by element, but only looks for a single pair of
* elements to be different and give an alert.
* Compile with gcc -Wall
*/

#include <stdio.h>

//Required function to be implemented per the project guidelines
int one_element_different( int *a1, int *a2, int n, int *element1, int *element2);

int main (){

        int i, n;
        printf("Enter the length of the array: ");
        scanf("%d", &n);
      
        int arr1[n], arr2[n];
        int El1, El2; 
       
        printf("Enter the elements of the first array: ");
        for (i = 0; i < n; i++)
                scanf("%d", &arr1[i]);

        printf("Enter the elements of the second array: ");
        for (i = 0; i < n; i++)
                scanf("%d", &arr2[i]);

        //calling the function 
        int difference = one_element_different(arr1, arr2, n, &El1, &El2);

        if(difference)
                //call the element pointers that hold the single set of values that are different
                printf("The arrays are different by one element, %d and %d \n", El1, El2);
        else
                printf("The arrays are NOT different by one element\n"); 

        return 0;
}

int one_element_different(int *a1, int *a2, int n, int *element1, int *element2){

        //The element pointers are used only if a single pair of elements between the arrays is different
        int i = 0;
        int *p, *q;
        
        for(p = &a1[0], q = &a2[0]; p < &a1[n] && q < &a2[n]; p++, q++)
        {
                //Nested if statments to assign the element values
                if (*p != *q)
                {
                        *element1 = *p;
                        *element2 = *q;
                        i++;

                        if (i == 1)
                                continue;
                        else
                                return 0;
                }
        }
        //return i has to be 1 or else the if statements return the 0
        return i;
}
