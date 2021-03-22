#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 1e6;
int visited[26];
int cou,f;
void topoSort(int i,int adj[26][26],int result[26]){
  visited[i]=1;
  for (int j=0;j<26; ++j)
  {
    if(adj[i][j]&&!visited[j]){
      topoSort(j,adj,result);
    }
    
  }
  
  
  result[cou]=i;
  cou++;

}

int check_cycle(int i,int adj[26][26], int visited[], int rec[]){
    if(visited[i] == 0) 
    { 
         
        visited[i] = 1; 
        rec[i] = 1; 
  
        for(int j=0;j<26;j++) 
        { 
            if(adj[i][j]){
            if ( !visited[j] && check_cycle(j, adj,visited, rec)) 
                return 1; 
            else if (rec[j]) 
                return 1; 
                
            }
        } 
  
    } 
    rec[i] = 0;
    return 0;
}



 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int n;
    scanf("%d\n",&n);
    int adj[26][26];
    for (int i = 0; i < 26; ++i)
    {
      for (int j=0;j<26; ++j)
      {
        adj[i][j]=0;
      }
    }
    int alph[26]={0};
    for (int i = 0; i < n; ++i)
    {
      char x,y;
      scanf("%c %c\n",&x,&y);
      adj[x-'A'][y-'A']=1;
      alph[x-'A']=1;
      alph[y-'A']=1;

    }
    int rec[26];
    for(int i=0;i<26;i++){
        rec[i]=0;
    }
    int cycle = 0;
    for(int i=0;i<26;i++){
        if (check_cycle(i,adj, visited, rec)) {
            cycle=1;
        }
 
    }
    if(cycle==1){
        printf("ALIENS BE CRAZY");
        return 0;
        
    }
    for(int i=0;i<26;i++){
        visited[i]=0;
    }
    int result[26]={-1};
    for (int i = 0; i < 26; ++i)
    {
        f=0;
        for(int j=0;j<26;j++){
            if(adj[i][j]){
                f=1;
                break;
            }
        }
        
       if(!visited[i]&&f){
          topoSort(i,adj,result);
       
       //printf("%d ",adj[i][j]);
           
       }
       //printf("\n");
    }
    
    
   
   
    for (int i = cou-1; i >= 0; --i)
    {
      if(result[i]!=-1){
        printf("%c", result[i]+'A');
      }
    }
       
   


   

  






    


//  printf("%c",head->next->next->next->data);
    




   return 0;
}