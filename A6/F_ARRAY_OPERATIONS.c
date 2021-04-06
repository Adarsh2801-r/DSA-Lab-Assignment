#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 1e9;
int result[26]={-1};
int cou_low=1;
int cou_up=1;

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int n,t;
    scanf("%d%d",&n,&t);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&arr[i]);
    }
    int rot[t];
        int tot_rot[t];

    for (int i = 0; i < t; ++i)
    {
        scanf("%d",&rot[i]);
        tot_rot[i]=0;
    }
    int sum=0;
    for (int i = 0; i < t; ++i)
    {
        sum += rot[i];
        tot_rot[i]+=sum;
    }
    for (int i = 0; i < t; ++i)
    {
        int start = tot_rot[i]%n;
        int end= (start + n-1)%n;
        printf("%d %d\n",arr[start],arr[end]);
    }




   return 0;
}

