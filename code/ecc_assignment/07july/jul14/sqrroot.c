/*	Filename	:	demostat.c
 *	Date		:	14-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to demonstrate static variable
 */

 #include<stdio.h>
 #include<math.h>

 int main(void)
 {
 	float n,i,j,q;
	printf("Go for Perfect square: ");
	scanf("%f",&n);
	for(i=2;i<=n;i++)
	{
		q=n/i;
		if(i==q)
		{
			printf("\n%.0f is sqrt of %.0f",q,n);
			return 0;
		}
	}
	if(i!=q)
	{
		printf("\npls enter the perfect square");
	}
	return 0;
 } 

 	
