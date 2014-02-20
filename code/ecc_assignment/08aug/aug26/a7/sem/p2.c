/*	FileName	:	p2.c
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
#include<sys/sem.h>

int main(void)
{
	int semkey,shmkey,shmrid,semrid,status,status1;
	char *saddr=0,reply[100];
	printf("\nEnter the shared memory key: ");
	scanf("%d",&shmkey);
	shmrid=shmget(shmkey,100,IPC_CREAT);
	printf("\nShm_rid: %d",shmrid);
	printf("\nEnter the semaphore key: ");
	scanf("%d",&semkey);
	semrid=semget(semkey,1,IPC_CREAT);
	printf("\nSem_rid: %d",semrid);
	saddr=(char*)shmat(shmrid,NULL,0);
	system(saddr);						/* executing cmd in that shared mry area */
	while(1)
	{
		if(semctl(semrid,0,GETVAL,0)==1)		/* testing the value of semaphore */
		{
			printf("\nEnter the reply msg: ");
			scanf("%s",reply);
			strcpy(saddr,reply);
			exit(0);
		}
	}
	return 0;
}	
	
	


	
	
	

