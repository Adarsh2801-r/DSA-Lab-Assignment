#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;
int result[26]={-1};
int queue[500000];
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

int bs(int x){
    int low = f1, high = r1 - 1;
     while (low <= high)
    {
        int mid = (low + high)/2;
        if (x == queue[mid]) {
            return 1;
        }
        else if (x < queue[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
     return 0;
}
    


int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/

    int n;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%lld",&x);
        enqueue1(x);
    }
     
    int num;
    scanf("%lld",&num);
    int min=MAX;
    for(int i=f1;i<r1;i++){
        if(queue[i]<min){
            min=queue[i];
        }
    }
    while(front1()!=min){
        int t=front1();
        dequeue1();
        enqueue1(t);
    }
    while(num--){
        int q;
        scanf("%lld",&q);
        if(bs(q)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    


    	    
 



   return 0;
}