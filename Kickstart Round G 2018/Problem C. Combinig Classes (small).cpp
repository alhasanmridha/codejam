#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
struct pair{
	LL l,r;
	bool operator<(pair o){
		return r>o.r;
	}
}p[400001];
int main(){
	int t,n,q;
	LL x,x1,x2,y,y1,y2,z,z1,z2,a1,a2,a3,b1,b2,b3,c1,c2,c3,m1,m2,m3,k[100001];
	cin>>t;
	for(int nt=1;nt<=t;nt++){
		cin>>n>>q>>x1>>x2>>a1>>b1>>c1>>m1>>y1>>y2>>a2>>b2>>c2>>m2>>z1>>z2>>a3>>b3>>c3>>m3;
		p[0].l=min(x1,y1)+1;
		p[0].r=max(x1,y1)+1;
		p[1].l=min(x2,y2)+1;
		p[1].r=max(x2,y2)+1;
		k[0]=z1+1;
		k[1]=z2+1;
		for(int i=2;i<n;i++){
			x=(a1*x2+b1*x1+c1)%m1;
			y=(a2*y2+b2*y1+c2)%m2;
			p[i].l=min(x,y)+1;
			p[i].r=max(x,y)+1;
			x1=x2;
			y1=y2;
			x2=x;
			y2=y;
		}

		cout<<"Case #"<<nt<<": ";
		sort(p,p+n);
		for(int i=2;i<q;i++){
			z=(a3*z2+b3*z1+c3)%m3;
			k[i]=z+1;
			z1=z2;
			z2=z;
		}
		LL result=0;
		vector<LL> ans;
		for(int i=0;i<q;i++){
			LL lo=0,hi=1000000001,mid,cnt;
			while(lo<hi){
				mid=lo+(hi-lo+1)/2;
				cnt=0;
				for(int j=0;j<n;j++){
					if(p[j].r<mid) break;
					cnt+=(p[j].r-max(p[j].l,mid)+1);
				}
				if(cnt>=k[i]){
					lo=mid;
				}
				else{
					hi=mid-1;
				}

			}
			ans.push_back(lo);
		}

		for(int i=1;i<=q;i++){ 
			result+=ans[i-1]*i; }
		cout<<result<<"\n";
	}
	return 0;
}
