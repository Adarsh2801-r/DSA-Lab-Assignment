#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;

int max(int a,int b){
    return a>b?a:b;
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
    int mx=0,sum=0;
    
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==0){
                mx=max(mx,j-i+1);
            }
        }
    }
    printf("%lld",mx);
    
    return 0;
}