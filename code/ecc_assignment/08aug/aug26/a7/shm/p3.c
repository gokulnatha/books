/*	FileName	:	p3.c
 *	Date		: 	26-08-2010
 *	Author		:	Stalin Srinivasan.S	
 *	Description	:	To create and attach shared memory with process and try to read and write from two processes
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(void)
{
	int rid,fd,status,key;
	char *saddr=0,*reply=0,*buf;
	buf=malloc(100);
	system("clear");
	printf("\nEnter the key: ");
	scanf("%d",&key);
	rid=shmget(key,0,IPC_CREAT);
	saddr=shmat(rid,NULL,0);
	reply=saddr+7;
	fd=open(saddr,O_RDWR);
	read(fd,buf,100);
	reply=reply+7;
	strcpy(reply,buf);
	return 0;
}	
	
	


	
	
	

