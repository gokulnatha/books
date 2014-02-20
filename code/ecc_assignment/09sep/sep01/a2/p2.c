/*	FileName	:	p2.c
 *	Date		: 	01-09-2010
 *	Author		:	Stalin Srinivasan.S	
 *	Description	:	To spawn 3 threads from hwp and make synchronization between them for writing and reading
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>

struct emp1
{
	char name[30];
	int age;
	char org[30];
}*a1,*ra1;

struct emp2
{
	char addr[30];
	int phone;
}*a2,*ra2;

pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2=PTHREAD_MUTEX_INITIALIZER;

int fdw,fdr,n,phno;

void* write1()
{
	int i;
	fdw=open("src.txt",O_RDWR|O_CREAT,0777);
	for(i=0;i<n;i++)
	{
		pthread_mutex_lock(&m1);
		a1=malloc(sizeof(struct emp1));
		printf("\nEnter name: ");
		scanf("%s",a1->name);
		printf("\nEnter age: ");
		scanf("%d",&a1->age);
		printf("\nEnter org: ");
		scanf("%s",a1->org);
		write(fdw,a1,sizeof(struct emp1));
		pthread_mutex_unlock(&m2);
		pthread_mutex_unlock(&m1);
		sleep(1);
	}
	return NULL;
}
	
void* write2()
{
	int i;
	pthread_mutex_lock(&m2);
	for(i=0;i<n;i++)
	{
		pthread_mutex_lock(&m1);
		a2=malloc(sizeof(struct emp2));
		printf("\nEnter addr: ");
		scanf("%s",a2->addr);
		printf("\nEnter phone: ");
		scanf("%d",&a2->phone);
		write(fdw,a2,sizeof(struct emp2));
		pthread_mutex_unlock(&m1);
		sleep(1);
	}
	close(fdw);
	return NULL;
}

void* read1()
{
	int i;
	char name[30];
	fdr=open("src.txt",O_RDONLY);
	printf("\nEnter the name to be searched: ");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{
		ra1=malloc(sizeof(struct emp1));	
		read(fdr,ra1,sizeof(struct emp1));
		if(strcmp(name,ra1->name)==0)
		{
			printf("\nName	: %s",ra1->name);
			printf("\nAge	: %d",ra1->age);
			printf("\nOrg	: %s",ra1->org);  
			ra2=malloc(sizeof(struct emp2));
			read(fdr,ra2,sizeof(struct emp2));
			printf("\nAddr	: %s",ra2->addr);
			printf("\nPhone : %d",ra2->phone);
			break;
		}
		lseek(fdr,sizeof(struct emp2),SEEK_CUR);
	}
}

int main(void)
{
	pthread_t lwp1,lwp2,lwp3;
	int noe,i;
	system("clear");
	printf("\nEnter no of employees to be recorded: ");
	scanf("%d",&n);
	pthread_mutex_lock(&m2);
	pthread_create(&lwp1,NULL,write1,NULL);
	pthread_create(&lwp2,NULL,write2,NULL);
	pthread_join(lwp1,NULL);
	pthread_join(lwp2,NULL);
	printf("\nEnter how many employees to be searched: ");
	scanf("%d",&noe);
	for(i=0;i<noe;i++)
	{
		pthread_create(&lwp3,NULL,read1,NULL);
		pthread_join(lwp3,NULL);
	}
	printf("\n");
	return 0;
}
	
	

	
	

	
	
	
	


	
	
	

