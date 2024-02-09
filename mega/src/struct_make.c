#include"head.h"
#include"struct.h"

book* get_structs(){
	
        FILE *fp,*fp2;
        fp=fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/book_records.txt","r");
         
        char namee[50],genr[50],auth[50],idate[20];
        int bn,page,sn,pricee,avail,n;

	book* p1,*temp;
	
	n=get_book_count();

	if(n!=0){
		p1=(book *)calloc(n+1,sizeof(book));
		if(p1==NULL){
			printf("failed to allocate memery for structures \n");
			exit(1);
		}
	}


	temp=p1;

        while(!(feof(fp))){
                fscanf(fp,"%*s %*s %*s %*s %d %*s %*s %[^\n]s",&bn,namee);
                fscanf(fp,"%*s %*s %[^\n]s ",genr);
                fscanf(fp,"%*s %*s %[^\n]s ",auth);
                fscanf(fp,"%*s %*s %*s %[^\n]s ",idate);
                fscanf(fp,"%*s %*s %*s %d %*s %*s %*s %d %*s %*s %d %*s %*s %*s %d %*s",&page,&sn,&pricee,&avail);
//		printf("bn-%d  name-%s   genr-%s   auth-%s  idate-%s   page- %d  sn- %d  price- %d  avail - %d\n\n\n",bn,namee,genr,auth,idate,page,sn,pricee,avail);
		
	        strcpy(p1->name,namee);
	        strcpy(p1->genre,genr);
		strcpy(p1->author,auth);
		strcpy(p1->issue_date,idate);

		p1->book_no=bn;
		p1->total_pages=page;
		p1->shelf_no=sn;
		p1->price=pricee;
		p1->copy=avail;

/*
		printf("%s \n",p1->name);
		printf("%s \n",p1->genre);
		printf("%s \n",p1->author);
		printf("%s \n",p1->issue_date);
		printf("%d \n",p1->total_pages);
		
*/ //		printf("\n\n\n pointer value in its get structs fubciton       %ld       \n",p1);

		p1++;

        }
	
	fclose(fp);
	
	return temp;
}
