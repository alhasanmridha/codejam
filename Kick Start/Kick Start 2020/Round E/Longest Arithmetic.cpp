#include<iostream>
using namespace std;
void solve(){
	int n,ans=2;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n-1;){
		int j=i+1;
		while(j<n and a[j]-a[j-1]==a[i+1]-a[i]) j++;
		ans=max(ans,j-i);
		i=j-1;
	}
	cout<<ans<<"\n";
}
int main(){
	int t,nt=0;
	cin>>t;
	while(t--){
		cout<<"Case #"<<++nt<<": ";
		solve();
	}
}
