#include <stdio.h>
#include <stdlib.h>
const int MAX = 1e6;

struct Node 
{ 
    char data; 
    struct Node *next; 
    struct Node *prev; 
}; 

int main() {
   // printf() displays the string inside quotation
  int n;
   scanf("%d\n",&n);
   struct Node *head = NULL;
   struct Node *head1 = head;
   
   for (int i =0; i < n; ++i)
   {
    char x;
    scanf("%c",&x);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node*last = head;
    temp->data = x;
    temp->next = NULL;
    if(head==NULL){
      temp->prev=NULL;
      head=temp;
      continue;

    }
    while(last->next!=NULL){
      last=last->next;
    }
    last->next=temp;
    temp->prev=last;

    
   }
   
   struct Node*r = head;
 
   while(r->next!=NULL){
        //printf("%c",r->data);

        r = r->next;
          
    }
   while(head!=r){


                     
         

      if(head->data != r->data){

      printf("NOT A PALINDROME");
      return 0;
      }

      head = head->next;
      r = r->prev;
    }
    printf("PALINDROME");
    
    



      



   

   return 0;
}