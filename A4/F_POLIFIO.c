#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;
int result[26]={-1};

struct node{
    int d;
    int w;
};

void merge(struct node *arr[],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int l1[n1],r1[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]->d;
        l1[i]=arr[l+i]->w;
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j]->d;
        r1[j]=arr[m+j+1]->w;
    }
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k]->d = L[i];
            arr[k]->w = l1[i];
 
            i++;
        }
        else {
            arr[k]->d = R[j];
            arr[k]->w= r1[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k]->d = L[i];
        arr[k]->w = l1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k]->d = R[j];
        arr[k]->w = r1[j];
        
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
    int t;
    scanf("%lld",&t);
    while(t--){
        int n;
        scanf("%lld",&n);
        struct node * arr[n];
        for (int i = 0; i < n; ++i)
        {
            int xi,yi,wi;
            scanf("%lld %lld %lld",&xi,&yi,&wi);
            arr[i]=(struct node*)malloc(sizeof(struct node));
            arr[i]->d=yi-xi;
            arr[i]->w=wi;
            
        }
        mergeSort(arr,0,n-1);
        int sum=0;
        int acc=0;
        for (int i = 0; i < n; ++i)
        {
            
            //printf("%lld %lld\n",arr[i]->d,arr[i]->w);
            sum += arr[i]->w;

            
        }
        
        for(int i=0;i<n-1;i++){
            acc += arr[i]->w;
            if(acc==sum-acc&&arr[i]->d != arr[i+1]->d){
                printf("YES");
                return 0;
            }
        }
        printf("NO");
        
        printf("\n");
        
        


    }






    


    




   return 0;
}