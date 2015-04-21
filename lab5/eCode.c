/*
   File: eCode.c
   Course: CENG411
   Author: Leon King
   Date: Tuesday March 22, 2005
   Purpose: To THOROUGHLY test for ALL possible
            error codes while opening a file.
            (Helpful if you need to debug a program -
             not practical to check all cases every time
             with student projects.  see associated script
             eCodeTest
   */


#include <stdio.h>
#include <errno.h> 
int main(int argc, char * argv[ ])
{
    char defaultMode[]={"rt"};
    int errorCode;
    FILE *fp;
    int k;
    if(argc<2) {
	fprintf(stderr,"Usage: %s fileName [fileMode]\n",argv[0]); 
	return -1; /* Program fails */
    }
    fp=fopen(argv[1],argc>2 ? argv[2] : defaultMode);
    /*
       if(argc>2) fp=fopen(argv[1],argv[2]);
            else  fp=fopen(argv[1],defaultMode);
       */
    errorCode=errno;/* Better save errno - perror will reset it*/
    perror("Status of file open");
    fprintf(stdout,"The error code is: %d\n",errorCode); 
    /* Detect any error  - could insert our own code to deal with it*/
    switch(errorCode){
	case 0: 
	    fprintf(stdout,"Success\n"); 
	    break; 
	case EINVAL:
	     fprintf(stderr,"Invalid file mode\n"); 
	     break;
	case EACCES: 
	      fprintf(stderr,"Insufficient privilege to read file %s\n",argv[1]); 
	     break; 
	case ENOENT: 
	     fprintf(stderr,"Invalid directory or file name - try again\n"); 
	    break;
	case ELOOP: 
	      fprintf(stderr,"Bad Symbolic link - try again\n"); 
	    break;
	case EISDIR:
	      fprintf(stderr,"Can't write to a directory\n");
	     break;
	case ENOTDIR:
	      fprintf(stderr,"Invalid Path\n");
	      break;

        case ENAMETOOLONG :
             fprintf(stderr,"the path name is too long\n");
             break;
        case ENFILE:
             fprintf(stderr,"Too many files open\n");
             break; 
	case ENODEV:
	      fprintf(stderr,"No Such Device: %s\n",argv[1]);
	      break;
	default: 
	   perror("Undetected Error");
	   fprintf(stderr,"Undetected Error: %d\n",errorCode); 
	} 

	return 0;

} 
