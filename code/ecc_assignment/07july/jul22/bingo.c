/*	Filename	:	bingo.c
 *	Date		:	22-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to construct the bingo matrix
 */

 #include<stdio.h>
 #include<stdlib.h>

 int main(void)
 {
	int i,j,k,h,a[5][5];
        for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			a[i][j]=(rand()%15)+(j*15)+1;
			for(k=0;k<i;k++)
			{
				for(h=0;h<5;h++)
				{
					if(a[i][j]==a[k][h])
					{
						j--;
					}
				}
			}
		}
	}
	printf("\nB\tI\tN\tG\tO\n\n");
	for(i=0;i<5;i++)	
        {
		for(j=0;j<5;j++)
		{
			if((i==2)&&(j==2))
			{
				printf("free\t");
				continue;
			}
			printf("%d\t",a[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\n");
	return 0;
 }	

