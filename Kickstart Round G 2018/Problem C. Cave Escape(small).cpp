#include <bits/stdc++.h>
#define M 1000000000
using namespace std;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int t,n,m,e,sr,sc,tr,tc,grid[100+1][100+1],dist[100+1][100+1];
struct node{
	int x,y,d;
	bool operator<(const node& o) const{
		return d>o.d;
	}
};
int is_valid(int x, int y){
	return x<n&&y<m&&x>-1&&y>-1&&grid[x][y]!=-100000;
}
int main(){
	cin>>t;
	for(int C=1;C<=t;C++){
		cin>>n>>m>>e>>sr>>sc>>tr>>tc;
		sr--;
		sc--;
		tr--;
		tc--;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cin>>grid[i][j];
				dist[i][j]=M;
			}
		priority_queue<node> Q;
		Q.push({sr,sc,0});
		dist[sr][sc]=0;
		while(!Q.empty()){
			node nd=Q.top();
			Q.pop();
			if(dist[nd.x][nd.y]<nd.d)
				continue;
			for(int i=0;i<4;i++){
				int nx=nd.x+dx[i];
				int ny=nd.y+dy[i];
				if(is_valid(nx,ny)){
					if(dist[nd.x][nd.y]-grid[nx][ny]<dist[nx][ny]){
						dist[nx][ny]=dist[nd.x][nd.y]-grid[nx][ny];
						Q.push({nx,ny,nd.d-grid[nx][ny]});
					}
				}
			}
		}
		cout<<"Case #"<<C<<": ";
		if(dist[tr][tc]>e)
			cout<<-1<<"\n";
		else
			cout<<e-dist[tr][tc]<<"\n";
	}
	return 0;
}
