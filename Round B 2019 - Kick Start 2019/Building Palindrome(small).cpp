#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,tc=0,n,q,L[26],ans,l,r,cnt;
	string s;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&q);
		cin>>s;
		ans=0;
		while(q--){
			scanf("%d%d",&l,&r);
			cnt=0;
			for(int i=0;i<26;i++) L[i]=0;
			for(int i=l-1;i<r;i++){
				if(L[s[i]-'A']==0) L[s[i]-'A']++;
				else L[s[i]-'A']--;
			}
			for(int i=0;i<26;i++) if(L[i]!=0) cnt++;
			if((r-l+1)%2==cnt) ans++;
		}
		printf("Case #%d: %d\n",++tc,ans);
	}
}
