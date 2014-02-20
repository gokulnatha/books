#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
int myglobal=0;
void *thread_function(void *arg)
{
	int i,j;
	printf("\nMy global: %d\tJ: %d",myglobal,j);
	for(i=0;i<20;i++)
	{
		j=myglobal;
		j=j+1;
		printf("\nMy global: %d\tJ: %d",myglobal,j);
		myglobal=j;
	}
	return 	NULL;
}

int main(void)
{
	pthread_t mythread;
	int i;
	pthread_create(&mythread,NULL,thread_function,NULL);
	for(i=0;i<20;i++)
	{
		myglobal=myglobal+1;
		printf("\nMy global: %d",myglobal);
		sleep(2);
	}
	printf("\nMy global equals %d",myglobal);
	return 0;
}
