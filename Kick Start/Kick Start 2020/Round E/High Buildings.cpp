#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	if(a+b-c>n or c>a or c>b or (a==1 and b==1 and n>1)){
		puts("IMPOSSIBLE");
		return;
	}
	vector<int> as,bs,cs;
	for(int i=0;i<a-c;i++) as.push_back(n-1);
	for(int i=0;i<c;i++) cs.push_back(n);
	for(int i=0;i<b-c;i++) bs.push_back(n-1);
	int left=n-a-b+c;
	vector<int> res;
	for(int a:as){
		res.push_back(a);
		as.pop_back();
		break;
	}
	for(int c:cs){
		if(!res.empty()) break;
		res.push_back(c);
		cs.pop_back();
	}
	for(int i=0;i<left;i++) res.push_back(1);
	for(int a:as) res.push_back(a);
	for(int c:cs) res.push_back(c);
	for(int b:bs) res.push_back(b);
	for(int r:res) cout<<r<<" ";
	puts("");
}
int main(){
	int t,nt=0;
	cin>>t;
	while(t--){
		cout<<"Case #"<<++nt<<": ";
		solve();
	}
}
