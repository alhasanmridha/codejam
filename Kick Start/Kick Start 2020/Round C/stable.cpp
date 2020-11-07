#include<bits/stdc++.h>
using namespace std;
string wall[30];
int r,c;
bool already[26];
bool possible(char tar){
	for(int i=0;i<r-1;i++){
		for(int j=0;j<c;j++){
			if(wall[i][j]!=tar) continue;
			if(wall[i+1][j]!=tar and !already[wall[i+1][j]-'A']) return false;
		}
	}
	return true;
}
string solve(){
	cin>>r>>c;
	for(int i=0;i<r;i++)cin>>wall[i];
	for(auto &v:already) v=true;
	for(int i=0;i<r;i++) for(char c:wall[i]) already[c-'A']=false;
	string ans="";
	for(char i=0;i<26;i++){
		for(char j='A';j<='Z';j++){
			if(already[j-'A']) continue;
			if(possible(j)){
				already[j-'A']=true;
				ans=ans+j;
			}
		}
		bool alldone=true;
		for(int i=0;i<26;i++) if(!already[i]) alldone=false;
		if(alldone) return ans;
	}
	return "-1";
}
int main(){
	int t,nt=1;
	cin>>t;
	while(t--) cout<<"Case #"<<nt++<<": "<<solve()<<"\n";
}
