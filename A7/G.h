#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;

struct node{
	int data;
	struct node*next;
	struct node*prev;
};




 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
   int n,k;
   scanf("%lld%lld",&n,&k);
   
   struct node*head=NULL;
   struct node *p1 = head;
   struct node *p2=head;
      struct node *p3=head;

   struct node*t = head;
   int init;
   scanf("%lld",&init);
   t=(struct node*)malloc(sizeof(struct node));
   	t->data=init;
   	t->prev=head;
   	t->next=NULL;
   	head=t;

   for(int i=1;i<n;i++){
   	int x;
   	scanf("%lld",&x);
   	t=(struct node*)malloc(sizeof(struct node));
   	t->data=x;
   	while(head->next){
   	    head=head->next;
   	}
    head->next=t;
    t->prev=head;
    
   	




   }
   while(head->prev){
       
       head=head->prev;
   }
   p1=head;
   p2=head;
   p3=head;
   while(k--){
       int y;
       scanf("%lld",&y);
       int num=y;
       int cou=0;
       while(num--){
           
           if(p2==NULL||p3==NULL){
               break;
           }
          
           p2->data = (p2->data)*y;
                      cou++;

           printf("%lld\n",p2->data);
                      p3=p3->next;


           p2=p2->next;
           
            
       }
       if(p2==NULL){
           p2=t;
       }
       else{
                        p2=p2->prev;
 
       }
       
       int num2=cou/2;
       while(num2--){
           int tmp=p1->data;
           p1->data=p2->data;
           p2->data=tmp;
           p1=p1->next;
           p2=p2->prev;
       }
       if(p3!=NULL){
       p1=p3;
       p2=p1;}
   }
   while(head){
   	printf("%lld ",head->data);
   	head=head->next;
   }
   

  




   return 0;
}