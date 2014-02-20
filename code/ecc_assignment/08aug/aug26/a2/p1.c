/*	FileName	:	p1.c
 *	Date		: 	26-08-2010
 *	Author		:	Stalin Srinivasan.S	
 *	Description	:	To create a simple message queue with same type value 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg
{
	long int type;
        char text[30];
}*bufs,*bufr;

int main(void)
{
	int i,n,rid,b,sos,sor;
	key_t key;
	bufs=malloc(sizeof(struct msg));
	bufr=malloc(sizeof(struct msg));
	printf("\nEnter the key value(only +ve):");	
	scanf("%d",&key);
	rid=msgget(key,IPC_CREAT|0777);
	system("clear");
	printf("\nEnter your Default type value: \n");			/* getting type value which is to be used for all messages */
	scanf("%ld",&bufs->type);
	printf("\nEnter no of msgs to be sent: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter any message to be sent\n");
		scanf("%s",bufs->text);
		sos=msgsnd(rid,bufs,30,0);
	}
	if(fork()==0)
	{
		printf("\nEnter no of msgs to be received: ");
		scanf("%d",&n);
		printf("\nEnter type value to be received: ");
		scanf("%ld",&bufr->type);
		for(i=0;i<n;i++)
		{
			sor=msgrcv(rid,bufr,30,bufr->type,MSG_NOERROR);
			printf("the received message is %s\n",bufr->text);
		}	
		exit(0);
	}
	else
	{
		wait();	
	}	
	return 0;
}
	
	
	
	
	

