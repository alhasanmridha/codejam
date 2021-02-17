#include<bits/stdc++.h>
using namespace std;
#define N 200001
#define mod 1000000007
typedef long long int LL;
LL fact[N],p[N];
LL mult(LL a, LL b){
	return a*b%mod;
}
LL inv(LL a){
	LL e=mod-2;
	LL ans=1;
	while(e){
		if(e&1) ans=mult(ans,a);
		a=mult(a,a);
		e>>=1;
	}
	return ans;
}
LL nck(LL n, LL k){
	return mult(fact[n],inv(mult(fact[k],fact[n-k])));
}
int solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	LL ans=0,sn=1;
	for(int i=0;i<=m;i++){
		ans=(ans+sn*mult(nck(m,i),mult(fact[2LL*n-i],p[i])))%mod;
		sn*=-1LL;
	}
	return (ans+mod)%mod;
}
int main(){
	int t,nt=0;
	fact[0]=p[0]=1LL;
	for(LL i=1;i<N;i++) fact[i]=mult(fact[i-1],i),p[i]=mult(p[i-1],2LL);
	scanf("%d",&t);
	while(++nt<=t) cout<<"Case #"<<nt<<": "<<solve()<<"\n";
}
