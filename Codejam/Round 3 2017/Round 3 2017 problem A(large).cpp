#include <bits/stdc++.h>
using namespace std;
int fact(int a){
	int re=1;
	for(int i=2;i<=a;i++)
		re*=i;
	return re;
}
int cnt;
void solve(vector<int>v){
	cnt++;
	int sum=0;
	vector<int>n;
	map<int,int>mp;
	for(int i=0;i<10;i++)
		mp[i]=0;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i];j++){
			n.push_back(i+1);
			sum+=(i+1);
		}
	}
	if(n.size()>v.size()) return;
	while(n.size()<v.size()){
		n.push_back(0);
	}
	for(int i=0;i<n.size();i++){
		mp[n[i]]++;
	}
	if(sum>v.size()){
		int add=fact(v.size());
		for(int i=0;i<10;i++){
			add/=fact(mp[i]);
		}
		cnt+=add;
		return;
	}
	sort(n.begin(),n.end());
	do{
		bool self_decay=true;
		for(int i=0;i<v.size();i++){
			if(v[i]!=n[i])
				self_decay=false;
		}
		if(!self_decay)
			solve(n);
	}while(next_permutation(n.begin(),n.end()));
}
int main(){
	ifstream cin("input");
	ofstream cout("output");
	int test;
	cin>>test;
	for(int Case=1;Case<=test;Case++){
		string n;
		cnt=0;
		vector<int>v;
		cin>>n;
		for(int i=0;i<n.size();i++)
			v.push_back(n[i]-'0');
		solve(v);
		cout<<"Case #"<<Case<<": "<<cnt<<"\n";
	}
}
