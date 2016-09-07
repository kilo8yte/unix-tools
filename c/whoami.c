

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main()
{
	struct passwd *user=getpwuid(geteuid());
	if(user==NULL){
		perror("whoami");
		return errno;	
	}
	write(1,user->pw_name,strlen(user->pw_name));
	write(1,"\n",1);
return 0;
}
