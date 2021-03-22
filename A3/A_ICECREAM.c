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
	mergeSort(arr,0,n);
	mergeSort(s,0,m);
	for (int i = 0; i < m; ++i)
	{
		printf("%lld ",s[i]);
	}
	int f[m],f1[m];
	for (int i = 0; i < m; ++i)
	{
		f[i]=0;
		f1[i]=0;
	}
	int cou=0,cou1=0;
	for (int i = 0; i < n; ++i)
	{
		int lr=arr[i]-k;
		int rr=arr[i]+k;
		int l=0,r=m-1;
		int x=0,y=0;
		if(l==r){
			if((s[0]>=lr&&s[0]<=rr)&&(f[l]==0)){
				printf("%lld ",s[0]);
				f[l]=1;

			}
		}
		else{
		while(l<r){
			int mid = l + (r-l)/2;
			if(s[mid]>rr){
				r = mid;
			}
			else if(s[mid]<lr||f[mid]==1){
				l = mid+1;
			}
			if(s[mid]>=lr&&s[mid]<=rr&&f[mid]==0){
				x++;
				f[mid]=1;
				break;
			}
			if(l==r&&s[l]>=lr&&s[l]<=rr&&f[l]==0){
				x++;
				f[l]=1;
				break;
			}
		}
		int l1=0,r1=m-1;
		while(l1<r1){
			int mid = l1 + (r1-l1)/2;
			if(s[mid]>rr||f1[mid]==1){
				r1 = mid;
			}
			else if(s[mid]<lr){
				l1 = mid+1;
			}
			if(s[mid]>=lr&&s[mid]<=rr&&f1[mid]==0){
				f1[mid]=1;
				break;
			}
			if(l1==r1&&s[l1]>=lr&&s[l1]<=rr&&f1[l1]==0){
				f1[l]=1;
				break;
			}
		}
		
		    
		}

	}
	printf("\n");
	
	
	for(int i=0;i<m;i++){
	    if(f[i]|f1[i]){
	        cou++;
	    }
	    printf("%lld ",f[i]);
	}
	printf("\n");
for(int i=0;i<m;i++){
	    printf("%lld ",f1[i]);
	}
	printf("\n");
		printf("%lld\n", cou);








	


//	printf("%c",head->next->next->next->data);
	




   return 0;
}