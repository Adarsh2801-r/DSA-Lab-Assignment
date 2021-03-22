#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;
 
int main() {
   
   int n,c;
   scanf("%lld %lld",&n,&c);
   char s[21];
   int count[36]={0};
   for(int i=0;i<n;i++){
      scanf("%s",s);
      if(s[0]>='A'&&s[0]<='Z'){
      count[s[0]-'A']++;}
      else{
         count[26+s[0]-'0']++;
      }
   }
   int t=c;
   while(t--){
      for(int i=0;i<36;i++){
         if(count[i]){
            count[i]--;
         }
      }
   }
   int ans=0;
   for(int i=0;i<36;i++){
      if(count[i]<=c&&count[i]>0){
         ans+=count[i];

      }
      else if(count[i]>c&&count[i]>0){
         int x = count[i]/c;
         int r = count[i]%c;
         if(c==1){
            ans += (x*(x+1))/2;
         }
         else{
         ans += ((c - r)*((x*(x+1))/2) + r*(((x+1)*(x+2))/2));}
      }

   }
   printf("%lld",ans);




  

  







   


   




   return 0;
}