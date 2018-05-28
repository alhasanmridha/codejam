#include <bits/stdc++.h>
using namespace std;
int t,n;
string s[100];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		printf("Case #%d: ",c );
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		vector<char>v[100];
		int cnt[100][100];
		memset(cnt,0,sizeof(cnt));
		v[0].push_back(s[0][0]);
		cnt[0][0]++;
		int it=0;
		for(int j=1;j<s[0].length();j++){
			if(s[0][j]!=v[0][v[0].size()-1]){
				v[0].push_back(s[0][j]);
				++it;
			}
			cnt[0][it]++;
		}
		for(int i=1;i<n;i++){
			v[i].push_back(s[i][0]);
			cnt[i][0]++;
			it=0;
			for(int j=1;j<s[i].length();j++){
				if(s[i][j]!=v[i][v[i].size()-1]){
					v[i].push_back(s[i][j]);
					++it;
				}
				cnt[i][it]++;
			}
		}
		bool done=false;
		for(int i=1;i<n;i++){
			if(v[i].size()!=v[i-1].size()){
				done=true;
				break;
			}
			for(int j=0;j<v[i].size();j++){
				if(v[i][j]!=v[i-1][j]){
					done=true;
					break;
				}
			}
		}
		int ans=0;
		for(int i=0;i<=it&&!done;i++){
			int tans=INT_MAX;
			for(int j=1;j<=100;j++){
				int result=0;
				for(int k=0;k<n;k++){
					result+=abs(cnt[k][i]-j);
				}
				tans=min(tans,result);
			}
			ans+=tans;
		}
		if(!done){
			cout<<ans<<"\n";
		}
		else{
			cout<<"Fegla Won\n";
		}	
	}
}
