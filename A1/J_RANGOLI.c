#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 1e6;
int n;
int visited[500];
int color[500];
int cou=0;
void dfs(int i, int a[n][n],int pr){
	if(visited[i]){
	    
		return;
	}
	visited[i]=1;
	if(i==0){
	    color[i]=0;
	}
	else{
	color[i]= color[pr]^1;}
	for (int j=0;j<n;j++)
	{
		if(a[i][j]){
		dfs(j,a,i);}
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
    for(int i=0;i<n;i++){
        if(!visited[i]){
                dfs(i,a,-1);

        }
    }
    int f=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j=0;j<n;j++)
		{
			if(a[i][j]){
			if(color[i] == color[j]){
				f=1;
				printf("NEED MORE COLOURS");
				break;
			}}
		}
		if(f){
			break;
		}
		
	}
	if(f==0){
		//cout<<"YES"<<endl;
		for (int i = 0; i <n; ++i)
		{
			if(color[i]==1){
              printf("B");

			}
			else{
               printf("R");


			}
		}
	}
   
    	 








	


//	printf("%c",head->next->next->next->data);
	




   return 0;
}