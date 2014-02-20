#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
int main(void)
{
	FILE *fp;
	int i=0;
	char *buf,buf1[50];
	buf=malloc(50);
	fp=fopen("myfile.c","r");
	while(!feof(fp))
	{
		fread(buf,sizeof(char),sizeof(buf[0]),fp);
		buf1[i]=*buf;
		i++;
	}
	buf1[i]='\0';
	printf("\n\nread content: %s",buf1);
	printf("\n\n");
	return 0;
}
	

