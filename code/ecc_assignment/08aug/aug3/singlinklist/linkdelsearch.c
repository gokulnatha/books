/*	Filename	:	linkdelsearch.c
 *	Date		:	03-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to demonstrate about the linked list deletion
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct node
 {
	int data;
	struct node *next;
 }*first;

 int n;

 void disp()
 {									//traversing from first to last and display elements on path
	int i=0;
	struct node *temp;
	printf("\nList of node elements: ");
	for(temp=first,i=0;temp!=NULL;temp=temp->next,i++)
	{
		printf("\nData of node %d: %d",i+1,temp->data);
	}
	printf("\n\n");
	return;
 }

 void delstart()
 {
	struct node *temp;
	temp=first;
	first=first->next;						//deleting the first node of the list
	free(temp);
	return;
 }

 void delend()
 {
	struct node *temp,*pa;
	pa=first;
	for(pa=first;pa->next->next!=NULL;pa=pa->next);			//deleting the end node of the list
	pa->next=NULL;
        free(pa->next);	
	return;
 }

 void delatpos()
 {
	struct node *temp,*pa;
	int pos,i=0;
	pa=first;
	do
	{
	printf("\nEnter the position get deleted: ");
	scanf("%d",&pos); 
	if(n<pos)
	{
		printf("\nUr given position exceeds node exists.\n"); 		//getting position and traverse to that for deletion
	        pos=1;	
	}
	}while(pos==1);
	for(i=0;i<pos-2;i++)
	{
		pa=pa->next;
	}
	temp=pa->next;
        pa->next=temp->next;		
	free(temp);
 	return;
 }

 void delbyval()
 {
	struct node *temp,*pa;
	int i=0,val,c=0;
	printf("\nEnter the value be deleted: ");
	scanf("%d",&val);
	for(pa=first;pa->next!=NULL;pa=pa->next)			//getting value to be deleted and traverse to it for deletion
	{
		if(pa->data==val)
		{
			c=2;
			break;
		}
		temp=pa;	
	}
	if(c==2)
	{
		temp->next=pa->next;
		free(pa);
	}
	else
	{
		printf("\nNot found");
	}
	return;
 }

 void search()
 {
	struct node *temp;
	int i,val,c=0;
	printf("\nEnter the value to be searched: ");
	scanf("%d",&val);
	for(temp=first,i=0;temp!=NULL;temp=temp->next,i++)		//search particular element as per previous function defn and display result
	{
		if(temp->data==val)
		{
			c=2;
			break;
		}
	}
	if(c==2)
	{
		printf("\nFound at %d position\n",i);
	}
	else
	{
		printf("\nNot Found\n");
	}
	return;
 } 

 int main(void)
 {
	struct node *temp,*prev;
	int i,choice,ch;
	first=malloc(sizeof(struct node));	
	printf("\nEnter the no of nodes: ");
	scanf("%d",&n);							//getting no of nodes and elements as much	
	for(i=0;i<n;i++)
	{
		temp=malloc(sizeof(struct node));
		printf("\nEnter the data for node %d:",i+1);
		scanf("%d",&temp->data);
		temp->next=NULL;
		if(!i)
		{
			first=temp;
			prev=first;
		}
		prev->next=temp;
	        prev=temp;
	}
	disp();
	do
	{
	printf("\n1.Deletion at start 2.Deletion at end 3.Deletion at position 4.Deletion by value 5.Searching\n"); 
	scanf("%d",&choice);
	if(choice==1)
		delstart();
	else if(choice==2)
		delend();
	else if(choice==3)					// getting choice of operation and calling certain function
		delatpos();
	else if(choice==4)
		delbyval();
	else if(choice==5)
		search();
	disp();
	printf("\nPress 1 to continue.. : ");
	scanf("%d",&ch);
	}while(ch==1);
	printf("\n\n");
	return 0;
 }
