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

   int n,k,x;
   scanf("%lld %lld %lld",&n,&k,&x);
   int arr[n];
   int r[k];
   int sum=0;
      int psum[n];
      for (int i = 0; i < n; ++i)
      {
      	psum[i]=0;
      }

   for (int i = 0; i < n; ++i)
   {
   	scanf("%lld",&arr[i]);
   	sum+=arr[i];
   	psum[i]=sum;
   }
   for (int i = 0; i < k; ++i)
   {
   	scanf("%lld",&r[i]);
   	sum-=arr[r[i]];
   }
   int mx=0;
   int start=0,end=n-1;
   for (int i = 0; i < k; ++i)
   {
   	 int l=i,rt=k-1;
   	 int f = r[i]+x-1;
   	 int flg=0;
   	 while(l<rt){
   	     flg=1;
   	 	int m = l + (rt-l)/2;
   	 	if(f<=r[m]){
   	 		rt=m;
   	 	}
   	 	else{
   	 		l=m+1;
   	 	}
   	 }
   	 if(r[l]>f){
   	     l--;
   	 }
   	 //printf("%lld ",l);
   	 if(psum[r[l]]-psum[r[i]]+arr[r[i]]>mx){
   	 	mx = psum[r[l]]-psum[r[i]]+arr[r[i]];
   	 	start = r[i];
   	 	end= r[l];
   	 }
   	 printf("%lld %lld %lld\n",mx,r[i],r[l]);

   }
   int s = psum[n-1];
   for (int i = 0; i < k; ++i)
   {
   	    if(r[i]<start||r[i]>end){
        s-=arr[r[i]];   	}
   }
   printf("%lld %lld",sum,s);


   return 0;
}