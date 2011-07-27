#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, const char *argv[])
{
#if 0
    int *str;
    fscanf();
    fprintf(str,"%s ...",);
    system(str);
#else
	int infd, outfd;
	void *from, *to;
	struct stat infstat;
	DIR *dp;
	
	dp = opendir("./");
	
	if(dp==NULL){
	printf("Open dirctory failed!\n");
	return -1;
	}	  

	printf("%s\n",(char *)dp);
#endif
    return 0;
}
