#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#define size 10
sem_t writer,rd;
int b;
int readcount=0;
void *w(void *param)
{
	int i;
	for(i=0;i<size;i++)
	{	
		//sleep(1);
		//i++;
		sem_wait(&writer);
		b=random();
		//pthread_mutex_lock(&mutex);
		printf("Writer is writing record = %d\n",b);
		//pthread_mutex_unlock(&mutex);
		sem_post(&writer);
		printf("Writer going to sleep\n\n");
		sleep(2);
	}
	printf("Writer is leaving\n");	
}
void *r(void *param)
{
	int *rr = (int*)param;
	int i;
	for(i=0;i<size;i++)
	{
		sem_wait(&rd);
		readcount++;
		if(readcount==1)
		sem_wait(&writer);
		sem_post(&rd);
		printf("Reader %d is reading %d \n",*rr,b);
		printf("Reader %d going to sleep\n\n",*rr);
		sleep(2);
		sem_wait(&rd);
		readcount--;
		if(readcount==0)
		sem_post(&writer);
		sem_post(&rd);
		sleep(2);
	}
	printf("Reader no. %d is leaving\n",*rr);	
}
int main()
{
	pthread_t w1,r1,r2;
	int rr1=1,rr2=2;
	b=0;
	readcount=0;
	printf("Value of shared variable is %d\n",b);
	sem_init(&rd,0,1);
	sem_init(&writer,0,1);
	
	pthread_create(&w1,NULL,w,NULL);
	pthread_create(&r1,NULL,r,(void*)&rr1);
	pthread_create(&r2,NULL,r,(void*)&rr2);
	pthread_join(w1,NULL);
	pthread_join(r1,NULL);
	pthread_join(r2,NULL);
	return 0;
}



















