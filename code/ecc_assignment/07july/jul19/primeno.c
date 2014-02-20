/*	Filename	:	primeno.c
 *	Date		:	19-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to verify the no prime or not
 */

 #include<stdio.h>
 #include<math.h>
 
 int main(void)
 {
	int i,n,f=0,r;
	printf("\nEnter the no to be clarified: ");
	scanf("%d",&n);
	if((n%2!=0)&&(n!=2))
	{
	for(i=1;i<n/2;i+=2)
	{
		r=n%i;
		if(!r)
		{
			f=1;
			break;
		}
	}
	}
	else if(n==2)
	{
		f=0;
	}
	else
		f=1;
	if(f==1)
		printf("\nIt is non prime no");
	else
		printf("\n prime no");
	printf("\n\n");
	return 0;
 }

	

