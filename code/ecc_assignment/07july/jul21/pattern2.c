/*	Filename	:	pattern2.c
 *	Date		:	21-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to get the desired pattern series
 */

 #include<stdio.h>
 #include<stdlib.h>

 int main(void)
 {
	int i,j,k,n;
	printf("\nEnter the no of lines to be generated: ");
	scanf("%d",&n);
	for(i=n;i>0;i--)
	{
		for(k=0;k<n-i;k++)
		{
			printf("\t");
		}
		for(j=0;j<i;j++)
		{
			printf("*\t");
		}	
		printf("\n");
	}
	return 0;
 }
			

