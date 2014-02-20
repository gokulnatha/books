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
	kill(pid,SIGKILL); 					/* getting pid and sending signal to kill(signal) that process started by super user */
	return 0;
}

/*analysis:
	we have to be a super user to kill the process started by super user else that process wont be killed.*/
	


