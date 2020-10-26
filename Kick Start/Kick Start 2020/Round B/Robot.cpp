#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL M=1e9;
int n;
struct cord{
	LL x;
   	LL y;
};
map<int,int>mp;
string s;
cord get(int id){
	LL mult=s[id]-'0';
	int n=mp[id];
	id++;
	cord cur={0LL,0LL};
	for(int i=id;i<n;){
		if(s[i]<='9' and s[i]>='1'){
			cord ret=get(i);
			cur.x+=ret.x;
			cur.y+=ret.y;
			i=mp[i];
			continue;
		}
		if(s[i]=='N') cur.y--;
		if(s[i]=='S') cur.y++;
		if(s[i]=='E') cur.x++;
		if(s[i]=='W') cur.x--;
		if(cur.x<0) cur.x+=M;
		if(cur.y<0) cur.y+=M;
		cur.x%=M;
		cur.y%=M;
		i++;
	}
	return {cur.x*mult%M,cur.y*mult%M};
}
void solve(){
	cin>>s;
	s="1("+s+")";
	n=s.length();
	stack<int> st;
	for(int i=1;i<n;i++){
		if(s[i]=='(') st.push(i-1);
		if(s[i]==')') mp[st.top()]=i+1,st.pop();
	}
	cord ans=get(0);
	cout<<ans.x+1<<" "<<ans.y+1<<"\n";
}
int main(){
	int t,nt=0;
	cin>>t;
	while(t--){
		cout<<"Case #"<<++nt<<": ";
		solve();
	}
	return 0;
}
