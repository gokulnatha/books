/*	FileName	:	p1.c
 *	Date		: 	25-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	To signal from one process to other 
 */

#include<stdio.h>
#include<signal.h>

int main(void)
{
	int pid;
	printf("\nEnter the process to be signalled: ");
	scanf("%d",&pid);
	kill(pid,2); 				
	return 0;
}
	

