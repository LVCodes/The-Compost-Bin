/*Lauren Vogel    COP3514 Section2   Spring 2020                *
* The purpose of this code is to take in a command line         *
* argument that has a math operation (+, -, /, x) and two int   *
* numbers and prints the results of the operation.              *
* Compiles with gcc -Wall
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BAD_INPUT 1


/* Take in an op as a character, and two ints that represent the left-hand side and
*  right-hand side of an arithmetic operation. Return result.*/
int operate(char op, int lhs, int rhs);

int main(int argc, char *argv[]){

        int a[argc];
        int i;
        
        if(argc > 3)
        {
                // Store arithmetic operator
                char operator = argv[1][0];
                for(i = 2; i < argc; i++) 
                {
                a[i - 2] = atoi(argv[i]);

                //Check if operands are actually numbers; atoi returns zero on reading a non-integer.
                if (a[i - 2] == 0) 
                {
                        if (argv[i][0] != '0') 
                        {
                                printf("Invalid option. +, -, x, or / followed by two operands\n");
                                exit(BAD_INPUT);
                        }
                }
                }

        printf("Result: %d\n", operate(operator, a[0], a[1]));
        
        }
        else
                printf("Invalid option. +, -, x, or / followed by two operands\n");
      

        return 0;
}

int operate(char op, int lhs, int rhs) {
        switch(op) {
        case '+':
                return lhs + rhs;
        case 'x':
                return lhs * rhs;
        case '-':
                return lhs - rhs;
        case '/':
                return lhs / rhs;
        default:
                printf("Invalid option. +, -, x, or / followed by two operands\n");
                exit(BAD_INPUT);
        }
}
