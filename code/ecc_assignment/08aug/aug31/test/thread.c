#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int myglobal=0;
pthread_mutex_t mymutex=PTHREAD_MUTEX_INITIALIZER;
void *thread_function(void *arg)
{
	int i,j;
	printf("\nMy thread id %d",pthread_self());
	printf("\nThread: My global: %d\tJ: %d",myglobal,j);
	for(i=0;i<20;i++)
	{
		pthread_mutex_lock(&mymutex);
		j=myglobal;
		j=j+1;
		printf("\nThread: My global: %d\tJ: %d",myglobal,j);
		myglobal=j;
		pthread_mutex_unlock(&mymutex);
		sleep(1);
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
		pthread_mutex_lock(&mymutex);
		myglobal=myglobal+1;	
		printf("\nMain:My global: %d",myglobal);
		sleep(1);
		pthread_mutex_unlock(&mymutex);
	}
	printf("\nMy global equals %d",myglobal);
	return 0;
}
