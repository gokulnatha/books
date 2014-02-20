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
	if(isdigit(n))
	{
	for(i=1;i<=n;i++)
	{
		s*=i;
	}
	if(s==1)
	{
		if((n==1)||(n==0))
		{
			printf("\nFactorial: 1");
		}
		else
		{
			printf("\nDont enter negativenos/string/specialchars\n");
			return 0;
		}
	}
	else if(s==0)
	{
		printf("\nDont enter negativenos/string/specialchars\n");
		return 0;
	}
	printf("\nFactorial: %qi",s);
        return 0; 
	}
	printf("\nDont enter negativenos/string/specialchars\n");
	printf("\n\n");
	return 0;
 } 	
