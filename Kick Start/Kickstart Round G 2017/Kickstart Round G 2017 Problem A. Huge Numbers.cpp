#include <bits/stdc++.h>
using namespace std;
long long int f(int a,int n,int p){
	if(n==0)
		return 1;
	long long int mod=f(a,n/2,p);
	mod=(mod*mod)%p;
	if(n%2==1)
		return (mod*a)%p;
	return mod;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		long long int a,n,p;
		scanf("%lld%lld%lld",&a,&n,&p);
		for(int i=0;i<n;i++){
			a=f(a,i+1,p);
		}
		cout<<"Case #"<<c<<": "<<a<<"\n";
	}
}
