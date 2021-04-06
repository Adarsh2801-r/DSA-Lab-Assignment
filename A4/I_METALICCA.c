#include<stdio.h>
 
const int MOD = 1000000000 +7;
 
long long unsigned factorial(long long unsigned n){
    if (n == 1)
        return 1;
    return (n*factorial(n-1));
}
 
int main(){

    long long unsigned n, ans;
    int x, pos;
    scanf("%lld %d %d", &n, &x, &pos);
    ans = factorial(n-1);
    printf("%lld", ans%MOD);
    
}
