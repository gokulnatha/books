#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int i=0;

void* threadroutine(void *p)
{
	while(i<10)
	{
		printf("\nThread->i: %d",i++);
	}
}

int main(void)
{
	pthread_t myth;
	system("clear");
	pthread_create(&myth,NULL,threadroutine,NULL);
	while(i<10)
	{
		printf("\nProcess->i: %d",i);
		i++;
	}
	printf("\nResult: %d\n",i);
	return 0;
}
	
