#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e9;
int main()
{
    int n;
    scanf("%lld",&n);
    int arr[n];
        int sum=0,mx=0;
    int neg_mx=-MAX;
    int flag=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        if(arr[i]>0){
            flag=1;
        }
        if(arr[i]>neg_mx){
            neg_mx=arr[i];
        }
    }
    if(flag){
        for(int i=0;i<n;i++){
            if(sum+arr[i]>0){
                sum+=arr[i];
            }
            else{
                sum=0;
            }
            if(sum>=mx){
                mx=sum;
            }
        }
        printf("%lld",mx);
    }
    else{
        printf("%lld",neg_mx);
    }
    
    
    return 0;
}
