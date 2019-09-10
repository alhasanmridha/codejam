#include <iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		int n,k;
		string grid[50];
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>grid[i];
		}
		int n_in=n-1;
		for(int i=0;i<n;i++){
			n_in=n-1;
			for(int j=n-1;j>-1;j--){
				if(grid[i][j]!='.'){
					char tmp=grid[i][j];
					grid[i][j]='.';
					grid[i][n_in]=tmp;
					n_in--;
				}
			}
		}
		bool rslt[26];
		rslt['B'-'A']=false;
		rslt['R'-'A']=false;
		bool vis[4][50][50];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int l=0;l<4;l++)
					vis[l][i][j]=false;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]!='.'){
					char tar=grid[i][j];
					int cnt=0;
					if(!vis[0][i][j]){
						for(int jp=j;jp<n;jp++){
							if(grid[i][jp]!=tar)
								break;
							cnt++;
							vis[0][i][jp]=true;
						}
					}
					if(cnt>=k){
						rslt[tar-'A']=true;
						continue;
					}
					cnt=0;
					if(!vis[1][i][j]){
						for(int xp=0;xp+j<n&&xp+i<n;xp++){
							if(grid[i+xp][j+xp]!=tar)
								break;
							cnt++;
							vis[1][i+xp][j+xp]=true;
						}
					}
					if(cnt>=k){
						rslt[tar-'A']=true;
						continue;
					}
					cnt=0;
					if(!vis[2][i][j]){
						for(int ip=i;ip<n;ip++){
							if(grid[ip][j]!=tar)
								break;
							cnt++;
							vis[2][ip][j]=true;
						}
					}
					if(cnt>=k){
						rslt[tar-'A']=true;
						continue;
					}
					cnt=0;
					if(!vis[3][i][j]){
						for(int x=0;x+i<n&&j-x>=0;x++){
							if(grid[x+i][j-x]!=tar)
								break;
							cnt++;
							vis[3][x+i][j-x]=true;
						}
					}
					if(cnt>=k){
						rslt[tar-'A']=true;
					}
				}
			}
		}
		cout<<"Case #"<<c<<": ";
		bool rb,bb;
		rb=rslt['R'-'A'];
		bb=rslt[1];
		if(rb&bb)
			cout<<"Both\n";
		else if(rb)
			cout<<"Red\n";
		else if(bb)
			cout<<"Blue\n";
		else
			cout<<"Neither\n";
	}
	return 0;
}
