/*	FileName	:	p1.c
 *	Date		: 	25-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	server writing a msg to client through seperate fifo and read by the corresponding clients
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<signal.h>
	
int main(void)
{
	int i,j,fd[20][2],n;	
	char *s,*w,*r;
	s=malloc(30);
	w=malloc(30);
	r=malloc(30);
	printf("\nEnter the clients to be dealt ( max 20 ): ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the fifo name: ");
		scanf("%s",s);	
		mkfifo(s,0777);
		fd[i][0]=open(s,O_RDONLY|O_NONBLOCK);
		fd[i][1]=open(s,O_WRONLY|O_NONBLOCK);
		printf("\nEnter the string to be sent: ");
		scanf("%s",w);
		write(fd[i][1],w,strlen(w));
	}
	for(i=0;i<n;i++)
	{
		if(fork()==0)
		{
			read(fd[i][0],r,30);
			printf("\nRead content: %s",r);
			exit(0);
		}
		else
		{
			wait();
		}
	}
	return 0;
}



	
	


