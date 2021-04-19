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

int parity(int a,int b){
	int d_a=0,d_b=0;
	int ta=a,tb=b;
	int arr1[10]={0},arr2[10]={0};
	int i1=0,i2=0;
	while(ta){
		d_a++;
		arr1[i1]=ta%10;
		ta/=10;
		i1++;
	}
	while(tb){
		d_b++;
		arr2[i2]=tb%10;
		tb/=10;
		i2++;
	}
	
	for (int i = 0; i < 10; ++i)
	{
       if(arr1[i]%2!=arr2[i]%2){
       	return 0;
       }
	}
	return 1;

}





 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
   int n;
   scanf("%lld",&n);
   int t=n;
   while(t--){
   	char s[10];
   	scanf("%s",s);
   	int x;
   	scanf("%lld",&x); 
   	if(strcmp(s,"add")==0){
   		push(x);
   	}  

   	if(strcmp(s,"delete")==0){
   		int idx=0;
   		for(int i=0;i<size();i++){
   			if(stack[i]==x){
   				idx=i;
   				break;
   			}
   		}
        int temp=stack[idx];
        stack[idx]=stack[t1];
        stack[t1]=temp;
   		pop();
   	}

   	if(strcmp(s,"query")==0){
   		int cou=0;
   		for(int i=0;i<size();i++){
   			cou+=parity(stack[i],x);
   		}
   		printf("%lld\n",cou);
      
   		
   	}


   }





   return 0;
}