/*	Filename	:	dblinkdemo2.c
 *	Date		:	04-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to demonstrate about double linked list
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct node
 {
	struct node *l;
	int data;
	struct node *r;
 }*first;
 
 int main(void)
 {
	struct node *temp,*pa;
	int i=0,n;
	printf("\nEnter no of nodes to be inserted: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		temp=malloc(sizeof(struct node));
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
	for(pa=first,i=0;pa!=NULL;pa=pa->r,i++)
	{
		printf("\nData of node %d: %d",i+1,pa->data);
	}
        printf("\n\n");		
	return;
 } 

