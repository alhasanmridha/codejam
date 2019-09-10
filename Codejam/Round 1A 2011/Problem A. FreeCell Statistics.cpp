#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		int pg,pd;
		long long int n;
		cin>>n>>pd>>pg;
		cout<<"Case #"<<c<<": ";
		if((pd!=100&&pg==100)||(pg==0&&pd!=0)){
			cout<<"Broken\n";
			continue;
		}
		bool fnd=false;
		for(int i=1;i<=n;i++){
			if((i*pd)%100==0){
				fnd=true;
				break;
			}
		}
		if(fnd)
			cout<<"Possible";
		else
			cout<<"Broken";
		cout<<"\n";
	}
	return 0;
}
