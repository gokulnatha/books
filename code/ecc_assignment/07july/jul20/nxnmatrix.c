/*	Filename	:	nxnmatrix.c
 *	Date		:	20-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to perform n x n matrix multiplication
 */

 #include<stdio.h>
 #include<math.h>

 int main(void)
 {
	int r1,r2,c1,c2,i,j,k,t,a[10][10],c[10][10],b[10][10];
	printf("\nEnter order of matrix 1: ");
	printf("\nRows: ");
	scanf("%d",&r1);
	printf("Columns: ");
	scanf("%d",&c1);
	printf("\nEnter order of matrix 2: ");
	printf("\nRows: ");
	scanf("%d",&r2);
	printf("\nColumns: ");
	scanf("%d",&c2); 
	if(c1==r2)
	{
		printf("\n1st matrix\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{	
			scanf("%d",&a[i][j]);
		}
	}
		printf("\n2nd matrix\n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{	
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			t=0;
			for(k=0;k<r2;k++)
			{
				t+=a[i][k]*b[k][j];
			}
			c[i][j]=t;  		
	        }
	}
	printf("\nResultant matrix: \n\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n\n");
	}
	}
	else
	{
		printf("\nEnter the valid order ");
	}
	return 0;
 }
				
