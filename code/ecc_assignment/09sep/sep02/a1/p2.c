/*	FileName	:	p2.c
 *	Date		: 	01-09-2010
 *	Author		:	Stalin Srinivasan.S	
 *	Description	:	To make communication between threads of this process to the unrelated process ( p1.c )	
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>

char fifo[30],conr[30],conw[30];
int fdr,fdw;

void* r1()
{
	fdr=open(fifo,O_RDONLY);
	read(fdr,conr,30);
	printf("\nRead content: %s",conr);
	close(fdr);
}

void *r2()
{
	fdw=open(fifo,O_WRONLY);
	printf("\nEnter the content to be written: ");
	scanf("%s",conw);
	write(fdw,conw,strlen(conw));
}


int main()
{
	pthread_t th1,th2;
	printf("\nEnter the fifo name: ");
	scanf("%s",fifo);
	pthread_create(&th1,NULL,r1,NULL);
	pthread_join(th1,NULL);
	pthread_create(&th2,NULL,r2,NULL);
	pthread_join(th2,NULL);
}

	
	

	
	

	
	
	
	


	
	
	

