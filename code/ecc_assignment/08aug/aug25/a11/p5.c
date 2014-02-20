/*	FileName	:	p4.c
 *	Date		: 	25-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	To remove fifo 
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<signal.h>

int main(void)
{
	char *s;
	s=malloc(30);
	printf("\nEnter the fifo to be assassinated: ");
	scanf("%s",s);
	unlink(s);
	return 0;		
}


	
	


