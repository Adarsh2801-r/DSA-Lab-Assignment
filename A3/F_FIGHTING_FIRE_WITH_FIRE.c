#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;
int visited[100000];

struct node{
	int data;
	struct node*next;
};

struct adjList{
	struct node*head;
};

void merge(int arr[],int l,int m,int r){
	int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }


}

void mergeSort(int arr[],int l,int r){
	if(l<r){
		int mid = (l+r)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);

	}

}

void dfs(int i,struct adjList*adj){
	visited[i]=1;
   	struct node*t = adj[i].head;
   	while(t){
   	   	if(!visited[t->data]){
   	   	dfs(t->data,adj);}
   	   	t = t->next;}
}









 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif	*/


    int n,m;
    scanf("%lld %lld",&n,&m);
    struct adjList*adj = (struct adjList*)malloc(n*sizeof(struct adjList));
    for (int i = 0; i < m; ++i)
    {
    	int x,y;
    	scanf("%lld %lld",&x,&y);
    	struct node * t = (struct node*)malloc(sizeof(struct node));
    	t->data = x;
    	t->next = adj[y].head;
    	adj[y].head = t;

    	struct node * t1 = (struct node*)malloc(sizeof(struct node));
    	t1->data = y;
    	t1->next = adj[x].head;
    	adj[x].head = t1;



    }
    int comp[n];
    for (int i = 0; i < n; ++i)
    {
    	comp[i]=0;
    }
    int cou=0,k=0;
    for(int i=0;i<n;i++){
    	if(!visited[i]){
    		dfs(i,adj);
    		cou++;
    		comp[k]=cou;
         	k++;
    	}
    	

    }
    int num=80*n;
    int threshold = (80*n)/100 + 1;
   mergeSort(comp,0,n-1);

    int sum=0;
    for(int i=0;i<n;i++){
        printf("%lld ",comp[i]);
    }
    for (int i = 0; i < n; ++i)
    {
    	sum+=comp[i];
    	if(sum>=threshold){
    		printf("%lld",i+1);
    		break;
    	}
    }

	

	




   return 0;
}