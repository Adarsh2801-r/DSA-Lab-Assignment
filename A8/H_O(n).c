#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
#define SIZE 200000

const int MAX = 1e9;

struct items {
   int data;   
   int key;
};

struct items* hashArray[SIZE]; 
struct items* dummyItem;
struct items* item;

int hashCode(int key) {
   return key % SIZE;
}

struct items *search(int key) {
   int hashIndex = hashCode(key);  
	
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 
			
      ++hashIndex;
		
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert(int key,int data) {

   struct items *item = (struct items*) malloc(sizeof(struct items));
   item->data = data;  
   item->key = key;

   int hashIndex = hashCode(key);

   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      ++hashIndex;
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}

int max(int a,int b){
    return a>b?a:b;
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
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    int sum=0,len=0;
    for (int i = 0; i < n; ++i)
    {
    	sum += arr[i];
    	if(arr[i]==0&&len==0){
    		len=1;
    	}
    	if(sum==0){
    		len = i+1;
    	}
    	item=search(sum);
    	if(item !=NULL){
    		len = max(len,i-item->data);
    	}
    	else{
    		insert(sum,i);
    	}
    }
    printf("%lld",len);
    return 0;
}