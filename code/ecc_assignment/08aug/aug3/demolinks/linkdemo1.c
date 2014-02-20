/*	Filename	:	linkdemo1.c
 *	Date		:	03-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to demonstrate about the linked list 
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct node
 {
	int data;
	struct node *next;
 }*first;

 int main(void)
 {
	first=malloc(sizeof(struct node));	
	printf("\nEnter the data to be inserted: ");
	scanf("%d",&first->data);
	first->next=NULL;
	printf("\nData of the node: %d",first->data);
	printf("\n\n");
	return 0;
 }
