#include<bits/stdc++.h>
#define S 100001 //size of the array
using namespace std;
typedef long long int ll;
int k,n;
struct point{
	ll x,c;
	bool operator<(point o){
		return x<o.x;
	}
};
point p[S];

int get_cost(int i,int j){
	return p[i].c+abs(p[i].x-p[j].x);
}
int main(){
	int t;
	cin>>t;
	for(int nt=1;nt<=t;++nt){
		cin>>k>>n;
		for(int i=0;i<n;i++)
			cin>>p[i].x;
		for(int i=0;i<n;i++)
			cin>>p[i].c;
		sort(p,p+n);
		ll ans=LLONG_MAX;
		ll dp[101][101];
		for(int j=1;j<n;j++){
			for(int i=0;i<n;i++)
				dp[i][0]=0;
			for(int i=0;i<n;i++)
				for(int l=1;l<=k;l++)
					dp[i][l]=LLONG_MAX/2;

			dp[0][1]=get_cost(0,j);
			for(int i=1;i<n;i++){
				if(i==j){
					for(int l=1;l<=k;l++)
						dp[i][l]=dp[i-1][l];
					continue;
				}
				for(int l=1;l<=k;l++)
					dp[i][l]=min(dp[i-1][l-1]+get_cost(i,j),dp[i-1][l]);
			}
			ans=min(ans,dp[n-1][k]+p[j].c);
		}
		cout<<"Case #"<<nt<<": "<<ans<<"\n";
	}
}
