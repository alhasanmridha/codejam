#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,a;
	cin>>t;
	for(int nt=1;nt<=t;nt++){
		priority_queue<int, std::vector<int>, std::greater<int> > pq;
		cin>>n;
		cout<<"Case #"<<nt<<": ";
		for(int i=0;i<n;i++){
			cin>>a;
			pq.push(a);
			while(pq.top()<(int)pq.size())
				pq.pop();
			cout<<pq.size()<<" ";
		}
		puts("");
	}
}
