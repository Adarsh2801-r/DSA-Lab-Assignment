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
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int n,m;
    scanf("%lld %lld",&n,&m);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
    	scanf("%lld",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    while(m--){
    	int q;
    	scanf("%lld",&q);
    	int l=0,r=n-1;
    	int f=0;
    	while(l<=r){
    		int m1 = l + (r-l)/3;
    		int m2 = r - (r-l)/3;
    		if(q==arr[m1]){
    			f=1;
    			printf("YES");
    			break;
    		}
    		if(q==arr[m2]){
    			f=1;
    			printf("YES");
    			break;
    		}
    		if(q<arr[m1]){
    			r = m1-1;


    		}
    		else if(q > arr[m2]){
    			l=m2+1;
    		}
    		else{
    			l=m1+1;
    			r=m2-1;
    		}
    }
    if(f==0){
    	printf("NO");
    	
    }
    printf("\n");
    }

    


   

  






    


//  printf("%c",head->next->next->next->data);
    




   return 0;
}