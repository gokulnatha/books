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
	kill(pid,SIGQUIT); 					/* getting pid and sending signal to quit(signal) that process from here */
	return 0;
}
	

/*Analysis:
		using kill() we can quit the process (SIGQUIT) by passing signal from here to the specified process*/

