/*	FileName	: togglebit.c
 *	Date		: 14-07-2010
 *	Author		: Stalin Srinivasan.S
 *	Description	: to demonstrate the bitwise operators
 */

 #include<stdio.h>
 #include<math.h>

 int main(void)
 {
 	int p,m=1;
	long long t;
	printf("\nEnter the number to be toggled: ");
	scanf("%qi",&t);
	if((t>0)&&(t<4294967296))
	{
		printf("\nEnter the desired bit position: ");
		scanf("%d",&p);
		m=m<<p;
		t=t^m;
		printf("\nToggled number: %qi",t);
	}
	else
	{
		printf("\nOut of Range");
	}
	printf("\n\n");
	return 0;
 }  
