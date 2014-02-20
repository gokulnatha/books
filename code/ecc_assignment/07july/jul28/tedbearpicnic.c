/*	Filename	:	tedbearpicnic.c
 *	Date		:	28-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to make some mathematical game with user i/p
 */

 #include<stdio.h>
 #include<stdlib.h>

 int teddy(int n)
 {
	if(n<=42)
	{	
		return n;
	}
	else if((n%5==0)&&(n>42))
 	{
		teddy(n-42);	
	}
        else if(((n%3==0)||(n%4==0))&&(((n%10)*((n%100)/10))!=0))
	{
		teddy(n-((n%10)*((n%100)/10)));
	}
	else if(n%2==0)
	{
		teddy(n/2);	
	}
	else
	{
		return n;
	}
 }
	 
 int main(void)
 {
	int n;
	printf("\nEnter the no of teddies u give: ");
	scanf("%d",&n);
	if(teddy(n)==42)
		printf("\nYou are the boss (now proven)\n");
	else
		printf("\nNow i am having the %d bears(but boss, it would be 42)",teddy(n));
	printf("\n\n");
	return 0;
 }
 	

