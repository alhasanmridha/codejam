#include<bits/stdc++.h>
using namespace std;
int solve(){
	int n,k;
	cin>>n>>k;
	string s[n];
	for(int i=0;i<n;i++) cin>>s[i];
	map<string,int> cntPrefix;
	for(int i=0;i<n;i++){
		string cur="";
		for(int j=0;j<(int)s[i].length();j++){
			cur+=s[i][j];
			cntPrefix[cur]++;
		}
	}
	int ans=0;
	for(auto a:cntPrefix) ans+=a.second/k;
	return ans;
}
int main(){
	int t,nt=0;
	cin>>t;
	while(t--) cout<<"Case #"<<++nt<<": "<<solve()<<"\n";
}

