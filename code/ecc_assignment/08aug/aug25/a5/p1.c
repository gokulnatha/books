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
	int fd[2];
	char *w="hello",*r;
	r=malloc(10);
	if(pipe(fd))
	{
		printf("\nPipe is not created\n");
		exit(0);
	}
	if(fork())
	{
		printf("\nI am parent and now i am writing hello\n");
		close(fd[0]);
		write(fd[1],w,strlen(w));	
		exit(0);
	}
	close(fd[1]);
	read(fd[0],r,strlen(w));
	printf("\nMy parent says %s to me\n",r);
	exit(0);
	return 0;
}


	
	


