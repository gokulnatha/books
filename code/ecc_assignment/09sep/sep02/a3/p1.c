/*	Filename	:	p1.c
 *	Date		:	02-09-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to perform n x n matrix multiplication using threads.
 */

 #include<stdio.h>
 #include<math.h>
 #include<stdlib.h>
 #include<pthread.h>

int r1,r2,c1,c2,i,j,k,a[10][10],c[10][10],b[10][10];
pthread_t th1,th2,th3;

void *kloop()
{
	int t=0;
	for(k=0;k<r2;k++)
	{
		t+=a[i][k]*b[k][j];
	}
	c[i][j]=t;
}

void *jloop()
{
	for(j=0;j<c2;j++)
	{
		pthread_create(&th3,NULL,kloop,NULL);
		pthread_join(th3,NULL);	
	}
}

void *iloop()
{
	for(i=0;i<r1;i++)
	{
		pthread_create(&th2,NULL,jloop,NULL);
		pthread_join(th2,NULL);
	}
}

int main(void)
{
	int i,j,k;
	system("clear");
	printf("\nEnter the order of I matrix:\n");
	printf("\nRow: ");
	scanf("%d",&r1);	
	printf("\nColumn: ");
	scanf("%d",&c1);
	printf("\nEnter the order of II matrix:\n");
	printf("\nRow: ");
	scanf("%d",&r2);	
	printf("\nColumn: ");
	scanf("%d",&c2);
	if(c1==r2)
	{
		printf("\nEnter the elements for 1st matrix: (Row Major)\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{	
				scanf("%d",&a[i][j]);
			}
		}
		printf("\nEnter the elements for 2nd matrix: (Row Major)\n");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{	
				scanf("%d",&b[i][j]);
			}
		}
		pthread_create(&th1,NULL,iloop,NULL);
		pthread_join(th1,NULL);
		printf("\nResultant matrix: \n\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				printf("%d\t",c[i][j]);
			}
			printf("\n\n");
		}
		return 0;
	}
	else
	{
		printf("\n...Pls enter the valid order...\n");
		return 0;
	}
}
	

				
