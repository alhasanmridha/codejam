#include<bits/stdc++.h>
using namespace std;
int n,k,p,b[51][31],dp[51][31][1501];
int solve(int i,int j,int al){
	if(i==n or al==p) return 0;
	if(j==k) return solve(i+1,0,al);
	if(dp[i][j][al]!=-1) return dp[i][j][al];
	int cur=b[i][j]+solve(i,j+1,al+1);
	int nxt=solve(i+1,0,al);
	return dp[i][j][al]=max(cur,nxt);
}
int main(){
	int t;
	cin>>t;
	for(int nt=1;nt<=t;nt++){
		cin>>n>>k>>p;
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				cin>>b[i][j];
			}
		}
		for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) for(int w=0;w<=p;w++) dp[i][j][w]=-1;
		cout<<"Case #"<<nt<<": "<<solve(0,0,0)<<"\n";
	}
}
