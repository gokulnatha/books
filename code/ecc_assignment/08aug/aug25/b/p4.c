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
	r=malloc(30);
	printf("\nEnter fifo to be used: ");
	scanf("%s",s);
	fd1=open(s,O_RDONLY|O_NONBLOCK);
	while(1)
	{
		read(fd1,r,30);
		close(fd1);
		printf("\nOpposite: %s",r);
		fd2=open(s,O_WRONLY);
		printf("\nMe: ");
		scanf("%s",w);
		write(fd2,w,strlen(w));
		close(fd2);	
		fd1=open(s,O_RDONLY);
	}
	exit(0);
	return 0;
}


	
	


