#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
	DIR *d = opendir(argv[1]);
	while(d!=NULL)
	{
		struct dirent *d1 = readdir(d);
		printf("%s\n",d1->d_name);
	}
	return 0;
}
