#include<stdio.h>
 
const int MOD = 1000000000 +7;
 
long long unsigned fact(long long unsigned n){
    if (n == 1)
        return 1;
    return (n*fact(n-1));
}
 
int main(){

    long long unsigned n;
    int x, pos;
    scanf("%lld %d %d", &n, &x, &pos);
    printf("%lld", fact(n-1)%MOD);
    
}
