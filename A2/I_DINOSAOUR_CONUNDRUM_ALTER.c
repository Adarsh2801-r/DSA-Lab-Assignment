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
   #endif   */
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
  
   int ans=0;
   for(int i=0;i<36;i++){
      if(count[i]>c&&count[i]>0){
         int x = count[i]/c;
         int r = count[i]%c;
         ans += c*(((x*(x-1))/2) + r*(((x)*(x+1))/2));
      }

   }
   printf("%lld",ans);




  

  







   


// printf("%c",head->next->next->next->data);
   




   return 0;
}