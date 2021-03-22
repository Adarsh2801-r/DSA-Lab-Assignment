#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;

const int mod = 1e9 + 7;
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
        if (L[i] <= R[j]) {
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
    int n,d;
    scanf("%lld %lld",&n,&d);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    mergeSort(arr,0,n-1);
   int p=n-1;
   int cou=0;
   int x = arr[n-1];
   int sum=0;
   while(cou<d){
       if(p==0){
           mergeSort(arr,0,n-1);
           p=n-1;
       }
       if(arr[p]<arr[p-1]){
           p--;

       }
       sum = (sum + arr[p])%mod;
       cou++;
       arr[p]/=3;
   }
   printf("%lld",sum);


   return 0;
}