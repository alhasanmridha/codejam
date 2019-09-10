#include <bits/stdc++.h>
using namespace std;
int parent[1001],rank[1001];
int sq(int a){
	return a*a;
}
int root(int a){
	if(parent[a]!=a) parent[a]=root(parent[a]);
	return parent[a];
}
void connect(int u,int v){
	int ru=root(u);
	int rv=root(v);
	if(ru==rv) return;
	if(rank[ru]>rank[rv]){
		parent[rv]=parent[ru];
		rank[ru]+=rank[rv];
	}
	else{
		parent[ru]=parent[rv];
		rank[rv]+=rank[ru];
	}
}
int main(){
	freopen("input","r",stdin);
	freopen("output","w",stdout);
	int t,n,s,x[1001],y[1001],z[1001];
	double w,grid[1001][1001],ans;
	cin>>t;
	for(int C=1;C<=t;C++){
		cin>>n>>s;
		for(int i=0;i<n;i++){parent[i]=i;rank[i]=1;}
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i]>>z[i]>>w>>w>>w;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				grid[i][j]=sqrt(sq(x[i]-x[j])+sq(y[i]-y[j])+sq(z[i]-z[j]));
		vector<pair<double,pair<int,int> > >Q;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				Q.push_back(make_pair(grid[i][j],make_pair(i,j)));
		sort(Q.begin(),Q.end());
		for(int i=0;i<Q.size();i++){
			ans=Q[i].first;
			connect(Q[i].second.first,Q[i].second.second);
			if(root(0)==root(1))
				break;
		}
		cout<<"Case #"<<C<<": "<<fixed<<setprecision(7)<<ans<<"\n";
	}
}
