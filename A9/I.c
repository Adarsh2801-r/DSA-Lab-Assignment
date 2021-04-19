#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const double DOUBLE_MAX = 1e9;
int result[26]={-1};

int cmp(const void* p, const void* q) { return *((int*) p) - *((int*) q);}





 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/

   int n,k;
   scanf("%lld%lld",&n,&k);
   int arr[n];
   for (int i = 0; i < n; ++i)
   {
   scanf("%lld",&arr[i]);
   }
   qsort(arr, n, sizeof(int), cmp);
   int mn=MAX;
   for (int i = 0; i < n; ++i)
   {
   	int j=0;
   	int cou=1;
   	int end = arr[i]+k;
   	while(j<n){
   		int corr = (i+j)>=n?360:0;
        if(arr[(i+j)%n]+corr>end){
        	cou++;
        	end = arr[(i+j)%n]+corr+k;
        }
        j++;
   	}
   	if(cou<mn){
   		mn=cou;
   	}
   }
   printf("%lld",mn);







   


   return 0;
}