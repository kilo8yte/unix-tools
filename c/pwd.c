

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#ifndef PATH_MAX
#define PATH_MAX 255
#endif

int main(int argc,char *argv[])
{
	char *path=NULL;
	path=getcwd(path,PATH_MAX);	
	if(path==NULL){
		perror("pwd: getcwd");
		return errno;
	}
	path[strlen(path)]='\n';
	write(1,path,strlen(path));
	free(path);
 return 0;
}
