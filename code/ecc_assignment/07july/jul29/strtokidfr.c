/*	Filename	:	chkidfr.c
 *	Date		:	29-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to check the valid identifier in the string statement using strtok and recursion
 */

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<ctype.h>

 int i=0;

 char* chkid(char *id,char *del)
 {
	char *r;
	int l,j,c=0;
	r=malloc(100);
	r=strtok(id,del);
	if(r==NULL)
	{
		return;
	}
	else
	{
		if(!isalpha(*r))
		{
			printf("\nwrong start: %s",r);
			chkid(NULL,del);
		}
		else
		{
			for(j=1;*(r+j)!='\0';j++)
			{
				if((isalnum(*(r+j))==0)&&(*(r+j)!='_'))
				{
					c=3;
					printf("\nWrong following: %s",r);
					chkid(NULL,del);
				}
			}
			if(c!=3)
			{
				printf("\nValid Identifier: %s",r);
				chkid(NULL,del);
			}
		}
	}	
 }

 int main(void)
 {
	char *id,*del;
        int j,l,c=0;
	del=malloc(1);
	id=malloc(80);
	printf("\nEnter your delimiter: ");
	gets(del);
	printf("\nEnter your identifier: ");
	gets(id);
        chkid(id,del);	
	printf("\n\n");
	return 0;
 }
	
           
		
        
         

