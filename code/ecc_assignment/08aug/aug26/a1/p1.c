/*	FileName	:	p1.c
 *	Date		: 	26-08-2010
 *	Author		:	Stalin Srinivasan.S	
 *	Description	:	To create a simple message queue with two messages 
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
	printf("\nEnter the key value(only +ve):");		/* getting key value ( +ve )	*/
	scanf("%d",&key);
	rid=msgget(key,IPC_CREAT|0777);
	system("clear");
	for(i=0;i<2;i++)
	{
		printf("Enter any message to be sent\n");
		scanf("%s",bufs->text);
		printf("\nEnter type value to be set: \n");
		scanf("%ld",&bufs->type);
		msgsnd(rid,bufs,30,0);				/* sending msg using resource identifier */
	}
	printf("\nEnter type value to be received: ");
	scanf("%ld",&bufr->type);
	msgrcv(rid,bufr,30,bufr->type,MSG_NOERROR);		/* receiving msg using resource identifier ( that same msg queue ) */
	printf("the received message is %s\n",bufr->text);
	return 0;
}
	
	
	
	
	

