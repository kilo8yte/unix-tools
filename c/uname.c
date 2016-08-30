/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <benni@include-benni.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Benjamin Hartmann
 * ----------------------------------------------------------------------------
 */

#include <unistd.h>
#include <sys/utsname.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc,char *argv[])
{
        struct utsname un;
        if(uname(&un)==-1){
                if(errno==EFAULT){
                        write(2,"uname: buffer for uname isn't valid",35);
                }
        }
        if(argc==1){
                write(1,un.sysname,strlen(un.sysname));
                return 0;
        }    
        int i=1;
        do{
                if(*argv[i]=='-'){
                        ++argv[i];                               
                        switch(*argv[i]){
                                case 'v':write(1,un.version,strlen(un.version));
                                        break;
                                case 'r':write(1,un.release,strlen(un.release));
                                        break;
                                case 'n':write(1,un.nodename,strlen(un.nodename));
                                        break;
                                case 's':write(1,un.sysname,strlen(un.sysname));
                                        break;
                                case 'm':
                                case 'p':write(1,un.machine,strlen(un.machine));
                                        break;
                                default:write(2,"uname: unknown option",22);
                                        break;
                        }
                        write(1," ",1);
                }
                ++i;
        }while(i<argc);
        write(1,"\n",1);
 return 1;
}
