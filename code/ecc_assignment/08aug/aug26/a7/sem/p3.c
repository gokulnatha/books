/*	FileName	:	p3.c
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

struct sembuf bufunl={0,+1,1};
struct sembuf bufl={0,-1,1};

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
	system(saddr);
	semop(semrid,&bufunl,1);			/* releasing semaphore by unlocking */
	return 0;
}	
	
	


	
	
	

