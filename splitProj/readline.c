/*Lauren Vogel      COP3514 Section 2     Spring 2020         *
* The goal of this code is to take in student information and *
* put it in a database for permits. The code allows the user  *
* to add students to the database, update permit status, and  *
* print the list of students. Code is heavily focused on      *
* using linked list and dynamic memory allocation.            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "readline.h"

#include <stdio.h>
#include <ctype.h>

int read_line(char str[], int n)
{
        int ch, i = 0;

        while (isspace(ch = getchar()))
                ;

        str[i++] = ch;
        while ((ch = getchar()) != '\n') 
        {
                if (i < n)
                        str[i++] = ch;
    
        }

        str[i] = '\0';
        return i;
}
