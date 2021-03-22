#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const int MAX = 1e6;
int sum=0;
struct node{
	int data;
	struct node*left;
	struct node*right;
};

struct node* construct(int arr[],struct node*root,int i,int n){
	if(i<n){
		struct node*temp = (struct node*)malloc(sizeof(struct node));
		temp->data = arr[i];
		temp->left=NULL;
		temp->right=NULL;
		root = temp;
		root->left = construct(arr,root->left, 2 * i + 1, n);
		 root->right = construct(arr,root->right, 2 * i + 2, n);

	}
	return root;

}

void levelOrder(struct node* root,int cou) 
{ 
    if (root != NULL) 
    { 
        printf("%d ",root->data); 
        sum+=cou*(root->data);
        levelOrder(root->left,cou+1); 
        levelOrder(root->right,cou+1); 
    } 
} 


int main() {
   // printf() displays the string inside quotation
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);



	}
	struct node*root = construct(arr,root,0,n);
	    levelOrder(root,1); 
	    printf("\n%d",sum);




	


	




   return 0;
}