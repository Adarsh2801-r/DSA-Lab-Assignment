#include <stdio.h>
//#define long long int
const int MAX = 1e6;

int main() {
   // printf() displays the string inside quotation
	int t;
	scanf("%d\n",&t);
	int ans=0,mx=0;
	char x;
	while(t--){
		scanf(" %c",&x);
		//printf("%c",x);

		if(x=='E'){
			int n;
			scanf("%d",&n);
			ans += n;
				//printf("%d ",ans);
					//	printf("hello ");


		}
		else{
			int p;
			scanf("%d",&p);
			int y[p];
			for (int i = 0; i < p; ++i)
			{
							scanf("%d",&y[i]);

			}
			ans -= p;
		}
		if(ans>mx){
		    mx=ans;
		}
	//	printf("hello ");


	}
	printf("%d",mx);

   return 0;
}