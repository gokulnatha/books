/*	FileName	:	p1.c
 *	Date		: 	25-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	To read and write between related processes using pipe 
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>

int main(void)
{
	int result;
	result=mkfifo("myfifo1",0777);
	if(result==-1)
	{
		printf("\nFifo mission impossible\n");
		exit(0);
	}
	return 0;
}


	
	


