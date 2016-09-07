

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>

void help()
{
	write(2,"usage: mkdir <opt><arg> <dirname>\n -h show help\n -m XXX specify mode\n",70);
}

int parse_mod(const char *n)
{
	int count=0;
	while(*n){
		if(!(*n>=0&&*n<='7'))
			return -1;
		else
			count=count*8+*n-'0';
		++n;	
	}
 return count;
}

int main(int argc,char *argv[])
{
	if(argc==1){
		help();
		return 0;
	}

	mode_t mode=0775;
	umask(0);
	int i=1;
	for(;i<argc;++i){
		if(*argv[i]=='-'){
			++(argv[i]);		
			switch(*argv[i]){
				case 'h':help(); return 0;
					break;
				case 'm':if(i+1<argc){ ++i; if((mode=parse_mod(argv[i]))==-1){
						write(2,"mkdir: please check your settings for -m\n",41);	return 1;}}
					break;
				default:write(2,"mkdir: invalid option\n",22); return 1;
					break;
			}
		}
		else{
			if((mkdir(argv[i],mode))==-1){
				perror("mkdir");
				return errno;
			}
		}	
	}
	
return 0;
}
