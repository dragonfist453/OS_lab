#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char buf[100];
	int fd1,fd2,n;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2],O_RDWR | O_CREAT);
	if( fd1 < 0 || fd2 < 0 )
	{
		printf("File not opened!!\n");
		exit(0);
	}
	while( (n = read(fd1,buf,100)) && n != 0 )
		write(fd2,buf,n);
	close(fd1);
	close(fd2);
	return 0;
}

