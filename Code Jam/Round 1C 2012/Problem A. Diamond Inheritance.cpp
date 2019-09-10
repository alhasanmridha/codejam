#include<bits/stdc++.h>
using namespace std;
vector<int>v[1000];
bool vis[1000];
bool dfs(int in){
	if(vis[in])
		return true;
	vis[in]=true;
	bool ret=false;
	for(int i=0;i<v[in].size();i++){
		ret|=dfs(v[in][i]);
	}
	return ret;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		int n,inh;
		cin>>n;
		for(int i=0;i<n;i++){
			int m;
			cin>>m;
			for(int j=0;j<m;j++){
				cin>>inh;
				v[inh-1].push_back(i);
			}
		}
		bool is_daiamond=false;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				vis[j]=false;
			if(dfs(i)){
				is_daiamond=true;
				break;
			}
		}
		cout<<"Case #"<<c<<": ";
		if(is_daiamond)
			cout<<"Yes\n";
		else
			cout<<"No\n";
		for(int i=0;i<n;i++){
			v[i].clear();
		}
	}
	return 0;
}
