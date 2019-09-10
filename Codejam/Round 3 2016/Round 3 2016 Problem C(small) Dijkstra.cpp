#include <bits/stdc++.h>
using namespace std;
typedef pair<double,int> ii;
typedef vector<ii> vi;
int sq(int a){
	return a*a;
}
int main(){
	freopen("input","r",stdin);
	freopen("output","w",stdout);
	int t,n,s,x[1001],y[1001],z[1001],u,v;
	double w,val=0;
	cin>>t;
	for(int C=1;C<=t;C++){
		cin>>n>>s;
	    vi grid[n];
		vector<double> dist(1001,(double)10000000);
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i]>>z[i]>>w>>w>>w;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				w=sqrt(sq(x[i]-x[j])+sq(y[i]-y[j])+sq(z[i]-z[j]));
				grid[i].push_back(ii(w,j));
			}
		priority_queue<ii,vector<ii>,greater<ii> >Q;
		Q.push(ii(0,0));
		dist[0]=0;
		while(!Q.empty()){
			ii top=Q.top();
			u=top.second;
			double d=top.first;
			Q.pop();
			if(dist[u]==d)
				for(int i=0;i<grid[u].size();i++){
					v=grid[u][i].second;
					w=grid[u][i].first;
					if(max(d,w)<dist[i]){
						dist[i]=max(d,w);
						Q.push(ii(dist[i],i));
					}
				}
			}
		cout<<"Case #"<<C<<": "<<fixed<<setprecision(7)<<dist[1]<<"\n";
	}
}
