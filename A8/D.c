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
int path[100000];
int flag=0,d=0;
struct node{
    int val;
    struct node*left;
    struct node* right;

};

struct node*temp;

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

void delete(struct node*root,int x){
    if(root==NULL){
        return;
    }
  
    if(root->left!=NULL&&arr[root->left->val]==x){
        root->left=NULL;
        return;
    }
     if(root->right!=NULL&&arr[root->right->val]==x){
        root->right=NULL;
        return;
    }
    delete(root->left,x);
    delete(root->right,x);
    
    
}

struct node* find(struct node* root,int x){
      

        
        if(root->left!=NULL&&arr[root->left->val]==x){  
            flag=1;
        //printf("{%lld}",arr[root->val]);
        temp=(struct node*)malloc(sizeof(struct node));
        temp= root;
        }
        if(root->right!=NULL&&arr[root->right->val]==x){
                        flag=1;

            temp=(struct node*)malloc(sizeof(struct node));
        temp= root;
        }
        
    
    if(flag==0&&root->left!=NULL){
    find(root->left,x);}
    if(flag==0&&root->right!=NULL){
    find(root->right,x);}
    if(flag==1){
                return temp;}

}

void swap(struct node* root,int x,int y){
    
    struct node* t1=(struct node*)malloc(sizeof(struct node));
    struct node* t2= (struct node*)malloc(sizeof(struct node));
    t1=find(root,x);
    flag=0;
    t2=find(root,y);
    //printf("(%lld)",arr[t1->val]);
    struct node*c1;
    struct node*c2;
    struct node*d1;
    struct node*d2;
    int a=0,b=0;
    if(t1->left!=NULL&&arr[t1->left->val]==x){
        c1=t1->left;
        a=1;
    }
    if(t1->right!=NULL&&arr[t1->right->val]==x){
        c1=t1->right;
    }
     if(t2->left!=NULL&&arr[t2->left->val]==y){
        c2=t2->left;
        b=1;
    }
    if(t2->right!=NULL&&arr[t2->right->val]==y){
        c2=t2->right;
    }
    if(a){
        if(b){
            t1->left=c2;
            
            t2->left=c1;
        }
        else{
            t1->left=c2;
            t2->right=c1;
        }
    }
    else{
        if(b){
            t1->right=c2;
            t2->left=c1;
        }
        else{
            t1->right=c2;
            t2->right=c1;
        }
    }
   
    
}

int max(int a,int b){
    return a>b?a:b;
}

int diameter(struct node*root){
    if(root==NULL){
        return 0;
    }
    int leftPath = diameter(root->left);
    int rightPath = diameter(root->right);
    d= max(d,leftPath+rightPath);
    return max(leftPath,rightPath)+1;
    
}

int main()
{
    int n,t;
    scanf("%lld%lld",&n,&t);
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
    while(t--){
        char s[10];
        scanf("%s",s);
        if(!strcmp(s,"DELETE")){
            int x;
            scanf("%lld",&x);
            if(arr[root->val]==x){
                root=NULL;
            }
            else{
            delete(root,x);}
        }
        if(!strcmp(s,"SWAP")){
            int x,y;
            scanf("%lld%lld",&x,&y);
            //printf("%lld--",root->left->val);
            swap(root,x,y);
        }
        
    }
    diameter(root);
    printf("%lld",d);

    
    return 0;
}
