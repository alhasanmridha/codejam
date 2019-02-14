#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
bool is_sq[MAX];
int dp[MAX];
int solve(int n){
	if(is_sq[n]) return 1;
	if(dp[n]!=MAX) return dp[n];
	for(int i=1;i<=n/2;i++)
		dp[n]=min(dp[n],solve(n-i)+solve(i));
	return dp[n];
}
int main(){
	for(int i=1;i<MAX;i++) dp[i]=MAX;
	for(int i=1;i*i<MAX;i++) is_sq[i*i]=true;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n,cnt;
	cin>>t;
	for(int c=1;c<=t;c++){
		cin>>n;
		cout<<"Case #"<<c<<": "<<solve(n)<<"\n";
	}
	return 0;
}
