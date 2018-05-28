#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		int spd=0,n,r1=0,r2=0,m[1000];
		cin>>n>>m[0];
		for(int i=1;i<n;i++){
			cin>>m[i];
			spd=max(spd,m[i-1]-m[i]);
			r1+=(max(0,m[i-1]-m[i]));
		}
		for(int i=0;i<n-1;i++){
			if(m[i]>spd)
				r2+=spd;
			else
				r2+=m[i];
		}
		cout<<"Case #"<<c<<": ";
		cout<<r1<<" "<<r2<<"\n";
	}
}
