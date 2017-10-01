#include <bits/stdc++.h>
using namespace std;
struct details{
	int cnt=0;
	long long int val;
	bool operator<(details o){
		return cnt>o.cnt;
	}
};
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		cout<<"Case #"<<c<<": ";
		int n,val,it=0;
		details cnt[2001];
		map<int,int>mp;
		long long int ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&val);
			if(!mp.count(val)){
				mp[val]=it++;
			}
			cnt[mp[val]].cnt++;
			cnt[mp[val]].val=val;
		}
		sort(cnt,cnt+it);
		int last_two=0,last_three=0;
		for(int i=0;i<it;i++){
			if(cnt[i].cnt>2)
				last_three=i;
			if(cnt[i].cnt>1)
				last_two=i;
		}
		for(int i=0;i<=last_three;i++){
			for(int j=0;j<it;j++){
				if(j==i||cnt[i].val*3<=cnt[j].val){
					continue;
				}
				else{
					ans+=cnt[i].cnt*(cnt[i].cnt-1)*(cnt[i].cnt-2)/6*cnt[j].cnt;
				}
			}
		}
		for(int i=0;i<=last_two;i++){
			for(int j=0;j<it;j++){
				if(j==i){
					continue;
				}
				else{
					for(int k=j+1;k<it;k++){
						if(k==i||cnt[i].val*2+cnt[j].val<=cnt[k].val||cnt[i].val*2+cnt[k].val<=cnt[j].val)
							continue;
						else
							ans+=cnt[i].cnt*(cnt[i].cnt-1)/2*cnt[j].cnt*cnt[k].cnt;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
