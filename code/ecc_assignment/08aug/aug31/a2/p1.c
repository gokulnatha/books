/*	FileName	:	p1.c
 *	Date		: 	31-08-2010
 *	Author		:	Stalin Srinivasan.S	
 *	Description	:	To spawn 3 threads from another thread 
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void* threadroutine1(void *p)
{
	printf("\nhai\n");
	return NULL;
}

void* threadroutine(void *p)
{
	pthread_t th11,th12,th13;
	pthread_create(&th11,NULL,threadroutine1,NULL);
	pthread_create(&th12,NULL,threadroutine1,NULL);
	pthread_create(&th13,NULL,threadroutine1,NULL);
	pthread_join(th11,NULL);
	pthread_join(th12,NULL);
	pthread_join(th13,NULL);
	return NULL;
}

int main(void)
{
	pthread_t th1;
	pthread_create(&th1,NULL,threadroutine,NULL);
	pthread_join(th1,NULL);
	printf("\nbye\n");
	return 0;
}

	
	

	
	
	
	


	
	
	

