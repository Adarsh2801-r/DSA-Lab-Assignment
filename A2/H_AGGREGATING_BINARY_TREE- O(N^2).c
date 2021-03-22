#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const int MAX = 1e6;

int main() {
   // printf() displays the string inside quotation
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);

	}
	int x=1,sum=0,y=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<i+x;j++){
		    //printf("%d ",arr[j]);
			sum += ((y+1)*arr[j]);
		}
		y++;
		i=i+x-1;
		x*=2;
		//printf("\n");

	}
	printf("%d",sum);

  







	


	




   return 0;
}