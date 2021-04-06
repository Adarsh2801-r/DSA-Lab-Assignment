#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 1e9;
int result[26]={-1};
int cou=0;
int t1=-1,t2=-1;
void push1(int st[],int x){
    t1++;
    st[t1]=x;
}
void push2(int st[],int x){
    t2++;
    st[t2]=x;
}
int top1(int st[]){
    t1--;
    return st[t1+1];
}
int top2(int st[]){
    t2--;
    return st[t2+1];
}

void reverse(char s[],int a,int b){
    for(int i=a;i<=(a+b)/2;i++){

        char t=s[i];
        s[i]=s[b-i+a];
        s[b-i+a]=t;
    } 
}

void inc(char s[],int a,int b){
     for(int i=a;i<=b;i++){
        if(s[i]>='a'&&s[i]<='z'){
        s[i]++;}
    } 
}


 

int main() {
   // printf() displays the string inside quotation
   /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    char s[100000];
    scanf("%s",s);
    char a1[100000],a2[100000];
    int stack1[100000],stack2[100000];
    int n=0,len1=0,len2=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='('){
            push1(stack1,i);
        }
        if(s[i]=='['){
            push2(stack2,i);
        }
        if(s[i]==')'){
            int x = top1(stack1);
            reverse(s,x+1,i-1);
            
        }
        if(s[i]==']'){
            int x= top2(stack2);
            inc(s,x+1,i-1);
        }
        
    }
    for(int i=0;s[i]!='\0';i++){
            if(s[i]>='a'&&s[i]<='z'){
                    printf("%c",s[i]);}

        }
    

  

   return 0;
}