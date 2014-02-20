/*	Filename	:	pattern1.c
 *	Date		:	21-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to get the desired pattern series
 */

 #include<stdio.h>
 #include<stdlib.h>

 int main(void)
 {
	int i,j,n;
	printf("\nEnter the no of lines to be generated: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			printf("*\t");
		}
		printf("\n");
	}
	return 0;
 }

