/*	Filename	:	charascii.c
 *	Date		:	15-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to get the ascii value of a character 
 */

 #include<stdio.h>
 #include<math.h>
 #include<string.h>
 
 int main(void)
 {
 	char c[100],i[100];
	int j,k;
	do
	{
		printf("\nEnter a character: ");
		gets(c);	
		for(j=0;c[j]!='\0';j++)
		{
			if(c[j]==32)
			{
				printf("\nPlease dont enter space bw your characters\n");
				return 0;
			}
			printf("Yours specified character's ascii value is %d\n\n",c[j]);
		}
		printf("\n\n");
		printf("\nPress y to continue: ");
		getchar();
		scanf("%s",i);
	}while(strcmp(i,"y")==0);
	return 0;
 }
