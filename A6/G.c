#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;
int result[26]={-1};
int i1=0,i2=0;
int l1[10000],l2[10000];
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

void f1(int arr[],int idx1,int n){
    if(2*idx1+1>=n){
       l1[i1]=arr[idx1];
       i1++;
       return;
    }
    if(arr[2*idx1+1]==-1&&arr[2*idx1+2]==-1){
        l1[i1]=arr[idx1];
       i1++;
       return;
        
    }
    f1(arr,2*idx1+1,n);
    f1(arr,2*idx1+2,n);
    
}
void f2(int arr[],int idx2,int n){
    if(2*idx2+1>=n){
       l2[i2]=arr[idx2];
       i2++;
       return;
    }
    if(arr[2*idx2+1]==-1&&arr[2*idx2+2]==-1){
        l2[i2]=arr[idx2];
       i2++;
       return;
        
    }
    f2(arr,2*idx2+1,n);
    f2(arr,2*idx2+2,n);
    
}

 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/

 int n,a,b;
 scanf("%lld%lld%lld",&n,&a,&b);
 int idx1=-1,idx2=-1;
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
if(idx1==-1||idx2==-1){
	printf("-1");
	return 0;
}
int min_hamming=MAX;
f1(arr,idx1,n);
f2(arr,idx2,n);
/*for(int i=0;i<i1;i++){
    printf("%lld ",l1[i]);
}
printf("\n");
for(int i=0;i<i2;i++){
    printf("%lld ",l2[i]);
}*/

for (int i = 0; i < i1; ++i)
{
	for (int j=0;j<i2; ++j)
	{
	    if(l1[i]>0&&l2[j]>0){
		if(hamming(l1[i],l2[j])<min_hamming){
			min_hamming=hamming(l1[i],l2[j]);
		}}
	}
}

printf("%lld", min_hamming);


 
 





   return 0;
}