#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;
int result[26]={-1};
int stack[1000000];

int t1=-1,t2=-1;
void push(int x){
    t1++;
    stack[t1]=x;
}

void pop(){
    t1--;
}
int top(){
    return stack[t1];
}

int size(){
    return t1+1;
}





 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
   int n;
   scanf("%lld",&n);
   int arr[n];
   int left[n],right[n];
   for (int i = 0; i < n; ++i)
   {
    scanf("%lld",&arr[i]);
   }
   push(0);
   left[0]=-1;
   for (int i = 1; i < n; ++i)
   {
     //printf("%lld %lld\n",size(),top());   
    while(size()>0&&arr[top()]>=arr[i]){
          pop();
     }
     if(size()<=0){
      left[i]=-1;
     }
     else{
     	left[i]=top();
     }
     push(i);

   }
   t1=-1;
   push(n-1);
   right[n-1]=n;
   for (int i = n-2;i>=0; --i)
   {
   	  while(size()>0&&arr[top()]>=arr[i]){
   	  	pop();
   	  }
   	  if(size()<=0){
      right[i]=n;
     }
     else{
     	right[i]=top();
     }
     push(i);

   }
   int w[n+1];
   for(int i=0;i<=n;i++){
       w[i]=0;
   }
   for(int i=0;i<n;i++){
       int len = right[i]-left[i]-1;
       if(arr[i]>=w[len]){
           w[len]=arr[i];
       }
   }
   for(int i=n-1;i>=0;i--){
       if(w[i+1]>=w[i]){
           w[i]=w[i+1];
       }
   }
   int mx=-1;
   for(int i=1;i<=n;i++){
       if(i*w[i]>mx){
           mx=i*w[i];
       }
   }
   /*for(int i=0;i<n;i++){
   	printf("%lld----%lld\n",left[i],right[i]);
   }*/
   printf("%lld",mx);







   return 0;
}