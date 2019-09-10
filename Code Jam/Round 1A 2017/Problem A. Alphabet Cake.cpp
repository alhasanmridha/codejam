#include <bits/stdc++.h>
using namespace std;
int row,col;
string grd[25];

int alphabet_left(int sr,int sc,int er,int ec){
	int cnt=0;
	for(int i=sr;i<=er;i++)
		for(int j=sc;j<=ec;j++)
			if(grd[i][j]!='?')
				cnt++;
	return cnt;
}
void _fill(int sr,int sc,int er,int ec){
	char tar='?';
	for(int i=sr;i<=er;i++){
		for(int j=sc;j<=ec;j++){
			if(grd[i][j]!='?')
				tar=grd[i][j];
		}
		if(tar!='?')
			break;
	}
	for(int i=sr;i<=er;i++)
		for(int j=sc;j<=ec;j++)
			grd[i][j]=tar;
}
void fill(int sr,int sc,int er,int ec){
	// print_grd(sr,sc,er,ec);
	int left = alphabet_left(sr,sc,er,ec);
	if(left == 1){
		_fill(sr,sc,er,ec);
		return;
	}
	for(int i=sr;i<=er;i++){
		for(int j=sc;j<=ec;j++){
			if(grd[i][j]!='?'){
				left = alphabet_left(i+1,sc,er,ec);
				if(left==0){
					fill(sr,sc,er,j);
					fill(sr,j+1,er,ec);
					return;
				}
				else{
					fill(sr,sc,i,ec);
					fill(i+1,sc,er,ec);
					return;
				}
			}
		}
	}

}
int main(){
	int T;
	cin>>T;
	for(int c=1;c<=T;c++){
		scanf("%d%d",&row,&col);
		for(int i=0;i<row;i++)
			cin>>grd[i];
		cout<<"Case #"<<c<<":\n";
		fill(0,0,row-1,col-1);
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cout<<grd[i][j];
			}
			cout<<"\n";
		}
	}
	return 0;
}
