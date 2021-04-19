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


void search(struct node* root, int x){
    if(root==NULL){
        return;
    }
    if(root->val==x){
        return;
    }
    if(root->val<x){
            search(root->right,x);
       if(root->right==NULL){
        struct node* new =  (struct node*)malloc(sizeof(struct node));
        new->val=x;
        new->left=NULL;
        new->right=NULL;
       root->right=new;
      return;}
    }
    if(root->val>x){
        search(root->left,x);
        if(root->left==NULL){
        struct node* new =  (struct node*)malloc(sizeof(struct node));
        new->val=x;
        new->left=NULL;
        new->right=NULL;
       root->left=new;
      return;}
    }
}

void postorder(struct node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%lld ",root->val);
}


int main()
{
    int n;
    scanf("%lld",&n);
    int arr[n];
    struct node * root = (struct node*)malloc(sizeof(struct node));
    scanf("%lld",&arr[0]);
    root->val=arr[0];
    root->left=NULL;
    root->right=NULL;
    for (int i = 1; i < n; ++i)
    {
        scanf("%lld",&arr[i]);
                search(root,arr[i]);

    }
    postorder(root);
    return 0;
}

