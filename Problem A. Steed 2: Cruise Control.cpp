//Problem Link
//https://code.google.com/codejam/contest/8294486/dashboard
#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		double d,n,k,s;
		cin>>d>>n;
		double mx=0,temp;
		for(int i=0;i<n;i++){
			cin>>k>>s;
			temp=(d-k)/s;
			if(temp>mx)
				mx=temp;
		}
		cout<<"Case #"<<c<<": "<<setprecision(6)<<fixed<<d/mx<<"\n";
	}
}
