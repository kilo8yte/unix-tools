/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <benni@include-benni.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Benjamin Hartmann
 * ----------------------------------------------------------------------------
 */

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
