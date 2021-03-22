#include <stdio.h>
#include <stdlib.h>

const int mod = 1e6;

struct node{
	int data;
    struct node * next;
};

int main() {
   // printf() displays the string inside quotation
	int x=0;
	struct node * head = NULL;
    	struct node * head1 = NULL;
    	scanf("%d",&x);
    	head = (struct node*) malloc(sizeof(struct node));
    	head->data = x;
    	head->next=NULL;
    	head1 = head;

	while(x!=-1){
		scanf("%d",&x);
		struct node * temp = (struct node*) malloc(sizeof(struct node));
		temp->data = x;
		temp->next = NULL;
		head->next=temp;
        head=head->next;
		

	}
	struct node*ptr = head1;
		struct node*p1 = head1;
	struct node*p2 = NULL;
		struct node*p3 = NULL;


	while(p1!=NULL){
	    p2= p1 -> next;
	    p1->next = p3;
	    p3=p1;
	    p1=p2;
		
	}
	ptr=p3;
while(ptr!=NULL){
    if(ptr->data!=-1){
    printf("%d ", ptr->data);}
		ptr=ptr->next;
}
   return 0;
}