/*	Filename	:	dectobin.c
 *	Date		:	21-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to convert decimal to binary value
 */

 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>

 int main(void)
 {
	int i,j,n,s,a[30];
	printf("\nEnter the decimal no to be converted: ");
	scanf("%d",&n);
	i=0;
	while(n>1)
	{
        	a[i]=n%2;
		n/=2;
		i++;
	}
	a[i]=n;
        for(j=i;j>=0;j--)
		printf("%d",a[j]);
	printf("\n\n");
	return 0;
 }		
		
