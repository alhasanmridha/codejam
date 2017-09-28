#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	int b[51],a[51];
	int t,l;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>s;
		cout<<"Case #"<<i<<": ";
		l=s.length();
		for(int i=0;i<l;i++)
			a[i]=s[i]-'A';
		if(l%2==1){
			cout<<"AMBIGUOUS\n";
			continue;
		}
		b[1]=a[0];
		for(int i=3;i<l;i++){
			if(a[i-1]<b[i-2])
				a[i-1]+=26;
			b[i]=(a[i-1]-b[i-2])%26;
		}
		b[l-2]=a[l-1];
		for(int i=l-4;i>=0;i--){
			if(a[i+1]<b[i+2])
				a[i+1]+=26;
			b[i]=(a[i+1]-b[i+2])%26;
		}
		for(int i=0;i<l;i++)
			cout<<(char)(b[i]+'A');
		cout<<"\n";
	}
}
