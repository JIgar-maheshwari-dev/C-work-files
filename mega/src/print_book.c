#include"head.h"

void print_book(){
	FILE *fp;
	fp=fopen("../book_files/book_records.txt","r");
	
	int bn;
	char namee[50],genr[50],auth[50],idate[20];
	int i=0,page,sn,pricee,avail;

	while(!(feof(fp))){
		fgets(genr,100,fp);
		//printf("%d string is = ",i);
		printf("%s",genr);

		//printf("%d string is = ",i);
		//printf("%s\n",test);

/*
		fscanf(fp,"%*s %*s %*s %*s %d %*s %*s %[^\n]s",&bn,namee);
		fscanf(fp,"%*s %*s %[^\n]s ",genr);
		fscanf(fp,"%*s %*s %[^\n]s ",auth);
		fscanf(fp,"%*s %*s %*s %[^\n]s ",idate);
		fscanf(fp,"%*s %*s %*s %d %*s %*s %*s %d %*s %*s %d %*s %*s %*s %d %*s",&page,&sn,&pricee,&avail);
		printf("bn-%d  name-%s   genr-%s   auth-%s  idate-%s   page- %d  sn- %d  price- %d  avail - %d\n\n\n",bn,namee,genr,auth,idate,page,sn,pricee,avail);

*/


	}





/*
	fscanf(fp,"%*s %*s %*s %*s %d %*s %*s %[^\n]s",&bn,namee);
	fscanf(fp,"%*s %*s %[^\n]s ",genr);
	fscanf(fp,"%*s %*s %[^\n]s ",auth);
	fscanf(fp,"%*s %*s %*s %[^\n]s ",idate);
	fscanf(fp,"%*s %*s %*s %d %*s %*s %*s %d %*s %*s %d %*s %*s %*s %d %*s",&page,&sn,&pricee,&avail);
	printf("bn-%d  name-%s   genr-%s   auth-%s  idate-%s   page- %d  sn- %d  price- %d  avail - %d\n",bn,namee,genr,auth,idate,page,sn,pricee,avail);
*/



/*
	fscanf(fp,"%*s %*s %*s %*s %*s %*s %*s %s",test);
	printf("%s",test);
*/



}

