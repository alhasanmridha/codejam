#include <bits/stdc++.h>
using namespace std;
int p[]={0,10,100,1000};
int main(){
	freopen("input","r",stdin);
	freopen("output","w",stdout);
	int test;
	cin>>test;
	for(int T=1;T<=test;T++){
		string C,J;
		cin>>C>>J;
		int ci,ji,ans=1000000;
		for(int i=0;i<p[(int)C.length()];i++){
			vector<int>f;
			int n=i;
			while(n){
				f.push_back(n%10);
				n/=10;
			}
			for(int it=f.size();it<C.length();it++) f.push_back(0);
				reverse(f.begin(),f.end());
			bool ok=true;
			for(int it=0;it<C.length();it++){
				if(C[it]!='?'&&C[it]-'0'!=f[it]){
					ok=false;
					break;
				}
			}
			if(!ok) continue;
			for(int j=0;j<p[(int)C.length()];j++){
				vector<int>s;
				int n=j;
				while(n){
					s.push_back(n%10);
					n/=10;
				}
				for(int it=s.size();it<J.size();it++) s.push_back(0);
					reverse(s.begin(),s.end());
				bool ok=true;
				for(int it=0;it<J.length();it++){
					if(J[it]!='?'&&J[it]-'0'!=s[it]){
						ok=false;
						break;
					}
				}
				if(!ok) continue;
				int d=i-j;
				if(abs(d)>ans) continue;
				if(abs(d)<ans){
					ans=abs(d);
					ci=i;
					ji=j;
				}
				else if(abs(d)==ans&&ci>i){
					ci=i;
					ji=j;
				}
				else if(abs(d)==ans&&ci==i&&ji>j){
					ji=j;
				}
			}
		}
		std::vector<int> oc;
		std::vector<int> oj;
		while(ci){
			oc.push_back(ci%10);
			ci/=10;
		}
		while(ji){
			oj.push_back(ji%10);
			ji/=10;
		}
		for(int i=oc.size();i<C.size();i++) oc.push_back(0);
		for(int i=oj.size();i<C.size();i++) oj.push_back(0);	
		cout<<"Case #"<<T<<": ";
		reverse(oc.begin(),oc.end());
		reverse(oj.begin(),oj.end());
		for(int i=0;i<C.size();i++) cout<<oc[i];
		cout<<" ";
		for(int i=0;i<C.size();i++) cout<<oj[i];
		cout<<"\n";
		}
	}
