/*	Filename	:	doublelinkinssort.c
 *	Date		:	04-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to do insertion and sorting on double linked list
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct node
 {
	struct node *l;
	int data;				// creation of double linked list
	struct node *r;
 }*first;

 void disp(int n)
 {
	struct node *pa;
	int i;
	for(pa=first,i=0;pa->r!=NULL;pa=pa->r,i++)				//traverse from first to end and display elements on path
	{
		if(n!=2)
		printf("\nData of node %d: %d",i+1,pa->data);
	}
	printf("\nData of node %d: %d",i+1,pa->data);
	if(n==2)
	{
	while(i>=0)
	{
		printf("\ndata %d: %d",i+1,pa->data);
		pa=pa->l;
		i--;
	}
	}
	return;	
 }
	
 void insertatstart()
 {
	struct node *temp;
	temp=malloc(sizeof(struct node));
	printf("\nEnter the element to be inserted: ");		//to insert element at the beginning of the list
	scanf("%d",&temp->data);	
       	temp->l=NULL;	
	temp->r=first;
	first->l=temp;	
	first=temp;
 }

 void insertatpos()
 {
	struct node *temp,*pa;
	int pos,i;
	temp=malloc(sizeof(struct node));
	printf("\nEnter the position to get inserted: ");
	scanf("%d",&pos);
	printf("\nEnter the element to be inserted: ");		//getting position, traverse from first to that position and inserting a node
	scanf("%d",&temp->data);
	for(pa=first,i=0;i<pos-2;pa=pa->r,i++);
	temp->r=pa->r;
	temp->l=pa;
	pa->r->l=temp;
	pa->r=temp;
        	
 }

 void insertatend()
 {
	struct node *temp,*pa;
	temp=malloc(sizeof(struct node));
	printf("\nEnter the element to be inserted: ");		//to insert the element at end traverse from first to end of the list
	scanf("%d",&temp->data);
	for(pa=first;pa->r!=NULL;pa=pa->r);
	temp->r=NULL;
	pa->r=temp;
	temp->l=pa;
 }

 void sorting()
 {
	struct node *temp,*pa;
	int s,r,i;
	printf("\n1.Ascending sort 2.Descending sort \n");
	scanf("%d",&r);
	if(r==1)
	{
	for(pa=first;pa!=NULL;pa=pa->r)
	{
		for(temp=first;temp!=pa;temp=temp->r)
		{
			if(temp->data>pa->data)
			{
				s=temp->data;			//traverse and sort the elements as in ascending order
				temp->data=pa->data;
				pa->data=s;
			}
		}
	}
	}
	else
	{
		for(pa=first;pa!=NULL;pa=pa->r)
		{
			for(temp=first;temp!=pa;temp=temp->r)
			{
				if(temp->data<pa->data)
				{
					s=temp->data;
					temp->data=pa->data;
					pa->data=s;
				}
			}
		}
	}
 }
 
 int main(void)
 {
	struct node *temp,*pa;
	int i=0,n,choice,ch;
	printf("\nEnter no of nodes to be inserted: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		temp=malloc(sizeof(struct node));			//getting no of nodes and elements as much to store as double linked list
		printf("\nEnter data for node %d: ",i+1);
		scanf("%d",&temp->data);
		temp->r=NULL;
		if(!i)
		{
			first=temp;
			first->l=NULL;
			pa=first;
		}
		pa->r=temp;
		temp->l=pa;
		pa=temp;
	}
	disp(1);
	do
	{
		printf("\n1.Insertion at start 2. Insertion at position 3. Insertion at end 4. Sorting 5. Display in reverse\n");
		scanf("%d",&choice);
		if(choice==1)
			insertatstart();
		else if(choice==2)
			insertatpos();					//getting choice of opertion and calling certain function
		else if(choice==3)
			insertatend();
		else if(choice==4)
			sorting();
		else if(choice==5)
			disp(2);
		disp(1);
		printf("\nPress 1 to continue.. : ");
		scanf("%d",&ch);
	}while(ch==1);
        printf("\n\n");		
	return;
 } 

