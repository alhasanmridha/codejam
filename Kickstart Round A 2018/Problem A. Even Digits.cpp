#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		long long int n,np;
		cin>>n;
		vector<int>v;
		np=n;
		while(np){
			v.push_back(np%10);
			np/=10;
		}
		int gr=-1;
		reverse(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			if(v[i]%2!=0){
				gr=i;
				break;
			}
		}
		cout<<"Case #"<<c<<": ";
		if(gr==-1){
			cout<<0<<"\n";
			continue;
		}
		long long int modn=0;
		for(int i=gr;i<v.size();i++){
			modn=modn*10+v[i];
		}
		long long int tar=v[gr]-1;
		for(int i=gr+1;i<v.size();i++){
			tar=tar*10+8;
		}
		if(v[gr]==9){
			cout<<modn-tar<<"\n";
		}
		else{
			long long int tar1=v[gr]+1;
			for(int i=gr+1;i<v.size();i++){
				tar1*=10;
			}
			cout<<min(modn-tar,tar1-modn)<<"\n";
		}
	}
	return 0;
}
