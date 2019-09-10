#include<bits/stdc++.h>
#define N 100001
int L[N][26];
using namespace std;
int main(){
	int t,tc=0,n,q,ans,l,r,cnt;
	string s;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&q);
		cin>>s;
		for(int i=0;i<=n;i++) for(int j=0;j<26;j++) L[i][j]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<26;j++) L[i][j]=L[i-1][j];
			L[i][s[i-1]-'A']++;
		}
		ans=0;
		while(q--){
			scanf("%d%d",&l,&r);
			cnt=0;
			for(int i=0;i<26;i++) if((L[r][i]-L[l-1][i])%2) cnt++;
			if((r-l+1)%2==cnt) ans++;
		}
		printf("Case #%d: %d\n",++tc,ans);
	}
}
