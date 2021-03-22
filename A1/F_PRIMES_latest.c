
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

const int MAX = 1e6;


int main() {
   // printf() displays the string inside quotation
    long long int a,b;
	scanf("%lld %lld",&a,&b);
	int isPrime[1000000+1]={0};
	for (long long int i = 2; i*i<= MAX; ++i)
	{
		if(isPrime[i]==0){
			for (long long int j=2*i;j<=MAX;j+=i)
			{
				isPrime[j]=1;
			}


		}
	}
	long long int c=0;
	for(long long int i=2;i<=MAX;i++){
		if(isPrime[i]==0){
			c++;
		}
	}
	int num_primes[c];
	int x=0;
	for(long long int i=2;i<=MAX;i++){
		if(isPrime[i]==0){
			num_primes[x]=i;
			x++;
		}
	}
	long long int range[b-a+1];
	for(long long int i=0;i<=b-a;i++){
		range[i]=0;
	}
	for(long long int i=0;i<c;i++){
		if(num_primes[i]*num_primes[i]>b){
			break;
		}

		long long int r = floor(a/num_primes[i])*num_primes[i];
		if (r < a) {
			r += num_primes[i];
		}

		if (r == num_primes[i]){
			r += num_primes[i];
		}

		for (long long int j = r; j <= b; j+=num_primes[i]) {
			range[j-a] = 1;
		}




	}

	c=0;
	for(long long int i=0;i<=b-a;i++){
		if(range[i]==0){
			c++;
		}
	}
	long long int arr[c];
	x=0;

	for(long long int i=0;i<=b-a;i++){
		if(range[i]==0){
			arr[x]=i+a;
			x++;
		}
	}
	long long int freq[10]={0};
	for(long long int i=0;i<c;i++){
		long long int t=arr[i];

		while(t){
			freq[t%10]++;
			t/=10;
		}
	}
	x=0;
	for(long long int i=0;i<10;i++){
		if(freq[i]>freq[x]){
			x=i;
		}
	}
	printf("%d %lld",x,freq[x]);
	
	




   return 0;
}