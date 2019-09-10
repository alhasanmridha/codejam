#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream cin("input");
	ofstream cout("output");
	int t,n,k;
	double u,p[51];
	cin>>t;
	for(int C=1;C<=t;C++){
		cin>>n>>k>>u;
		for(int i=0;i<n;i++){
			cin>>p[i];
		}
		sort(p,p+n,greater<int>());
		double l=0,r=1,m;
		while(r-l>.000000001){
			m=(r+l)/2;
			double sum=0;
			for(int i=0;i<k;i++){
				sum+=max((double)0,m-p[i]);
			}
			if(sum<=u)
				l=m;
			else
				r=m;
		}
		double ans=1;
		for(int i=0;i<k;i++)
			ans*=max(p[i],m);
		cout<<"Case #"<<C<<": "<<fixed<<setprecision(6)<<ans<<"\n";
	}
}
