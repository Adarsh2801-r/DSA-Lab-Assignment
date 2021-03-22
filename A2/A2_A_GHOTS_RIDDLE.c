#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const int MAX = 1e6;
int f(int n,int arr[]){
	int x=0;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			arr[x]=i;
			x++;
		}
	}

	if(x<=3){
		return n;
	}
	int div1 = arr[x-2];
	int div2 = arr[x-3];
	return f(div1,arr)+f(div2,arr);
	



}
int main() {
   // printf() displays the string inside quotation
   int n;
   int arr[n+1];
   scanf("%d",&n);
   printf("%d",f(n,arr));
    







	


//	printf("%c",head->next->next->next->data);
	




   return 0;
}