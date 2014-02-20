#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>

int n,*a,*e,*o,ec=0,oc=0;

void* fact()
{
	int s=0,*p=0,i;
	p=a+(n+2);
	*p=1;
	for(i=1;i<=*(a+n+1);i++)
	{
		*p=*p*i;
	}
}
	
	
void* sum()
{
	pthread_t vlwp1;
	int i,*p=0;
	p=a+(n+1);
	*p=0;
	for(i=0;i<n;i++)
	{
		*p=*p+*(a+i);
	}
	pthread_create(&vlwp1,NULL,fact,NULL);
	pthread_join(vlwp1,NULL);
}

void* arrange()
{
	int i;
	e=malloc(n*sizeof(int));
	o=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		if(*(a+i)%2==0)
		{
			*(e+ec)=*(a+i);
			ec++;
		}
		else
		{
			*(o+oc)=*(a+i);
			oc++;
		}
	}
}

int main(void)
{
	pthread_t lwp1,lwp2;
	int i;
	a=malloc(30*sizeof(int));
	system("clear");
	printf("\nEnter the no to be listed: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter %d no: ",i+1);
		scanf("%d",a+i);
	}
	pthread_create(&lwp1,NULL,sum,NULL);
	pthread_join(lwp1,NULL);

	pthread_create(&lwp2,NULL,arrange,NULL);
	pthread_join(lwp2,NULL);

	printf("\nResult:\n\n");
	printf("\n\nTotal Sum of the list : %d",*(a+n+1));
	printf("\n\nEven Nos:\n");
        for(i=0;i<ec;i++)
	{
		printf("\n>%d",*(e+i));
	}
	printf("\nOdd Nos:\n");
        for(i=0;i<oc;i++)
	{
		printf("\n>%d",*(o+i));
	}
	printf("\n\nFactorial of the sum  : %d",*(a+n+2));
	printf("\n\n");		     			
	return 0;
}

		

	

	
		
		

