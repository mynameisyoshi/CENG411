#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
struct FLAGS
   {
     char ingnore;
     char next;
     bool save;
     bool visual;
     bool undelete;
     };

  
int main(int argc, char * argv[],char * envp[])
{
  struct FLAGS flags={false, false,false,false,1,"  "};//set defaults

  int flag;
  long double result;

  while((flag=getopt(argc,argv,"insvu"))!=-1)
  {
     fprintf(stdout,"Processing cmd line arg #%d with flag %c.\n",
                    optind-1,flag); 
     switch(flag)
     {
       case 'i':
            flags.ignore=true;
            break;
       case 'n':
            flags.next=true;
            break;
       case 's':
            flags.save=true;
            break;
       case 'v':
            flags.visual=true;
            break;
       case 'u':
            flags.undelete=true;
            break;
       default:
            perror("Ooops! Bad flag or missing argument");
            fprintf(stderr,"flag: %c  opterr: %d optopt %c\n",
                         flag, opterr, optopt);
       }
  }

    //Verification - necessary for testing the getopt loop
     fprintf(stdout,"The flag -a is set to: %s\n", flags.ignore ? "true" : "false");
     fprintf(stdout,"The flag -c is set to: %s\n", flags.next ? "true" : "false");
     fprintf(stdout,"The flag -d is set to: %s\n", flags.save ? "true" : "false");
     fprintf(stdout,"The flag -e is set to: %s\n", flags.visual ? "true" : "false");
     fprintf(stdout,"The flag -m is set to: %s\n", flags.undelete ? "true" : "false");
    
  //Print out the remaining values
  for(int i=optind; i<argc; i++)
    fprintf(stdout,"%d. %s\n", i, argv[i]); 

  return 0;
}
