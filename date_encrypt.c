/*Lauren Vogel    COP3514 Section 2    Spring 2020        *
* The purpose of this code is to read in a text file and  *
* encrypt it using a 6 digit date given by the user. Each *
* number in the date given is assigned in order to each   *
* letter in the file (no digit is assigned to white space *
* or any other special characters) and each letter has the*
* number assigned to it added to the letters ASCII value  *
* then a new file is written with the same name as the    *
* original read in file with the added .ecp extension that*
* contains the encryption of the original message.        *
* Compile with gcc -Wall
* Points lost as it doesn't handle white spaces correctly
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#define FILE_NAME 100
#define MAX_LEN 10000
#define DATE 6
#define EXTENSION 4

void encrypt (char *message, int date[], int n);

int main(){

        //fileOG is the first file given to be encrypted
        //fileNEW is the pointer to the original message encrypted
        char filenameOG[FILE_NAME];
        //The + 4 added to the array is for the .ecp extension
        char filenameNEW[FILE_NAME + 4];
        char dot_ecp[EXTENSION] = ".ecp";
        FILE* fileOG;
        FILE* fileNEW;
        //char message[];
        int date[6];
        char buffer[MAX_LEN]; //should this be a char array?
        int i, j;

        printf("Enter file name: ");
        scanf("%s", filenameOG);

        printf("Enter the date in the format of 6 digit: ");
        for(i = 0; i < DATE; i++)
        {
                scanf("%1d", &date[i]);
        }

  
        fileOG = fopen(filenameOG, "r");  
        for(i = 0; i < FILE_NAME && filenameOG[i] != '\0'; i++)
        {
                filenameNEW[i] = filenameOG[i];
        }

        for (j = 0; j < EXTENSION; j++ , i++)
        {
                filenameNEW[i] = dot_ecp[j];
        }

        filenameNEW[i] = '\0';
        fileNEW = fopen(filenameNEW , "w");



        if(fileOG == NULL)
        {
                printf("Error opening file\n");
                return 1;
        }

        while (!feof(fileOG) && !ferror(fileOG))
        {
                if (fgets(buffer, MAX_LEN, fileOG) != NULL)
                {
                        encrypt(buffer, date, DATE);
                        fprintf(fileNEW, "%s", buffer);
                }
        }

        fclose(fileOG);
        fclose(fileNEW);

        printf("Output file name: %s", filenameNEW);
        return 0;
}

void encrypt(char *message, int date[], int n){

        char *p;

        for (p = message; *p != '\0'; p++)
        {
                if(*p == ' ')
                {
                        *p = ' ';
                }

                else if(*p >= 'a' && *p <= 'z')
                {
                        *p = ((*p - 'a' + date[(p - message) % n]) % 26) + 'a';
                }

                else if (*p >= 'A' && *p <= 'Z')
                {
                        
                        *p = ((*p - 'A' + date[(p - message) % n]) % 26) + 'A';
                }
        }
}
