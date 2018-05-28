#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <fstream>
#define P 3.14159265359
using namespace std;
struct food{
	double r,h;
	bool operator<(const food& o) const
	{
		return r>o.r;
	}
};
int main(){
	ifstream cin("input");
	ofstream cout("output");
	int test;
	cin>>test;
	for(int C=1;C<=test;C++){
		int n,k;
		vector<int>v;
		double ans=-1.0;
		cin>>n>>k;
		food cake[1000];
		for(int i=0;i<n;i++){
			cin>>cake[i].r>>cake[i].h;
		}
		sort(cake,cake+n);
		for(int i=0;i<k;i++) v.push_back(0);
		for(int i=k;i<n;i++) v.push_back(1);
		do{
			int i;
			for(i=0;v[i];i++);
			double temp=P*cake[i].r*(cake[i].r+2*cake[i].h);
			for(int j=i+1;j<n;j++){
				if(!v[j]) temp+=2*P*cake[j].r*cake[j].h;
			}
			if(temp>ans) ans=temp;
		}while(next_permutation(v.begin(),v.end()));
		cout<<"Case #"<<C<<": ";
		cout<<fixed<<setprecision(6)<<ans<<"\n";
	}
}
