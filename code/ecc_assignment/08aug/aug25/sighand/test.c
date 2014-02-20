/*	FileName	:	test.c
 *	Date		: 	25-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	To signal from one process to other 
 */

#include<stdio.h>
#include<signal.h>

void hdlr(int signo)
{
	printf("\nI am being quiting .. bye... \n");
}

int main(void)
{
	void(*pthdlr)(int);
	pthdlr=hdlr;
	signal(2,pthdlr);
	sleep(1000);
}
	


