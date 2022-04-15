/*Lauren Vogel      COP3514 Section 2     Spring 2020         *
* The goal of this code is to take in student information and *
* put it in a database for permits. The code allows the user  *
* to add students to the database, update permit status, and  *
* print the list of students. Code is heavily focused on      *
* using linked list and dynamic memory allocation.            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "request.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


