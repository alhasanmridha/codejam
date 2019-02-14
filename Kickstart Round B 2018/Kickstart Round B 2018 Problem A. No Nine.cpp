#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli getLegalUpto(lli n){
	lli actual_n=n;
	lli good_shape=n-n%10;
	n = good_shape;
	lli cnt=0;
	vector<int> ongko;
	while(n){
		ongko.push_back(n%10);
		n/=10;
	}
	reverse(ongko.begin(),ongko.end());
	for(int i=0;i<ongko.size();i++){
		cnt=cnt*9+ongko[i];
	}
	lli extra_cnt=0;
	for(lli i=good_shape;i<=actual_n;i++){
		if(i%9!=0)
			extra_cnt++;
	}
	return 8*cnt/9+extra_cnt;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		lli f,l;
		cin>>f>>l;
		cout<<"Case #"<<c<<": "<<(getLegalUpto(l)-getLegalUpto(f))+1<<"\n";
	}
  return 0;

}
