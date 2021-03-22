#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;
int result[26]={-1};



 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int m;
    scanf("%lld",&m);
    int arr[m];
    for (int i = 0; i < m; ++i)
    {
    	scanf("%lld",&arr[i]);
    }
    int mx=0,mn=MAX;
    for (int i = 0; i < m; ++i)
    {
    	if(arr[i]>mx){
    		mx=arr[i];
    	}
    	if(arr[i]<mn){
    		mn=arr[i];
    	}
    }
    int mx_cou=0,mn_cou=0;
    for (int i = 0; i < m; ++i)
    {
    	if(arr[i]==mx){
    		mx_cou++;
    	}
    	if(arr[i]==mn){
    		mn_cou++;

    	}  
    }
    if(mx!=mn){
    printf("%lld %lld",mx-mn,mx_cou*mn_cou);
        
    }
    else{
        printf("%lld %lld",mx-mn,(m*(m-1))/2);
    }




   return 0;
}