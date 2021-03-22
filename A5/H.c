#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 1e9;
int result[26]={-1};
int cou_low=1;
int cou_up=1;

void min_heapify_down(int mn[],int i){
    int left=2*i+1;
    int right=2*i+2;
    int smallest=i;
    if(left<cou_low){
        if(mn[left]<mn[right]){
            smallest=left;
        }
        else{
            smallest=right;
        }
    }
    if(mn[smallest]<mn[i]){
        int temp=mn[smallest];
        mn[smallest]=mn[i];
        mn[i]=temp;
        min_heapify_down(mn,smallest);
    }

}

void min_heapify_up(int mn[],int i){
    int parent;
    if(i%2){
        parent = (i-1)/2;
    }
    else{
       parent = (i-2)/2; 
    }    
    if(parent<0){
        return;
    }
    if(mn[i]<mn[parent]){
        int tmp=mn[parent];
        mn[parent]=mn[i];
        mn[i]=tmp;
        min_heapify_up(mn,parent);
    }
    
}

void max_heapify_down(int mx[],int i){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<cou_low){
        if(mx[left]>mx[right]){
            largest=left;

        }
        else{
            largest=right;
        }
    }
    if(mx[largest]>mx[i]){
        int temp=mx[largest];
        mx[largest]=mx[i];
        mx[i]=temp;
        max_heapify_down(mx,largest);
    }


}

void max_heapify_up(int mx[],int i){
    int parent;
    if(i%2){
        parent = (i-1)/2;
    }
    else{
       parent = (i-2)/2; 
    }

    if(parent<0){
        return;
    }
    if(mx[i]>mx[parent]){
        int tmp=mx[parent];
        mx[parent]=mx[i];
        mx[i]=tmp;
        max_heapify_up(mx,parent);
    }

}



void insert_into_mx(int x, int mx[]){
    mx[cou_low]=x;
    cou_low++;
    max_heapify_up(mx,cou_low-1);

}

void insert_into_mn(int x,int mn[]){
    mn[cou_up]=x;
    cou_up++;
    min_heapify_up(mn,cou_up-1);

}

int remove_top_mx(int mx[]){
    int temp = mx[0];
    mx[0]=mx[cou_low-1];
    cou_low--;
    max_heapify_down(mx,0);

   



}

int remove_top_mn(int mn[]){
     int temp = mn[0];
    mn[0]=mn[cou_up-1];
    cou_up--;
    min_heapify_down(mn,0);

}

 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&arr[i]);
    }
    int mx[n];
    int mn[n];
    int ans[n];

    if(arr[0]>=arr[1]){
        mn[0]=arr[0];
        mx[0]=arr[1];
    }
    else{
       mx[0]=arr[0];
       mn[0]=arr[1];
    }
    
    ans[0]=arr[0];
    ans[1]=(arr[0]+arr[1])/2;
    for (int i = 2; i < n; ++i)
    {
        for(int j=0;j<cou_low;j++){
                printf("%d ",mx[j]);
            }
            printf("---");
            for(int j=0;j<cou_up;j++){
                printf("%d ",mn[j]);
            }
            printf("\n");
            if(cou_low>cou_up){
                if(arr[i]<ans[i-1]){
                    int x=mx[0];
                        remove_top_mx(mx);
                        insert_into_mn(x,mn);
                        
                        insert_into_mx(arr[i],mx);
                }
                else{
                    insert_into_mn(arr[i],mn);
                }
                ans[i]= (mn[0]+mx[0])/2;
                
            }
            else if(cou_low==cou_up){
                if(arr[i]<ans[i-1]){
                    insert_into_mx(arr[i],mx);
                    ans[i]=mx[0];
                }
                else{
                    insert_into_mn(arr[i],mn);
                    ans[i]=mn[0];
                }
            }
            else{
                if(arr[i]>=ans[i-1]){
                    int x = mn[0];
                    remove_top_mn(mn);
                    insert_into_mx(x,mx);
                    insert_into_mn(arr[i],mn);
                }
                else{
                    insert_into_mx(arr[i],mx);
                }
                ans[i]= (mx[0]+mn[0])/2;
            }
            
    }
    
    /*for(int j=0;j<cou_low;j++){
                printf("%d ",mx[j]);
            }
            printf("---");
            for(int j=0;j<cou_up;j++){
                printf("%d ",mn[j]);
            }
            printf("\n");*/
    for (int i = 0; i < n-1; ++i)
    {
        printf("%d ",ans[i]);
    }
    printf("%d",ans[n-1]);






   return 0;
}