#include <bits/stdc++.h>
using namespace std;
bool comp(vector<char> a,vector<char>b){
	return a.size()>b.size();
}
int main(){
	ifstream cin("input");
	ofstream cout("out");
	int test,n,col[7];
	map<int,char>mp;
	mp[0]='R';
	mp[2]='Y';
	mp[4]='B';
	//R O Y G B V
	cin>>test;
	for(int c=1;c<=test;c++){
		vector<char>s[6];
		cin>>n;
		for(int i=0;i<6;i++){
			cin>>col[i];
			for(int j=0;j<col[i];j++){
				s[i].push_back(mp[i]);
			}
		}
		sort(s,s+6,comp);
		cout<<"Case #"<<c<<": ";
		if(s[0].size()>s[1].size()+s[2].size()){
			cout<<"IMPOSSIBLE\n";
			//cout<<s[0].size()<<s[1].size();
			continue;
		}
		int cnt=0;
		for(int i=s[1].size();i<s[0].size();i++){
			s[1].push_back(s[2][0]);
			cnt++;
		}
		if((s[2].size()-cnt)%2==1){
			cout<<s[2][0];
		}
		for(int i=0;i<(s[2].size()-cnt)/2;i++){
			s[0].push_back(s[2][0]);
			s[1].push_back(s[2][0]);
		}
		reverse(s[1].begin(),s[1].end());
		for(int i=0;i<s[1].size();i++){
			cout<<s[0][i]<<s[1][i];
		}
		cout<<"\n";
	}
}
