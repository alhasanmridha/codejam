#include<bits/stdc++.h>
using namespace std;
int main(){
	int  T;
	cin>>T;
	for(int c=1;c<=T;c++){
		string leader,str;
		int l;
		scanf("%d",&l);
		getline(cin,str);
		int len=0;
		for(int i=0;i<l;i++){
			getline(cin,str);
			int flag[26];
			for(int i=0;i<26;i++){
				flag[i]=0;
			}
			int tlen=0;
			// cout<<str<<" "<<str.length()<<endl;
			for(int i=0;i<str.length();i++){
				if(str[i]==' '){
					continue;
				}
				tlen+=(1-flag[str[i]-'A']);
				flag[str[i]-'A']=1;
			}
			if(tlen==len){
				leader=min(str,leader);
			}
			if(tlen>len){
				len=tlen;
				leader=str;
			}
		}
		cout<<"Case #"<<c<<": "<<leader<<"\n";
	}
}
