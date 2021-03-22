#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;
const int DOUBLE_MAX = 1e9;
int result[26]={-1};


struct node{
    int data;
    int idx;
};


int abs_val(int a,int b){
    return a>b ? a-b:b-a;

}

 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int n,a,b;
    scanf("%lld %lld %lld",&n,&a,&b);
    struct node* arr[n];
    for (int i = 0; i < n; ++i)
    {
        int r;
       scanf("%lld",&r);
       arr[i]=(struct node*)malloc(sizeof(struct node));
       arr[i]->data=r;
       arr[i]->idx=i+1;
    }
    int k=0,kprev=n;
    if(n==1){
        printf("%lld %lld",arr[0]->idx,arr[0]->data);
        return 0;
    }

    while(1){
        k=0;
    for (int i = 0; i < kprev; i+=2)
    {
        if(i==kprev-1){
            arr[i]->data+=b;
            arr[k]->data=arr[i]->data;
            arr[k]->idx = arr[i]->idx;
            k++;
        }
        else{
            if(arr[i]->data>arr[i+1]->data){
                arr[i]->data = abs_val(arr[i]->data, a*(arr[i]->data-arr[i+1]->data));
                arr[k]->data=arr[i]->data;
                arr[k]->idx = arr[i]->idx;
                k++;

            }
            else if(arr[i]->data<arr[i+1]->data){
                arr[i+1]->data = abs_val(arr[i+1]->data, a*(arr[i+1]->data-arr[i]->data));
                arr[k]->data=arr[i+1]->data;
                arr[k]->idx = arr[i+1]->idx;
                k++;
            }
        }
        
    }
    kprev=k;
    if(k==1){
        printf("%lld %lld",arr[0]->idx,arr[0]->data);
        break;
    }
    if(k==0){
        printf("-1 -1");
        break;
    }
}


   return 0;
}