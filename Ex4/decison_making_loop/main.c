#include<stdio.h>

int bin_search(int x,int v[], int n);

void main() {

    printf("start main\n\n");
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int ans ;
    printf("before calling function \n\n");
    ans = bin_search(3,a,10);
    printf("%d\n",ans);
}

int bin_search(int x,int v[], int n){
    int low,high,mid;
    low=0;
    high=n-1;

    printf("inside search function before loop \n\n");

    while(low<=high){
        mid=(low+high)/2;
        printf("inside loop %d \n\n",mid);
        if(x<v[mid])
            high=mid+1;
        else if(x>v[mid])
            low=mid+1;
        else
            return mid;
    }
    return -1;
}
