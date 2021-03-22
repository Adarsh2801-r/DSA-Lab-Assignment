#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;
int result[100000];



void merge(int arr[],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int l1[n1],r1[n2];
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
        l1[i]=arr[l+i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
        r1[j]=arr[m+j+1];
    }
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            arr[k] = l1[i];
            i++;
        }
        else {
            arr[k] = R[j];
            arr[k]= r1[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        arr[k] = l1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        arr[k] = r1[j];
        j++;
        k++;
    }


}

void mergeSort(int arr[],int l,int r){
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
    #endif  */
    int m,n;
    scanf("%lld %lld",&m,&n);
    int a[m],b[n];
    for(int i=0;i<m;i++){
        scanf("%lld",&a[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld",&b[i]);
    }
    mergeSort(a,0,m);
    
    for(int i=0;i<n;i++){
        int t=b[i];
        int f=0;
        int l=0,r=m-1;
        if(l==r){
            if(t>=a[l]){
                printf("%lld ",l+1);
                f=1;
                break;
            }
        }
        else{
            while(l<r){
            int mid = l + (r-l)/2;
            
            if(a[mid]>t){
                r = mid;

            }
            else{
                l = mid+1;
            }
            if((a[mid]<=t && a[mid+1]>t)||(mid==m-1)){
                printf("%lld ",mid+1);
                f=1;
                break;
        }
        if(l==r){
            if(t>= a[l]){
            printf("%lld ",l+1);
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