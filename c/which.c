

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	if(argc==1){
		write(2,"which: which programename\n",28);
		return 1;
	}
	char *path=getenv("PATH");
	char **subpath=NULL;
	unsigned int count=0;
	path=strtok(path,":");
	while(path){
		if((subpath=realloc(subpath,sizeof (char *) * ++count))==NULL){
			perror("which: realloc");
			return errno;
		}
		subpath[count-1]=path;
		path=strtok(NULL,":");
	}
	int i,j;
	for(i=1;i<argc;i++){
		for(j=0;j<count;j++){
			if(chdir(subpath[j])==0){
				if(access(argv[i],X_OK)==0){
					write(1,subpath[j],strlen(subpath[j]));
					write(1,"/",1);
					write(1,argv[i],strlen(argv[i]));
					write(1,"\n",1);
					break;
				}
			}
		}
	}
	free(subpath);
 return 1;
}
