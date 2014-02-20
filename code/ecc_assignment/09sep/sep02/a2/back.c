/*	FileName	:	p1.c
 *	Date		: 	02-09-2010
 *	Author		:	Stalin Srinivasan.S	
 *	Description	:	To	
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<pthread.h>

int msgrid,i,n;

struct mymsg
{
	int type;
	char name[30];
}*a1,*a2;

void* token()
{
	int ret,status;
	printf("\nEnter name of patient: ");
	scanf("%s",a1->name);
	printf("\nHis/her token no alloted is %d",i);
	a1->type=i;
	status=msgsnd(msgrid,a1,sizeof(struct mymsg),0);
	printf("\nStatus: %d",status);
}
	
void* fees()
{
	msgrcv(msgrid,a2,sizeof(struct mymsg),i,0);
	printf("\nName of patient: %s",a2->name);
	printf("\nHis/Her token no: %d",a2->type);
}

int main(void)
{
	pthread_t th1,th2;
	int choice,msgkey;
	a1=malloc(sizeof(struct mymsg));
	a2=malloc(sizeof(struct mymsg));
	printf("\nEnter the key: ");
	scanf("%d",&msgkey);
	msgrid=msgget(msgkey,IPC_CREAT|0777);
	printf("\nEnter no of patients: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		pthread_create(&th1,NULL,token,NULL);
		pthread_join(th1,NULL);
	}
	for(i=1;i<=n;i++)
	{
		pthread_create(&th2,NULL,fees,NULL);
		pthread_join(th2,NULL);
	}
}
	


	

	
	

	
	
	
	


	
	
	

