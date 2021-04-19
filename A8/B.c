#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int mod = 1e9+7;
const int MAX = 1e9;
int result[26]={-1};
int arr[10000];
int pre[10000];
int post[10000];
int in[10000];
int p1,p2,p3;


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
void preorder(struct node*root){
    if(root==NULL){
        return;
    }
    pre[p1]=arr[root->val];
    p1++;
    //printf("%lld-",root->val);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    in[p2]=arr[root->val];
    p2++;
    inorder(root->right);
}
void postorder(struct node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    post[p3]=arr[root->val];
    p3++;
}

int abs_val(int a){
    return a>=0?a:-a;
}


 
 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/

    int n;
    scanf("%lld",&n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld",&arr[i]);
    }
    struct node * root = (struct node*)malloc(sizeof(struct node));
   struct node * head = (struct node*)malloc(sizeof(struct node));
    root->val=0;
    root->left=NULL;
    root->right=NULL;
    head=root;
    for (int i = 0; i < n-1; ++i)
    {
        int x,y;
        char c;
        scanf("%lld %lld %c",&x,&y,&c);
        search(root,x,y,c);

    }
    preorder(root);
    inorder(root);
    postorder(root);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+= ((in[i]%mod)*(abs_val(pre[i]-post[i])%mod));
    }
    printf("%lld",ans);

    


            
 



   return 0;
}