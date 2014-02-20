#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<pthread.h>

int main(void)
{
	int pid;
	printf("\nEnter the pid: ");
	scanf("%d",&pid);
	kill(pid,SIGUSR2);
}

