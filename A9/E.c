#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const double DOUBLE_MAX = 1e9;
int result[26]={-1};


struct node{
	int data;
	struct node*next;

};

struct adjList{
	struct node* head;
};

int dfs(int src,int dest,int visited[],int sub[],int check_sb[],struct adjList* adj){
	visited[src]=1;
	sub[src]=1;
	if(src==dest){
		check_sb[src]=1;
	}
	else{
		check_sb[src]=0;
	}
    struct node*t = adj[src].head;
    //printf("%lld---",t->data);
   	while(t){
   	   	if(!visited[t->data]){
   	   	sub[src]+= dfs(t->data,dest,visited,sub,check_sb,adj);
   	   	check_sb[src]=check_sb[src]|check_sb[t->data];
   	   }
   	   	t = t->next;
   	}
   	return sub[src];

}




 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/

   int n,x,y;
   scanf("%lld%lld%lld",&n,&x,&y);
   int tot_paths= n*(n-1);
   int sub[100000];
   int visited[100000]={0};
   int check_sb[100000];
   int sub_y;
   struct adjList* adj = (struct adjList*)malloc(n*sizeof(struct adjList));
   for(int i=0;i<n-1;i++){
   	int u,v;
   	scanf("%lld%lld",&u,&v);
   	u--;
   	v--;
   	struct node* new = (struct node*)malloc(sizeof(struct node));
   	new->data = v;
   	new->next = adj[u].head;
   	adj[u].head = new;

   	struct node* new1 = (struct node*)malloc(sizeof(struct node));
   	new1->data = u;
   	new1->next = adj[v].head;
   	adj[v].head = new1;   }
    
    x--;
    y--;
    
   dfs(y,x,visited,sub,check_sb,adj);
  
      
   	struct node*t = adj[y].head;
   	   while(t){
   	   	if(check_sb[t->data]){
   	   	sub_y = n - sub[t->data];
        break;
   	   }
   	   	t = t->next;
   	   }

printf("%lld",tot_paths- sub_y*sub[x]);






   


   return 0;
}