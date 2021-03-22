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
  
   int n,k1,k2;
   scanf("%lld %lld %lld",&n,&k1,&k2);
   int a[n];
   int b[n];
   int c[n];
   for (int i = 0; i < n; ++i)
   {
    scanf("%lld",&a[i]);
   }
   for (int i = 0; i < n; ++i)
   {
    scanf("%lld",&b[i]);
   }
   for (int i = 0; i < n; ++i)
   {
    c[i]=a[i]-b[i];
   }
   int k = k2-k1;
   int l=0,r=n-1;
   int ans=0;
   mergeSort(c,0,n-1);
   /*for(int i=0;i<n;i++){
    printf("%lld ",c[i]);
   }*/
   while(l<r){
    if(c[l]+c[r]>k){
      ans += (r-l);
          r--;

    }
    else{
      l++;
    }
   }

   printf("%lld",ans);




  







  


  




   return 0;
}