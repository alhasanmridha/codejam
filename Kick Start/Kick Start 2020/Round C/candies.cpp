#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define N 200001
int n,q,a[N];
LL mult[3*N],normal[3*N];
void build(int node, int l, int r){
	if(l==r){
		normal[node]=a[l];
		mult[node]=l*a[l];
		return;
	}
	int left=node<<1;
	int right=left|1;
	int mid=(l+r)>>1;
	build(left,l,mid);
	build(right,mid+1,r);
	normal[node]=normal[left]+normal[right];
	mult[node]=mult[left]+mult[right];
}
void update(int node, int l, int r, int id, int val){
	if(id<l or id>r) return;
	if(l==r){
		normal[node]=val;
		mult[node]=l*val;
		return;
	}
	int left=node<<1;
	int right=left|1;
	int mid=(l+r)>>1;
	update(left,l,mid,id,val);
	update(right,mid+1,r,id,val);
	mult[node]=mult[left]+mult[right];
	normal[node]=normal[left]+normal[right];
}
LL query(int node, int st, int en, int l, int r){
	if(r<st or l>en) return 0;
	if(st<=l and r<=en) return mult[node]-normal[node]*(st-1);
	int left=node<<1;
	int right=left|1;
	int mid=(l+r)>>1;
	return query(left,st,en,l,mid)+query(right,st,en,mid+1,r);
}
LL getRangeSum(int l, int r){
	LL sum=query(1,l,r,1,n);
	if(l%2==0) sum*=-1;
	return sum;
}

LL solve(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) if(i%2==0) a[i]*=-1;
	build(1,1,n);
	LL tot=0;
	while(q--){
		char type;
		cin>>type;
		if(type=='U'){
			int x,v;
			scanf("%d%d",&x,&v);
			if(x%2==0) v*=-1;
			update(1,1,n,x,v);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			tot+=getRangeSum(l,r);
		}
	}
	return tot;
}
int main(){
	int t,nt=1;
	cin>>t;
	while(t--) cout<<"Case #"<<nt++<<": "<<solve()<<"\n";
}

