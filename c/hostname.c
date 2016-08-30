/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <benni@include-benni.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Benjamin Hartmann
 * ----------------------------------------------------------------------------
 */

#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 255
#endif

extern int gethostname(char *,size_t);
extern int sethostname(const char *,size_t);

void print_help()
{
        write(2,"usage: hostname -s $hostname\n",29);
}           

int main(int argc,char *argv[])
{
	if(argc==1){
        	char hostname[HOST_NAME_MAX+1];
        	if(gethostname(hostname,HOST_NAME_MAX)==-1){
                        perror("uname");
        	}                
                write(1,hostname,strlen(hostname));
                write(1,"\n",1);
                return 0;
        }
        
        int i=1;
        do{
                if(*argv[i]=='-'){
                        ++argv[i];
                        switch(*argv[i]){
                                case 's':if(i+1<argc){
                                                ++i;
                                                if(sethostname(argv[i],strlen(argv[i]))==-1)
                                                        perror("hostname");
                                        }
                                        break;
                                case 'h':print_help();
                                        break;
                        }
                }
                ++i;
        }while(i<argc);        
 return 0;
}
