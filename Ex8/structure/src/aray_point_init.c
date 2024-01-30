#include<stdio.h>
#include"head.h"

void init_p_array(struct point temp[],int n){
	
	for(int i=0;i<n;i++){
		scanf("%d",&temp[i].x);
		scanf("%d",&temp[i].y);
	}		
}

