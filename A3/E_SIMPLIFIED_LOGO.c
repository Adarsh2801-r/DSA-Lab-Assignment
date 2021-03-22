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
    #endif */ 

    int n;
    scanf("%lld",&n);
    int sum=0;
    int m=1;
    int cou1=0,cou2=0;
    int arr[10000]={0};
            int x;
            int k=0;
   int d[n];
   
    while(n--){
        char s[32];
        scanf("%s",s);
        if(strcmp(s,"END")){
                    scanf("%lld",&x);

        }
        if(strcmp(s,"FD")==0){
            sum += m*x;
        }
        else if(strcmp(s,"LOOP")==0){
            m*=x;   
            d[k++]=x;
        }
        else if(strcmp(s,"END")==0){
            m/=d[--k];
        }

    }
    printf("%lld",sum);
  






    


//  printf("%c",head->next->next->next->data);
    




   return 0;
}