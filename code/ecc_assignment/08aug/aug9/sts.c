#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int s=0;
	while(++s<10)
	{
		if(s<4&&s<9)
		continue;
		printf("\n%d",s);
	}
}

