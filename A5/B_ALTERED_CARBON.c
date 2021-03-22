#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int mod = 1e9+7;
int result[26]={-1};
void merge(unsigned long long int arr[],int l,int m,int r){
  int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    unsigned long long int L[n1], R[n2];
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

void mergeSort(unsigned long long int arr[],int l,int r){
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
    scanf("%d %d",&n,&k);
    unsigned long long int c[200]={0};
    int l=0;
    for (int i = 0; i < n; ++i)
    {
    	char s[150];
    	scanf("%s",s);
    	for (int j=0;s[j]!='\0'; ++j)
    	{ 
    	        			

    		if(s[j]>='0'&&s[j]<='9'){
    		    unsigned long long int num = s[j]-'0';
    			while(1){
                    if(s[j+1]>='0'&&s[j+1]<='9'){
    				num = num*10 + (s[j+1]-'0');

                    }
    				else{
    					break;
    				}
    				j++;

    			}

                                            			c[l] += num;

    		}
    		
    		
    	}
    	    		l++;



    }
    mergeSort(c,0,l-1);
    unsigned long long int ans=0;
    for (int i = l-1; i >= l-k; --i)
    {
    	ans += c[i];
    	printf("%llu ",c[i]);
    	
    }
    printf("%llu",ans%mod);





   return 0;
}
