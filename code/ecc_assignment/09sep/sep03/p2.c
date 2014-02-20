/*	Filename	:	p1.c
 *	Date		:	03-09-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to achieve post man's work from mailing to delivery 
 */

 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include<fcntl.h>
 #include<unistd.h>
 #include<sys/types.h>
 #include<sys/ipc.h>

 struct mail
 {
	char txt[30];
	int tgt;
 }*aw,*ar; 

 int main(void)
 {
	int i,fd,nomsg;
	char filename[30];
	aw=malloc(sizeof(struct mail));
	ar=malloc(sizeof(struct mail));
	printf("\nEnter the no of mails to be posted: ");
	scanf("%d",&nomsg);
	for(i=0;i<nomsg;i++)
	{
		printf("\nSelect ur postbox...");
		printf("\nPress 1.South 2.North 3.West 4.East\n");
		scanf("%s",filename);
		fd=open(filename,O_WRONLY|O_APPEND|O_CREAT,0777);
		printf("\nEnter ur msg: ");
		scanf("%s",aw->txt);
		printf("\nSelect ur dest under our service: ");
		printf("\nPress 10.Chennai 20.Bengaluru 30.Mumbai 40.Kolkatta 50.Delhi\n");
		scanf("%d",&aw->tgt);
		write(fd,aw,sizeof(struct mail));
		close(fd);
	}
	/*fd=open(filename,O_RDONLY);
	while(read(fd,ar,sizeof(struct mail))>0)
	{
		printf("\nMsg: %s",ar->txt);
		printf("\nLoc: %d",ar->tgt);
	}*/
	return 0;
}
	
	


