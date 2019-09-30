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
		printf("Philosopher %d takes chopsticks %d and %d\n",phnum+i,left+i,phnum+i);
		printf("Philosopher %d is Eating\n",phnum+i);
		sem_post(&S[phnum]);
	}
}
void take_fork(int phnum)
{
	sem_wait(&mutex);
	state[phnum] = hungry;
	printf
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
			
