/*Lauren Vogel      COP3514 Section 2    Spring 2020          *
* The goal of this code is to take in student information and *
* put it in a database for permits. The code allows the user  *
* to add students to the database, update permit status, and  *
* print the list of students. Code is heavily focused on      *
* using linked list and dynamic memory allocation.            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define COURSE_LEN 100
#define NAME_LEN 30
#define STATUS_LEN 30

//struct DS given by prof
struct request{
	char courseID[COURSE_LEN+1];
	char studentID[NAME_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char status[STATUS_LEN+1];
	struct request *next;
};


struct request *append_to_list(struct request *list);
void update(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n);

/**********************************************************
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

        //chaos thrives in this house
        for (;;) 
        {
                printf("Enter operation code: ");
                scanf(" %c", &code);

                while (getchar() != '\n')   // skips to end of line
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

struct request *append_to_list(struct request *list){

        struct request *new_node = calloc(1, sizeof(struct request));        
        struct request *ptr;

        printf("Enter courseID: ");
        scanf("%s", new_node->courseID);
        printf("Enter studentID: ");
        scanf("%s", new_node->studentID);
       
        strcpy(new_node->status, "pending");

        /* new_node->next = NULL;  decided to use calloc instead 
           of malloc, need this if decide to use malloc */
        
        if(list == NULL)
        {
                printf("Enter student last name: ");
                scanf("%s", new_node->last); 
                printf("Enter student first name: ");
                scanf("%s", new_node->first);
                return new_node;
        }


        for(ptr = list; ptr->next != NULL; ptr = ptr->next)
                if(strcmp(ptr->courseID, new_node->courseID) == 0 
                && (strcmp(ptr->studentID, new_node->studentID) == 0))
                {
                        printf("Permit request already existed");
                        puts("");
                        free(new_node);
                        return list;
                }

        if(strcmp(ptr->courseID, new_node->courseID) == 0 
           && (strcmp(ptr->studentID, new_node->studentID) == 0))
        {
                printf("Permit request already existed");
                puts("");
                free(new_node);
                return list;
        }

        printf("Enter student last name: ");
        scanf("%s", new_node->last); 
        printf("Enter student first name: ");
        scanf("%s", new_node->first);

        
        ptr->next = new_node;
               

        return list;
}


void update(struct request *list){
        
        struct request *new_node = malloc(sizeof(struct request));
        
        printf("Enter courseID: ");
        scanf("%s", new_node->courseID);
        printf("Enter studentID: ");
        scanf("%s", new_node->studentID);

        for(; list != NULL; list = list->next)
                if((strcmp(list->courseID, new_node->courseID) == 0) &&
                  (strcmp(list->studentID, new_node->studentID) == 0))
                {
                        printf("Enter status: ");
                        scanf("%s", list->status);
                        free(new_node);
                        return;
                }      
        
        printf("Permit request not found in the record\n");
        free(new_node);
}


void printList(struct request *list){

        struct request *p;

        //lolololololololololol
        printf("=======================================================================\n");
        printf("CourseID      StudentID      Last Name      First Name      Status\n");

        for(p = list; p != NULL; p = p->next)
        {
                printf("%-14s", p->courseID);
                printf("%-15s", p->studentID);
                printf("%-15s", p->last);
                printf("%-16s", p->first);
                printf("%-s\n", p->status);
        }
        printf("=======================================================================\n");
}

//pulled clear list from exercises
void clearList(struct request *list)
{

        struct request *p;
        while(list != NULL)
        {
                p = list;
                list = list->next;

                if(p != NULL)
                        free(p);
        }

}


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
