/*	Filename	:	treedel.c
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

 int c=0;
	
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

 

 struct tree* del(struct tree *cur,int val)
 {
	struct tree *pa;
	if(cur==NULL)
	{
		return;
	}
	if(cur->l->data==val)
	{
		c=2;
		return cur;
	}
	else if(cur->r->data==val)
	{
		c=3;
		return cur;
	}
	else if(cur->data>val)
	{
		del(cur->l,val);
	}
	else if(cur->data<val)
	{
		del(cur->r,val);	
	}
 }

 struct tree* inorddisp(struct tree *cur)
 {
	if(cur==NULL)
	{
		return;
	}
	inorddisp(cur->l);
	printf("\nData: %d",cur->data);
	inorddisp(cur->r);
 }

 int main(void)
 {
	struct tree *cur,*temp,*parent,*child;
	int i,n,o,delval;
	root=malloc(sizeof(struct tree));
	printf("\nEnter the no of nodes to be inserted: ");
	scanf("%d",&n);
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
	printf("\nEnter the value to be deleted: ");
	scanf("%d",&delval);
	parent=del(root,delval);
	if(c==2)
	{
		child=parent->l;
		if(child->r==NULL)
		{
			parent->l=child->l;
		}
		else
		{
			parent->l=child->r;
		}
		free(child);
	}
	if(c==3)
	{
		child=parent->r;
		if(child->r==NULL)
		{
			parent->r=child->l;
		}
		else
		{
			parent->r=child->r;
		}
		free(child);
	}
	printf("\nDisp: ");
	inorddisp(root);
	return 0;
 }	
	
