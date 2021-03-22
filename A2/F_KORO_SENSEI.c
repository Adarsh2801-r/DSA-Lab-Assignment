#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define int long long
const int MAX = 1e6;
const int mod = 1e9 + 7;

int logg(int n){
    return (n > 1) ? 1 + logg(n / 2) : 0; 
}
int f(int n,int k){
	if (n == 0){
        return 1;}
 
    if (k == 0){
        return 1;}

    if (n >= pow(2, k)) {
        int curr_val = pow(2, k);
        return f(n - curr_val, k)
               + f(n, k - 1);
    }
    else{
        return f(n, k - 1);}

}

int main() {
   // printf() displays the string inside quotation
   int n;

   scanf("%lld",&n);
   int k = logg(n);
   printf("%lld",f(n,k));








	


	




   return 0;
}