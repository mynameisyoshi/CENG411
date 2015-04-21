#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
   int childPID=0;	
   childPID = fork();
   switch(childPID)
   {
     case 0:
          sleep(60);
          return 0;
     case -1:
          perror("Error in fork");
          break;
     default:    
          fprintf(stdout,"The parent %d says good-bye.  You have 60 seconds to examine the child %d\n",getpid(),childPID);
    }
 }
 
