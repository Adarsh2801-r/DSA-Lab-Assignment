#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define int long long
const int MAX = 1e6;
const int mod = 1e9 + 7;

int main() {
   // printf() displays the string inside quotation
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif
	int n;
	scanf("%lld",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	int b;
	scanf("%lld",&b);
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]>a[i]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	int x=0,y=n-1;
	int cou=0;
	while(x<=y){
		
		if(a[x]+a[y]<=b){
			x++;
			y--;
		}
		else{
			x++;
		}
		cou++;
	}
	printf("%lld",cou);





	


	




   return 0;
}