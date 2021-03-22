#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 1e6;

struct Node 
{ 
    char data; 
    struct Node *next; 
    struct Node *prev; 
}; 

int main() {
   // printf() displays the string inside quotation
	char ch;
	int cou=0;
	struct Node* head = NULL;
	struct Node* temp = head;

	while(ch!='\n'){
		
		scanf("%c",&ch);
		if(ch=='\n'){
			break;
		}
		temp = (struct Node*)malloc(sizeof(struct Node));
		struct Node*last = head;
		temp->data = ch;
		temp->next=NULL;
		if(head==NULL){
			temp->prev = NULL;
			head = temp;
			continue;

		}
		while(last->next!=NULL){
			last = last->next;
		}
		last->next = temp;
		temp->prev = last;





	}
	int t;
	scanf("%d\n",&t);
	int sum=0;

	while(t--){
	    sum=0;
		char in;

		while(1){
		    scanf("%c",&in);

		    if(in=='\n'){
		        break;
		    }

			sum += (int)in;

		}
		//printf("%d ",sum);
	    if(sum==159){
	        struct Node*t1=head;
	        while(t1->next!=NULL){
	            t1->data = t1->next->data;
	            t1=t1->next;
	            cou++;
	        }
	        t1->data='0';

	        
	        
	    }
	    else if(sum==165){
	        
	        struct Node*t2=head;
	        while(t2->next!=NULL){
	            t2=t2->next;
	        }
	        while(t2->prev!=NULL){
	            t2->data = t2->prev->data;
	            t2=t2->prev;
	        }
	        t2->data='0';
	        
	        

	        
	        
	    }
	    else if(sum==158){
	        struct Node*t1=head;
	        	        struct Node*t2=head;
           
            char x=t2->data;
	        while(t1->next!=NULL){
	            t1->data = t1->next->data;
	            t1=t1->next;
	        }
	        t1->data=x;

	        
	        
	    }
	     else if(sum==164){
	        
	        struct Node*t2=head;
	        while(t2->next!=NULL){
	            t2=t2->next;
	        }
	        char y= t2->data;
	        while(t2->prev!=NULL){
	            t2->data = t2->prev->data;
	            t2=t2->prev;
	        }
	        t2->data=y;
	        
	        

	        
	        
	    }
	    else if(sum==218){
	        struct Node* t1=head;
	        while(t1->next!=NULL){
	            t1=t1->next;
	        }
	        char carry='1';
	        while(t1!=NULL){
	            if(carry=='1'){
	                if(t1->data=='0'){
	                    t1->data = '1';
	                    carry='0';
	                }
	                else if(t1->data=='1'){
	                    t1->data='0';
	                    carry='1';
	                }
	                
	            }
	            else{
	                 if(t1->data=='0'){
	                    t1->data = '0';
	                    carry='0';
	                }
	                else if(t1->data=='1'){
	                    t1->data='1';
	                    carry='0';
	                }
	            }
	            t1=t1->prev;
	        }
	    }
	    else if(sum==204){
	        struct Node*t1=head;
	        while(t1->next!=NULL){
	            t1=t1->next;
	        }
	        char carry='0';
	        while(t1!=NULL){
	            if(carry=='1'){
	                if(t1->data=='1'){
	                    t1->data='1';
	                    carry='1';
	                    
	                }
	                else if(t1->data=='0'){
	                    t1->data='0';
	                    carry='1';
	                }
	            }
	            else{
	                if(t1->data=='1'){
	                    t1->data='0';
	                    carry='1';
	                }
	                else if(t1->data=='0'){
	                    t1->data='1';
	                    carry='0';
	                }
	            }
	            t1=t1->prev;
	            
	        }
	        
	    }
	    
	    
	}
	int c=0;
	while(head!=NULL){
	    printf("%c",head->data);
	    head=head->next;
	    c++;
	}
	printf("\n");
//	printf("%d",c);
//	printf("%c",head->next->next->next->data);
	




   return 0;
}
