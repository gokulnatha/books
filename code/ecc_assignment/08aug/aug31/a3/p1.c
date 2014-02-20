/*	FileName	:	p1.c
 *	Date		: 	31-08-2010
 *	Author		:	Stalin Srinivasan.S	
 *	Description	:	To spawn 3 threads from another thread 
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void* add(void *p)
{
	int a,b;
	printf("\nEnter two nos: ");
	scanf("%d\t%d",&a,&b);
	printf("\nResult: %d",a+b);
	return NULL;
}
	
void* mul(void *p)
{
	int a,b;
	printf("\nEnter two nos: ");
	scanf("%d\t%d",&a,&b);
	printf("\nResult: %d",a*b);
	return NULL;
}

void* sub(void *p)
{
	int a,b;
	printf("\nEnter two nos: ");
	scanf("%d\t%d",&a,&b);
	printf("\nResult: %d",a-b);
	return NULL;
}

int main(void)
{
	pthread_t th1,th2,th3;
	pthread_create(&th1,NULL,add,NULL);	
	pthread_join(th1,NULL);	
	pthread_create(&th2,NULL,sub,NULL);	
	pthread_join(th2,NULL);	
	pthread_create(&th3,NULL,mul,NULL);
	pthread_join(th3,NULL);	
	return 0;
}
	
	

	
	
	
	


	
	
	

