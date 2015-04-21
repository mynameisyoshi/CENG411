#include <stdio.h>
#include <crypt.h>
#include <unistd.h>
int main(int argc, char * argv[],char * envp[])
{
  char password[]="swordfish";
  char * result=crypt(password,"cinnamon");

  fprintf(stderr,"encrypted result: %s\n", result); //getpass also output 

  char *pass;
  pass=getpass("Enter your password: ");
  fprintf(stdout,"Your password was: %s\n",pass);
  result=crypt(pass,"pepper");
  fprintf(stderr,"encrypted result: %s\n", result); //getpass also output 
  return 0;
  }
