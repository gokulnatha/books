/*	Filename	:	arithptrs.c
 *	Date		:	23-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to perform arithmetic operations using pointers
 */

 #include<stdio.h>
 #include<stdlib.h>

 int main(void)
 {
	int i,n,*p,*cp,choice=0,count=0;
	printf("\nEnter the no of elements to be operated: ");
	scanf("%d",&n);
	p=malloc(n*sizeof(int));
        cp=malloc(sizeof(int));;	
	printf("\nEnter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",p+i);
	}
	do
	{
		printf("\n\n1.Addition 2.Subtraction 3.Multiplication 4.Division\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
                        {
				*cp=*(p+count)+*(p+count+1);
				printf("\nUpdated result is %d at location: %p",*cp,cp);
				count+=2;
				break;
			}
			case 2:
			{
				*cp=*(p+count)-*(p+count+1);
				printf("\nUpdated result is %d at location: %p",*cp,cp);
				count+=2;
				break;
			}
			case 3:
			{
				*cp=*(p+count)**(p+count+1);
				printf("\nUpdated result is %d at location: %p",*cp,cp);
				count+=2;
				break;
			}
			case 4:
			{
				*cp=(*(p+count))/(*(p+count+1));
				printf("\nUpdated result is %d at location: %p",*cp,cp);
				count+=2;
				break;
			}
			default:
			{
				break;
			}
		}
		n-=2;
		printf("\nto continue press 1: ");
		scanf("%d",&choice);
	}while((choice==1)&&(n!=1)&&(n!=0));
	free(p);
	free(cp);
	printf("\n\n");
	return 0;
 }

			
			
	
 	

