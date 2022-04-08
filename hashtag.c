/*Lauren Vogel    COP3514 Section2     Spring 2020              *
* The purpose of this program is to check an input to see if it *
* is a valid hashtag STARTING with the '#' character first, and *
* contains only letters, numbers, and underscores, no other     *
* special characters can be in the input. The program will print*
* whether the hashtag is valued or not before ending.           *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>

int main (){

        char ch;
        int valid = 1; /* Equal to 1 for true initialization */

        printf("Input: ");
        scanf("%c",&ch); /* Strictly to scan the first character only for '#' */
          if (ch != '#')
            valid = 0;
   
        ch = getchar();

        while(ch != '\n'){
          if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch == '_')))
                valid = 0;
          ch = getchar();
        }
        /*Checks if valid is true or fasle */ 
        if (valid) (printf("Output: Is a valid hashtag\n"));
        else printf("Output: It is an Invalid hashtag\n");


  return 0;
}
