#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;
int result[100000];

struct node{
    int b;
    int g;

};

void merge(struct node *arr[],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int l1[n1],r1[n2];
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]->b;
        l1[i]=arr[l+i]->g;
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j]->b;
        r1[j]=arr[m+j+1]->g;
    }
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k]->b = L[i];
            arr[k]->g = l1[i];
            i++;
        }
        else {
            arr[k]->b = R[j];
            arr[k]->g= r1[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k]->b = L[i];
        arr[k]->g = l1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k]->b = R[j];
        arr[k]->g = r1[j];
        j++;
        k++;
    }


}

void mergeSort(struct node* arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);

    }

}



 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/  

    int n,m;
    scanf("%lld %lld",&n,&m);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    struct node * s[m];
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%lld %lld",&x,&y);
        s[i] = (struct node*)malloc(sizeof(struct node));
        s[i]->b = x;
        s[i]->g = y;
    }

    int sum[m];
    for(int i=0;i<m;i++){
        sum[i]=0;
    }
    int k=0;
    mergeSort(s,0,m-1);
    int tot=0;
    for(int i=0;i<m;i++){
        tot+=s[i]->g;
        sum[k]=tot;
        k++;
    }
    /*for(int i=0;i<m;i++){
        printf("%lld ",sum[i]);
    }*/
    for(int i=0;i<n;i++){
        int t = arr[i];
        int f=0;
        int l=0,r=m-1;
        if(l==r){
            if(t>=s[0]->b){
                printf("%lld ",sum[l]);
                f=1;
            }

        }
        else{
        while(l<r){
            int mid = (l+r)/2;
            
            if(s[mid]->b>t){
                r = mid;

            }
            else{
                l = mid+1;
            }
            if((s[mid]->b<=t && s[mid+1]->b>t)||(mid==m-1)){
                printf("%lld ",sum[mid]);
                f=1;
                break;
        }
        if(l==r){
            if(t>= s[l]->b){
            printf("%lld ",sum[l]);
                f=1;
                break;}
        }

        }
        
    }
    if(f==0){
            printf("0 ");
        }
        
        
    }


   

  






    


//  printf("%c",head->next->next->next->data);
    




   return 0;
}