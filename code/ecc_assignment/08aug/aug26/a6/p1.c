/*	FileName	:	p1.c
 *	Date		: 	26-08-2010
 *	Author		:	Stalin Srinivasan.S	
 *	Description	:	To create and attach shared memory with process
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
	
int main(void)
{
	int rid,*addr;
	key_t key;
	system("clear");
	printf("\nEnter the key value: ");
	scanf("%d",&key);
	rid=shmget(key,100,IPC_CREAT);
	printf("\nResource Identifier: %d",rid);
	addr=shmat(rid,NULL,0);
	printf("\nStarting address of shared memory attached: %p",addr);
	return 0;
}	
	
	
	

	
	
	
	
	

