#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;
int result[26]={-1};
int i1=0,i2=0;
int l_sum,r_sum,l_mx,r_mx;

void f1(int arr[],int idx1,int n,int lvl){
    if(idx1>=n||(arr[idx1]==-1)){
       return;
    }
    //printf("%lld ",arr[idx1]);
    if(lvl>l_mx){
        //printf("%lld ",arr[idx1]);
        if(arr[idx1]>=0){
                   // printf("%lld ",arr[idx1]);

        l_sum += arr[idx1];
        l_mx=lvl;}
    }
    f1(arr,2*idx1+1,n,lvl+1);
    f1(arr,2*idx1+2,n,lvl+1);
    
}
void f2(int arr[],int idx2,int n,int lvl){
    if(idx2>=n||(arr[idx2]==-1)){
     
       return;
    }

    if(lvl>r_mx){
                    printf("%lld ",arr[idx2]);

        if(arr[idx2]>=0){
        r_sum += arr[idx2];
        r_mx=lvl;}
    }

        f2(arr,2*idx2+2,n,lvl+1);
       f2(arr,2*idx2+1,n,lvl+1);

    
}

 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/

 int n;
 scanf("%lld",&n);
 int arr[n];
 for(int i=0;i<n;i++){
     scanf("%lld",&arr[i]);
 }
 f1(arr,0,n,1);
 f2(arr,0,n,1);

 printf("%lld %lld",l_sum,r_sum);



 
 





   return 0;
}