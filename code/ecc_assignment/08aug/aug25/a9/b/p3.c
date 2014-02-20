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
	printf("\nEnter the fifo created: ");
	scanf("%s",s);
	if(mkfifo(s,0777)==-1)
	{
		printf("\nFifo not created\n");
		exit(0);
	}
	fd1=open(s,O_RDONLY|O_NONBLOCK);
	fd2=open(s,O_WRONLY|O_NONBLOCK);
	printf("\nFD: %d",fd2);
	printf("\nEnter the text: ");
	scanf("%s",w);
	st=write(fd2,w,strlen(w));
	printf("Status: %d",st);
	sleep(1000);
	exit(0);
	return 0;
}


	
	


