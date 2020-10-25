#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
struct tri{
	tri* nxt[26];
	int cnt=0;
};
void construct(tri* root, string s, int id){
	if(id==(int)s.length()) return;
	if(root->nxt[s[id]-'A']==NULL) root->nxt[s[id]-'A']=new tri;
	root->nxt[s[id]-'A']->cnt++;
	construct(root->nxt[s[id]-'A'],s,id+1);
}
void get(tri* root){
	if(root==NULL) return;
	ans+=root->cnt/k;
	for(int i=0;i<26;i++) get(root->nxt[i]);
}
int solve(){
	cin>>n>>k;
	string s[n];
	for(int i=0;i<n;i++) cin>>s[i];
	tri* root=new tri;
	for(string a:s) construct(root,a,0);
	ans=0;
	get(root);
	return ans;
}
int main(){
	int t,nt=0;
	cin>>t;
	while(t--) cout<<"Case #"<<++nt<<": "<<solve()<<"\n";
}

