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
 }*top;
 
 void push(int e)
 {
	struct node *temp;
	temp=malloc(sizeof(struct node));
	temp->data=e;
	temp->next=top;
	top=temp;
 }
	
 void pop() 
 {
	struct node *temp;
	printf("\nElement which is popped out: %d",top->data);
	temp=top;
	top=top->next;
	free(temp);
	return;
 }

 void disp()
 {
	struct node *temp;
	for(temp=top;temp!=NULL;temp=temp->next)
		printf("\nData: %d",temp->data);
	return;
 }	
	

 int main(void)
 {
	int i,n,e;
	top=malloc(sizeof(struct node));
	top=NULL;
	printf("\nEnter the stack size: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the element to be pushed: ");
		scanf("%d",&e);
		push(e);
	}
	printf("\nNow the stack is full\n");
	for(i=0;i<n;i++)
	{
		pop();
		disp();
	}
	if(top==NULL)
		printf("\nStack is empty\n");
	printf("\n\n");
	return 0;
 }

	
	
	
	
	
	
		
	
