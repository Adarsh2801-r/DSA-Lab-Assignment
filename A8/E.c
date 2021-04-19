#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int mod = 1e9+7;
const int MAX = 1e9;
int result[26]={-1};

void f(int in[],int pre[],int n){
    int root=-1;
    for(int i=0;i<n;i++){
        if(in[i]==pre[0]){
            root=i;
            break;
        }
    }
    if(root!=0){
        f(in,pre+1,root);
    }
    if(root!=n-1){
        f(in+root+1,pre+root+1,n-root-1);
    }
    printf("%lld ",pre[0]);
}

int main()
{
    int n;
    scanf("%lld",&n);
    int pre[n],in[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&in[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&pre[i]);
    }
    f(in,pre,n);
    
    return 0;
}
