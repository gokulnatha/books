/*	Filename	:	pman.c
 *	Date		:	03-09-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to achieve post man's work from mailing to delivery 
 */

 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include<fcntl.h>
 #include<unistd.h>
 #include<pthread.h>
 #include<signal.h>
 #include<sys/types.h>
 #include<sys/ipc.h>
 #include<sys/msg.h>

 struct mail
 {
	char txt[30];
	int tgt;
 }*ar,*aw;

 void* postmail()
 {
	int i,fd,key,msgrid,a,flag=0;
	char filename[30];
	ar=malloc(sizeof(struct mail));
	aw=malloc(sizeof(struct mail));
	for(i=0;i<4;i++)
	{
		key=ftok(".",i);
		//printf("\nKey value: %d",key);
		msgrid=msgget(key,IPC_CREAT|0777);
		while(msgrcv(msgrid,aw,sizeof(struct mail),0,IPC_NOWAIT)!=-1)
		{
		//	printf("\nReceive status: %d",a);
			if(aw->tgt==10)
			{
				strcpy(filename,"chennai");
			}
			else if(aw->tgt==20)
			{
				strcpy(filename,"bengaluru");
			}
			else if(aw->tgt==30)
			{
				strcpy(filename,"mumbai");
			}
			else if(aw->tgt==40)
			{
				strcpy(filename,"kolkatta");
			}
			else if(aw->tgt==50)
			{
				strcpy(filename,"delhi");
			}
			fd=open(filename,O_APPEND|O_WRONLY|O_CREAT,0777);
			write(fd,aw,sizeof(struct mail));
		}
		flag++;
	}
	if(flag==0)
	{
		printf("\nNo mails in the postbox\n");
	}	
}

void sighandler(int signo)
{
	pthread_t th1;
	alarm(20);	
	printf("\nI got the call...\n");
	pthread_create(&th1,NULL,postmail,NULL);
	pthread_join(th1,NULL);
}

int main(void)
{
	void(*handler)(int);
	handler=sighandler;
	alarm(20);
	signal(SIGALRM,handler);
	while(1)
	{
		printf("\nI am Post man and now i am in home...\n");
		sleep(3);
	}
}		
	
				
	
	


