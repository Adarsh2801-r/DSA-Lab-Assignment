#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
#define SIZE 200000

const int MAX = 1e9;
int n;

struct node{
    char val[100];
    struct node*left;
    struct node* right;

};

int max(int a,int b){
    return a>b?a:b;
}

void search(struct node* root, char arr[10000][100],int i,char x[]){
    if(root==NULL){
        return;
    }
    if(!strcmp(root->val,"-1")){
        return;
    }
    if(!strcmp(root->val,x)){
        struct node* new1 =  (struct node*)malloc(sizeof(struct node));
        struct node* new2 =  (struct node*)malloc(sizeof(struct node));
        strcpy(new1->val,arr[2*i+1]);
        strcpy(new2->val,arr[2*i+2]);
        new1->left=NULL;
                new1->right=NULL;
        new2->left=NULL;
        new2->right=NULL;

        root->left=new1;
        root->right=new2;
        
        
        
    }
    if(2*i+1<n){
    search(root->left,arr,2*i+1,x);}
    if(2*i+2<n){
    search(root->right,arr,2*i+2,x);}
}

void tostring(char str[], int num)
{
    int i, rem, len = 0, n1;
    
    n1 = num;
    int flg=0;
    if(n1<0){
        n1*=-1;
        num*=-1;
        flg=1;
    }
    while (n1 != 0)
    {
        len++;
        n1 /= 10;
    }
    if(flg==1){
        str[0]='-';
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        if(flg==1){
            str[len-i]=rem+'0';
        }
        else{
        str[len - (i + 1)] = rem + '0';}
    }
    if(flg){
        str[len+1]='\0';
    }
    else{
    str[len] = '\0';}
}
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

void swap(struct node* root){
    struct node*tmp=root->left;
    root->left=root->right;
    root->right=tmp;
    
}
void invert(struct node*root){
    if(root==NULL){
        return;
    }
    if(!strcmp(root->val,"-1")){
        return;
    }
    char x[100];
    strcpy(x,root->val);
    if(x[0]=='-'){
        strrev(x+1);
    }
    else{
    strrev(x);}
    strcpy(root->val,x);
    swap(root);
    invert(root->left);
    invert(root->right);
}

void inorder(struct node*root){
    if(root==NULL){
        return;
    }
    if(!strcmp(root->val,"-1")){
        return;
    }
    inorder(root->left);
    if(strlen(root->val)){
    printf("%s ",root->val);}
    inorder(root->right);
}



int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/


    
    scanf("%lld",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    struct node*root = (struct node*)malloc(sizeof(struct node));

//    root->val=arr[0];
   char t[10000][100];
   tostring(t[0],arr[0]);
   strcpy(root->val,t[0]);
   root->left=NULL;
   root->right=NULL;
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        tostring(t[i],arr[i]);
    }
    for(int i=0;i<n;i++){
                search(root,t,0,t[i]);

    }
    invert(root);
    inorder(root);
   // printf("...%s %s",root->val,root->left->val);
    return 0;
}