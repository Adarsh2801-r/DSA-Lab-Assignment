#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 1e6;
int n;
int visited[500];
int cou=0;
void dfs(int i, int a[n][n]){
    visited[i]=1;
    //printf("%d ",i);
    cou++;
    
        for(int j=0;j<n;j++){
            if(a[i][j]==1&&visited[j]==0){
                dfs(j,a);
            }
        }
    

}
int main() {
   // printf() displays the string inside quotation
    int m;
    scanf("%d %d",&n,&m);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u][v]=1;
        a[v][u]=1;
    }
    int conn[n];
    for(int i=0;i<n;i++){
        conn[i]=0;
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
           cou=0;
           dfs(i,a);
           conn[i]=cou;
          // printf("\n");

        }


    }
    

    int ans=0;

    for (int i = 0; i < n; ++i)
    {
        if(conn[i]!=0){
            ans++;
        }
    }

    printf("%d\n",ans);

    for (int i = 0; i < n; ++i)
    {
        if(conn[i]!=0){
            printf("%d ", conn[i]);
        }
    }
    








    


//  printf("%c",head->next->next->next->data);
    




   return 0;
}