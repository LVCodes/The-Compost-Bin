/*Lauren Vogel    COP3514 Section 2    Spring 2020        *
* The purpose of this program is to prompt the user to    *
* enter the total number of digits in the number they wish*
* to have encrypted, then the program will randomize the  *
* and encrypt each digit by assigning it to a randomized  *
* position and prints the key.                            *
* compile with gcc -Wall
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KEY_SIZE 10
#define VAL_NOT_FOUND -1

void swap(int a[], int n);

int find_index(int val, int a[], int n);

void replace(int a[], int b[], int key[], int n);

int main(){
        int num_digits, index;
        srand(time(NULL)); //seed random number generator
        printf("Enter the number of digits of the number: ");
        scanf("%d", &num_digits); //get number of digits
        int a[num_digits], b[num_digits], key[KEY_SIZE] = {1,2,3,4,5,6,7,8,9};

        printf("Enter the number: ");
        for(index = 0; num_digits > index; index++)
                scanf("%1d", &a[index]); //read in numbers one digit at a time

        swap(key,num_digits); //randomize numbers to make key map
        
        //print key map
        printf("Key array: ");
        for(index = 0; index < KEY_SIZE; index++)
                printf("%d ", key[index]);

        //encrypt
        replace(a, b, key, num_digits);
        
        //print out encrypted numbers
        printf("\nOutput: ");
        for(index = 0; index < num_digits; index++)
                printf("%d", b[index]);

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

// Return index that matches val in array a if val
// is the same as a value in a. int n represents the size of
// array a. Returns -1 if value is not a member of array a
int find_index(int val, int a[], int n) {
        int index;
        for(index = 0; index < n; index++)
                if(a[index] == val)
                        return index;
        return VAL_NOT_FOUND; //error if val is not found
}

// Takes in arrays a, b, and key, as well as int n, which
// represents the size of these arrays. For each element in
// a, write the corresponding key found in array key to
// array b.
void replace(int a[], int b[], int key[], int n){
        int index;

        for(index = 0; index < n; index++)
              b[index] = find_index(a[index], key, KEY_SIZE);
}
