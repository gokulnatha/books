/*	Filename	:	swapptrs.c
 *	Date		:	20-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to swap the values using pointers
 */

 #include<stdio.h>
 
 int main(void)
 {
	int a,b,c,*p1,*p2,*t;
	p1=&a;
	p2=&b;
	printf("\nEnter the value a: ");
	scanf("%d",&a);
	printf("\nEnter the value b: ");
        scanf("%d",&b);
	t=p2;
	p2=p1;
	p1=t;
	printf("\nAfter swapping, a is %d and b is %d",*p1,*p2);
	printf("\n\n");
	return 0;
 }	
