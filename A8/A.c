#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;
int result[26]={-1};
struct node{
      int val;
      struct node*left;
      struct node*right;
};
struct node* stack1[1000000];
struct node* stack2[1000000];


int t1=-1,t2=-1;
void push1(int x){
    t1++;
    stack1[t1]=x;
}

void pop1(){
    t1--;
}
struct node* top1(){
    return stack1[t1];
}

int size1(){
    return t1+1;
}

void push2(struct node* x){
    t2++;
    stack2[t2]=x;
}

void pop2(){
    t2--;
}
struct node* top2(){
    return stack2[t2];
}

int size2(){
    return t2+1;
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


int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
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
    push1(root);
    while(size1()||size2()){
    while(size1()>0){
    	struct node*tmp=top1();
    	printf("%lld ",arr[tmp->val]);
    	if(tmp->left){
    		push2(tmp->left);
    	}
    	if(tmp->right){
    		push2(tmp->right);
    	}
    	pop1();

    }
    while(size2()>0){
    	struct node*tmp=top2();
    	printf("%lld ",arr[tmp->val]);
    	if(tmp->right){
    		push1(tmp->right);
    	}
    	if(tmp->left){
    		push1(tmp->left);
    	}
    	pop2();

    }}
  




   



    	    
 



   return 0;
}