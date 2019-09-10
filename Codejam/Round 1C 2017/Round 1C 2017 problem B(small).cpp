#include <bits/stdc++.h>
using namespace std;
struct shedule{
	int st,end;
	bool operator<(const shedule& o)const
	{
		return st<o.st;
	}
};
int main(){
	ifstream cin("input");
	ofstream cout("output");
	int t,ac,aj;
	shedule c[2],j[2];
	cin>>t;
	for(int C=1;C<=t;C++){
		cout<<"Case #"<<C<<": ";
		cin>>ac>>aj;
		for(int i=0;i<ac;i++){
			cin>>c[i].st>>c[i].end;
		}
		for(int i=0;i<aj;i++){
			cin>>j[i].st>>j[i].end;
		}
		if(ac==1||aj==1) cout<<"2\n";
		else{
			if(ac==2){
				sort(c,c+2);
				if(c[0].st+1440-c[1].end>=720||c[1].st-c[0].end>=720) cout<<"2\n";
				else cout<<"4\n";
			}
			else{
				sort(j,j+2);
				if(j[0].st+1440-j[1].end>=720||j[1].st-j[0].end>=720) cout<<"2\n";
				else cout<<"4\n";
			}
		}
	}
}
