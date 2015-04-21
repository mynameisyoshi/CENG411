#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct MAIL
   {
     bool arithmetic;		//-n flag
     bool entry;		//-f flag
     bool stack;	//-R flag
     bool subject;	//-a flag
     bool user;	//-d flag

     };

int main(int argc, char * argv[], char * envp[])
{
	struct MAIL MAIL = {false,false, false, false, false, false}; //Set defaults

	int flag, flag_used = 0, total_arguments = 0, arguments = 0;
	
	while((flag = getopt(argc, argv, "insvu")) != -1)

	{
	//	fprintf(stdout,"Processing cmd line arg #%d with flag %c.\n", optind - 1, flag);
		switch(flag)
		{
			case 'i':
				MAIL.arithmetic=true;
				break;
			case 'n':
				MAIL.entry=true;
				break;	
			case 's':
				MAIL.stack=true;
				break;
			case 'v':
				MAIL.subject=true;
				break;
			case 'u':
				MAIL.user=true;
				break;
			default:
				perror("Bad flag!");
				fprintf(stderr,"flag: %c opterr: %d optopt %c\n", flag, opterr, optopt);
		}
	}

	//Verification - necessary for testing the getopt loop
        fprintf(stdout,"The flag -i is set to: %s\n", MAIL.arithmetic ?"true" : "false" );
        fprintf(stdout,"The flag -n is set to: %s\n", MAIL.entry ? "true" : "false");
        fprintf(stdout,"The flag -s is set to: %s\n", MAIL.stack ? "true" : "false");
        fprintf(stdout,"The flag -v is set to: %s\n", MAIL.subject ? "true" : "false");
        fprintf(stdout,"The flag -u is set to: %s\n", MAIL.user ? "true" : "false");
        	
	return 0;
}
