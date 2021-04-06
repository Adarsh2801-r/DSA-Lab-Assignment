#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;
int result[26]={-1};
int cou=0;

 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/

    int n;
    scanf("%lld",&n);
    int f=0;
    if(n<0){
    	f=1;
    	n*=-1;
    }
    int c=0;
    for (int i = 1; i*i*i <= n; ++i)
    {
    	//printf("%lld ",arr[i]);
    	c++;
    }
        int arr[c+1];

    for (int i = 1; i*i*i <= n; ++i)
    {
    	arr[i]=i*i*i;
    	//printf("%lld ",c);
    }
    int l=1,r=c;

    while(l<r){
    	int m = l + (r-l)/2;
    	if(arr[m]<n){
    		l=m+1;
    	}
    	else{
    		r=m-1;
    	}
    }
    if(f){
    	printf("%lld",-(l));
    	return 0;
    }
    printf("%lld",l);
  

   return 0;
}