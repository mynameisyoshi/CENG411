#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char * argv[],char * envp[])
{
  DIR * myDir=opendir(".");
  struct stat fileInfo;
  struct passwd * pwd;
  struct group *  group;
  struct dirent *dirent;
  while(dirent=readdir(myDir))
  {
     stat(dirent->d_name,&fileInfo);
     fprintf(stdout, "file name: %s  owner:  %s  group: %s\n",
           dirent->d_name,
           getpwuid(fileInfo.st_uid)->pw_gecos,
           getgrgid(fileInfo.st_gid)->gr_name);
    }
  return 0;
  }
