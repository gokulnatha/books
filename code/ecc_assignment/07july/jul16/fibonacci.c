/*	Filename	:	fibonacci.c
 *	Date		:	15-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to generate fibonacci series for the given number
 */

 #include<stdio.h>
 #include<math.h>
 
 int main(void)
 {
	int f1=0,f2=1,f3,i,n;
	printf("\nEnter the number to generate fibonacci series: ");
	scanf("%d",&n);
	if(!n)
	{
		printf("\nfor zero no series generated");
		return 0;
	}
	else if(n==1)
	{
		printf("\n0");
		return 0;
	}
	n/=2;
	if(n>0)
	{
	printf("\n%d\n%d",f1,f2);
	for(i=0;i<n-2;i++)
	{
		f3=f1+f2;
		f1=f2;
		f2=f3;
		printf("\n%d",f3);
	}
	}
	else
	{
		printf("\nDont enter negativenos/strings/specialchars");
	        return 0;
        }
	printf("\n\n");
	return 0;
 }
 	
