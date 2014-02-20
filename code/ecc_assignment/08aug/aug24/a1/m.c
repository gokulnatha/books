#include<stdio.h>
#include<unistd.h>
int main(void)
{
	int a,b,c;
	printf("\nEnter a value: ");
	scanf("%d",&a);
	printf("\nEnter b value: ");
	scanf("%d",&b);
	c=a*b;
	printf("\nResult: %d",c);
}
	
