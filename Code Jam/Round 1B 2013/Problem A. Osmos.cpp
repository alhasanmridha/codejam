#include<bits/stdc++.h>
using namespace std;

int a,n,m[100];

int rec(int indx,int cap,int cnt){
	if(indx==n)
		return cnt;
	if(cap>m[indx])
		return rec(indx+1,cap+m[indx],cnt);
	return min(rec(indx,2*cap-1,cnt+1),cnt+n-indx);
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		cin>>a>>n;
		for(int i=0;i<n;i++){
			cin>>m[i];
		}
		sort(m,m+n);
		cout<<"Case #"<<c<<": ";
		if(a==1)
			cout<<n<<"\n";
		else
			cout<<rec(0,a,0)<<"\n";
	}
	return 0;
}
