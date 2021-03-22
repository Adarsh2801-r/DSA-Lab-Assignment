#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 1e6;

int n;
int cou=0,mx=0;
void dfs(int i,int adj[n][n],int visited[]){
  visited[i]=1;
  cou++;
  //printf("%d ",i);
  for (int j=0;j<n; ++j)
  {
    if(adj[i][j]&&!visited[j]){
      dfs(j,adj,visited);
    }
  }

}
int main() {
   // printf() displays the string inside quotation
   int m;
   scanf("%d %d",&n,&m);
   int adj[n][n];
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           adj[i][j]=0;
       }
   }
   for(int i=0;i<m;i++){
    int x,y;
    scanf("%d %d",&x,&y);
    adj[x-1][y-1]=1;
   }

   for(int i=0;i<n;i++){
    cou=0;
    int visited[1000]={0};

    dfs(i,adj,visited);
    //printf("%d ",cou);
    if(cou>mx){
      mx=cou;
    }
    //printf("\n");

   }
   printf("%d",mx);










  


//  printf("%c",head->next->next->next->data);
  




   return 0;
}