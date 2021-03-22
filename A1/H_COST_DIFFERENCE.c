#include <stdio.h>
const long long int MAX = 1e18;
const long long int MIN = -1e18;


int main() {
   // printf() displays the string inside quotation
   int n;
   scanf("%d",&n);
   int a[n],b[n];
   for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
      b[i]=a[i];
   }
   long long int max=MIN,min=MAX;
   for(int i=0;i<n;i++){
      long long int sq=0,cub=0;
      for(int j=0;j<n;j+=2){
         sq += a[j]*a[j];
      }
      for(int j=1;j<n;j+=2){
         cub += a[j]*a[j]*a[j];
      }
      if(sq-cub > max){
         max= sq-cub;

      }
      if(sq-cub < min){
         min= sq-cub;

      }
      a[0]=b[n-1];
      for (int j = 1;j<n; ++j)
      {
         a[j]=b[j-1];
         
      }
      for (int j = 0;j<n; ++j)
      {
         b[j]=a[j];
         
      }
   }
   printf("%lld",max-min);

   return 0;
}