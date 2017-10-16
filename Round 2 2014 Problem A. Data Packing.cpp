#include <bits/stdc++.h>
using namespace std;
int vol[10000],t,n,x,cnt,last,first;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	for(int c=1;c<=t;c++){
		scanf("%d%d",&n,&x);
		for(int i=0;i<n;i++)
			scanf("%d",vol+i);
		sort(vol,vol+n);
		last=n-1,first=0,cnt=0;
		while(last>=first){
			if(vol[last]+vol[first]<=x){
				first++;
			}
			last--;
			cnt++;
		}
		printf("Case #%d: %d\n",c,cnt);
	}
}
