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
#include<signal.h>
#include<pthread.h>

int msgrid,generalcounter=0;

void(*handler1)(int);
void(*handler2)(int);

pthread_t th1,th2;

struct mymsg
{
	int type;
	char name[30];
}*a1,*a2;

void* token()
{
	int status;
	if(generalcounter<=5)
	{
		printf("\nPatient has come...\n");
		printf("\nEnter name of patient: ");
		scanf("%s",a1->name);
		printf("\nEnter token of him/her(>0): ");
		scanf("%d",&a1->type);
		status=msgsnd(msgrid,a1,sizeof(struct mymsg),0);
		generalcounter++;
	}
	else
	{
		printf("\nDoctor is Busy..Come tomorrow..\n");
	}
}
	
void* fees()
{
	int status;
	if(generalcounter>0)
	{
		printf("\nPatient got consultance ...\n");
		status=msgrcv(msgrid,a2,sizeof(struct mymsg),0,0);
		generalcounter--;
		printf("\nName of patient: %s",a2->name);
		printf("\nToken Of him: %d",a2->type);
	}
	else
	{
		printf("\nDoctor is free..Come even you have no disease..\n");
	} 
}


void sighandler1(int signo)
{
	pthread_create(&th1,NULL,token,NULL);
	pthread_join(th1,NULL); 
}

void sighandler2(int signo)
{
	pthread_create(&th2,NULL,fees,NULL);
	pthread_join(th2,NULL); 
}

int main(void)
{
	int msgkey;
	a1=malloc(sizeof(struct mymsg));
	a2=malloc(sizeof(struct mymsg));
	printf("\nEnter the key: ");
	scanf("%d",&msgkey);
	system("clear");
	msgrid=msgget(msgkey,IPC_CREAT|0777); 
	handler1=sighandler1;
	handler2=sighandler2;
	signal(SIGUSR1,handler1);
	signal(SIGUSR2,handler2);
	while(1)
	{
		printf("\n\n----------------------------------------\n");
		printf("\n  *** Stalin Hospitals Welcomes You ***   \n");
		printf("\n------------------------------------------\n\n");
		sleep(5);
	}
}
	


	

	
	

	
	
	
	


	
	
	

