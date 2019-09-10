#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
	int t;
	cin>>t;
	for(int C=1;C<=t;C++){
		int n;
		string num;
		cin>>n>>num;
		static int sum[5000000+1];
		sum[0]=num[0]-'0';
		for(int i=1;i<n;i++){
			sum[i]=num[i]-'0'+sum[i-1];
		}
		int lmt=(n+1)/2;
		int ans=0;
		for(int i=0;i+lmt-1<n;i++){
			ans=max(ans,sum[i+lmt-1]-sum[i]+num[i]-'0');
		}
		cout<<"Case #"<<C<<": "<<ans<<"\n";
	}
}
