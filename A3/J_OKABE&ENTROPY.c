#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 1e6;
int result[100000];

struct node{
    int v1;
    int v2;
    int w;

};
struct sub {
    int p;
    int r;
};

int find(struct sub subset[], int i)
{
    if (subset[i].p != i){
        subset[i].p= find(subset, subset[i].p);}
 
    return subset[i].p;
}
void un(struct sub subset[], int a, int b)
{
    int aroot = find(subset, a);
    int broot = find(subset, b);
    if (subset[aroot].r < subset[broot].r){
        subset[aroot].p = broot;}
    else if (subset[aroot].r > subset[broot].r){
        subset[broot].p = aroot;}
    else
    {
        subset[broot].p = aroot;
        subset[aroot].r++;
    }
}

int comp(const void* a, const void* b)
{
    struct node* a1 = (struct node*)a;
    struct node* b1 = (struct node*)b;
    return a1->w > b1->w;
}



 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/

    int n,m;
    scanf("%d %d",&n,&m);
    struct node* edge = (struct node*)malloc(m*sizeof(struct node));
    for (int i = 0; i < m; ++i)
    {
    	int u,v,e;
    	scanf("%d %d %d",&u,&v,&e);
    	edge[i].v1 = u;
    	edge[i].v2 = v;
    	edge[i].w = e;


    }
    struct node ans[n];
    int x=0,y=0;
    qsort(edge,m,sizeof(edge[0]),comp);

    struct sub* subset = (struct sub*)malloc(n * sizeof(struct sub));
    for (int i = 0; i < n; ++i)
    {
    	subset[i].p = i;
    	subset[i].r=0 ;   
    }
    while(x<n-1&&y<m){
    	struct node new = edge[y++];
    	int a= find(subset,new.v1);
    	int b = find(subset,new.v2);
    	if(a!=b){
    		ans[x++]=new;
    		un(subset,a,b);

    	}
    }

    int sum=0;
    for (int i = 0; i < x; ++i)
    {
    	sum += ans[i].w;
    }

    printf("%d",sum);


   

  






    


//  printf("%c",head->next->next->next->data);
    




   return 0;
}