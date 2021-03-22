#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;
const int mod = 1e9 + 7;
int cou=0;
double prob=1.0;
    double outdeg[100000];
        double indeg[100000];

    int v[100000];

struct node{
	int data;
	struct node*next;
};

struct adjList{
	struct node*head;
};

struct node1{
    double d;
    int w;
};

void merge(struct node1 *arr[],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    double L[n1], R[n2];
    int l1[n1],r1[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]->d;
        l1[i]=arr[l+i]->w;
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j]->d;
        r1[j]=arr[m+j+1]->w;
    }
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k]->d = L[i];
            arr[k]->w = l1[i];
 
            i++;
        }
        else {
            arr[k]->d = R[j];
            arr[k]->w= r1[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k]->d = L[i];
        arr[k]->w = l1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k]->d = R[j];
        arr[k]->w = r1[j];
        
        j++;
        k++;
    }


}

void mergeSort(struct node1* arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);

    }

}
void dfs(int s,int d,struct adjList*adj,int visited[],int init){
	visited[s]=1;
	
		

	
	v[cou]=s;
	cou++;
	if(s==d){
	    for(int k=0;k<cou;k++){
	        //printf("%lld ",v[k]);
	        
	        prob *= (indeg[v[k]]);
	    }
	    return;

	}
	
	struct node*t = adj[s].head;
   	while(t){
   	   	if(!visited[t->data]){
   	   	dfs(t->data,d,adj,visited,init);}
   	   	t = t->next;}
   	
	cou--;
	visited[s]=0;

}


 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int n,m,s;
    scanf("%lld %lld %lld",&n,&m,&s);
    for(int i=0;i<n;i++){
    	outdeg[i]=0.0;
    }
    struct adjList*adj = (struct adjList*)malloc(n*sizeof(struct adjList));
    for (int i = 0; i < m; ++i)
    {
    	int x,y;
        double w;
    	scanf("%lld %lld %lf",&x,&y,&w);
    	struct node * t = (struct node*)malloc(sizeof(struct node));
    	t->data = y;
    	t->next = adj[x].head;
    	adj[x].head = t;
    	outdeg[x]+=w;
    	indeg[y]=w;
    }
    indeg[s]=1;

    double result[n];
        	
   int init = s;
    for(int i=0;i<n;i++){
    	prob=1;
    	cou=0;
    	int visited[100000]={0};

        	dfs(s,i,adj,visited,init);
    	//printf("\n");
    	prob *= (1-outdeg[i]);
    	result[i]=prob;
    }
    /*for(int i=0;i<n;i++){
   	  printf("%lld -> ",i);
   	   struct node*t = adj[i].head;
   	   while(t){
   	   	printf("%lld,%lf",t->data,indeg[t->data]);
   	   	t = t->next;
   	   }
   	   printf("----%lf\n",result[i]);


   }*/
   struct node1 * arr[n];
        for (int i = 0; i < n; ++i)
        {
            arr[i]=(struct node1*)malloc(sizeof(struct node1));
            arr[i]->d=result[i];
            arr[i]->w=i;
            
        }
        mergeSort(arr,0,n-1);
   for (int i = 0; i < n; ++i)
        {
            printf("%lld ",arr[i]->w);
        }

   // printf("%lf",adj[1].head->wt);






    


    




   return 0ll;
}