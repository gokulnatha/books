/*	File Name  : Classifychar.c
 *	Date       : 13-07-2010
 *	Author     : Stalin Srinivasan.S
 *	Description: To Classify the input character type
*/

	#include<stdio.h>
	#include<ctype.h>

	int main(void)
	{
                char c;
		printf("\n");
		printf("Press any key to be classified: ");
		scanf("%c",&c);
		if(isprint(c))			/* checking it is printable or any ctrl special keys */
		{
			printf("\nPrintable->");
	        	if(isgraph(c))
			{
				printf("Graphical->");
				if(isalnum(c))
				{
					printf("Alphanum->");
					if(isalpha(c))
					{
						printf("Alpha->");
						if(isupper(c))
						{
							printf("Uppercase Character");
						}
						else
						{
							printf("Lowercase Character");
						}
					}
					else
					{
						printf("Digit");
					}
				}
				else if(ispunct(c))
				{
					printf("Punctuation Symbol");
				}
			}
			else if(isspace(c))
			{
				printf("Space Character");
			}
		}
		else if(iscntrl(c))
		{
			printf("Control Key");
		}
		printf("\n\n");
		return 0;
	}	
