#include <iostream>
using namespace std;
#define L 1001
int main(){
	int tot_test,n;
	cin>>tot_test;
	for(int Case=1;Case<=tot_test;Case++){
		cout<<"Case #"<<Case<<": ";
		int bff[L];
		cin>>n;
		int ans=0;
		int twos_len[L]={0};
		for(int i=0;i<n;i++){
			cin>>bff[i];
			bff[i]--;
		}
		int path[L]={0};
		for(int i=0;i<n;i++){
			int flag[L]={0};
			int cur=i;
			flag[cur]=1;
			int len=1;
			while(flag[bff[cur]]==0){
				cur=bff[cur];
				len++;
				flag[cur]=1;
			}
			if(bff[cur]==i){
				ans=max(ans,len);
			}
			if(bff[bff[cur]]==cur){
				twos_len[bff[cur]]=max(twos_len[bff[cur]],len-1);
			}
		}
		int sum=0;
		for(int i=0;i<n;i++)
			sum+=twos_len[i];
		cout<<max(ans,sum)<<"\n";
	}
}
