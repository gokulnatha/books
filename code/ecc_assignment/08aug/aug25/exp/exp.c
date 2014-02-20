/*	FileName	:	p1.c
 *	Date		: 	25-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	To read and write between related processes using pipe 
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<signal.h>

int main(void)
{
	char *s,*w,*r,*fr;
	int fd1,fd2,file,a,b,c;	
	s=malloc(30);
	w=malloc(30);
	r=malloc(30);
	fr=malloc(30);
	printf("\nEnter the fifo created: ");
	scanf("%s",s);
	if(mkfifo(s,0777)==-1)
	{
		printf("\nFifo not created\n");
		exit(0);
	}
	fd1=open(s,O_RDONLY|O_NONBLOCK);
	fd2=open(s,O_WRONLY|O_NONBLOCK);
	printf("\nEnter the filename: ");
	scanf("%s",w);
	write(fd2,w,strlen(w));
	if(fork())
	{	
		wait();
		exit(0);
	}
	read(fd1,r,strlen(w));
	printf("\nFilename: %s",r);
	file=open(r,O_RDWR);
	read(file,fr,30);
	printf("Read content: %s",fr);	
	return 0;
}


	
	


