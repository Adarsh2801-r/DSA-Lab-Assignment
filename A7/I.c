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

    int n,l;
    scanf("%lld%lld",&n,&l);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld",&arr[i]);
    }
    int s[n];
    int pref[n];
    int sm=0;
    for (int i = 0; i < n; ++i)
    {
                scanf("%lld",&s[i]);
                sm+=s[i];
                pref[i]=sm;

    }
    int mx[n];
    mx[0]=s[0];
    int sum=0;
    int idx=-1;
    for (int i = 1; i < n; ++i)
    {
        if(arr[i]>arr[0]+l){
            idx=i;
            break;
        }
        mx[i]=max(mx[i-1],s[i]);
        
    }
    if(idx==-1){
        idx=n;
    }
    
    
    for(int i=idx;i<n;i++){
        int id=i;
        for(int j=0;j<i;j++){
            if(arr[i]-arr[j]<=l){
                id=j;
                break;
            }
        }
        mx[i]= max(s[i]+mx[id-1],s[i]);
        
    }
    int m=-1;
    for(int i=0;i<n;i++){
        if(mx[i]>m){
            m=mx[i];
        }
    }
    printf("%lld",m);






   return 0;
}