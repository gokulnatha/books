/*	Filename	:	factrecurs.c
 *	Date		:	27-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to computer factorial using recursion
 */

 #include<stdio.h>
 
 int fact(int n)
 {
	int result;
	if(n==1)
		return 1;
	else
		result=n*fact(n-1);
 }
 
 int main(void)
 {
	int n;
	printf("\nEnter the no: ");
	scanf("%d",&n);
	printf("\nResultant value: %d",fact(n));
	printf("\n\n");
	return 0;
 }
 

