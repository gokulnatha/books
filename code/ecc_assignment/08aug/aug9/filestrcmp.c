/*	Filename	:	demostaticglobal.c
 *	Date		:	14-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to demonstrate static variable
 */

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 int main()
 {
	FILE *fp;
	char *bufr,bufw[10];
	int i,n,l[10];
	fp=fopen("myfile.c","w");
	printf("\nEnter the no of names to be recorded: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the name %d: ",i+1);
		scanf("%s",bufw);
		l[i]=strlen(bufw);
		fwrite(bufw,l[i],1,fp);
	}
	fclose(fp);
	fp=fopen("myfile.c","r");
	for(i=0;i<n;i++)
	{
		bufr=malloc(l[i]);
		fread(bufr,l[i],1,fp);
		if((*bufr=='a')||(*bufr=='A'))
		{
			printf("\nName Start with 'a' at position %d  : %s",i+1,bufr);
		}
		free(bufr);
	}
	fclose(fp);
	printf("\n\n");
	return 0;
 }
	
	
