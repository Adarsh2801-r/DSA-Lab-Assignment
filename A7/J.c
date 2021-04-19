#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;

int queue[100000];
int queue2[100000];

int f1,r1;
int f2,r2;
int n;

int size1(){
	return (-f1+r1);
}
int isEmpty1(){
	return f1==r1;
}
int front1(){
	return queue[f1];
}
void dequeue1(){
	for(int i=0;i<r1-1;i++){
	    queue[i]=queue[i+1];
	}
	r1--;
}
void enqueue1(int x){
	queue[r1]=x;
	r1=(r1+1);
}


int size2(){
	return (-f2+r2);
}
int isEmpty2(){
	return f2==r2;
}
int front2(){
	return queue2[f2];
}
void dequeue2(){
	for(int i=0;i<r2-1;i++){
	    queue2[i]=queue2[i+1];
	}
	r2--;
}
void enqueue2(int x){
	queue2[r2]=x;
	r2=(r2+1);
}

int h(int x){
    x=x%65535;
    x*=(x+13);
    x=x%65535;
    return x;
}

 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
   scanf("%lld",&n);
   int arr[n];
   for (int i = 0; i < n; ++i)
     {
     	scanf("%lld",&arr[i]);
     	enqueue1(arr[i]);
     }  
    int cou=0;
    int b=1;
    while(1){
        printf("%lld %lld-",size1(),size2());
        for(int i=f1;i<r1;i++){
            printf("%lld ",queue[i]);
        }
        printf("------");
         for(int i=f2;i<r2;i++){
            printf("%lld ",queue2[i]);
        }
        printf("\n");
    	if(b){
    	    while(size1()){
    		int x1=front1();
    		dequeue1();
            int x2=1;
    		if(size1()){
    		x2=front1();
    		dequeue1();}
    		enqueue2(h(x1*x2));}
    		
    	}
    	else{
    	    while(size2()){
    		int x1=front2();
    		dequeue2();
            int x2=1;
    		if(size2()){
    		x2=front2();
    		dequeue2();}
    		enqueue1(h(x1*x2));}
    		
    	}
    	b^=1;
    	if((isEmpty1()&&size2()==1)){
    		printf("%lld",front2() );
    		break;
    	}
    	if((isEmpty2()&&size1()==1)){
    		printf("%lld",front1());
    		break;
    	}

    }
    





   return 0;
}