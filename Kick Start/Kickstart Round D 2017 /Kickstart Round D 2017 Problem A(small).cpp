#include <bits/stdc++.h>
using namespace std;
int n,ts,tf,s[2001],f[2001],d[2001];
int dp(int in,int t){
	if(t>tf) return -100000;
	if(in==n-1) return 0;
	int tmax=t+ts,tmin=t;
	for(int x=0;;x++){
		if(s[in]+x*f[in]>=tmin){
			tmin=s[in]+x*f[in];
			break;
		}
	}
	int a=dp(in+1,tmin+d[in]);
	for(int x=0;;x++){
		if(s[in]+x*f[in]>=tmax){
			tmax=s[in]+x*f[in];
			break;
		}
	}
	int b=1+dp(in+1,tmax+d[in]);
	return max(a,b);
}
int main(){
	freopen("input","r",stdin);
	freopen("output","w",stdout);
	int T;
	cin>>T;
	for(int C=1;C<=T;C++){
		scanf("%d%d%d",&n,&ts,&tf);
		for(int i=0;i<n-1;i++){
			scanf("%d%d%d",s+i,f+i,d+i);
		}
		cout<<"Case #"<<C<<": ";
		int ans=dp(0,0);
		if(ans<0) cout<<"IMPOSSIBLE\n";
		else cout<<ans<<"\n";
	}
}
