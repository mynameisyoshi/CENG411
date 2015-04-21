#include <string.h>   
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>  //Added in C99


const char *progName;
//external variables related to getopt
//These are declared for us in getopt.h - we don't have to declare them
extern char * optarg;   //string.  Argument of the flag
extern int optind;      //index in argv[] of the next entry to parse
extern int optopt;      //If getopt returns '?' (invalid option) or ':'
extern int opterr;
//(missing argument) then optopt is the flag

int main(int argc,char * argv[])
{
    //A bundle of variables to remember the flags on the
    //command line
    struct Flags
    {
      bool ignore;
      char next;
      bool save;
      char visual;
      bool  undelete;
     } getOptFlags = {false,false,NULL,false,NULL,false};

    char * shortOptions="insuv"; 
    struct option  options[]= { //{flag,has_arg,ignore,returnCode} 
                       {"ignore", 0, NULL, 'i'}, 
                       {"next", 1, NULL, 'n'}, 
                       {"save",0,NULL,'s'},
                       {"visual",1,NULL,'u'},
                       {"undelete",0,NULL,'v'},
                        {NULL,0,NULL,'\0' }};

    //Use these variables to record the command line options
    int flag;
    int indexVal;
    int i,last=1;

	while( (flag=getopt_long(argc,argv,shortOptions,options,&indexVal))!=-1)
	{
	    fprintf(stdout,"flag: %c   Argument: %s Position: %d OptOpt: %c\n",
		    flag, optarg, optind, optopt);
	} 

	while( (flag=getopt_long(argc,argv,shortOptions,options,&indexVal))!=-1)
	{
            last=optind;
	    switch(flag)
	    {
		case 'i':  
			   getOptFlags.ignore=true;
			   break;

		case 'n':  
                           getOptFlags.next=true;
			   break;

		case 's':  //Convert optarg from string to int
                           getOptFlags.save=true;
			   break;

		case 'u': 
			   //getOptFlags.inFileName=strcpy(malloc(strlen(optarg)+1),optarg);
			   getOptFlags.visual=optarg;
			   break;
		case 'v':  
			   //getOptFlags.file=strcpy(malloc(strlen(optarg)+1),optarg);
			   getOptFlags.undelete=optarg;
			   break;
		case '?':  fprintf(stderr,"Invalid Flag: %c\n", optopt);
			   break;

		case ':':   fprintf(stderr,"Missing command line argument for flag %c\n",optopt);
			    break;

	    }
	}

    //Having parsed the flags, demonstrate that we remember them
    fprintf(stdout,"\n\nProgram Summary: ");
    if(getOptFlags.suppress)
               fprintf(stdout,"-i flag was processed\n");

    if(getOptFlags.nlocal) 
               fprintf(stdout,"-n flag was processed\n");

    if(getOptFlags.num) fprintf(stdout,"-s flag was processed\n");

    if(getOptFlags.file)
            fprintf(stdout,"-v flag was processed");

    if(getOptFlags.udomain) 
          fprintf(stdout,"-u flag was processed\n");

    fprintf(stdout,"\n\nThe remaining command line args are: \n");
    for(i=optind;i<argc;i++)
        fprintf(stdout,"argv[%d] is %s\n",i,argv[i]);


    return 0;
}
