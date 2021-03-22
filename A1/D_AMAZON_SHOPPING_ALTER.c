#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const int MAX = 1e6;


int main() {
   // printf() displays the string inside quotation
   int m;
    scanf("%d",&m);
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int tot = 1<<n;
    int sum=0;
    int x=0,mx=0;
    for(int i=0;i<tot;i++){
        sum=0;
        x=0;
        for(int j=0;j<n;j++){
            int f = 1<<j;
            if((i&f)!=0){
                sum += arr[j];
                x++;
            }
        }
       //printf("%d ",sum);
        if(sum<=m){
            if(x>=mx){
                mx=x;

            }

        }


    }
    
    printf("%d",mx);

 


    

//  printf("%c",head->next->next->next->data);
    




   return 0;
}