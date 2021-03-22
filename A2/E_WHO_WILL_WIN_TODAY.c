#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const int MAX = 1e6;
void f(char *arr,char *a,int i,int k,int n){
	
    if(i==k){
		
		printf("%s\n",arr);
		return;
	}
	for(int j=0;j<n;++j){
		arr[i]=a[j];
		f(arr,a,i+1,k,n);}
	
	



}
int main() {
   // printf() displays the string inside quotation
   int n,k;
   scanf("%d %d\n",&n,&k);
   char a[n];
   scanf("%s",a);
   char *arr = (char *) malloc (sizeof(char) * (k+1)) ; 
   arr[k] = '\0'; 
   f(arr,a,0,k,n);
   free(arr);
    







	


//	printf("%c",head->next->next->next->data);
	




   return 0;
}