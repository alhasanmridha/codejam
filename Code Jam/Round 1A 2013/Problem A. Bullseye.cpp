#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("input","r",stdin);
	freopen("output","w",stdout);
	int T;
	cin>>T;
	for(int C=1;C<=T;C++){
		long long int r,t,l,h,m;
		cin>>r>>t;
		l=0,h=min(2e9,2e18/r);
		while(l<h){
			m=(l+h+1)/2;
			if(m*(2*r-3)+2*m*(m+1)>t)
				h=m-1;
			else
				l=m;
		}
		cout<<"Case #"<<C<<": "<<l<<"\n";
	}
}
