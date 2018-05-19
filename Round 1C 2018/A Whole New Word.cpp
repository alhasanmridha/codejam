#include<bits/stdc++.h>
using namespace std;
vector<char> v[10];
bool is_found=false;
string s[2000];
int n,l;
void solve(string s_con,int in){
	if(in==l){
		for(int i=0;i<n;i++){
			if(s_con.compare(s[i])==0)
				return;
		}
		cout<<s_con<<"\n";
		is_found=true;
		return;
	}
	for(int i=0;i<v[in].size();i++){
		if(!is_found)
			solve(s_con+v[in][i],in+1);
		else
			return;
	}
}
int main(){
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		cin>>n>>l;
		set<char> tot_char[10]; 
		for(int i=0;i<n;i++){
			cin>>s[i];
			for(int j=0;j<l;j++){
				tot_char[j].insert(s[i][j]);
			}
		}
		for(int i=0;i<l;i++){
			for(set<char>::iterator it=tot_char[i].begin();it!=tot_char[i].end();++it){
				v[i].push_back(*it);
			}
		}
		is_found=false;
		cout<<"Case #"<<c<<": ";
		solve("",0);
		if(!is_found)
			cout<<"-\n";
		for(int i=0;i<l;i++){
			v[i].clear();
		}
	}
	return 0;
}
