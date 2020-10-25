#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
struct tri{
	tri* nxt[26];
	int cnt=0;
};
tri* root;
void construct(string &s){
	tri* cur=root;
	for(auto c:s){
		int b=c-'A';
		if(!cur->nxt[b]) cur->nxt[b]=new tri();
		cur=cur->nxt[b];
		cur->cnt++;
	}
}
void get(tri* root){
	if(!root) return;
	ans+=root->cnt/k;
	for(int i=0;i<26;i++) get(root->nxt[i]);
}
int solve(){
	cin>>n>>k;
	string s[n];
	for(int i=0;i<n;i++) cin>>s[i];
	root=new tri();
	for(string a:s) construct(a);
	ans=0;
	get(root);
	return ans;
}
int main(){
	int t,nt=0;
	cin>>t;
	while(t--) cout<<"Case #"<<++nt<<": "<<solve()<<"\n";
}
