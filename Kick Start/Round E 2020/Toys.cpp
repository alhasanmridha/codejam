#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
struct node{
	LL a;
	int i;
	bool operator<(node o)const {
		return a<o.a;
	}
};
void solve(){
	int n;
	cin>>n;
	LL e[n],r[n];
	for(int i=0;i<n;i++) scanf("%lld%lld",e+i,r+i);
	LL sum=0,cur_t=0,mx_t=0;
	int rm=0,ans=0;
	for(int i=0;i<n;i++) sum+=e[i];
	priority_queue<node> pq;
	cur_t=mx_t=sum;
	for(int i=0;i<n;i++){
		pq.push({e[i]+r[i],i});
		cur_t+=e[i];
		while(!pq.empty() and pq.top().a>sum){
			auto c=pq.top();
			pq.pop();
			sum-=e[c.i];
			cur_t-=2*e[c.i];
			rm++;
		}
		if(mx_t<cur_t){
			ans=rm;
			mx_t=cur_t;
		}
	}
	if(!pq.empty()) cout<<n-pq.size()<<" INDEFINITELY\n";
	else cout<<ans<<" "<<mx_t<<"\n";
}

int main(){
	int t,nt=0;
	cin>>t;
	while(t--){
		cout<<"Case #"<<++nt<<": ";
		solve();
	}
}
