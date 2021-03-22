#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e8;
int result[26]={-1};



 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int n,m;
    scanf("%lld %lld",&n,&m);
    int adj[n][n];
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		adj[i][j]=0;
    	}
    }
    for (int i = 0; i < m; ++i)
    {
    	int u,v,w;
    	scanf("%lld %lld %lld",&u,&v,&w);
    	adj[u][v]=w;
    	adj[v][u]=w;

    }
    int p[n];
    int k[n];
    int mst[n];
    for (int i = 0; i < n; ++i)
    {
    	k[i]=MAX;
    	mst[i]=0;
    }
    k[0]=0;
    p[0]=-1;

    for (int i = 0; i < n-1; ++i)
    {   int mn = MAX;
    	int mn_index;
    	for (int j=0;j<n;j++)
    	{
           if(mst[j]==0&&k[j]<mn){
           	mn=k[j];
           	mn_index=j;
           }
    	}
    	int x = mn_index;
    	mst[x]=1;
    	for (int j=0;j<n; ++j)
    	{
    		if(adj[x][j]&&mst[j]==0&&adj[x][j]<k[j]){
    			p[j]=x;
    			k[j]=adj[x][j];
    		}
    	}
    }
   
    int sum=0;
    for (int i = 1; i < n; ++i)
    {
    	sum += adj[i][p[i]];
    }
    printf("%lld",sum);
   




    


//  printf("%c",head->next->next->next->data);
    




   return 0;
}