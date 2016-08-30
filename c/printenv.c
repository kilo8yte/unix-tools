/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <benni@include-benni.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Benjamin Hartmann
 * ----------------------------------------------------------------------------
 */

#include <unistd.h>
#include <string.h>

int main()
{
	extern char **environ;
	unsigned int i=0;
	while(environ[i]){
		write(1,environ[i],strlen(environ[i]));
		write(1,"\n",1);
		++i;
	}
 return 0;
}
