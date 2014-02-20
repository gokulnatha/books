/*	Filename	:	seekalt.c
 *	Date		:	03-08-2010
 *	Author		:	Stalin Srinivasan.S
 *	Description	:	to traverse the records alternatively 
 */

 void seekalt(char *filename) 
 {
	FILE *fp;
	struct emp *a;
	int i,c;
	fp=fopen(filename,"r");
	printf("\nEnter ur choice : 1. Odd traversal 0.Even traversal \n");
	scanf("%d",&c);
	for(i=c;feof(fp)==0;i+=2)
	{
		fseek(fp,sizeof(struct emp)*i,SEEK_SET);		// setting cursor such a way to get alternates using fseek() and fread()
		a=malloc(sizeof(struct emp));
		fread(a,sizeof(struct emp),1,fp);
		printf("\nName: %s",a->name); 		
		printf("\nAge: %d",a->age); 		
		printf("\nEmpcode: %d",a->empcode); 		
		printf("\n");
		free(a);
	}
	fclose(fp);
 	return;
 }
		
