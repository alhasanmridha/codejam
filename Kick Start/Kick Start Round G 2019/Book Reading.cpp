#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,m,q,bis[100001],p,r;
	cin>>t;
	for(int nt=1;nt<=t;nt++){
		cin>>n>>m>>q;
		for(int i=0;i<100001;i++) bis[i]=0;
		while(m--){
			cin>>p;
			int i=1;
			for(;i*i<p;i++){
				if(p%i==0){
					bis[i]--;
					bis[p/i]--;
				}
			}
			if(i*i==p) bis[i]--;
		}
		long long int tot=0;
		while(q--){
			cin>>r;
			tot+=n/r+bis[r];
		}
		cout<<"Case #"<<nt<<": "<<tot<<"\n";
	}
}
