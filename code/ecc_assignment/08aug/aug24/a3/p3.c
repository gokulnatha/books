/*	FileName	:	p3.c
 *	Date		:	24-08-2010
 *	Author		: 	Stalin Srinivasan.S
 *	Description	:	to get clear about execl() when it called by process which is overwritten by its own address space
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
				execl("a.out",NULL,NULL); /*making exec parent itself end in infinite execution since it creating replica and going on spawning childs...*/
				printf("\nP\n");          /* this line wont get executed since execl() used to replace parent address space... */
			}
		}
	}
	printf("\nC\n");	
}
				
