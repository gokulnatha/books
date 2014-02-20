/*	Filename	:	clinkinsertsort.c
 *	Date		:	04-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to demonstrate about the circular linked list insertion
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct node
 {
	int data;
	struct node *next;
 }*first;

 void disp()
 {
	struct node *temp;
	int i,c=0;							// traverse from first to last and display content of nodes on path
	printf("\nList of node elements:\n");
	for(temp=first,i=0;temp->next!=first;temp=temp->next,i++)
	{
		printf("\nData of node %d: %d",i+1,temp->data);
	}
	printf("\nData of node %d: %d",i+1,temp->data); 
	printf("\n\n");
	return;
 }

 void insertstart()
 {
	struct node *temp;
	temp=malloc(sizeof(struct node));
	printf("\nEnter the elements to be inserted: ");		//inserting node at start of list
	scanf("%d",&temp->data);
	temp->next=first->next;
	first->next=temp;
	first=temp;
	return;
 }

 void insertend()
 {
	struct node *temp,*pa;
	for(pa=first;pa->next!=first;pa=pa->next);			//inserting node at end of the list
	temp=malloc(sizeof(struct node));
	printf("\nEnter the element to be inserted: ");
	scanf("%d",&temp->data);
	temp->next=first;
	pa->next=temp;
	return;
 }

 void insertatpos()
 {
	struct node *temp,*pa;
	int pos,i=0;
	pa=first;
	printf("\nEnter the position get inserted: ");			// getting the position and traverse from first to that and inserting node
	scanf("%d",&pos); 
	pa=first;
	for(i=0;i<pos-2;i++)
	{
		pa=pa->next;
	}
	temp=malloc(sizeof(struct node));
        printf("\nEnter the data to be inserted: ");
	scanf("%d",&temp->data);
	temp->next=pa->next;
	pa->next=temp;	
 	return;
 }

 void sorting()
 {
	struct node *temp,*pa;
	int i,j,s;
        for(pa=first;pa->next!=first;pa=pa->next)
	{
		for(temp=first;temp!=pa;temp=temp->next)		//sorting the elements as per ascending order
		{
			if(temp->data>pa->data)
			{
				s=temp->data;
				temp->data=pa->data;
				pa->data=s;
			}
		}
	}
	for(temp=first;temp->next!=first;temp=temp->next)
	{
		if(temp->data>pa->data)
		{
			s=temp->data;
			temp->data=pa->data;
			pa->data=s;
		}
	}
	return;
 }

 int main(void)
 {
	struct node *temp,*prev;
	int i,n,choice,ch;
	first=malloc(sizeof(struct node));	
	printf("\nEnter the no of nodes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		temp=malloc(sizeof(struct node));
		printf("\nEnter the data for node %d:",i+1);		// getting no of nodes and elements as much	
		scanf("%d",&temp->data);
		temp->next=NULL;
		if(!i)
		{
			first=temp;
			prev=first;
		}
		prev->next=temp;
	        prev=temp;
		prev->next=first;
	}
	disp();
	do
	{
	printf("\n1.Insertion at start 2.Insertion at end 3.Insertion at position 4.Sorting\n"); 
	scanf("%d",&choice);
	if(choice==1)
		insertstart();						// getting choice of operation and calling certain function
	else if(choice==2)
		insertend();
	else if(choice==3)
		insertatpos();
	else if(choice==4)
		sorting();
	disp();
	printf("\nPress 1 to continue.. : ");
	scanf("%d",&ch);
	}while(ch==1);
	printf("\n\n");
	return 0;
 }
