#include<bits/stdc++.h>
using namespace std;
#define B 1009
typedef long long int LL;
int main(){
	int t;
	cin>>t;
	for(int nt=1;nt<=t;nt++){
		int n,s,c,q;
		map<LL,int>mp;
		cin>>n>>s;
		vector<int>us[n];
		for(int i=0;i<n;i++){
			cin>>c;
			set<int>quality;
			while(c--){
				cin>>q;
				quality.insert(q);
				us[i].push_back(q);
			}
			LL rep=0;
			for(int q:quality){
				rep=n_rep*B+q;
			}
			mp[rep]++;
		}
		LL ans=0;
		for(vector<int> v:us){
			sort(v.begin(),v.end());
			int p=v.size();
			LL not_blocked=n;
			for(int i=1;i<(1<<p);i++){
				LL rep=0;
				for(int j=0;j<p;j++){
					if(1<<j & i) rep=rep*B+(LL)v[j];
				}
				not_blocked-=mp[rep];
			}
			ans+=not_blocked;
		}
		cout<<"Case #"<<nt<<": "<<ans<<"\n";
	}
}
