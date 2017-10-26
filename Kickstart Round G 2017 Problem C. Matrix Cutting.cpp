#include <bits/stdc++.h>
using namespace std;
int n,m,a[41],mn[41][41];
int f(int s,int e){
	if(s==e) return 0;
	int result=0;
	for(int i=s;i<e;i++){
		result=max(result,f(s,i)+f(i+1,e));
	}
	return result+mn[s][e];
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d",a+i);
			mn[i][i]=a[i];
		}
		for(int i=0;i<m;i++)
			for(int j=i+1;j<m;j++)
				if(a[j]<mn[i][j-1])
					mn[i][j]=a[j];
				else
					mn[i][j]=mn[i][j-1];
		cout<<"Case #"<<c<<": "<<f(0,m-1)<<"\n";
	}
}
