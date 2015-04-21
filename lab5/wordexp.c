/******************************
NAME: Harsh Joshi
Date: Monday April 6, 2015
Comments: So this code will run any command. like any. wont get me another beer tho :(
future note to my self dont hand in this copy of the programm
******************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <wordexp.h>
#include <sys/wait.h>
int main()
{
//declare my shit
int status;
 char cmd[1000];
 wordexp_t expansionList;
 int result;

while(1)
  {
     fprintf(stdout,"Your request is my command > ");
     fgets(cmd,sizeof(cmd),stdin);
     cmd[strlen(cmd)-1]='\0';
     if(feof(stdin)) break;

 result=wordexp(cmd,&expansionList, WRDE_SHOWERR);

//check if anything is here
     if(cmd[0]=='#') continue;

//to see if this shit runs
     if(strcmp(cmd,"Joshi")==0) 
               {fprintf(stdout,"This program is dedicated to Prof.Leon King\n");
                continue;
                }
//if i write exit the program leave
     if(strcmp(cmd,"fuck_it")==0) exit(0);

     switch(fork())
     {
//i fucked up something
       case 0:  
            execvp(expansionList.we_wordv[0],expansionList.we_wordv);
            return -1; 
//Computer fucked up
       case -1:  perror("Failed to fork");
             break;
//holy shit this worked! god bless king
       default: 
               wait(&status); 
               wordfree(&expansionList);

      }
//this will tell me the status - note to my self you can do this simple byt echo !?
     fprintf(stdout,"Status of command is: %d\n",status);    
   }
  return 0;
  }
