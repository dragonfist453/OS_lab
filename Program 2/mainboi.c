#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int pid = fork();
	if(pid == 0)
	{
		printf("PID of child = %d\n\n",getpid());
		execlp("./caesar","caesar",argv[1],NULL);
	}
	else
	{
		//wait(NULL);
		printf("PID of parent = %d\n\n",getpid());
		execlp("./combination","combination",argv[2],argv[3],NULL);
	}
	return 0;
}
