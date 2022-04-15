/*Lauren Vogel    COP3514 Section 2    Spring 2020        *
* This extra credit assignment asks that the program reads*
* in portions on an email so check it for "spammieness" by*
* counting how many times a word frequently used for      *
* scamming is used, then outputs the count for the user.  *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <string.h>

#define NUM_CHARS 1001
#define NUM_WORDS 501
#define CHARS_PER_WORD 51

int read_line(char *str, int n);

int main() {
        char *spam_words[] =
                {"suspended", "locked", "bank", "update",
                "statement", "personal", "click", "compromised", "deactivated",
                "reactivate", "account", "alert", "confirm", "won", "winner",
                "selected", "claim", "urgent", "disabled", "expire", "investment",
                "refinance", "pre-approved", ""};
	char **spam_ptr = spam_words;
	char delimiters[4] = " ,.!";
	char words[NUM_WORDS][CHARS_PER_WORD]; 
	

	printf("Input: ");
	read_line(*words, NUM_WORDS);


	char *token = strtok(*words, delimiters);

        int n_spam_words = 0;

	printf("Output: \n");

        //checking each word for suspiciousinounsnisness
	while(token != NULL)
        {
                //suggested to use string compare
		while(strcmp(*spam_ptr, "") != 0) 
                {
			if(strcmp(token, *spam_ptr++) == 0)
				n_spam_words++;
		}

		token = strtok(NULL, delimiters);
		spam_ptr = spam_words;
	}

        printf("%d spam words found\n", n_spam_words);

	return 0;
}
//From lecture notes
int read_line(char *str, int n){

        int ch;
        int i = 0;

        while ((ch = getchar()) != '\n')
        {
                if (i < n)
                {
                        *str++ = ch;
                        i++;
                }
        }
        *str = '\0';
        return 0;
}
