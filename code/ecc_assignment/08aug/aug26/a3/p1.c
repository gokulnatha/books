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
}*buf;

int main(void)
{
	int i,n,rid,b;
	key_t key=200;
	buf=malloc(sizeof(struct msg));
	rid=msgget(key,IPC_CREAT|0777);
	system("clear");
	printf("\nEnter no of msgs to be sent: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter type value for this msg : \n");
		scanf("%ld",&buf->type);
		printf("Enter the message to be sent: \n");
		scanf("%s",buf->text);
		msgsnd(rid,buf,30,0);
	}
	sleep(1000);
	return 0;
}
	
	
	
	
	

