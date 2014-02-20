/*	Filename	:	linkdemo3.c
 *	Date		:	03-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to demonstrate about the linked list 
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct node
 {
	int data;
	struct node *next;
 };

 int main(void)
 {
        typedef struct node N;
	N *first,*temp,*prev;
	int i,n,c=0,e;	
	printf("\nEnter the no of nodes: ");
	scanf("%d",&n);
	if(n>1)
	{
	first=malloc(sizeof(N));
	printf("\nEnter the data for node 1: ");
	scanf("%d",&first->data);
	first->next=NULL;
	prev=first;
	for(i=1;i<n;i++)
	{
		temp=malloc(sizeof(N));
		printf("\nEnter the data for node %d:",i+1);
		scanf("%d",&temp->data);
		temp->next=NULL;
		prev->next=temp;
	        prev=temp;
	}
	printf("\nList of node elements: ");
	temp=first;
	for(i=0;i<n;i++)
	{
		printf("\nData of node %d: %d",i,temp->data);
		temp=temp->next;
	}
	}
	else
	{
		printf("\n... enter valid number ...");
		exit(0);
	}
	printf("\nEnter the element to be traversed: ");
	scanf("%d",&e);	
	temp=first;
        while(temp->next!=NULL)
	{
		if(temp->data==e)
		{
			c=1;
			break;
		}
		temp=temp->next;
	}
	if(c==1)
	{
		printf("\nYour element has been found");
	}
	else
	{	
		printf("\nNot found\n");
	}
	printf("\n\n");
	return 0;
 }
