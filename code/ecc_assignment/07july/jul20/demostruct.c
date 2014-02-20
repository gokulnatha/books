#include<stdio.h>

struct demo
{
	char c[5];
	int i;
}__attribute__((__packed__));

int main(void)
{
	
	struct demo e;
	printf("\nSize of demo struct : %d",sizeof(e));
	printf("\n\n");
	return 0;
}

