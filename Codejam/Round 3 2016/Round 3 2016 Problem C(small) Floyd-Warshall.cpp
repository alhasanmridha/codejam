#include <bits/stdc++.h>
using namespace std;
float sq(float a){
	return a*a;
}
int main(){
	freopen("input","r",stdin);
	freopen("output","w",stdout);
	int t,n,s;
	float x[1001],y[1001],z[1001],v,grid[1001][1001];
	cin>>t;
	for(int C=1;C<=t;C++){
		cin>>n>>s;
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i]>>z[i]>>v>>v>>v;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				grid[i][j]=sqrt(sq(x[i]-x[j])+sq(y[i]-y[j])+sq(z[i]-z[j]));
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					grid[i][j]=min(grid[i][j],max(grid[i][k],grid[k][j]));
		cout<<"Case #"<<C<<": "<<fixed<<setprecision(7)<<grid[0][1]<<"\n";
	}
}
