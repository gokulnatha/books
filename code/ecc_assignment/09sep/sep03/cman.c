/*	Filename	:	cmant.c
 *	Date		:	03-09-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to achieve post man's work from mailing to delivery 
 */

 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include<fcntl.h>
 #include<unistd.h>
 #include<signal.h>
 #include<sys/types.h>
 #include<sys/ipc.h>
 #include<sys/msg.h>
 #include<pthread.h>

 struct mail
 {
	char txt[30];
	int tgt;
 }*ar,*aw;
	 

 void* clearmail()
 {
	int i,fd,key,msgrid,flag=0;
 	char filename[4][2]={"1","2","3","4"};	
 	ar=malloc(sizeof(struct mail));
 	aw=malloc(sizeof(struct mail));
	for(i=0;i<4;i++)
	{
		key=ftok(".",i);
		//printf("\nKey value: %d",key);
		msgrid=msgget(key,IPC_CREAT|0777);
		fd=open(filename[i],O_RDONLY);
		while(read(fd,ar,sizeof(struct mail))>0)
		{
			//printf("\nMsg: %s",ar->txt);
		//	printf("\nDest: %d",ar->tgt);
			msgsnd(msgrid,ar,sizeof(struct mail),0);
			flag++;
		}
		if(flag==0)
		{
			printf("\nThere is no mail in the box: %d\n",i);
		}
		else
		{
			fd=open(filename[i],O_WRONLY|O_TRUNC);
			close(fd);
		}
	}
 }

 void sighandler(int signo)
 {
	pthread_t th1;
	alarm(15);
	printf("\nI got the call..\n"); 		
	pthread_create(&th1,NULL,clearmail,NULL);
	pthread_join(th1,NULL);
 }

 int main(void)
 {
	void(*handler)(int);
	handler=sighandler;
	alarm(15);
	signal(SIGALRM,handler);
	while(1)
	{
		printf("\nI am Clearing guy and now i am in home...\n");
		sleep(3);
	}
 }
	
				
	
	


