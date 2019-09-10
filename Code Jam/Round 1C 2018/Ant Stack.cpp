#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli H=1000000000000000000;
lli w[100001];
lli dp[100001][141];
lli solve(int in, int cnt){
	if(cnt==0)
		return 0;
	if(in<0||cnt>in+1){
		return H/1000;
	}
	if(dp[in][cnt]!=H)
		return dp[in][cnt];
	lli w1=solve(in-1,cnt-1);
	if(w1<=6*w[in])
		dp[in][cnt]=w1+w[in];
	w1=solve(in-1,cnt);
	return dp[in][cnt]=min(dp[in][cnt],w1);
}
int main(){
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			cin>>w[i];
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<141;j++)
				dp[i][j]=H;
		for(int i=140;i>0;i--){
			if(solve(n-1,i)<H/1000){
				printf("Case #%d: %d\n",c,i );
				break;
			}
		}
	}
}
