#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;
int result[26]={-1};
struct node{
	int d;
	int idx;
};

int hamming(int x,int y){
	int ans = x^y;
	int dist=0;
	while(ans>0){
		dist+= (ans&1);
		ans>>=1;	
	}
	return dist;
	
}

 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/

 int n,a,b;
 scanf("%lld%lld%lld",&n,&a,&b);
 int idx1=0,idx2=0;
 int arr[n];

 for (int i = 0; i < n; ++i)
 {
 	scanf("%lld",&arr[i]);
 	if(arr[i]==a){
 		idx1=i;
 	}
 	if(arr[i]==b){
 		idx2=i;
 	}
 }
 int a1[n],a2[n];
 while(2*idx1+1<n&&(arr[2*idx1+1]!=-1||arr[2*idx1+2]!=-1)){
     
 	idx1=2*idx1+1;
 }
  while(2*idx2+1<n&&(arr[2*idx2+1]!=-1||arr[2*idx2+2]!=-1)){
 	idx2=2*idx2+1;
 }
 printf("%lld %lld\n",idx1,idx2);
 int x[2]={0};
 int y[2]={0};
 if(arr[idx1]!=-1){
 x[0]=arr[idx1];}
 if(arr[idx1+1]!=-1&&arr[idx1]!=a){
 x[1]=arr[idx1+1];}
 if(arr[idx2]!=-1){
 y[0]=arr[idx2];}
 if(arr[idx2+1]!=-1&&arr[idx2]!=b){
  y[1]=arr[idx2+1];
}
int min_hamming=MAX;

for (int i = 0; i < 2; ++i)
{
	for (int j=0;j<2; ++j)
	{
	    if(x[i]>0&&y[j]>0){
		if(hamming(x[i],y[j])<min_hamming){
			min_hamming=hamming(x[i],y[j]);
		}}
	}
}
if(min_hamming==0){
	printf("-1");
	return 0;
}
printf("%lld", min_hamming);


 
 





   return 0;
}