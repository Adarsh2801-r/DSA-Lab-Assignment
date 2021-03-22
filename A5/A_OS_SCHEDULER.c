#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;
const int DOUBLE_MAX = 1e9;
int result[26]={-1};
int t;

struct node{
	int ei;
	int pi;
	int idx;

};
void swap(struct node * a, struct node* b){
	struct node temp = *a;
	*a=*b;
	*b = temp;
}
void heapify(struct node*arr[],int i,int t){
	int left = 2*i + 1;
	int right = 2*i + 2;
	int smallest=-1;
	if(left<t){
		if(arr[left]->pi<arr[i]->pi){
           smallest = left;
		} 
		else if(arr[left]->pi==arr[i]->pi){
			if(arr[left]->ei<arr[i]->ei){
				smallest = left;
			}
			else if(arr[left]->ei==arr[i]->ei){
			    if(arr[left]->idx<arr[i]->idx){
			        smallest=left;
			    }
			    else{
			        smallest=i;
			    }
			}
			else{
				smallest = i;
			}
		}
		else{
			smallest=i;
		}

	}
	if(right<t){
		if(arr[right]->pi<arr[smallest]->pi){
			smallest = right;
		}
		else if(arr[right]->pi==arr[smallest]->pi){
			if(arr[right]->ei<arr[smallest]->ei){
				smallest = right;
			}
			else if(arr[right]->ei==arr[smallest]->ei){
			    if(arr[right]->idx<arr[smallest]->idx){
			        smallest=right;
			    }
			}
		}

	}
	if(smallest != i && smallest !=-1){
	    swap(arr[i],arr[smallest]);
		heapify(arr,smallest,t);
	}
}

void buildMinHeap(struct node*arr[],int t){
	int len = t;
	for(int i=t/2;i>=0;i--){
		heapify(arr,i,t);
	}

}

void remove_top(struct node * arr[]){
    printf("%lld -- %lld -- %lld\n",arr[0]->ei,arr[0]->pi,arr[0]->idx);
    arr[0]=arr[t-1];
    t--;
    heapify(arr,0,t);

    
}






 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int k;
    scanf("%lld %lld",&t,&k);
    struct node * arr[t];
    for (int i = 0; i < t; ++i)
    {
    	int e,p;
    	scanf("%lld %lld",&e,&p);
    	arr[i]= (struct node*)malloc(sizeof(struct node));
        arr[i]->ei = e;
        arr[i]->pi = p;
        arr[i]->idx = i;
    }
    buildMinHeap(arr,t);
    /*for(int i=0;i<t;i++){
        printf("%lld %lld\n",arr[i]->ei,arr[i]->pi);
    }*/
    k=8;
    while(k--){
        remove_top(arr);
    }



   return 0;
}