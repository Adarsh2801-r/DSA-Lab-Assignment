
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 1e6;

struct Node 
{ 
    char data; 
    struct Node *next; 
    struct Node *prev; 
}; 

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
	long long int freq[10]={0};
	for (long long int i = a;i<=b;i++)
	{
		if(isPrime[i]==0){
			long long int x=i;
			while(x){
				freq[x%10]++;
				x/=10;

			}
		}
	}
	long long int mx=0,m_num=0;
	for (int i = 0; i < 10; ++i)
	{
		if(freq[i]>mx){
			mx = freq[i];
			m_num=i;
		}
	}
	printf("%lld %lld",m_num,mx);

	


//	printf("%c",head->next->next->next->data);
	




   return 0;
}