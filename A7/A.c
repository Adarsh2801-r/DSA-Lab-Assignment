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
   for (int i = 0; i < n; ++i)
   {
    scanf("%lld",&arr[i]);
   }
   push(1);
   printf("-1 ");
   for (int i = 1; i < n; ++i)
   {
     //printf("%lld %lld\n",size(),top());   
    while(size()>0&&arr[top()-1]>=arr[i]){
          pop();
     }
     if(size()<=0){
      printf("-1 ");
     }
     else{
         printf("%lld ",top());
     }
     push(i+1);

   }





   return 0;
}