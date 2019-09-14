#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
long unsigned int prod=1;
void *odd_multiplier(void *param)
{
	int n = atoi(param);
	int i;
	for(i=1;i<=n;i+=2)
		prod*=i;
	pthread_exit(0);
}
void *even_multiplier(void *param)
{
	int n = atoi(param);
	int i;
	for(i=2;i<=n;i+=2)
		prod*=i;
	pthread_exit(0);
}
int main(int argc,char* argv[])
{
	pthread_t odd,even;
	//pthread_attr_t attr;
	if(argc!=2 || strcasecmp("HELP",argv[1])==0)
	{
		fprintf(stderr,"usage: a.out <integer value>\n");
		return -1;
	}
	if(atoi(argv[1])<0)
	{
		fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
		return -1;
	}
	//pthread_attr_init(&attr);
	pthread_create(&odd,NULL,odd_multiplier,argv[1]);
	pthread_create(&even,NULL,even_multiplier,argv[1]);
	pthread_join(odd,NULL);
	pthread_join(even,NULL);
	printf("Factorial of %d is %lu\n",atoi(argv[1]),prod);
	return 0;
}
