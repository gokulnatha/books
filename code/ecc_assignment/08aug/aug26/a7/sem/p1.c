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
#include<sys/sem.h>

union semun
{
	int val;
	struct semid_ds *buf;
	ushort *array;
}i;

int main(void)
{
	int shmrid,semrid,shmkey,semkey,status,status2;
	char *saddr=0;
	i.val=0;
	printf("\nEnter the key for shm: ");	
        scanf("%d",&shmkey);	
	shmrid=shmget(shmkey,200,IPC_CREAT|0777);
	printf("\nshm_rid: %d",shmrid);
	printf("\nEnter the key for sem: ");	
        scanf("%d",&semkey);	
	semrid=semget(semkey,1,IPC_CREAT|0777);		/* getting key value to semaphore set */ 
	printf("\nsem_rid: %d",semrid);
	saddr=shmat(shmrid,NULL,0);
	printf("\nEnter the command: ");
	scanf("%s",saddr);
	semctl(semrid,0,SETVAL,i);			/* setting value for the semaphore */
	return 0;
}	
	
	


	
	
	

