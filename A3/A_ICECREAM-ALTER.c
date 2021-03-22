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
    #endif	*/

	int n,m,k;
	scanf("%lld %lld %lld",&n,&m,&k);
	int arr[n];
	int s[m];
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld",&arr[i]);	
	}

	for (int i = 0; i < m; ++i)
	{
		scanf("%lld",&s[i]);	
	}
	mergeSort(arr,0,n-1);
	mergeSort(s,0,m-1);
	int cou=0,r=n-1,r1=m-1;
	int f[m];
	for(int i=0;i<m;i++){
	    f[i]=0;
	}
	while(r>=0&&r1>=0){
	  //  printf("%lld %lld\n",r,r1);
	    if(s[r1]>arr[r]+k){
	        r1--;
	        
	    }
	    else if(s[r1]<arr[r]-k){
	        r--;
	    }
	    else{
	        if(f[r1]==0){
	        cou++;
	        f[r1]=1;
	        r1--;
	        r--;
	        
	        }
	       
	    }
	    
	}
	/*for(int i=0;i<m;i++){
	    printf("%lld ",f[i]);
	}*/
	printf("%lld",cou);

   return 0;
}