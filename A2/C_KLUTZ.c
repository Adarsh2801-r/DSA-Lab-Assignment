#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;
   int n;
   int f=0,g=0;
   int v[300];
void dfs(int i,int d, int adj[n+1][n+1],int visited[300]){
	visited[i]=1;
	//printf("%d ",i);
	if(i==d){
      f=1;
   }
	for(int j=1;j<=n;j++){
		if(adj[i][j]&&!visited[j]){
			dfs(j,d,adj,visited);
		}
	}
}
int main() {
   // printf() displays the string inside quotation
   scanf("%lld",&n);
   int m = (n*(n-1))/2 - 1;
   int adj[n+1][n+1];
   for(int i=0;i<=n;i++){
   	for(int j=0;j<=n;j++){
   		adj[i][j]=0;
   	}
   }
   for(int i=0;i<m;i++){
   	   int x,y;
   	   scanf("%lld %lld",&x,&y);
   	   adj[x][y]=1;


   }
   int v1,v2;
   for(int i=1;i<=n;i++){
   	for(int j=1;j<=n;j++){
   		if(adj[i][j]==0&&adj[j][i]==0&&i!=j){
   			v1=i;
   			v2=j;
   		}
   	}
   }
   int visited[200]={0};
   int visited1[200]={0};
   dfs(v1,v2,adj,visited);
   if(f==1){
      printf("%lld %lld",v1,v2);
      return 0;
   }
   f=0;
   dfs(v2,v1,adj,visited);
    if(f==1){
      printf("%lld %lld",v2,v1);
      return 0;
   }

   printf("%lld %lld",v1,v2);





  

  







	


//	printf("%c",head->next->next->next->data);
	




   return 0;
}