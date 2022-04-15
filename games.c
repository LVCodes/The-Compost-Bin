/*Lauren Vogel    COP3514 Section 2     Spring 2020       *
* The purpose of this code is to read in the contents of a*
* file containing the names, stock, and quantity sold of  *
* different games in a store. This code is supposed to    *
* take the file and make a new file of the same name with *
* "sorted_" added to the beginning of the file name where *
* the original file contents are organized by which game  *
* was bought most.                                        *
* compile with gcc -Wall
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME 100
#define FILE_ITEM 100
#define GAME_NAME 100

struct game{
        char game_title[GAME_NAME + 1];
        int sold;
        int stock;
};

void sort_games(struct game list[], int n);

int main(){

        char filename[FILE_NAME + 1];
        //The + 8 added to the array is for the addition of "sorted_" to the beginning of the filename
        char Sortedfilename[FILE_NAME + 8];
        char sorted_[] = "sorted_";

        //heehee imma keep OG from last project
        FILE* fileOG;
        FILE* fileSort;
        struct game list[FILE_ITEM];
        int i, j;

        printf("Enter the file name: ");
        scanf("%s", filename);

        fileOG = fopen(filename, "r");

        for(i = 0; sorted_[i] != '\0'; i++)
                Sortedfilename[i] = sorted_[i];
        for(j = 0; i < FILE_NAME && filename[j] != '\0'; i++, j++)
                Sortedfilename[i] = filename[j];
      
        

        Sortedfilename[i] = '\0';
        fileSort = fopen(Sortedfilename , "w");



        if(fileOG == NULL)
        {
                printf("Error opening file\n");
                return 1;
        }

        i = 0;
        while (!feof(fileOG) && !ferror(fileOG) && i < FILE_ITEM)
        {
                fscanf(fileOG, "%d", &list[i].sold); 
                fscanf(fileOG, "%d", &list[i].stock); 
                fscanf(fileOG, "%[^\n]\n", (char *)&list[i].game_title); 
                i++;
        }
        
        sort_games(list, i);

        for(j = 0; j < i; j++)
        {
                fprintf(fileSort,"%d ", list[j].sold);
                fprintf(fileSort,"%d ", list[j].stock);
                fprintf(fileSort,"%s\n", list[j].game_title);
                
        }
        fclose(fileOG);
        fclose(fileSort);

        printf("Output file name: %s\n",Sortedfilename );        

        return 0;
}

void sort_games(struct game list[], int n){

        if (n == 1)
                return;

        int i, min = n - 1;
        struct game temp;
        //finding the game that sold the most, by quantity sold and moving to end of list
        for(i = 0; i < n; i++ )
        {
                if(list[i].sold < list[min].sold)
                {
                        temp = list[i];
                        list[i] = list[min];
                        list[min] = temp;
                }
        }
        
        sort_games(list, n - 1);
                
}
