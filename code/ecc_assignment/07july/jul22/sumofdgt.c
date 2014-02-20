/*	Filename	:	sumofdgt.c
 *	Date		:	22-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to count and find the sum of digits of an integer value
 */

 #include<stdio.h>

 int main(void)
 {
	int n,s=0,i;
	printf("\nEnter the value: ");
	scanf("%d",&n);
	i=0;
	while(n>0)
	{
		s=s+n%10;
		n/=10;
		i++;
	}
	printf("\nCount: %d",i);
	printf("\n\nSum: %d",s);
	printf("\n\n");
	return 0;
 }

