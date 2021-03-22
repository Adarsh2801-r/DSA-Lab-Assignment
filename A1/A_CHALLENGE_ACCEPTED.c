#include <stdio.h>
const int MAX = 1e6;

int n;
int cou;
int cou1=0;
int f,g;
void substring(){
	if(cou==n+1){
		return;
	}
	char ch;
	scanf("%c",&ch);
	if(cou1==0){
		if(ch=='b'){
			cou1++;
		}

	}
	else if(cou1==1){
		if(ch=='a'){
			cou1++;
		}
	}
	else if(cou1==2){
		if(ch=='a'){
			cou1++;
		}
		else{
			cou1--;
		}
	}
	else if(cou1==3){
		if(ch=='a'){
			cou1=0;
		}
		else{
			cou1=1;
			f++;
			if(f==1){
			    printf("YES ");
			}
			printf("%d ",cou-3);
		}
	}


	

	cou++;
	substring();


}


int main() {
   // printf() displays the string inside quotation
   scanf("%d",&n);
   substring();
   if(f==0){
       printf("NO");
   }
   

   return 0;
}