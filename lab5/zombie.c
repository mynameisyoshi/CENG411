#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "includes.h"
int main()
{
   int childPID;	
   childPID = fork();
   if(childPID==0)
          fprintf(stdout,"This is the child %d speaking\n",
                           getpid());
   else if(childPID==-1)
          exit(1);  //return right away - the child becomes a zombie 
   else 
      {   //This is the parent     
          sleep(1); //give the child enough time to die
          fprintf(stdout,"The is parent %d.  Checking the status of child %d\n", getpid(),childPID);
          system("ps -O ppid");  //examine the child status
          wait(NULL); //reap the child
       }
   fprintf(stdout,"Process %d is now done\n",getpid());
 }
 
