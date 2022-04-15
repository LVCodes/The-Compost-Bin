//Reuses code from previous request project but to practice
//using header files and multi-file projects
#include "readline.h"
#include "request.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define COURSE_LEN 100
#define NAME_LEN 30
#define STATUS_LEN 30



/************************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/


int main(void)
{
        char code;

        struct request *permit_list = NULL;  
        printf("Operation Code: a for appending to the list, u for updating a request"
	  ", p for printing the list; q for quit.\n");

        for (;;) 
        {
                printf("Enter operation code: ");
                scanf(" %c", &code);

                while (getchar() != '\n')   /* skips to end of line */
                        ;
                switch (code) 
                {
                case 'a': permit_list = append_to_list(permit_list);
                        break;
                case 'u': update(permit_list);
                        break;
                case 'p': printList(permit_list);
                        break;
                case 'q': clearList(permit_list);
		        return 0;
                default:  printf("Illegal code\n");
                }

        printf("\n");
        }
}

