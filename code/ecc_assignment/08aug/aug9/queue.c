/*	Filename	:	queue.c
 *	Date		:	09-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to implement the queue 
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct node
 {
	int data;
	struct node *next;
 }*rear,*front,*bfront;
 
 void inq(int e)
 {
	struct node *temp;
	temp=malloc(sizeof(struct node));
	temp->data=e;
	temp->next=rear;
	rear=temp;
	for(temp=rear;temp->next!=NULL;temp=temp->next);
	front=temp;
	return;
 }
	
 void disp()
 {
	struct node *temp;
	for(temp=rear;temp!=NULL;temp=temp->next)
		printf("\nData: %d",temp->data);
	printf("\n\n");
 }
	
 void delq()
 {
	struct node *temp;
	for(temp=rear;temp->next!=front;temp=temp->next);
	bfront=temp;	
	temp=front;
	front=bfront;
	front->next=NULL;
	free(temp);
 }
	

 int main(void)
 {
	int i=0,e;
	struct node *temp;
	printf("\nqueue size: 10");
	for(i=0;i<6;i++)
	{
		printf("\nEnter the element to be queued: ");
		scanf("%d",&e);
		inq(e);
	}
	printf("\nQueue is full now\n");
	while(rear!=front)
	{
		delq();
		disp();
	}
	free(rear);
	printf("\nQueue is empty now\n");
	return 0;
 }

	
	
	
	
	
	
		
	
