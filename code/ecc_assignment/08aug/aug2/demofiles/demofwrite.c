#include<stdio.h>
#include<string.h>
int main(void)
{
	FILE *fp;
	int s;
	char buf[]="india";
	fp=fopen("myfile.c","a");
	s=fwrite(buf,sizeof(char),strlen(buf),fp);
	printf("\nreturn value: %d",s);
	printf("\n%p",fp);
	printf("\n\n");
	fclose(fp);
	return 0;
}
	

