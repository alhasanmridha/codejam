#include <bits/stdc++.h>
using namespace std;
int n,q;
double e[101],s[101],d[101][101],u[101],v[101];
int main(){
	ifstream cin("input");
	ofstream cout("output");
	int test;
	cin>>test;
	for(int c=1;c<=test;c++){
		cout<<"Case #"<<c<<": ";
		cin>>n>>q;
		double dp[101];
		for(int i=0;i<=n;i++)
			dp[i]=1e15;
		for(int i=0;i<n;i++)
			cin>>e[i]>>s[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>d[i][j];
		for(int i=0;i<q;i++)
			cin>>u[i]>>v[i];
		dp[n-1]=0;
		for(int i=n-1;i>0;i--){
			double rest=e[i-1],dist=0;
			for(int j=i;j<n;j++){
				dist+=d[j-1][j];
				if(dist>e[i-1]) break;
				dp[i-1]=min(dp[i-1],dist/s[i-1]+dp[j]);
			}
		}
		cout<<fixed<<setprecision(6)<<dp[0]<<"\n";
	}
}
