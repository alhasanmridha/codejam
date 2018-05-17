#include <bits/stdc++.h>
using namespace std;
int n,w[100],dp[100][6002];
int solve(int in, int wcap){
	if(in==n||wcap==0)
		return 0;
	if(dp[in][wcap]!=-1)
		return dp[in][wcap];
	if(w[in]>wcap)
		return solve(in+1,wcap);
	int wcap1;
	if(wcap==6001)
		wcap1=6*w[in];
	else
		wcap1=min(6*w[in],wcap-w[in]);
	return dp[in][wcap]=max(1+solve(in+1,wcap1),solve(in+1,wcap));
}
void reint(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<6002;j++){
			dp[i][j]=-1;
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		scanf("%d",&n);
		reint(n);
		for(int i=0;i<n;i++){
			scanf("%d",w+i);
		}
		reverse(w,w+n);
		printf("Case #%d: %d\n",c,solve(0,6001));
	}
	return 0;
}
