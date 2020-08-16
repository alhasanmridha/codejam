#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,k,m[100000];
	cin>>t;
	for(int nt=1;nt<=t;nt++){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>m[i];
		}
		vector<int>dif;
		for(int i=1;i<n;i++) dif.push_back(m[i]-m[i-1]);
		int lo=1,hi=1e9,mid;
		while(lo<hi){
			mid=lo+(hi-lo)/2;
			int req=0;
			for(int a:dif){
				if(a>mid){
					req+=(a+mid-1)/mid-1;
				}
			}
			if(req>k) lo=mid+1;
			else hi=mid;
		}
		cout<<"Case #"<<nt<<": "<<lo<<"\n";
	}
}
