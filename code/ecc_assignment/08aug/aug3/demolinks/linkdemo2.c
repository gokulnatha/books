/*	Filename	:	linkdemo2.c
 *	Date		:	03-07-2010
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
	int i,n;	
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
		exit(0);
	}	
	printf("\n\n");
	return 0;
 }
