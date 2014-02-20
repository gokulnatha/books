/*	FileName	:	p1.c
 *	Date		: 	25-08-2010
 *	Author		:	Stalin Srinivasan.S	
 *	Description	:	To kill other process 
 */

#include<stdio.h>
#include<signal.h>

int main(void)
{
	int pid;
	printf("\nEnter the process to be signalled: ");
	scanf("%d",&pid);
	kill(pid,SIGKILL); 					/* getting pid and sending signal to kill(signal) that process from here as normal both */
	return 0;
}

/* Analysis:
		we can kill the process started by normal user by being a normal user....*/
	


