/*	Filename	:	powfunc.c
 *	Date		:	26-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to get power of a no using function
 */

 #include<stdio.h>
 #include<stdlib.h>

 int i; 
 int powval(int n,int p)
 {
	int result=1;
	for(i=0;i<p;i++)
	{
		result=n*result;
	}
	return result;
 }
 void powref(int n,int p,int *r)
 {
	for(i=0;i<p;i++)
	{
		*r=n**r;	
	}
 } 
 int main(void)
 {
	int n,p,choice,result=1;
	printf("\nEnter the no : ");
	scanf("%d",&n);
	printf("\nEnter the power to raise above no: ");
	scanf("%d",&p);
	printf("\n1.Call by value 2.Call by reference\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		result=powval(n,p);
	}
	else
	{	
		powref(n,p,&result);
	}
	printf("\nResultant value: %d",result);
	printf("\n\n");
	return 0;
 }
