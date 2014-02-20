/*	Filename	:	chkidfr.c
 *	Date		:	22-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to check the valid identifier
 */

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<ctype.h>

 int main(void)
 {
	char id[80];
        int i,j,l,c=0;
	do
	{
		printf("\nEnter your identifier: ");
        	scanf("%s",id);
		l=strlen(id);
		if(!isalpha(id[0]))
		{
			printf("\nSorry boss, you have to start with alphabets\n");
			c=3;
			continue;
		}
        	for(i=1;i<l;i++)
		{
			if((isalnum(id[i])==0)&&(id[i]!='_'))
			{
				printf("\nBoss you have to complete letters only with alphanumeric/'_'\n");
				c=3;
				break;
			}
			c=5;
		}
	}while(c==3);
	if(i==l)
	{
		printf("\nthe B O S S ");
	}
	printf("\n\n");
	return 0;
 }
	
           
		
        
         

