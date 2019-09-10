#include <bits/stdc++.h>
using namespace std;
int n,x,y;
vector<int>v[1001],cycle;
int parent[1001],dis[1001];
bool vis[1001],insrtd[1001];
bool fnd=false;
int hlt;
void create_cycle(int node){
	cycle.push_back(node);
	insrtd[node]=true;
	dis[node]=0;
	if(node==hlt)
		return;
	create_cycle(parent[node]);
	return;
}
void prnt_cycle(int indx){
	if(vis[indx]){
		fnd=true;
		hlt=indx;
		create_cycle(parent[indx]);
		return;
	}
	vis[indx]=true;
	for(int i=0;i<v[indx].size();i++){
		int node=v[indx][i];
		if(node!=parent[indx]&&!fnd){
			parent[node]=indx;
			prnt_cycle(node);
		}
	}
}
void calc(int node,int dst){
	dis[node]=dst;
	for(int i=0;i<v[node].size();i++){
		if(!insrtd[v[node][i]]){
			insrtd[v[node][i]]=true;
			calc(v[node][i],dst+1);
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t=1;
	cin>>t;
	for(int c=1;c<=t;c++){
		cin>>n;
		fnd=false;
		cycle.clear();
		for(int i=0;i<n;i++){
			cin>>x>>y;
			v[x-1].push_back(y-1);
			v[y-1].push_back(x-1);
			parent[i]=-1;
			vis[i]=false;
			insrtd[i]=false;
		}
		prnt_cycle(0);
		for(int i=0;i<cycle.size();i++){
			calc(cycle[i],0);
		}
		cout<<"Case #"<<c<<": ";
		for(int i=0;i<n;i++)
			cout<<dis[i]<<" ";
		cout<<"\n";
		for(int i=0;i<n;i++){
			v[i].clear();
		}
	}
}
