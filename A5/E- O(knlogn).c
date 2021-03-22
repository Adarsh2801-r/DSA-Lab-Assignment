#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 1e9;
int result[26]={-1};
void merge(int arr[],int l,int m,int r){
  int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] > R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
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
    #endif*/
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
    	scanf("%d",&arr[i]);
    }
    int diff[n-1];
    for (int i = 0; i < n-1; ++i)
    {
    	diff[i]=arr[i+1]-arr[i];
    }
    

    while(k--){
    	mergeSort(diff,0,n-2);
        /*for(int i=0;i<n-1;i++){
        printf("%d ",diff[i]);
        }
        printf("\n");*/
        if(diff[0]%2){
    		diff[0]=diff[0]/2 + 1;
    	}
    	else{
    		diff[0]/=2;
    	}

    }
    mergeSort(diff,0,n-2);
    printf("%d",diff[0]);





   return 0;
}