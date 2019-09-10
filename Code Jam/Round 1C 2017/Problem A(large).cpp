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
bool comp(food a,food b){
	return a.h*a.r>b.h*b.r;
}
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
		for(int i=0;i<n-k+1;i++){
			sort(cake,cake+n);
			double temp=P*cake[i].r*(cake[i].r+2*cake[i].h);
			sort(cake+i+1,cake+n,comp);
			for(int j=i+1;j<k+i;j++){
				temp+=2*P*cake[j].r*cake[j].h;
			}
			ans=max(temp,ans);
		}
		cout<<"Case #"<<C<<": ";
		cout<<fixed<<setprecision(6)<<ans<<"\n";
	}
}
