#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;

int visited[5000];
int min = 1e6;
   int path_index=0;

struct node{
	int data;
	struct node*next;


};

struct adjList{
    struct node*head;
};

void dfs(int s,int d,struct adjList*adj,int n){

	visited[s]=1;
	path_index++;



	if(s==d){

		

		if(path_index<min){
			min=path_index;
		}
	

	}
	else{
	
   	   struct node*t = adj[s].head;
   	   while(t){
   	   	if(!visited[t->data]){
   	   	dfs(t->data,d,adj,n);}
   	   	t = t->next;
   	   }

}
   path_index--;
   visited[s]=0;


}
 
int main() {
   // printf() displays the string inside quotation
   #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif	
   int n,m,s,t;
   scanf("%lld %lld %lld %lld",&n,&m,&s,&t);
   struct adjList * adj = (struct adjList*)malloc(n*sizeof(struct adjList));
   for(int i=0;i<n;i++){
   	adj[i].head=NULL;
   } 

   for(int i=0;i<m;i++){
   	int x,y;
   	scanf("%lld %lld",&x,&y); 
   	struct node* new = (struct node*)malloc(sizeof(struct node));
   	new->data = y;
   	new->next = adj[x].head;
   	adj[x].head = new;

   	struct node* new1 = (struct node*)malloc(sizeof(struct node));
   	new1->data = x;
   	new1->next = adj[y].head;
   	adj[y].head = new1;
   }


   /*for(int i=0;i<n;i++){
   	  printf("%lld -> ",i);
   	   struct node*t = adj[i].head;
   	   while(t){
   	   	printf("%lld ",t->data);
   	   	t = t->next;
   	   }
   	   printf("\n");


   }*/

   dfs(s,t,adj,n);
   printf("%lld",100*(min-1));


  







	


//	printf("%c",head->next->next->next->data);
	




   return 0;
}