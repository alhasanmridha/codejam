#include<iostream>
using namespace std;
int main(){
	int t,nt=0;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int ans=0;
		for(int i=0;i<n;){
			int j=0;
			if(a[i]==k){
				bool fnd=true;
				for(;j<k;j++){
					if(a[i+j]!=k-j){
						fnd=false;
						break;
					}
				}
				if(fnd) ans++;
				i+=j;
			}
			else{
				i++;
			}
		}
		cout<<"Case #"<<++nt<<": "<<ans<<"\n";
	}
}
