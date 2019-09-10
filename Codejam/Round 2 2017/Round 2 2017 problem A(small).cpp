#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int main(){
	ifstream cin("input");
	ofstream cout("output");
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		cout<<"Case #"<<c<<": ";
		int n,p,a[100],one=0,two=0,cnt=0;
		cin>>n>>p;
		for(int i=0;i<n;i++)
			cin>>a[i];
		if(p==2){
			for(int i=0;i<n;i++){
				if(a[i]%2==0)
					cnt++;
			}
			cout<<cnt+(n-cnt+1)/2<<"\n";
		}
		if(p==3){
			for(int i=0;i<n;i++){
				if(a[i]%3==0)
					cnt++;
				else if(a[i]%3==1){
					one++;
				}
				else if(a[i]%3==2){
					two++;
				}
			}
			cout<<cnt+min(one,two)+(max(one,two)-min(one,two)+2)/3<<"\n";
		}
	}
}
