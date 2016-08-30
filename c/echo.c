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

int main(int argc,char *argv[])
{
	for(unsigned int i=1;i<argc;i++){
		write(1,argv[i],strlen(argv[i]));
		write(1," ",1);
	}
	write(1,"\n",1);
 return 0;
}
