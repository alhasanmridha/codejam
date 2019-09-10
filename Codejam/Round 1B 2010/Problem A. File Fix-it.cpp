#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		int n,m;
		map<string,int>mp;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			string st="";
			for(int i=0;i<s.length();){
				st+=s[i++];
				while(i<s.length()){
					if(s[i]=='/')
						break;
					st+=s[i++];
				}
				// cout<<st<<"\n";
				if(mp.find(st)==mp.end())
					mp[st]=true;
			}
		}
		int cnt=0;
		for(int i=0;i<m;i++){
			string s;
			cin>>s;
			string st="";
			for(int i=0;i<s.length();){
				st+=s[i++];
				while(i<s.length()){
					if(s[i]=='/')
						break;
					st+=s[i++];
				}
				// cout<<st<<"\n";
				if(mp.find(st)==mp.end()){
					mp[st]=true;
					cnt++;
				}
			}
		}
		cout<<"Case #"<<c<<": "<<cnt<<"\n";
	}
	return 0;
}
