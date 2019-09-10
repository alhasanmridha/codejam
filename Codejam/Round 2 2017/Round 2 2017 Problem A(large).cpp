#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int main(){
	ifstream cin("input");
	ofstream cout("output");
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		cout<<"Case #"<<c<<": ";
		int n,p,a[100],cnt[4];
		for(int i=0;i<4;i++) cnt[i]=0;
		cin>>n>>p;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++){
			cnt[a[i]%p]++;
		}
		if(p==2){
			cout<<cnt[0]+(cnt[1]+1)/2<<"\n";
		}
		if(p==3){
			cout<<cnt[0]+min(cnt[1],cnt[2])+(max(cnt[1],cnt[2])-min(cnt[1],cnt[2])+2)/3<<"\n";
		}
		if(p==4){
			int re=cnt[0]+cnt[2]/2;
			cnt[2]%=2;
			re+=min(cnt[1],cnt[3]);
			int rest=max(cnt[1],cnt[3])-min(cnt[1],cnt[3]);
			if(cnt[2]){
				re+=1;
				rest-=2;
			}
			if(rest>0){
				re+=(rest+3)/4;
			}
			cout<<re<<"\n";
		}
	}
}
