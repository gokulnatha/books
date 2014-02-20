/*	Filename	:	empstructptr.c
 *	Date		:	23-07-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to get and traverse the employee details using pointers 
 */

 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include<ctype.h>
 
 struct emp
 {
	char n[30],a[60],o[30];
	int p[2],eid;
 }*p[10];
 int main(void)
 {
	int i,j,k,n,an,contno,f=0,c=5,choice,mch,ref,refint,eid,clash=0,test;
	printf("\nEnter the no of employees to be entered:(ur starting integer value only bothered) ");
	scanf("%d",&n);
	if(n>0)
	{
	for(i=0;i<n;i++)
	{
		p[i]=malloc(sizeof(struct emp));
		printf("\nName of Employee: ");
                scanf("%s",p[i]->n);
		printf("\nEmployee id: ");
		scanf("%d",&p[i]->eid);
		printf("\nAddress of Employee: ");
		scanf("%s",p[i]->a);
                printf("\nContact nos:");
		printf("\nOffice: ");
		scanf("%d",&p[i]->p[0]);
		printf("\nPersonal: ");
		scanf("%d",&p[i]->p[1]);
		printf("\nBelonging Organisation: ");
		scanf("%s",p[i]->o);
	}
	do
	{
		printf("\n\n1.Traversal 2.Insertion 3.Deletion 4.Exit \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
			do
			{
        		printf("\nEnter the contact no: ");
			scanf("%d",&contno);
        		for(i=0;i<n;i++)
			{
				if((p[i]->p[0]==contno)||(p[i]->p[1]==contno))
				{
				printf("\nName: %s\nEmpid: %d\nAddress: %s\nContacts->Offi %d\tPres %d\nOrganistation %s",p[i]->n,p[i]->eid,p[i]->a,p[i]->p[0],p[i]->p[1],p[i]->o);
				f=1;
				break;
				}
			}
			if(f!=1)
			{
				printf("\nUr specified contact no is not belonging to our colleagues");
				f=0;
        		}
			printf("\nDo u wish to continue traversal press 1: ");
			scanf("%d",&c);
			}while(c==1);
			mch=6;
			break;
		}
                case 3:
		{
			do
			{
				printf("\nEnter the contact no to be deleted: ");
				scanf("%d",&contno);
				for(i=0;i<n;i++)
				{
					if((p[i]->p[0]==contno)||(p[i]->p[1]==contno))
					{
						f=3;
						free(p[i]);
						p[i]=NULL;
						for(j=i;j<n;j++)
						{
							p[j]=p[j+1];
						}
						n--;
						printf("\nDeleted");
						break;
					}
                		}
				if(f!=3)
				{
					printf("\nUr Specified contact no is not belonging to our colleagues");
					f=0;
				}
				printf("\nDo u wish to continue deletion  press 3: ");
				scanf("%d",&c);
			}while(c==3);
			mch=6;
			break;
		}
		case 2:
		{
			do
			{
				printf("\nEnter the no of employees to be appended: ");
				scanf("%d",&an);
				for(i=n;i<n+an;i++)
				{
					p[i]=malloc(sizeof(struct emp));
					printf("\nIs there any reference press 7: ");
					scanf("%d",&ref);
					if(ref==7)
					{
				              printf("\nEnter the empid referring: ");
					      scanf("%d",&eid);
					      for(j=0;j<n;j++)
					      {
						if(eid==p[j]->eid)
						{
							printf("\nName of Employee: ");
                					scanf("%s",p[i]->n);
							printf("\nEmployee id: ");
							scanf("%d",&p[i]->eid);
							for(k=0;k<n;k++)
							{
								if(p[i]->eid==p[k]->eid)
								{
									printf("\nYour mentioned empid is clashing with our db..");
									clash=8;
									break;
								}
							}
							if(clash==8)
							{
								break;
							}	
							printf("\nContact: ");
							printf("\noff: ");	
							scanf("%d",&p[i]->p[0]);
							printf("\npersonal: ");
							scanf("%d",&p[i]->p[1]);
							strcpy(p[i]->a,p[j]->a);
							strcpy(p[i]->o,p[j]->o);
							refint=9;
						}
					      }
					      if((refint!=9)&&(clash!=8))
					      {
						 printf("\nYour referred empid is invalid");
					      }
					}
					else
					{
					printf("\nName of Employee: ");
                			scanf("%s",p[i]->n);
					printf("\nEmployee id: ");
					scanf("%d",&p[i]->eid);
						for(k=0;k<n;k++)
						{
							if(p[i]->eid==p[k]->eid)
							{
								printf("\nYour mentioned empid is clashing with our db..");
								break;
								clash=8;
							}
						}
						if(clash==8)
						{
							continue;
						}	
					printf("\nAddress of Employee: ");
					scanf("%s",p[i]->a);
                			printf("\nContact nos:");
					printf("\nOffice: ");
					scanf("%10d",&p[i]->p[0]);
					printf("\nPersonal: ");
					scanf("%10d",&p[i]->p[1]);
					printf("\nBelonging Organisation: ");
					scanf("%s",p[i]->o);
					}

				}
				n+=an;
			        printf("\nDo u wish to continue appending press 2: ");
				scanf("%d",&c);
			}while(c==2);
			mch=6;
			break;	
		}	
                case 4:
		{
			exit(0);
		}	
	}
	}while(mch==6);
	}
	else
	{
		printf("\nDont enter negativenos/string/specialchars");
	}
	printf("\n");
        return 0;
 }
