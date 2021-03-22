#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const int MAX = 1e6;
long long int x,y;
void subset(int n,int bit[n],int sub[x][n],int i){
	if(i==n){
	    for(int j=0;j<n;j++){
	        sub[y][j]=bit[j];
	    }
		y++;
		return;
	}
	bit[i]=0;
	subset(n,bit,sub,i+1);
	bit[i]=1;
		subset(n,bit,sub,i+1);



}
int main() {
   // printf() displays the string inside quotation
    long long int m;
    scanf("%lld",&m);
    int n;
    scanf("%d",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
    	scanf("%lld",&arr[i]);
    }
    
    
    x = (int)pow(2,n);
    int sub[x][n];

    int bit[n];
    subset(n,bit,sub,0);
    long long int sum=0,mx=0;
    for(long long int i=0;i<x;i++){
        sum=0;
    	for(int j=0;j<n;j++){
    	    if(sub[i][j]==1){
    		sum += arr[j];
    		}
    	}
    	if(sum<m){
    	    mx=i;
    	}
    	//printf("\n");
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(sub[mx][i]==1){
            ans++;
        }
    }
    printf("%d",ans);

    







	

//	printf("%c",head->next->next->next->data);
	




   return 0;
}

