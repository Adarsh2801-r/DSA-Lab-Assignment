#include <stdio.h>
const int MAX = 1e6;

int main() {
   // printf() displays the string inside quotation
	char s1[2000];
	char s2[2000];
	char s3[2000];
	scanf("%s",s1);
	scanf("%s",s2);
	int cou1=0,cou2=0;
	int x=0,y=0;
	while(s1[x]!='\0'){
		cou1++;
		x++;
	}
	while(s2[y]!='\0'){
		cou2++;
		y++;
	}
	char ans[2000];
	if(cou1>cou2){
		for(int i=0;i<cou1-cou2;i++){
			s3[i]='0';
		}
		for(int i=cou1-cou2;i<cou1;i++){
			s3[i]=s2[i-cou1+cou2];
		}
		s3[cou1]='\0';
		int carry=0;

		for (int i = cou1; i >=1; --i)
		{
			ans[i] = (s1[i-1]-'0'+s3[i-1]-'0' + carry)%10 + '0';
			carry =  (s1[i-1]-'0'+s3[i-1]-'0' + carry)/10;
		}
		
		ans[0] = carry+'0';
		ans[cou1+1]='\0';


	}
	else if(cou2>=cou1){
		for(int i=0;i<cou2-cou1;i++){
			s3[i]='0';
		}
		for(int i=cou2-cou1;i<cou2;i++){
			s3[i]=s1[i-cou2+cou1];
		}
		s3[cou2]='\0';

        int carry=0;
		for (int i = cou2; i >=1; --i)
		{
			ans[i] = (s2[i-1]-'0'+s3[i-1]-'0' + carry)%10 + '0';
			carry =  (s2[i-1]-'0'+s3[i-1]-'0' + carry)/10;
		}
		
		ans[0] = carry+'0';
		ans[cou2+1]='\0';



	}
	char sum[2000];
    int a=0,b=0;

        for(int i=0;ans[i]!='\0';i++){
            if(ans[i]!='0'){
                a=i;
                break;
            }
           
        }
         
        
    
    
         for(int i=a;ans[i]!='\0';i++){
            sum[b]=ans[i];
            b++;
            
        }
        sum[b]='\0';
    
   
	printf("%s",sum);




   return 0;
}