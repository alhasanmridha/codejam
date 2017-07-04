#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream cin("input");
	ofstream cout("output");
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		int n,q,s[1],same=0;
		cin>>n>>q;
		string r[2];
		for(int i=0;i<=n;i++){
			cin>>r[i];
		}
		for(int i=0;i<n;i++)
			cin>>s[i];
		for(int i=0;i<q;i++){
			if(r[0][i]==r[1][i])
				same++;
		}
		cout<<min(same,s[0])+q-max(same,s[0])<<"\n";
	}
}
