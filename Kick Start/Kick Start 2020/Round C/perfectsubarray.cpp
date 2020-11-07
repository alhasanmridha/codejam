#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL solve(){
	int n;
	scanf("%d",&n);
	int a[n],ma=0;
	for(int i=0;i<n;i++) {
		scanf("%d",a+i);
		ma+=a[i];
	}
	vector<int>mp(2*ma+1);
	//for(int i=ma;i<ma+20;i++) cout<<mp[i]<<" ";
	mp[ma]=1;
	LL ans=0;
	int pre=0;
	for(int x:a){
		pre+=x;
		//sqlimit+=abs(x);
		for(int i=0;i*i<=ma;i++){
			//cout<<pre-i*i<<" "<<mp[pre-i*i+ma]<<"\n";
			ans+=mp[pre-i*i+ma];
		}
		mp[pre+ma]++;
	}
	return ans;
}

int main(){
	int t,nt=0;
	cin>>t;
	while(t--) cout<<"Case #"<<++nt<<": "<<solve()<<"\n";
}

