#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define int long long
const int MAX = 1e6;
const int DOUBLE_MAX = 1e9;
int result[26]={-1};




 
int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    char s1[200];
    char s2[200];
    char s3[400];
    scanf("%s",s1);
    scanf("%s",s2);
    int n1=0,n2=0;
    int k=0;
    while(s1[k]!='\0'){
    	n1++;
    	k++;

    }
    k=0;
    while(s2[k]!='\0'){
    	n2++;
    	k++;

    }
    int p1=0,p2=0;
    int p3=0;
    while(p1<n1&&p2<n2){
//        printf("%lld %lld\n",p1,p2);
    	if(s1[p1]>s2[p2]){
    		s3[p3]=s1[p1];
    		p1++;
    		p3++;

    	}
    	else if(s1[p1]<s2[p2]){
    		s3[p3]=s2[p2];
    		p2++;
    		p3++;
    	}
    	else{
    	    
    		int x=p1;
    		int y=p2;
    		int c1=0,c2=0;
    		    	//	printf("%lld %lld %lld %lld --- ",x,y,c1,c2);

    		while(s1[x]==s1[x+1]&&x<n1){
    			c1++;
    			x++;

    		}
    		if(x<n1-1){
    			    		x++;

    		}
    		while(s2[y]==s2[y+1]&&y<n1){
    			c2++;
    			y++;

    		}
    		if(y<n2-1){
    		y++;}
           printf("%lld %lld %lld %lld\n",x,y,c1,c2);
    		if(c1>c2){
    			if(s2[y]<s2[y-1]){
    				s3[p3]=s1[p1];
    				p1++;
    				p3++;
    			}
    			else{
    				s3[p3]=s2[p2];
    		        p2++;
    		        p3++;
    			}

    		}
    		else if(c1<c2){
    			if(s1[x]<s1[x-1]){
    				s3[p3]=s2[p2];
    				p2++;
    				p3++;
    			}
    			else{
    				s3[p3]=s1[p1];
    		        p1++;
    		        p3++;
    			}
    		}
    		else{
    			if(s1[x]>=s2[y]){
    				s3[p3]=s1[p1];
    		        p1++;
    		        p3++;

    			}
    			else{
    				s3[p3]=s2[p2];
    				p2++;
    				p3++;
    			}
    		}



    	}

    }
    while(p1<n1){
    	s3[p3]=s1[p1];
    	p3++;
    	p1++;
    }
    while(p2<n2){
    	s3[p3]=s2[p2];
    	p3++;
    	p2++;
    }
    s3[p3]='\0';
    printf("%s",s3);
   


   return 0;
}