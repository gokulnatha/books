#include<stdio.h>
int main(void)
{
	static int a=10;
	if(a)
	{
		a--;
		main();
		printf("\n%d",a);
	}
	return 0;
}
	

