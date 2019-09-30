#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define size 10
int buffer[size],counter;
pthread_mutex_t mutex;
sem_t empty,full;
void* producer(void *param)
{
	srandom(random());
	while(1)
	{
		sleep(1);
		int item = random()&20;
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		printf("Producer has produced item %d\n",item);
		buffer[counter] = item;
		counter++;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}	
}
void* consumer(void *param)
{
	while(1)
	{
		sleep(1);	
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		counter--;
		if(counter<0)
		{
			counter = 0;
			pthread_exit(0);
		}	
		int item = buffer[counter];
		printf("Consumer has consumed item %d\n",item);
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}	
}

int main(int argc,char *argv[])
{
	pthread_t prod[10],cons[10];
	pthread_mutex_init(&mutex,NULL);
	int size_prod = atoi(argv[1]);
	int size_cons = atoi(argv[2]);
	sem_init(&full,0,1);
	sem_init(&empty,0,size);
	counter = 0;
	int i;	
	for(i=0;i<size_prod;i++)
	{
		//sleep(1);
		pthread_create(&prod[i],NULL,producer,NULL);
	}	
	for(i=0;i<size_cons;i++)
	{
		//sleep(1);
		pthread_create(&cons[i],NULL,consumer,NULL);
	}		
	for(i=0;i<size_prod;i++)
		pthread_join(prod[i],NULL);
	for(i=0;i<size_cons;i++)
		pthread_join(cons[i],NULL);
	return 0;
}			
