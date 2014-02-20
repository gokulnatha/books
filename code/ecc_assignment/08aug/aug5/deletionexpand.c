/*	Filename	:	treedel4.c
 *	Date		:	06-08-2010
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

 int c=0,*ptoc;
	
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
	
 struct tree* max(struct tree *cur)
 {
	if(cur->r==NULL)
		return cur;
	max(cur->r);
 }

 struct tree* min(struct tree *cur)
 {
	if(cur->l==NULL)
		return cur;
	min(cur->l);
 }

 struct tree* getpar(struct tree *cur,struct tree *child)
 {
	if(cur==NULL)
	{
		return;
	}
	else if((cur->r==child)||(cur->l==child))
	{
		return cur;
	}
	if(cur->data>child->data)
	{
		getpar(cur->l,child);
	}
	else if(cur->data<child->data)
	{
		getpar(cur->r,child);
	}
 }

 int isleaf(struct tree *cur)
 {
	if((cur->r==NULL)&&(cur->l==NULL))
		return 0;
	else
		return 1;
 }
	

 struct tree* travdel(struct tree *cur,int val)
 {
	if(cur==NULL)
	{
		return;
	}
	else if(cur->data==val)
	{
		*ptoc=1;
		return cur;
	}
	else if(cur->l->data==val)
	{
		*ptoc=2;
		return cur;
	}
	else if(cur->r->data==val)
	{
		*ptoc=3;
		return cur;
	}
	else if(cur->data>val)
	{
		travdel(cur->l,val);
	}
	else if(cur->data<val)
	{
		travdel(cur->r,val);	
	}
 }

 void delleft(struct tree *parent)
 {
	struct tree *child,*gchild1,*gchild2,*gchild,*gp1,*gp2;
	child=parent->l;
	if((child->l==NULL)&&(child->r==NULL))
	{
		parent->l=NULL;
	}
	else if((child->r==NULL)&&(child->l!=NULL))
	{
		parent->l=child->l;
	}
	else if((child->l==NULL)&&(child->r!=NULL))
	{
		parent->l=child->r;
	}
	else if((child->l!=NULL)&&(child->r!=NULL))
	{
		gchild1=max(child->l);
		gp1=getpar(root,gchild1);
		gchild2=min(child->r);
		gp2=getpar(root,gchild2);
		if((isleaf(gchild1)==0)&&(isleaf(gchild2)!=0))
			gchild=gchild1;
		else if((isleaf(gchild1)!=0)&&(isleaf(gchild2)==0))
			gchild=gchild2;
		else if((isleaf(gchild1)==0)&&(isleaf(gchild2)==0))
			gchild=gchild1;
		else if((isleaf(gchild1)!=0)&&(isleaf(gchild2)!=0))
		{
			gchild=gchild1;
			gchild->r=child->r;
			parent->l=gchild;
			free(child);
			return;
		}
		child->data=gchild->data;
		if(gp1->r==gchild)
			gp1->r=NULL;
		else
			gp1->l=NULL;
		free(gchild);	
		return;
	}
	free(child);
	return;
 }

 void delright(struct tree *parent)
 {
	struct tree *child,*gchild1,*gchild2,*gchild,*gp1,*gp2;
	child=parent->r;
	if((child->l==NULL)&&(child->r==NULL))
	{
		parent->r=NULL;
	}
	else if((child->r==NULL)&&(child->l!=NULL))
	{
		parent->r=child->l;
	}
	else if((child->l==NULL)&&(child->r!=NULL))
	{
		parent->r=child->r;
	}
	else if((child->l!=NULL)&&(child->r!=NULL))
	{
		gchild1=max(child->l);
		gp1=getpar(root,gchild1);
		gchild2=min(child->r);
		gp2=getpar(root,gchild2);
		if((isleaf(gchild1)==0)&&(isleaf(gchild2)!=0))
		{
			gchild=gchild1;
		}
		else if((isleaf(gchild1)!=0)&&(isleaf(gchild2)==0))
		{
			gchild=gchild2;
		}
		else if((isleaf(gchild1)==0)&&(isleaf(gchild2)==0))
		{
			gchild=gchild1;
		}
		else if((isleaf(gchild1)!=0)&&(isleaf(gchild2)!=0))
		{
			gchild=gchild1;
			gchild->r=child->r;
			parent->r=gchild;
			free(child);
			return;
		}
		child->data=gchild->data;
		if(gp1->r==gchild)
		{
			gp1->r=NULL;
		}
		else
		{
			gp1->l=NULL;
		}
		free(gchild);	
		return;
	}
	free(child);
	return;
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
	struct tree *cur,*temp,*parent,*child,*grandchild1,*grandchild2,*gp1,*gp2;
	int i,n,o,delval;
	ptoc=&c;
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
	if(root->data==delval)
	{
		parent=root;
		if((parent->r==NULL)&&(parent->l!=NULL))
		{
			root=parent->l;
		}
		else if((parent->l==NULL)&&(parent->r!=NULL))
		{
			root=parent->r;
		}
		free(parent);
		inorddisp(root);
		exit(0);
	}
	parent=travdel(root,delval);
	if(c==2)
	{
		delleft(parent);
	}
	else if(c==3)
	{
		delright(parent);
	}
	printf("\nDisp: ");
	inorddisp(root);
	return 0;
 }	
	
