#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <error.h>

int main(int argc,char *argv[])
{
	int fd;
	char buffer[255];
	struct flock fl;
	if(argc==1)
	{
		fprintf(stderr,"Usage : %s filename\n",argv[0]);
		return -1;
	}
	if((fd=open(argv[1],O_RDWR))==-1)
	{
		perror("File not opened!\n");
		return -1;
	}
	fl.l_type=F_WRLCK;
	fl.l_whence=SEEK_SET;
	fl.l_start=0;
	fl.l_len=100;
	if((fcntl(fd,F_SETLK,&fl))==0)
	{
		//sleep(20);
	}
	else
	{
		fcntl(fd,F_GETLK,&fl);
		printf("File is locked by process with pid : %d\n",fl.l_pid);
		return -1;
	}		
	printf("Press enter to release lock\n");
	getchar();
	fl.l_type = F_UNLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 100;
	if((fcntl(fd,F_UNLCK,&fl))==-1)
	{
		perror("File not getting unlocked!! (maybe cos it wasn't locked at all?)\n");
		exit(0);
	}
	printf("Unlocked!\n");
	close(fd);
	return 0;	
}
