#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
struct node{
	int x,y,d;
};
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
string grid[255];
int t,r,c;
int dist[255][255];
bool is_valid(int x,int y){
	if(x>=r||y>=c||x<0||y<0) return false;
	return true;
}
void calc_distance(){
	queue<node>q;
	for(int x=0;x<r;x++){
		for(int y=0;y<c;y++){
			if(grid[x][y]=='1'){
				q.push({x,y,0});
				dist[x][y]=0;
			}
		}
	}
	while(!q.empty()){
		node cur=q.front();
		q.pop();
		int x,y;
		for(int i=0;i<4;i++){
			x=cur.x+dx[i];
			y=cur.y+dy[i];
			if(is_valid(x,y) and dist[x][y]>cur.d+1){
				q.push({x,y,cur.d+1});
				dist[x][y]=cur.d+1;
			}
		}
	}
}
bool is_ok(int k){
	int max_sum=-501,max_diff=-501,min_sum=501,min_diff=501;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(dist[i][j]>k){
				max_sum=max(max_sum,i+j);
				min_sum=min(min_sum,i+j);
				max_diff=max(max_diff,i-j);
				min_diff=min(min_diff,i-j);
			}
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			bool is_ok=true;
			if(max_sum-(i+j)>k)  is_ok=false;
			if(max_diff-(i-j)>k) is_ok=false;
			if(i+j-min_sum>k) is_ok=false;
			if(i-j-min_diff>k) is_ok=false;
			if(is_ok) return true;
		}
	}
	return false;
}

int main(){
	cin>>t;
	for(int nt=1;nt<=t;nt++){
		cin>>r>>c;
		for(int i=0;i<r;i++)
			cin>>grid[i];
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) dist[i][j]=500;
		calc_distance();
		int k=0,hi=500,lo=0;
		while(hi>lo){
			k=lo+(hi-lo)/2;
			if(is_ok(k)) hi=k;
			else lo=k+1;
		}
		cout<<"Case #"<<nt<<": "<<lo<<"\n";
	}
}	
