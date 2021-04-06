#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 1e9;
int result[26]={-1};
int cou=0;

int f(int arr[],int r){
	if(r<0){
		return cou;
	}
	int mx=0,idx=r;
	for (int i = 0; i <= r; ++i)
	{ 
		if(arr[i]>=mx){
			mx=arr[i];
			idx=i;
		}
		
	}
	cou++;
	printf("%d %d\n",mx,idx);
	f(arr,idx-1);



}
 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
    	scanf("%d",&arr[i]);
    }
    printf("%d",f(arr,n-1));
  

   return 0;
}