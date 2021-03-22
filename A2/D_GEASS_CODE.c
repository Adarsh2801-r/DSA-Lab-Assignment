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
	int n,m;
	scanf("%lld %lld",&n,&m);
	int p[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&p[i]);
	}
	int a[m];
	for(int i=0;i<m;i++){
		scanf("%lld",&a[i]);
	}
	int i=0,j=0,x=0;
	while(i<n-m+1){
		p[j]*=(a[x]);
		j++;
		x++;
		if(x==m){
			i++;
			j=i;
			x=0;

		}
	}
	for(int i=0;i<n;i++){
		printf("%lld ",p[i]%mod);
	}
  







	


	




   return 0;
}