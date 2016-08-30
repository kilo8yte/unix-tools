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
#include <stdlib.h>

void show_help()
{
	write(2,"usage: sleep NUMBER[SUFFIX]\nSuffix: s for seconds\n \
	m for minutes\n\th for hours\n\td for days\n",94);
}

#include <stdio.h>
int main(int argc,char *argv[])
{
	if(argc==1){
		show_help();
		return 0;
	}
	char tmp=argv[1][strlen(argv[1])-1];
	unsigned int factor=0;
	switch(tmp){
		case 's':
		case 'S':factor=1; 
			break;
		case 'm':
		case 'M':factor=60;
			break;
		case 'h':
		case 'H':factor=3600;
			break;
		case 'd':
		case 'D':factor=86400;
			break;
		default: show_help(); return -1;
	}
	argv[1][strlen(argv[1])-1]=0;
	sleep(atoi(argv[1])*factor);
 return 0;
}
