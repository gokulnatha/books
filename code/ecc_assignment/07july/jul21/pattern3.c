/*	Filename	:	pattern3.c
 *	Date		:	21-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to get the desired pattern series
 */

 #include<stdio.h>
 #include<stdlib.h>

 int main(void)
 {
	int i,j,k,c=0,n;
	printf("\nEnter the no of lines to be generated: ");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		for(k=0;k<n-i;k++)
		{
			printf("\t");
		}
		for(j=0;j<(2*i)-1;j++)
		{
			printf("*\t");
		}
		printf("\n");
	}
			
	printf("\n");
	return 0;
 }

