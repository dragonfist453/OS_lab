#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int num;
void *factorial(void *param)
{
	num = atoi(param);
	int i=1;
	long int prod=1;
	for(i=1;i<=num;i++)
		prod*=i;
	printf("Factorial of %d is %ld\n",num,prod);
	pthread_exit(0);
}
int main(int argc,char* argv[])
{
	pthread_t tid;
	pthread_attr_t attr;
	if(argc!=2)
	{
		fprintf(stderr,"usage: a.out <integer value>\n");
		return -1;
	}
	if(atoi(argv[1])<0)
	{
		fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
		return -1;
	}
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,factorial,argv[1]);
	pthread_join(tid,NULL);
	return 0;
}
