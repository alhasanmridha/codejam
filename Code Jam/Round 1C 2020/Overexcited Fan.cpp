#include<bits/stdc++.h>
using namespace std;
string m;
int t,nt=0,x,y,cx,cy,l;
int solve(){
	cx=x,cy=y;
	l=m.length();
	for(int i=0;i<l;i++){
		if(m[i]=='S') cy--;
		if(m[i]=='N') cy++;
		if(m[i]=='E') cx++;
		if(m[i]=='W') cx--;
		if(abs(cx)+abs(cy)<=i+1) return i+1;
	}
	return -1;
}
int main(){
	cin>>t;
	while(t--){
		cin>>x>>y>>m;
		int ans=solve();
		cout<<"Case #"<<++nt<<": ";
		if(ans<0) puts("IMPOSSIBLE");
		else cout<<ans<<"\n";
	}
}
