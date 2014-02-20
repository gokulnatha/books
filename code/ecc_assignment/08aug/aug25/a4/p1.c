/*	FileName	:	p1.c
 *	Date		: 	25-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	To observe pipe 
 */

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int main(void)
{
	int fd[2],fd1[2];
	if(pipe(fd))						// creating pipe
	{
		printf("\nFailed Pipe creation\n");
		exit(0);
	}
	printf("\nPipe Created Successfully\n");
	printf("\nI am Parent\n");
	printf("\nReading File Descriptor: %d\n",fd[0]);	// file descriptor for reading
	printf("\nWriting File Descriptor: %d\n",fd[1]);	// file descriptor for writing
	if(fork())
	{
		exit(0);
	}
	printf("\nI am Child\n");
	printf("\nReading File Descriptor: %d\n",fd[0]);	// since opened files are inherited from parent to child 
	printf("\nWriting File Descriptor: %d\n",fd[1]);
	exit(0);
	return 0;
}


	
	


