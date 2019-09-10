#include <bits/stdc++.h>
using namespace std;
int cnt;
void prnt(vector<char> v){
	for(int i=0;i<v.size();i++)
		cout<<v[i];
	cout<<"\n";
}
void solve(vector<char>v){
	cnt++;
	vector<char>n;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i]-'0';j++){
			n.push_back(i+1+'0');
		}
	}
	if(n.size()>v.size()) return;
	while(n.size()<v.size()){
		n.push_back(0+'0');
	}
	sort(n.begin(),n.end());
	do{
		//prnt(n);
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
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int test;
	cin>>test;
	for(int Case=1;Case<=test;Case++){
		string n;
		cnt=0;
		vector<char>v;
		cin>>n;
		for(int i=0;i<n.size();i++)
			v.push_back(n[i]);
		solve(v);
		cout<<"Case #"<<Case<<": "<<cnt<<"\n";
	}
}
