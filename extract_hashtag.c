/*Lauren Vogel    COP3514 Section 2   Spring 2020               *
* The purpose of this code is to take in an input from the user *
* where the input is a message that MIGHT contain a hashtag     *
* used to sort/identify the topic of the user's message. The    *
* program's job is to read the message and determine if it      *
* contains a hashtag statement and then print the hashtag found,*
* but only printing permitted characters (letters, number, and  *
* under scores) before terminating and only the first hashtag if*
* there are multiple.                                           *
* compile with gcc -Wall                                        *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 1000

//Function given in lecture
int read_lines(char *str, int n);
//Function required for project and must utilize pointer arithmetic (no array subscripting)
int find_hashtag(char *s1, char *s2);

int main (){
        printf("Input: ");
        char s1 [N + 1];
        char s2 [N + 1]; 
        int n, found;

        n = read_lines(s1, N);

        //Found is if a hashtag is found in the input.
        found = find_hashtag(s1, s2);
        
        if (found)
                printf("Output: %s\n", s2);
        else
                printf("No hashtag in the input \n");

        return 0;
}

int read_lines(char *str, int n){          
        int ch; 
        int i = 0; 
        while ((ch = getchar()) != '\n')
        {
                if (i < n)
                {         
                         *str++= ch;
                         i++;
                }
        }
        *str = '\0';     // ends string
        return i;        // number of characters stored
}

int find_hashtag(char *s1, char *s2){

        char *p;
        char *q = s2;

        //Take the string and search for '#'. If not found, return 0
        for (p = s1; *p != '\0'; p++)
        {
                //If '#' found, start assigning the hashtag to *q and return 1
                if (*p == '#')
                {
                        *q++ = *p;
                        p++;
                
                        for(; *p == '_' || isalnum(*p); p++)
                        {
                                *q++ = *p;
                        }
                //End of the string assignment
                *q = '\0';
                return 1;
                }
                
        }

        return 0;
}
