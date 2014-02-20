/*	FileName	:	p3.c
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
	int fd1,fd2,st;	
	s=malloc(30);
	w=malloc(30);
	r=malloc(30);
	printf("\nEnter the fifo created: ");
	scanf("%s",s);
	mkfifo(s,0777);
	fd2=open(s,O_WRONLY|O_NONBLOCK);
	while(1)
	{
		printf("\nMe: ");
		scanf("%s",w);
		write(fd2,w,30);
		close(fd2);
		fd1=open(s,O_RDONLY);
		read(fd1,r,30);
		printf("\nOpposite: %s",r);
		close(fd1);
		fd2=open(s,O_WRONLY);
	}
	exit(0);
	return 0;
}


	
	


