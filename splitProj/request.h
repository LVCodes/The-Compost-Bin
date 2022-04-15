/*      U95724682       Lauren Vogel      COP3514 Section 2   *
* The goal of this code is to take in student information and *
* put it in a database for permits. The code allows the user  *
* to add students to the database, update permit status, and  *
* print the list of students. Code is heavily focused on      *
* using linked list and dynamic memory allocation.            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __REQUEST_H
#define __REQUEST_H

#define COURSE_LEN 100
#define NAME_LEN 30
#define STATUS_LEN 30

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

#endif
