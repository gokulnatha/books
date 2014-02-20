/*	Filename	:	randarray.c
 *	Date		:	21-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to use random generator to fill array and operate on this
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct histo
 {
	int rn,h,f;
 }a[30];
 
 int main(void)
 {
	int i,j,n,c,p,st,k,rem;	
	printf("\nEnter the no of elements u want to be operated: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
        {
		a[i].rn=rand()%10;
	}
	printf("\nRandomly generated nos: \n");
	for(i=0;i<n;i++)
        {
		printf("%d\n",a[i].rn);
	}
	printf("\nIn Reverse Order:\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\n",a[i].rn);
	}
	printf("\nEnter the column width: ");
        scanf("%d",&c);
	p=n/c;
	rem=n%c;
	st=0;
	for(i=0;i<p;i++)
	{
		for(j=st;j<st+c;j++)
		{
			printf("%d\t",a[j].rn);
		}
		st+=c;
		printf("\n");
	}
	for(i=st;i<st+rem;i++)
	{
		printf("%d",a[i].rn);
	}
	printf("\nHistograms: \n");
	for(i=0;i<n;i++)
	{
		a[i].h=0;
		a[i].f=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i].rn==a[j].rn)
			{
				a[i].h++;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i].f!=4)
		{
			for(k=0;k<n;k++)
			{
				if(a[i].rn==a[k].rn)
				{
					a[k].f=4;
					a[i].f=5;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i].f!=4)
                {
		printf("\n%d : ",a[i].rn);
		for(j=0;j<a[i].h;j++)
		{	
			printf("*");
		}
		}
	}
	printf("\n\n");
        return 0;
 }	
