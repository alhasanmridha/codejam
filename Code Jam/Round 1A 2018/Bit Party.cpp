#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int C=1;C<=t;C++){
		long long int r,b,c;
		long long int m[1001],s[1001],p[1001];
		scanf("%lld%lld%lld",&r,&b,&c);
		for(int i=0;i<c;i++)
			scanf("%lld%lld%lld",m+i,s+i,p+i);
		long long int l=0,h=4e18,mid,val;
		while(h-l>1){
			vector<long long int> robs;
			mid=(l+h)/2;
			for(int i=0;i<c;i++){
				val=mid-p[i];
				if(val>0)
					robs.push_back(min(val/s[i],m[i]));
			}
			sort(robs.begin(),robs.end(),greater<int>());
			long long int tot=0;
			for(int i=0;i<robs.size()&&i<r;i++)
				tot+=robs[i];
			if(tot>=b)
				h=mid;
			else
				l=mid;

		}
		printf("Case #%d: %lld\n",C,h);
	}
	return 0;
}
