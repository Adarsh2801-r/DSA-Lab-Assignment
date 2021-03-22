
#include <stdio.h>
const int mod = 1e6;

struct node{
   char data;
    struct node * next;
    struct node * prev;
};

int main() {
   // printf() displays the string inside quotation
   long long int m;
   scanf("%d",&m);
   int n;
   scanf("%d",&n);
   long long int p[n];
   for (int i = 0; i < n; ++i)
   {
      scanf("%lld",&p[i]);
   }
   for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
         if(p[j]<p[i]){
            long long int t=p[i];
            p[i]=p[j];
            p[j]=t;
         }
      }
   }
   long long int cost=0;
   int x=0;
   for(int i=0;i<n;i++){

      cost += p[i];
         printf("%d ",p[i]);

      if(cost>m){
         cost-=p[i];
         x=i;
         break;
      }
      if(i==n-1){
          x=i+1;
          break;
      }
   }
   printf("%d",x);

   return 0;
}