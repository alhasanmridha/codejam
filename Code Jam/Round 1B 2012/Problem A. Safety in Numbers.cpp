#include<bits/stdc++.h>
#define max(a,b) a>b?a:b;
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n;
	double s[200];
	cin>>t;
	for(int c=1;c<=t;c++){
		double x=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i];
			x+=s[i];
		}
		cout<<"Case #"<<c<<": "<<fixed<<setprecision(6);
		for(int i=0;i<n;i++){
			double l=s[i],m,h=x,spar;
			if(l==h){
				cout<<0<<" ";
				continue;
			}
			while(h-l>.0000001){
				m=(l+h)/2;
				spar=x;
				for(int i=0;i<n;i++){
					spar-=max(0,m-s[i]);
				}
				if(spar<0)
					h=m;
				else
					l=m;
			}
			double rslt=(m-s[i])*100;
			rslt/=x;
			cout<<rslt<<" ";
		}
		cout<<"\n";
	}
}
