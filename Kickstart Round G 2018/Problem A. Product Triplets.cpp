#include<bits/stdc++.h>
using namespace std;
struct comp{
	bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};
int main(){
	int t,n;
	cin>>t;
	for(int C=1;C<=t;C++){
		scanf("%d",&n);
		map<int,long long int>mp;
		set<int>s;
		long long int res=0;
		int temp;
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			mp[temp]++;
			s.insert(temp);
		}
		cout<<"Case #"<<C<<": ";
		// reverse(s.begin())
		for(set<int>::iterator it=s.begin();it!=s.end();++it){
			if(*it==0){
				res+=mp[*it]*(mp[*it]-1)*(mp[*it]-2)/6;
				continue;
			}
			if(*it==1){
				res+=mp[*it]*(mp[*it]-1)*(mp[*it]-2)/6;
				if(mp.count(0))
					res+=mp[*it]*(mp[0]-1)*mp[0]/2;
				continue;
			}
			int i=2;
			for(;i*i<*it;i++){
				if(*it%i==0&&mp.count(i)&&mp.count(*it/i)){
					// cout<<*it<<" "<<i<<" "<<*it/i<<"\n";
					res+=mp[*it]*mp[i]*mp[*it/i];
				}
			}
			if(*it==i*i)
				res+=mp[i]*(mp[i]-1)*mp[*it]/2;
			if(mp.count(0))
				res+=mp[*it]*(mp[0]-1)*mp[0]/2;
			if(mp.count(1))
				res+=mp[1]*(mp[*it]-1)*mp[*it]/2;
		}
		cout<<res<<"\n";
	}
	return 0;
} 
