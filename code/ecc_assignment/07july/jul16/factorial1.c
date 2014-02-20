/*	Filename	:	factorial.c
 *	Date		:	15-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to generate the factorial of a number
 */

 #include<stdio.h>
 #include<ctype.h>
 
 int main(void)
 {
 	long long n,s=1;
	int i,c=5;
	printf("\nEnter the number to generate its factorial: ");
	scanf("%qi",&n);
	if((n==0)||(n==1))
		printf("\nFactorial: 1");
	n=n/2;
	if(n>0)
	{
	for(i=1;i<=n;i++)
	{
		s*=i;
	}
	}
        else
	{
	 printf("\nDont enter negativenos/string/specialchars\n");  
	 return 0;
	}
	printf("\nFactorial: %qi",s);
	printf("\n\n");
	return 0;
 } 	
