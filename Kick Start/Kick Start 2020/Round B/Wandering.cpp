#include<bits/stdc++.h>
using namespace std;
#define N 200001
double l2[N],lfac[N];
double prob(int x,int y){
	return exp(lfac[x+y]-lfac[x]-lfac[y]-l2[x+y]);
}
double solve(){
	int w,h,l,u,r,d;
	cin>>w>>h>>l>>u>>r>>d;
	w--,h--,l--,u--,r--,d--;
	double ans=0.0;
	int lx=l,gy=d;
	while(lx>0 and d<h){
		lx--,gy++;
		double m=1.0;
		if(gy>=h) gy=h-1,m=0.5;
		ans+=prob(lx,gy)*m;
	}
	int rx=r,sy=u;
	while(sy>0 and r<w){
		rx++,sy--;
		double m=1.0;
		if(rx>=w) rx=w-1,m=0.5;
		ans+=prob(rx,sy)*m;
	}
	return ans;
}
int main(){
	lfac[0]=0.0;
	for(int i=1;i<N;i++) lfac[i]=lfac[i-1]+log(i);
	l2[1]=log(2);
	for(int i=2;i<N;i++) l2[i]=l2[i-1]+l2[1];
	int t,nt=0;
	cin>>t;
	while(t--) cout<<"Case #"<<++nt<<": "<<solve()<<"\n";
	return 0;
}
