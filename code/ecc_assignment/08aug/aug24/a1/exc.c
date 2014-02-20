/*	FileName	:	exc.c
 *	Date		: 	24-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	To get clear picture about execl() system call
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int a,b,c;
	if(fork()==0)
	{
		execl("m",NULL,NULL);			// 	after execl() following instruction of the process wont get executed
		printf("\nEnter 2 nos: ");		//	since	its addressspace is overwritten by user specifiedprocess
		scanf("%d\t%d",&a,&b);
		c=a+b;
		printf("\nResult: %d",c);
		exit(0);
	}
	wait();
	exit(0);
	return 0;
}


