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
	int fd1[2],fd2[2],file;
	char *w="src.txt",*r,*cw,*cr;
	r=malloc(10);
	cr=malloc(30);
	cw=malloc(30);
	pipe(fd1);
	pipe(fd2);
	if(fork())
	{
		close(fd1[0]);
		write(fd1[1],w,strlen(w));
		wait();	
		close(fd2[1]);
		read(fd2[0],cr,30);
		printf("\nParent content: %s",cr);
		exit(0);
	}
	close(fd1[1]);
	read(fd1[0],r,strlen(w));
	file=open(r,O_RDONLY);
	read(file,cw,30);
	printf("\nChild Content: %s",cw);
	close(fd2[0]);
	write(fd2[1],cw,strlen(cw));
	exit(0);
}

	
	


