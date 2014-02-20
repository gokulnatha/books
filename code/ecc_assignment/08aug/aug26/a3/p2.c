/*	FileName	:	p2.c
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
	int i,n,rid,b,r;
	key_t key=200;
	buf=malloc(sizeof(struct msg));
	rid=msgget(key,IPC_CREAT|0777);
	system("clear");
	printf("\nEnter no of msgs to be received: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter type value to be received: \n");
		scanf("%ld",&buf->type);
		msgrcv(rid,buf,30,buf->type,0);
		printf("\nthe received message: %s",buf->text);
	}
	return 0;
}
	
	
	
	
	

