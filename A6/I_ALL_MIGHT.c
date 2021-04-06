#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const double DOUBLE_MAX = 1e9;
int result[26]={-1};

struct villain{
	int x,y,idx,dist;
	double orient;
};

struct hero{
	int x,y,idx;
};

void merge(struct villain *arr[],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    double L[n1], R[n2];
    int l1[n1],r1[n2];
    int l2[n1],r2[n2];    
    int l3[n1],r3[n2];
    int l4[n1],r4[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]->orient;
        l1[i]=arr[l+i]->x;
        l2[i]=arr[l+i]->y;
        l3[i]=arr[l+i]->idx;
        l4[i]=arr[l+i]->dist;
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j]->orient;
        r1[j]=arr[m+j+1]->x;
        r2[j]=arr[m+j+1]->y;
        r3[j]=arr[m+j+1]->idx;
        r4[j]=arr[m+j+1]->dist;
    }
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <R[j]) {
            arr[k]->orient = L[i];
            arr[k]->x = l1[i];
                        arr[k]->y = l2[i];
                        arr[k]->idx=l3[i];
                        arr[k]->dist=l4[i];

 
            i++;
        }
        else if(L[i]==R[j]){
        	if(l4[i]<r4[j]){
        		arr[k]->orient = L[i];
            arr[k]->x = l1[i];
                        arr[k]->y = l2[i];
                        arr[k]->idx=l3[i];
                        arr[k]->dist=l4[i];

 
            i++;
        	}
        	else{
            arr[k]->orient = R[j];
            arr[k]->x= r1[j];
            arr[k]->y= r2[j];
            arr[k]->idx=r3[j];
            arr[k]->dist=r4[j];
            j++;
        	}
        }
        else {
            arr[k]->orient = R[j];
            arr[k]->x= r1[j];
            arr[k]->y= r2[j];
            arr[k]->idx=r3[j];
            arr[k]->dist=r4[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k]->orient = L[i];
            arr[k]->x = l1[i];
                        arr[k]->y = l2[i];
                        arr[k]->idx=l3[i];
                        arr[k]->dist=l4[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k]->orient = R[j];
            arr[k]->x= r1[j];
            arr[k]->y= r2[j];
            arr[k]->idx=r3[j];
            arr[k]->dist=r4[j];
        j++;
        k++;
    }


}

void mergeSort(struct villain* arr[],int l,int r){
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

    int n;
    scanf("%lld",&n);
    int x,y;
    int idx;
    struct villain* pts[n];
    for (int i = 0; i < n; ++i)
    {
    	scanf("%lld%lld%lld",&idx,&x,&y);
    	pts[i]= (struct villain*)malloc(sizeof(struct villain));
    	pts[i]->x= x;
    	pts[i]->y=y;
    	pts[i]->idx=idx;
    }

    struct hero *h = (struct hero*)malloc(sizeof(struct hero));
    int mn=0;
    for(int i=0;i<n;i++){
    	if(pts[i]->y<pts[mn]->y){
    		mn=i;
    	}
    }
    h->x=pts[mn]->x;
    h->y=pts[mn]->y;
    h->idx=pts[mn]->idx;

    struct villain*v[n-1];
   
    int cou=0;
    for (int i = 0; i < n; ++i)
    {
    	if(i==mn){
    		continue;
    	}
    	else{
    	    v[cou]=(struct villain*)malloc(sizeof(struct villain));
    		v[cou]=pts[i];
    		cou++;
    	}
    }
    int x1=h->x;
    int y1= h->y;
    
    struct villain* q1[n-1];
    struct villain* q2[n-1]; 
    struct villain* q3[n-1];
    struct villain* q4[n-1]; 
        int a=0,b=0,c=0,d=0;
        printf("%lld %lld\n",x1,y1);
    for(int i=0;i<n-1;i++){
    	int x2=v[i]->x;
    	int y2=v[i]->y;
    	int id = v[i]->idx;
    	if(x2>=x1&&y2>=y1){
    		q1[a]=(struct villain*)malloc(sizeof(struct villain));

    		q1[a]->x = x2;
           q1[a]->y = y2;
           q1[a]->idx=id;
           q1[a]->dist= abs_dist(x2,x1)+abs_dist(y2,y1);

           if(x2-x1==0){
            q1[a]->orient = DOUBLE_MAX;
           }
           else if(y2-y1==0){
            q1[a]->orient =0;
           }
           else{
                       q1[a]->orient = (double)(y2-y1)/(x2-x1);

           }


           a++;
    	}
    	if(x2<x1&&y2>y1){
           q2[b]=(struct villain*)malloc(sizeof(struct villain));

           q2[b]->x = x2;
           q2[b]->y = y2;
           q2[b]->orient = (double)(y2-y1)/(x2-x1) ;
           q2[b]->idx=id;
           q2[b]->dist= abs_dist(x2,x1)+abs_dist(y2,y1);


           b++;
      }
      if(x2<=x1&&y2<=y1){
      	   q3[c]=(struct villain*)malloc(sizeof(struct villain));

           q3[c]->x = x2;
           q3[c]->y = y2;
           q3[c]->idx=id;
           q3[c]->dist= abs_dist(x2,x1)+abs_dist(y2,y1);

           if(x2-x1==0){
            q3[c]->orient = DOUBLE_MAX;
           }
           else if(y2-y1==0){
            q3[c]->orient =0;
           }
           else{
                       q3[c]->orient = (double)(y2-y1)/(x2-x1) ;

           }
           c++;
      }
      if(x2>x1&&y2<y1){
      	   q4[d]=(struct villain*)malloc(sizeof(struct villain));
           q4[d]->x = x2;
           q4[d]->y = y2;
           q4[d]->orient = (double)(y2-y1)/(x2-x1) ;
           q4[d]->idx=id;
           q4[d]->dist= abs_dist(x2,x1)+abs_dist(y2,y1);


           d++;
      }


    }
   
    mergeSort(q1,0,a-1);
    mergeSort(q2,0,b-1);
    mergeSort(q3,0,c-1);
    mergeSort(q4,0,d-1);
    for(int i=0;i<a;i++){
        printf("%lld--%lld--%lld--%f\n",q1[i]->idx,q1[i]->x,q1[i]->y,q1[i]->orient);
    }
    for(int i=0;i<b;i++){
        printf("%lld--%lld--%lld--%f\n",q2[i]->idx,q2[i]->x,q2[i]->y,q2[i]->orient);

    }
    for(int i=0;i<c;i++){
       printf("%lld ",q3[i]->idx);

    }
    for(int i=0;i<d;i++){
        printf("%lld ",q4[i]->idx);

    }
   





   return 0;
}