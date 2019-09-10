#include <bits/stdc++.h>
using namespace std;
int n,m,a[41][41],mn[41][41][41][41],dp[41][41][41][41];
int f(int l,int r,int p,int q){
	if((l==r && p==q)||(r<l||q<p)){
		return 0;
	}
	if(dp[l][r][p][q])
		return dp[l][r][p][q];
	int ans=0;
	for(int i=l;i<r;i++){
		ans=max(ans,f(l,i,p,q)+f(i+1,r,p,q));
	}
	for(int i=p;i<q;i++){
		ans=max(ans,f(l,r,p,i)+f(l,r,i+1,q));
	}
	return dp[l][r][p][q]=ans+mn[l][r][p][q];
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]);
				mn[i][i][j][j]=a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m-1;j++){
				for(int k=j+1;k<m;k++){
					mn[i][i][j][k]=min(mn[i][i][j][k-1],mn[i][i][k][k]);
				}
			}
		}
		for(int i=0;i<m;i++){
			for(int j=i;j<m;j++){
				for(int k=0;k<n-1;k++){
					for(int l=k+1;l<n;l++){
						mn[k][l][i][j]=min(mn[k][l-1][i][j],mn[l][l][i][j]);
					}
				}
			}
		}
		cout<<"Case #"<<c<<": "<<f(0,n-1,0,m-1)<<"\n";
	}
}
