/*	FileName	: p3c.c
 *	Date		: 24-08-2010
 *	Author		: Stalin Srinivasan.S
 *	Description	: To get into parent and child relationship in case of child termination
 */	
	
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	if(fork())
	{
		if(fork())
		{
			if(fork())
			{
				wait();
				printf("Boss.. I have catched. How is it?\n");	/*this line executed when one of his child exits.. */ 
				exit(0);
			}
		}
	}
	printf("\n I am child and now i exits");   /* this line executed thrice since 3 childs.. But wont by parent process */
	exit(0);
}
				
