#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,b,a[100001],tot;
	cin>>t;
	for(int nt=1;nt<=t;nt++){
		cin>>n>>b;
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		int i;
		tot=0;
		for(i=0;i<n;i++){
			if(a[i]+tot>b) break;
			tot+=a[i];
		}
		cout<<"Case #"<<nt<<": "<<i<<"\n";
	}
}
