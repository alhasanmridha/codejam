/* This is the implementation for small data set as stated in the analysis. The idea is very interesting */
#include<bits/stdc++.h>
using namespace std;
int S=1e5+1;
bool is_odd(int a){
	int cnt=0;
	for(int i=0;1<<i<=a;i++)
		cnt+=min(1,1<<i & a);
	return cnt%2;
}
int main(){
	int t,n,q,a[S],v,p,s[S+1];
	cin>>t;
	s[0]=0;
	for(int nt=1;nt<=t;nt++){
		cin>>n>>q;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			s[i]=s[i-1] xor a[i-1];
		cout<<"Case #"<<nt<<":";
		for(int i=0;i<q;i++){
			cin>>p>>v;
			if(is_odd(a[p])!=is_odd(v)){
				a[p]=v;
				for(int i=p+1;i<=n;i++)
					s[i]= s[i-1] xor a[i-1];
			}
			int ans=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(!is_odd(s[j] xor s[i]))
						ans=max(ans,j-i);
				}
			}
			cout<<" "<<ans;
		}
		cout<<"\n";

	}
	return 0;
}
