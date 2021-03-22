#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;



 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int n;
    scanf("%lld",&n);
    char s[n];
    scanf("%s",s);
    int cou[8]={0};
  
    for (int i = 0; i < n; ++i)
    {
    	cou[s[i]-'A']++;
    }
 
    int l=0,r=n-1;
    int left=0,right=n-1;
    while(1){
        //printf("w1%lld %lld\n",l,r);

    	if((--cou[s[l]-'A'])>0){
    		l++;
    	}
    	if(cou[s[l]-'A']<=0){
    	    left=l;
    		break;

    	}
    	
    }
    while(1){
        //printf("w2%lld %lld\n",l,r);

    	if((--cou[s[r]-'A'])>0){
    		r--;
    	}
    	if(cou[s[r]-'A']<=0){
    	    right=r;
    		break;

    	}
    	
    }
    printf("%lld",right-left+1);
    





    







   return 0;
}