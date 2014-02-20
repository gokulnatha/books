/*	Filename	:	maxminsize.c
 *	Date		:	05-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to observe the tree and insertion of nodes on it
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct tree
 {
	int data;
	struct tree *l,*r;
 }*root;
	
 struct tree* insert(struct tree *cur,struct tree *temp)
 {
	if(temp->data<=cur->data)
	{
		if(cur->l==NULL)
		{
			cur->l=temp;
			return;
		}
	 	cur=cur->l;		
	}
	else
	{
		if(cur->r==NULL)
		{
			cur->r=temp;
			return;
		}
		cur=cur->r;	
	}
	insert(cur,temp);
 }

 void max(struct tree *cur)
 {
	if(cur->r==NULL)
	{
		printf("\nMaximum value: %d",cur->data);
		return;
	}
	max(cur->r);
 }
	
 void min(struct tree *cur)
 {
	if(cur->l==NULL)
	{
		printf("\nMinimum value: %d",cur->data);
		return;
	}
	min(cur->l);
 }


 int main(void)
 {
	struct tree *cur,*temp;
	int i,n,o;
	root=malloc(sizeof(struct tree));
	printf("\nEnter the no of nodes to be inserted: ");
	scanf("%d",&n);
	printf("\nEnter the data for noded as root: ");
	scanf("%d",&root->data);
	for(i=0;i<n;i++)
	{
		temp=malloc(sizeof(struct tree));
		temp->l=NULL;
		temp->r=NULL;
		printf("\nEnter the data to be noded at %d: ",i+1);
		scanf("%d",&temp->data);
		if(!i)
		{
			root=temp;
			cur=root;
			continue;
		}
	        insert(cur,temp);
	}
	max(root);
	min(root);
	return 0;
 }	
	
