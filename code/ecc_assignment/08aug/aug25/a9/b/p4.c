/*	FileName	:	p4.c
 *	Date		: 	25-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	To read and write between unrelated processes using pipe 
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<signal.h>

int main(void)
{
	char *s,*w,*r,*fr;
	int fd1,fd2;	
	s=malloc(30);
	w=malloc(30);
	printf("\nEnter fifo to be used: ");
	scanf("%s",s);
	fd1=open(s,O_RDONLY|O_NONBLOCK);
	while(1)
	{
		read(fd1,w,30);
		printf("\nFile Content: %s",w); 
	}
	exit(0);
	return 0;
}


	
	


