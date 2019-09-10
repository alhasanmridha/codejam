#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int main(){
	string s;
	int test;
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	cin>>test;
	for(int Case=1;Case<=test;Case++){
	vector<int>v(10);
	cin>>s;
	int cnt[100]={0};
	for(int i=0;i<s.length();i++){
		cnt[s[i]]++;
	}
	v[0]=cnt['Z'];
	v[2]=cnt['W'];
	v[8]=cnt['G'];
	v[6]=cnt['X'];
	v[7]=cnt['S']-v[6];
	v[4]=cnt['U'];
	v[3]=cnt['R']-v[4]-v[0];
	v[5]=cnt['F']-v[4];
	v[9]=cnt['I']-v[5]-v[6]-v[8];
	v[1]=cnt['N']-2*v[9]-v[7];
	cout<<"Case #"<<Case<<": ";
	for(int i=0;i<10;i++)
		for(int j=0;j<v[i];j++)
			cout<<i;
	cout<<"\n";
	}

}
