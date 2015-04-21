
#include <stdio.h>
#include <string.h>

int main()
{
   int originalProcess;	

   originalProcess=getpid();

   if(fork()==-1) {
          printf("Error in fork\n");
	}
   else if(originalProcess==getpid()) //We're in the parent
   {
       int status;
       wait(&status);
       printf(stdout,"Parent responds.  The child has died with error code: %d\n", status);
    }
	 else 
      { printf(stdout,"This is the child %d speaking\n", getpid());
        exit(17); 
       }
		 return 0;
 }
 
