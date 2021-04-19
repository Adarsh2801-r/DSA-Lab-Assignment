#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int n;
    long long int x;
    scanf("%lld", &n);
 
    int arr[1000000] = {0};
 
    int d = 0;
 
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &x);
        if (x > n) {
            d++;
        } else {
            arr[x]++;
        }
    }
 
    for (int i = 1; i <= n; ++i) {
        if (arr[i] == i) continue;
        if (arr[i] < i) d+= arr[i];
        if (arr[i] > i) d += (arr[i] - i);
    }
 
    printf("%d", d);
 
    return 0;
}