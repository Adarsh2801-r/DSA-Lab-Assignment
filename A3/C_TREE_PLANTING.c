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
   #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif	
	int n,m;
	scanf("%lld %lld",&n,&m);
	int arr[m];
	for(int i=0;i<m;i++){
		scanf("%lld",&arr[i]);
	}
	mergeSort(arr,0,m);
	int l=0,r=arr[m-1]-arr[0];
	int ans=-1,f=0;
	while(l<r){
		int mid= l + (r-l)/2;
		int x = arr[0];
		int cou=1;
		for(int i=1;i<m;i++){
			if(arr[i]-x>=mid){
				x=arr[i];
				cou++;
				if(cou==n){
					f=1;
					break;
				}
			}
		}
		if(f){
			if(mid>ans){
				ans=mid;
			}
							l=mid+1;


		}
		else{
			r=mid;
		}


	}
	printf("%lld",ans);







	


//	printf("%c",head->next->next->next->data);
	




   return 0;
}