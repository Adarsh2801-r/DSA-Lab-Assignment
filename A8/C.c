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
struct node* stack[1000000];
int t1=-1,t2=-1;



void push(struct node* x){
    t1++;
    stack[t1]=x;
}

void pop(){
    t1--;
}
struct node* top(){
    return stack[t1];
}

int size(){
    return t1+1;
}

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


int main()
{
    int n;
    scanf("%lld",&n);
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
    int flag=0;
    while(!flag){
        if(root==NULL){
            if(size()!=0){
                root = top();
                printf("%lld ",arr[root->val]);
                pop();
                root=root->right;
            }
            else{
                flag=1;
            }
        }
        else{
            push(root);
            root=root->left;
        }
    }
    
    return 0;
}

