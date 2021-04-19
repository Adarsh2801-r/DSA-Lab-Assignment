#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int mod = 1e9+7;
const int MAX = 1e9;
struct node{
    int val;
    struct node*left;
    struct node* right;

};
void search(struct node* root, int x,int y,char c){
    if(root==NULL){
        return;
    }
    if(root->val==x){
        struct node* new =  (struct node*)malloc(sizeof(struct node));
        new->val=y;
        new->left=NULL;
        new->right=NULL;
        if(c=='L'){
            root->left=new;

        }
        else{
            root->right=new;
        }
        return;
    }
    search(root->left,x,y,c);
    search(root->right,x,y,c);
}

struct node* lca(struct node*root,int n1,int n2){
    if(root==NULL)
        return NULL;
    
      if(root->val==n1 || root->val==n2)
        return root;
        
      struct node *l = lca(root->left,n1,n2);
      struct node *r = lca(root->right,n1,n2);
      if (l && r)
        return root;
  
      return (l!=NULL)?l:r;
}

int main()
{
int n,q;
    scanf("%lld%lld",&n,&q);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld",&arr[i]);
    }
    struct node * root = (struct node*)malloc(sizeof(struct node));
    root->val=0;
    root->left=NULL;
    root->right=NULL;
    for (int i = 0; i < n-1; ++i)
    {
        int x,y;
        char c;
        scanf("%lld %lld %c",&x,&y,&c);
        search(root,x,y,c);

    }
    while(q--){
        int n1,n2;
        scanf("%lld%lld",&n1,&n2);
        printf("%lld ",lca(root,n1,n2)->val);
    }
    
    return 0;
}
