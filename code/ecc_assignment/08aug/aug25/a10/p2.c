/*	FileName	:	p1.c
 *	Date		: 	25-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	all client writes to server through common fifo	
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<signal.h>
	
int main(void)
{
	int i,j,fd[20][2],n;	
	char *s,*w[20],*r[20];
	s=malloc(30);
	for(i=0;i<20;i++)
	{
		w[i]=malloc(30);
		r[i]=malloc(30);
	}
	printf("\nEnter the clients to be dealt ( max 20 ): ");
	scanf("%d",&n);
	printf("\nEnter the server fifo name: ");
	scanf("%s",s);
	mkfifo(s,0777);
	fd[0][0]=open(s,O_RDONLY|O_NONBLOCK);
	fd[0][1]=open(s,O_WRONLY|O_NONBLOCK);
	for(i=0;i<n;i++)
	{
		if(fork()==0)
		{
			printf("\nChild %d: I am writing to parent\n",i+1);
			printf("\nGive some msg: ");
			scanf("%s",w[i]);
			write(fd[0][1],w[i],strlen(w[i]));
			exit(0);
		}
		else
		{
			wait();
			read(fd[0][0],r[i],30);
		}
	}
	printf("\nParent\n");
	for(i=0;i<n;i++)
	{
		printf("\nFrom Client %d: %s\n",i,r[i]);
	}
	exit(0);
	return 0;
}



	
	


