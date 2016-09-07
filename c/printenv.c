

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
