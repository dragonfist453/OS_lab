#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int i;
	for(i=1;i<argc;i++)
		unlink(argv[i]);
	return 0;
}
