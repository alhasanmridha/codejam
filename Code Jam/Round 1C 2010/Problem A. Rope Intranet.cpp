#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		int n,a,b;
		cin>>n;
		vector<pair<int,int> > v;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			v.push_back(make_pair(a,b));
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			int a1=v[i].first;
			int b1=v[i].second;
			for(int j=i+1;j<n;j++){
				int a2=v[j].first;
				int b2=v[j].second;
				if((a1-a2)*(b1-b2)<0)
					cnt++;
			}
		}
		cout<<"Case #"<<c<<": "<<cnt<<"\n";
	}
	return 0;
}
