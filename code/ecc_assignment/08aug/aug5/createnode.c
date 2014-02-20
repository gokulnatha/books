/*	Filename	:	tree1.c
 *	Date		:	05-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to observe the tree 
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct tree
 {
	int data;
	struct tree *l,*r;
 }*root;
 
 int main(void)
 {
	struct tree *temp;
	int i;
	root=malloc(sizeof(struct tree));
	printf("\nEnter the data for root node: ");
	scanf("%d",&root->data);
	root->l=NULL;
	root->r=NULL;
	printf("\nData of the root node: %d",root->data);
	printf("\nEnter the data: ");
	temp=malloc(sizeof(struct tree));
	scanf("%d",&temp->data);
	temp->l=NULL;
	temp->r=NULL;
	if(temp->data<=root->data)
	{
		root->l=temp;
		printf("\nData at left of root: %d",root->l->data);
	}
	else
	{
		root->r=temp;
		printf("\nData at right of root: %d",root->r->data);
	}
	return 0;
 }
	
