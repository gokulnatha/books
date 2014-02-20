/*	Filename	:	dblinkdemo1.c
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
	first=malloc(sizeof(struct node));
	printf("\nEnter the data to be inserted: ");
	scanf("%d",&first->data);
	first->l=NULL;
	first->r=NULL;
	printf("Data of the first node: %d",first->data);
	return;
 } 

