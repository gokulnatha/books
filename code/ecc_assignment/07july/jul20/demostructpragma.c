#include<stdio.h>

int main(void)
{
struct demo1
{
	char c;
	int i;
	char d;
	int j;
        char e;
}e1;
	printf("\nSize of demo struct: %d",sizeof(e1));
	#pragma pack(1)
struct demo2
{
	char c;
	int i;
	char d;
	int j;
	char e;
}e2;
	printf("\nSize of demo struct : %d",sizeof(e2));
	printf("\n\n");
	return 0;
}

