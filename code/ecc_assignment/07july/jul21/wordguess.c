/*	Filename	:	wordguess.c
 *	Date		:	21-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to design word guess game
 */

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<ctype.h>

 int main(void)
 {
	char s[30],d[30],g;
	int i,j,l,l1,c=0,track=0;
	printf("\n*** Word Guess ***\n\n");
	printf("\nyou have only seven chances to guess the word. All the Best..\n\n");
	printf("\nEnter the word to be guessed: ");
	gets(s);
	l=strlen(s);
	l1=l;
	for(i=0;i<l;i++)
		d[i]='*';
	d[i]='\0';
	for(i=0;i<l;i++)
	{
		if(isspace(s[i]))
		{
			printf("\nDont enter white spaces\n\n");
			exit(0);
		}
		if(isalpha(s[i]))	
		{
			if(isupper(s[i]))
			{
				printf("\nPls enter the lower case characters\n\n");
				exit(0);
		        }	
		}
		else
		{
			printf("\nPls enter only alphabets\n\n");
			exit(0);
		}
	}
	for(i=0;i<7;i++)
	{
        	printf("\nYour %d Guess: \n",i+1);
		printf("\nEnter a character u guess: ");
		scanf("%c",&g);
		c=0;
		for(j=0;j<l1;j++)
		{
			if(s[j]==g)
			{
				if(d[j]!=s[j])
				{
					d[j]=s[j];
				}
				else
				{
					track=5;
					i++;
				}
				c++;
			}
		}
		if(c==0)
		{
			printf("\nSorry wrong guess");
		}
		else if((c==0)&&(i==6))
		{
			printf("\nExceeding limit. Sorry, Try again...");
			exit(0);
		}
		else if(c>0)
		{
			l-=c;
			i--;
		 	if(l==0)
			{
				printf("\nYa! you done it the word is %s",d);
				printf("\n\nWhere is the party tonite?\n");
				return 0;
			}
			if(track!=5)
		        {		
				printf("\nYou are at track. Go ahead!");
			}
			else
			{
				printf("\nYou already pressed %c. dont waste your chance",g);
				track=0;
			}
			printf("\n\n");
			printf("%s",d);
		} 
		getchar();
	}
	printf("\n\n");
	return 0;
 }

	
	


