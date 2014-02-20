/*      FileName        :       divstr.c 
 *	Date		:	15-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to divide the string on specific partition 
 */

 #include<stdio.h>
 #include<math.h>
 #include<string.h>
 
 int main(void)
 {
	char s[30];
	int i,j,l,p,q,cs,ea,k=0;
	do
	{
	printf("\nEnter the string: ");
	scanf("%s",s);
	l=strlen(s);
	printf("\nEnter the partition: ");
	scanf("%d",&p);
        cs=l/p;
	if(!cs)
        {
		printf("\nPlease enter the partition level less than length of the string\n");
        }
	}while(cs==0);
	ea=l%p;
	for(i=0;i<p;i++)
	{
		if(l>k)
		{
			for(j=0;j<cs;j++)
			{
				printf("%c",s[k+j]);
			}
				if(i==p-1)
				{
					k+=cs;
					for(q=0;q<ea;q++)
					{
						printf("%c",s[k+q]);
					}
				}
		}
		k+=cs;
		printf("\n");

	}
	printf("\n\n");
        return 0;
 }	
