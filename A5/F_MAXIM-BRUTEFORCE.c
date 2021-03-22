#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 1e9;
int result[26]={-1};
int cou_low=1;
int cou_up=1;
int visited[100000];
struct node{
	int data;
	struct node* next;

};

struct adjList{
	struct node * head;

};
/*void merge(struct node *arr[],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int l1[n1],r1[n2];
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]->b;
        l1[i]=arr[l+i]->a;
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j]->b;
        r1[j]=arr[m+j+1]->a;
    }
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k]->a = L[i];
            arr[k]->b = l1[i];
            i++;
        }
        else if(L[i]>R[j]){
            arr[k]->a = R[j];
            arr[k]->b= r1[j];
            j++;
        }
        else{
        	if (l1[i] < r1[j]) {
            arr[k]->a = L[i];
            arr[k]->b = l1[i];
            i++;
        }
        else if(l1[i]>r1[j]){
            arr[k]->a = R[j];
            arr[k]->b= r1[j];
            j++;
        }

        }
        k++;
    }
    while (i < n1) {
        arr[k]->a = L[i];
        arr[k]->b = l1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k]->a = R[j];
        arr[k]->b = r1[j];
        j++;
        k++;
    }


}

void mergeSort(struct node* arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);

    }

}*/

void dfs(struct adjList*adj,int n){
     
	for(int k=0;k<n-1;k++){
      int min = MAX;
	  for (int j=0;j<n; ++j)
	  {
	      
	      if(visited[j]){
	  	
	  		struct node*t = adj[j].head;
   	   while(t){
   	       //printf("%d ",t->data);
   	   	if(visited[t->data]==0){
   	       if(t->data<min){
   	       	min=t->data;

   	       }
   	   	    
   	   	}
   	       t=t->next;
   	   }
   	       
   	   }


	  	}
	  	visited[min]=1;
	  	printf("%d ",min+1);


	  }


	  
}


 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int n,m;
    scanf("%d%d",&n,&m);
    struct adjList * adj = (struct adjList*)malloc(n*sizeof(struct adjList));

    for (int i = 0; i < m; ++i)
    {
    	int x,y;
    	scanf("%d%d",&x,&y);
    	struct node* new = (struct node*)malloc(sizeof(struct node));
   	new->data = y-1;
   	new->next = adj[x-1].head;
   	adj[x-1].head = new;

   	struct node* new1 = (struct node*)malloc(sizeof(struct node));
   	new1->data = x-1;
   	new1->next = adj[y-1].head;
   	adj[y-1].head = new1;

    }
    visited[0]=1;
    /*for(int i=0;i<n;i++){
   	  printf("%lld -> ",i);
   	   struct node*t = adj[i].head;
   	   while(t){
   	   	printf("%lld ",t->data);
   	   	t = t->next;
   	   }
   	   printf("\n");


   }*/
   printf("1 ");
    dfs(adj,n);





   return 0;
}