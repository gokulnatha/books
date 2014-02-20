/*	Filename	:	doublelinkdelsearch.c
 *	Date		:	04-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to do deletion and searching on double linked list
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct node
 {
	struct node *l;
	int data;					// creation of double linked list
	struct node *r;
 }*first;

 void disp()
 {
	struct node *pa;
	int i;
	for(pa=first,i=0;pa!=NULL;pa=pa->r,i++)
	{
		printf("\nData of node %d: %d",i+1,pa->data);		//traverse the whole list and display elements on path
	}

 }

 void delatstart()
 {
	struct node *temp,*pa;
	pa=first;
	temp=pa->r;
	temp->l=NULL;						//deleting the first node of the list 
	free(pa);
	first=temp;	
 }

 void delatpos()
 {
	struct node *templ,*tempr,*pa;
	int pos,i;
	printf("\nEnter the position to get deleted: ");
	scanf("%d",&pos);
	for(pa=first,i=0;i<pos-1;pa=pa->r,i++);			//getting position and deleting that element by traversing from first to that position
	templ=pa->l;
	tempr=pa->r;
	templ->r=tempr;
	tempr->l=templ;
	free(pa);
 }

 void delatend()
 {
	struct node *temp,*pa;
	for(pa=first;pa->r!=NULL;pa=pa->r);		//deleting the end node of the list
	temp=pa->l;
	temp->r=NULL;
	free(pa);
 }

 void delbyval()
 {
	struct node *pa,*templ,*tempr;
	int val;
	printf("\nEnter the element to be deleted: ");
	scanf("%d",&val);
	for(pa=first;pa->data!=val;pa=pa->r);		//deleting the value that get from user by traversing from first till that value reached
	templ=pa->l;
	tempr=pa->r;
        templ->r=tempr;
	tempr->l=templ;
	free(pa);	
 }

 void searching()
 {
	struct node *pa;
	int i,val,c=0;
	printf("\nEnter the element to be searched: ");
	scanf("%d",&val);
	for(i=0,pa=first;pa!=NULL;pa=pa->r,i++)
	{
		if(pa->data==val)
		{
			c=2;
			break;				//searching for the value through traversal from first till that value reached
		}
	}
	if(c==2)
	{
		printf("\nFound at %d position",i+1);
	}
	else
	{
		printf("\nNot Found\n");
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
		temp=malloc(sizeof(struct node));		// getting no of nodes and elements as much
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
	do
	{
		printf("\n1.Deletion at start 2. Deletion at end 3. Deletion at position 4. Deletion by value 5. Searching\n");
		scanf("%d",&choice);
		if(choice==1)
			delatstart();
		else if(choice==2)
			delatend();
		else if(choice==3)
			delatpos();			//getting choice of operation and calling certain function
		else if(choice==4)
			delbyval();
		else if(choice==5)
			searching(); 
		disp();
		printf("\nPress 1 to continue.. : ");
		scanf("%d",&ch);
	}while(ch==1);
        printf("\n\n");		
	return;
 } 

