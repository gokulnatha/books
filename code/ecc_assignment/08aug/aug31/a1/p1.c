/*	FileName	:	p1.c
 *	Date		: 	31-08-2010
 *	Author		:	Stalin Srinivasan.S	
 *	Description	:	To spawn 3 threads from main process 
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void* threadroutine1(void *p)
{
	printf("\nThread 1");
	return NULL;
}

void* threadroutine2(void *p)
{
	printf("\nThread 2 ");
	return NULL;
}

void* threadroutine3(void *p)
{
	printf("\nThread 3");
	return NULL;
}

int main(void)
{
	pthread_t th1,th2,th3;
	pthread_create(&th1,NULL,threadroutine1,NULL);
	pthread_create(&th2,NULL,threadroutine2,NULL);
	pthread_create(&th3,NULL,threadroutine3,NULL);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);
	printf("\nThe end...");
	return 0;
}
	
  		
	
	
	
	


	
	
	

