#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;
int result[26]={-1};
struct node{
    int d;
    int idx;
};

int flr(float x){
    return (int)x;
}
void merge(struct node *arr[],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int l1[n1],r1[n2];
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]->d;
        l1[i]=arr[l+i]->idx;
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j]->d;
        r1[j]=arr[m+j+1]->idx;
    }
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k]->d = L[i];
            arr[k]->idx = l1[i];
            i++;
        }
        else if(L[i]>R[j]){
            arr[k]->d = R[j];
            arr[k]->idx= r1[j];
            j++;
        }
        else{
            if (l1[i] < r1[j]) {
            arr[k]->d = L[i];
            arr[k]->idx = l1[i];
            i++;
        }
        else if(l1[i]>r1[j]){
            arr[k]->d = R[j];
            arr[k]->idx= r1[j];
            j++;
        }

        }
        k++;
    }
    while (i < n1) {
        arr[k]->d = L[i];
        arr[k]->idx = l1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k]->d = R[j];
        arr[k]->idx = r1[j];
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

void stableSort(struct node* arr[],int n){
    int c[2000]={0};
    struct node * b[n+1];
    for (int i = 0; i < n; ++i)
    {
        c[arr[i]->d]++;
    }
    for (int i = 1; i < 2000; ++i)
    {
        c[i]=c[i-1]+c[i];
    }
    for (int i = n-1;i>=0; --i)
    {
        b[c[arr[i]->d]] = (struct node*)malloc(sizeof(struct node));
        b[c[arr[i]->d]]->d=arr[i]->d;
        b[c[arr[i]->d]]->idx=arr[i]->idx;
        c[arr[i]->d]--;
    }
    for (int i = 0; i < n; ++i)
    {
        arr[i]->d=b[i+1]->d;
        arr[i]->idx=b[i+1]->idx;
    }
}


 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/

    int n,c,d,k;
    scanf("%lld%lld%lld%lld",&n,&c,&d,&k);
    int Bx[c],By[d];
    for(int i=0;i<c;i++){
        Bx[i]=0;
    }
    for(int i=0;i<d;i++){
        By[i]=0;
    }
    
    float xi[n],yi[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%f%f",&xi[i],&yi[i]);
        int a = flr(xi[i]);
        int b = flr(yi[i]);
    //  printf("%lld %lld \n",a,b);
        Bx[a]++;
        By[b]++;

    }
    struct node* cou[n];
    for (int i = 0; i < n; ++i)
    {
        int a = flr(xi[i]);
        int b = flr(yi[i]);
        cou[i]=(struct node*)malloc(sizeof(struct node));
        cou[i]->d=Bx[a]*By[b];
        cou[i]->idx=i;
        
    }
    //stableSort(cou,n);
    mergeSort(cou,0,n-1);
    for (int i = 0; i < n; ++i)
    {
        printf("%lld ",cou[i]->idx);
    }




   return 0;
}