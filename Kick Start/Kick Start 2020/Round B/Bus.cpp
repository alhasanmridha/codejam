#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main(){
	int t,nt=0,n;
	LL d,x[1001];
	cin>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>x[i];
		reverse(x,x+n);
		for(int i=0;i<n;i++) d-=d%x[i];
		cout<<"Case #"<<++nt<<": "<<d<<"\n";
	}
}
