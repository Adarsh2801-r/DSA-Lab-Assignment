#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <sstream>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ull unsigned long long 
//#define int long long 
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define MAX 1e18
#define PI 3.14159265
const int mod = 1e9 + 7;
 std::vector<vector<char>> ans;
 int f=0;
	     bool vis[55][55];
	     int c[55][55];
	     std::vector<pair<int,int>> p1,p2;
	     int rowNum[]={-1,-1,-1,0,0,1,1,1};
	     int colNum[]={-1,0,1,-1,1,-1,0,1};
	    // const int n=6;

int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int lcm(int a, int b){
	return (gcd(a,b))/(a*b);
}
bool isValid(int x, int y, int prx,int pry,int n){
	return (x>=0)&&(x<n)&&(y>=0)&&(y<n)&&!(x==prx&&y==pry);
}
void dfs(int s, vector<bool>& visited,vector<int>adj[]){

   if(visited[s]){
   	f=1; 
   	return;  
   }
   if(adj[s].size()==0){
   	return;
   }
   visited[s]=true;
   for (auto i:adj[s])
   {
   	dfs(i,visited,adj);
   }

    



	
}
 
 
int32_t main(){
 
	IOS;
	
	     /*int m,s,d;
	     cin>>m>>s>>d;
	     int adj[n][n];
	     for (int i = 0; i < n; ++i)
	     {
	     	for (int j=0;j<n; ++j)
	     	{
	     		adj[i][j]=INT_MAX;
	     	}
	     }
	     bool visited[n]={0};
	     for (int i = 0; i < m; ++i)
	     {
	     	int e1,e2,wt;
	     	cin>>e1>>e2>>wt;
	     	adj[e1-1][e2-1] = wt;
	     	adj[e2-1][e1-1] = wt;
	     }
	     visited[s]=true;
	     cout<<dfs(s,d,visited,adj);*/
	/*int n,m;
	cin>>n>>m;
	std::vector<int> adj[n];
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin>>x>>y;
		adj[y].pb(x);
	}*/
	int a,b;
	cin>>a>>b;
	int isPrime[b+1]={0};
	for (int i = 2; i*i<=b ; ++i)
	{
		if(isPrime[i]==0){
			for (int j=2*i;j<=b;j+=i)
			{
				isPrime[j]=1;
			}


		}
	}
	int freq[10]={0};
	for (int i = a;i<=b;i++)
	{
		if(isPrime[i]==0){
			int x=i;
			while(x){
				freq[x%10]++;
				x/=10;

			}
		}
	}
	int mx=0,m_num=0;
	for (int i = 0; i < 10; ++i)
	{
		if(freq[i]>mx){
			mx = freq[i];
			m_num=i;
		}
	}
	cout<<m_num<<" "<<mx;

	












	    




	
	return 0;
}
		
