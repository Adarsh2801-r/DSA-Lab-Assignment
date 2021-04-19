#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;
int result[26]={-1};

struct node{
    char c;
    int cou;
    int isLeaf;
    struct node* child[26];
};

struct node *getNode()
{
    struct node *pNode = (struct node*)malloc(sizeof(struct node));
    pNode->cou = 0;
    pNode->isLeaf=0;
   
    for (int i = 0; i < 26; i++)
        pNode->child[i] = NULL;    
   
    return pNode;
}

void insert(struct node *root, const char *key)
{
        int length = 0;

    for(int i=0;key[i]!='\0';i++){
        length++;
    }
  
    struct node *pCrawl = root;
   
    for (int level = 0; level < length; level++)
    {
        int index = (int)key[level]-(int)'a';
        if (!pCrawl->child[index])
            pCrawl->child[index] = getNode();
   
        pCrawl = pCrawl->child[index];
    }
   
    pCrawl->isLeaf = 1;
}

int search(struct node *root, const char *key)
{
    int level;
    int length = 0;

    for(int i=0;key[i]!='\0';i++){
        length++;
    }    
    int index;
    struct node *pCrawl = root;
  
    for (level = 0; level < length; level++)
    {
        index = (int)key[level]-(int)'a';
  
        if (!pCrawl->child[index])
            return 0;
  
        pCrawl = pCrawl->child[index];
    }
    pCrawl->cou += (pCrawl != NULL && pCrawl->isLeaf);
    //printf("%lld ",pCrawl->cou);
    return pCrawl->cou;
}
 
 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/

        

   
        int n;
        scanf("%lld",&n);
        char keys[n][20];
        struct node *root = getNode();

        for (int i = 0; i < n; ++i)
        {
            scanf("%s",keys[i]);
            insert(root,keys[i]);
        }
        int flag=0;
        int c1=-1,c2=-1;
        for (int i = 0; i < n-1; ++i)
        {
            int cou=0;
            for (int j=0;keys[i][j]!='\0'; ++j)
            {
                cou++;
            }
            if(keys[i][cou-1]!=keys[i+1][0]){
                flag=1;
                c1=i+1;
                break;
            }
        }
    
        for (int i = 0; i < n; ++i)
        {
            if(search(root,keys[i])>1){
                
                flag=1;
                c2=i;
                break;
            }
        }
        if(flag==0){
            if(n%2==0){
                printf("Bob ");
            }
            else{
                printf("Alice ");
            }
        }
        else{
            //printf("{%lld,%lld}",c1,c2);
            if((c1<c2&&c1!=-1)||c2==-1){
            if(c1%2==1){
                printf("Alice ");
            }
            else{
                printf("Bob ");
            }}
            else if((c2<=c1&&c2!=-1)||c1==-1){
               if(c2%2==1){
                printf("Alice ");
            }
            else{
                printf("Bob ");
            } 
            }
        }


        //printf("\n");
            
    
    
 



   return 0;
}  