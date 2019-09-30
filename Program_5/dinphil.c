#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#define size 5
#define thinking 2
#define hungry 1
#define eating 0
#define left (phnum+4)%size
#define right (phnum+1)%size
int state[size];
int phil[size] = {0,1,2,3,4};

sem_t mutex,S[size];

void test(int phnum)
{
	if(state[phnum] == hungry && state[left] != eating && state[right] != eating)
	{
		state[phnum] = eating;
		sleep(2);
		printf("Philosopher %d takes chopsticks %d and %d\n",phnum+1,left+1,phnum+1);
		printf("Philosopher %d is Eating\n",phnum+1);
		sem_post(&S[phnum]);
	}
}
void take_fork(int phnum)
{
	sem_wait(&mutex);
	state[phnum] = hungry;
	printf("Philosopher %d is Hungry\n",phnum+1);
	test(phnum);
	sem_post(&mutex);
	sem_wait(&S[phnum]);
	sleep(1);
}
void put_fork(int phnum)
{
	sem_wait(&mutex);
	state[phnum]=thinking;
	printf("Philosopher %d putting chopsticks %d and %d down\n",phnum+1,left+1,phnum+1);
	printf("Philosopher %d is thinking\n",phnum+1);
	test(left);
	test(right);
	sem_post(&mutex);
}
void *philosopher(void *num)
{
	while(1)
	{
		int *i = num;
		sleep(1);
		take_fork(*i);
		sleep(0);
		put_fork(*i);
	}
}
int main()
{
	int i;
	pthread_t thread_id[size];
	sem_init(&mutex,0,1);
	for(i=0;i<size;i++)
		sem_init(&S[i],0,0);
	for(i=0;i<size;i++)
	{
		pthread_create(&thread_id[i],NULL,philosopher,&phil[i]);
		printf("Philosopher %d is thinking\n",i+1);
	}
	for(i=0;i<size;i++)
		pthread_join(thread_id[i],NULL);
	return 0;		
}

