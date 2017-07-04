#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream cin("input");
	ofstream cout("output");
	int T;
	cin>>T;
	for(int C=1;C<=T;C++){
		cout<<"Case #"<<C<<": ";
		int n,tr=0,ride=0,c,m,p[1001],b[1001],one[1001],two[1001],sz[1001];
		bool found;
		cin>>n>>c>>m;
		for(int i=0;i<=n;i++){
			one[i]=0;
			two[i]=0;
			sz[i]=0;
		}
		for(int i=0;i<m;i++){
			cin>>p[i]>>b[i];
			if(b[i]==1){
				cnt_one++;
				one[p[i]]++;
				sz[p[i]]++;
			}
			else{
				cnt_two++;
				two[p[i]]++;
				sz[p[i]]++;
			}
		}
		for(int i=1;i<=n;i++){
			while(one[i]!=0){
				int t_sz=-1,in=-1;
				ride++;
				one[i]--;
				sz[i]--;
				found=false;
				for(int k=i+1;k<=n;k++){
					if(two[k]>0){
						if(sz[k]>t_sz||(sz[k]==t_sz&&in!=-1&&two[in]<two[k])){
							in=k;
							t_sz=sz[k];
							found=true;
						}
					}
				}
				if(!found&&i!=1&&two[i]>0){
					two[i]--;
					tr++;
					sz[i]--;
				}
				else if(found){
					sz[in]--;
					two[in]--;
				}
			}
			while(two[i]!=0){
				ride++;
				two[i]--;
				sz[i]--;
				int t_sz=-1,in=-1;
				found=false;
				for(int k=i+1;k<=n;k++){
					if(one[k]>0){
						if(sz[k]>t_sz||(sz[k]==t_sz&&in!=-1&&one[in]<one[k])){
							in=k;
							t_sz=sz[k];
							found=true;
						}
					}
				}
				if(!found&&i!=1&&one[i]>0){
					one[i]--;
					tr++;
					sz[i]--;
				}
				else if(found){
					sz[in]--;
					one[in]--;
				}
			}
		}
		cout<<ride<<" "<<tr<<"\n";
	}
}
