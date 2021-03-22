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
	int a,p,c;
	scanf("%lld %lld %lld",&a,&p,&c);
	int auth[p];
	for(int i=0;i<p;i++){
		scanf("%lld",&auth[i]);
	}
	int adj[p][p];
	for (int i = 0; i < p; ++i)
	{
		for (int j=0;j<p;++j)
		{
			adj[i][j]=0;
		}
	}
	for (int i = 0; i < c; ++i)
	{
		int x,y;
		scanf("%lld %lld",&x,&y);
		adj[y][x]=1;
	}

	int indeg[p];

	int s=0;

	for(int i=0;i<p;i++){
		s=0;
		for(int j=0;j<p;j++){
			if(adj[i][j]){
				s++;
			}
		
		}

		indeg[i]=s;

	} 

	int cou=0;

	int h_index[a];
	for (int i = 0; i < a; ++i)
	{
		h_index[i]=0;
	}

	int start[a];
    int f=0;
	for(int i=0;i<a;i++){
		cou=0;
		f=0;
		for (int j = 0; j< p; ++j)
		{
			if(auth[j]==i){
				
				if(indeg[j]<cou+1){
					f=1;
					break;

				}
				cou++;

			}

		}
		
		h_index[i]=cou;
	}
	for (int i = 0; i < a; ++i)
	{
		printf("%lld ",h_index[i]);
	}






	


//	printf("%c",head->next->next->next->data);
	




   return 0;
}