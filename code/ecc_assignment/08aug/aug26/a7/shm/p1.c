/*	FileName	:	p1.c
 *	Date		: 	26-08-2010
 *	Author		:	Stalin Srinivasan.S	
 *	Description	:	To create and attach shared memory with process and try to read and write from two processes
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(void)
{
	int rid,status,key;
	char *saddr=0;
	printf("\nEnter the key: ");
	scanf("%d",&key);
	rid=shmget(key,100,IPC_CREAT|0777);
	printf("shared mry: %d",rid);
	saddr=shmat(rid,NULL,0);
	system("clear");
	printf("\nEnter the filename: ");
	scanf("%s",saddr);
	sleep(20);
	printf("\nContent: %s",saddr);
	return 0;
}	
	
	


	
	
	

