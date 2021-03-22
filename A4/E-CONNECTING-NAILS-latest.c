#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;
const int DOUBLE_MAX = 1e9;
int result[26]={-1};


struct node{
  int x;
  int y;
  double m;
};

void merge(struct node *arr[],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    double L[n1], R[n2];
    int l1[n1],r1[n2];
int l2[n1],r2[n2];
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]->m;
        l1[i]=arr[l+i]->x;
        l2[i]=arr[l+i]->y;
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j]->m;
        r1[j]=arr[m+j+1]->x;
        r2[j]=arr[m+j+1]->y;
    }
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k]->m = L[i];
            arr[k]->x = l1[i];
                        arr[k]->y = l2[i];

 
            i++;
        }
        else {
            arr[k]->m = R[j];
            arr[k]->x= r1[j];
            arr[k]->y= r2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k]->m = L[i];
            arr[k]->x = l1[i];
                        arr[k]->y = l2[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k]->m = R[j];
            arr[k]->x= r1[j];
            arr[k]->y= r2[j];
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

int abs_dist(int a,int b){
  return a>b ? a-b:b-a;

}

 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int m;
    scanf("%lld",&m);
    struct node * q1[m];
    struct node * q2[m];
    struct node * q3[m];
    struct node * q4[m];
    int a=0,b=0,c=0,d=0;
    for (int i = 0; i < m; ++i)
    {
      int xi,yi;
      scanf("%lld %lld",&xi,&yi);
      if(xi>=0&&yi>=0){
           q1[a]=(struct node*)malloc(sizeof(struct node));
           q1[a]->x = xi;
           q1[a]->y = yi;
           if(xi==0){
            q1[a]->m = DOUBLE_MAX;
           }
           else if(yi==0){
            q1[a]->m =0;
           }
           else{
                       q1[a]->m = yi/xi ;

           }


           a++;
      }
      if(xi<0&&yi>0){
           q2[b]=(struct node*)malloc(sizeof(struct node));
           q2[b]->x = xi;
           q2[b]->y = yi;
           q2[b]->m = yi/xi ;
           b++;
      }
      if(xi<=0&&yi<=0){
           q3[c]=(struct node*)malloc(sizeof(struct node));
           q3[c]->x = xi;
           q3[c]->y = yi;

           if(xi==0){
            q3[c]->m = DOUBLE_MAX;
           }
           else if(yi==0){
            q3[c]->m =0;
           }
           else{
                       q3[c]->m = yi/xi ;

           }
           c++;
      }
      if(xi>0&&yi<0){
           q4[d]=(struct node*)malloc(sizeof(struct node));
           q4[d]->x = xi;
           q4[d]->y = yi;
           q4[d]->m = yi/xi ;
           d++;
      }
      

    }
    mergeSort(q1,0,a-1);
    mergeSort(q2,0,b-1);
    mergeSort(q3,0,c-1);
    mergeSort(q4,0,d-1);
    int dist=0;
    struct node * arr[m];
    int k=0;
    for(int i=0;i<a;i++){
        arr[k]=(struct node*)malloc(sizeof(struct node));
        arr[k]->x = q1[i]->x;
        arr[k]->y = q1[i]->y;
        arr[k]->m = q1[i]->m;
        k++;
    }
    for(int i=0;i<b;i++){
        arr[k]=(struct node*)malloc(sizeof(struct node));
        arr[k]->x = q2[i]->x;
        arr[k]->y = q2[i]->y;
        arr[k]->m = q2[i]->m;
        k++;
    }
    for(int i=0;i<c;i++){
        arr[k]=(struct node*)malloc(sizeof(struct node));
        arr[k]->x = q3[i]->x;
        arr[k]->y = q3[i]->y;
        arr[k]->m = q3[i]->m;
        k++;
    }
    for(int i=0;i<d;i++){
        arr[k]=(struct node*)malloc(sizeof(struct node));
        arr[k]->x = q4[i]->x;
        arr[k]->y = q4[i]->y;
        arr[k]->m = q4[i]->m;
        k++;
    }
    for (int i = 0; i < m-1; ++i)
    {
      dist += abs_dist(arr[i]->x,arr[i+1]->x) + abs_dist(arr[i]->y,arr[i+1]->y);
    //  printf("%lld\n",abs_dist(arr[i]->x,arr[i+1]->x) + abs_dist(arr[i]->y,arr[i+1]->y));
    }
    if(m>2){
    dist += abs_dist(arr[0]->x,arr[m-1]->x) + abs_dist(arr[0]->y,arr[m-1]->y);}
    
  
     for (int i = 0; i < m; ++i)
    {
      printf("%lld %lld\n",arr[i]->x,arr[i]->y);
    }
    
      
   

   printf("%lld", dist);






    


    




   return 0;
}