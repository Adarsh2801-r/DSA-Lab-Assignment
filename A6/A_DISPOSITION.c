#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 1e9;
int result[26]={-1};
int cou_low=1;
int cou_up=1;
struct node{
	int a;
	int b;

};
void merge(struct node *arr[],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int l1[n1],r1[n2];
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]->b;
        l1[i]=arr[l+i]->a;
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j]->b;
        r1[j]=arr[m+j+1]->a;
    }
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k]->b = L[i];
            arr[k]->a = l1[i];
            i++;
        }
        else if(L[i]>R[j]){
            arr[k]->b = R[j];
            arr[k]->a= r1[j];
            j++;
        }
        else{
        	if (l1[i] < r1[j]) {
            arr[k]->b = L[i];
            arr[k]->a = l1[i];
            i++;
        }
        else if(l1[i]>r1[j]){
            arr[k]->b = R[j];
            arr[k]->a= r1[j];
            j++;
        }

        }
        k++;
    }
    while (i < n1) {
        arr[k]->b = L[i];
        arr[k]->a = l1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k]->b = R[j];
        arr[k]->a = r1[j];
        j++;
        k++;
    }


}

void mergeSort(struct node* arr[],int l,int r){
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
    struct node* arr[n];
    for (int i = 0; i < n; ++i)
    {
    	int x;
    	scanf("%d",&x);
        arr[i]=(struct node*)malloc(sizeof(struct node));
        arr[i]->a=x;
        arr[i]->b= x%k;
    }
    mergeSort(arr,0,n-1);
    for (int i = 0; i < n; ++i)
    {
    	printf("%d ",arr[i]->a);
    }
    





   return 0;
}