/*	Filename	:	tree2.c
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
	
 struct tree* preorddisp(struct tree *cur)
 {
	if(cur==NULL)
	{
		return;
	}
	printf("\nData: %d",cur->data);
	preorddisp(cur->l);
	preorddisp(cur->r);
 }

 struct tree* postorddisp(struct tree *cur)
 {
	if(cur==NULL)
	{
		return;
	}
	postorddisp(cur->l);
	postorddisp(cur->r);
	printf("\nData: %d",cur->data);
 }

 int main(void)
 {
	struct tree *cur,*temp;
	int i,n,o;
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
	if(root==NULL)
		printf("\nEmpty tree");
	else
	{
		printf("\n1.Inorder traversal 2.Preorder 3.Post order traversal\n");
		scanf("%d",&o);
		if(o==1)
			inorddisp(root);
		else if(o==2)
			preorddisp(root);
		else if(o==3)
			postorddisp(root);
		else
			exit(0);
	}
	return 0;
 }	
	
