#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
	int t;
	cin>>t;
	for(int C=1;C<=t;C++){
		int n,p;
		cin>>n>>p;
		string forbd[p];
		lli res=(lli) pow(2,n);
		for(int i=0;i<p;i++){
			cin>>forbd[i];
		}
		for(int i=0;i<p;i++){
			bool flag=false;
			for(int j=0;j<p;j++){
				if(i==j)
					continue;
				size_t found = forbd[i].find(forbd[j]);
				if(found!=string::npos&&found==0){
					flag=true;
					break;
				}
			}
			if(!flag){
				res-=pow(2,n-forbd[i].length());
			}
		}
		cout<<"Case #"<<C<<": "<<res<<"\n";
	}
}
