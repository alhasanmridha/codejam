#include <bits/stdc++.h>
using namespace std;
string grd[100];
int r,c,h,v,chocntrow[101],chocntcol[101];
int main(){
	int t;
	cin>>t;
	for(int C=1;C<=t;C++){
		cin>>r>>c>>h>>v;
		int totchocnt=0;
		for(int i=0;i<c;i++)
			chocntcol[i]=0;
		for(int i=0;i<r;i++){
			chocntrow[i]=0;
			cin>>grd[i];
			for(int j=0;j<c;j++)
				if(grd[i][j]=='@'){
					chocntrow[i]++;
					chocntcol[j]++;
				}
			totchocnt+=chocntrow[i];
		}
		cout<<"Case #"<<C<<": ";
		if(totchocnt==0){
			cout<<"POSSIBLE\n";
			continue;
		}
		int totdiv=(h+1)*(v+1);
		if(totchocnt%totdiv!=0){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		int chocpersq=totchocnt/totdiv;
		int chocperh=chocpersq*(v+1);
		int chocperv=chocpersq*(h+1);
		int hcutcnt=0;
		int rowcuts[101],colcuts[101];
		rowcuts[0]=0;
		colcuts[0]=0;
		for(int i=0;i<r;){
			int cnt=0;
			while(cnt<chocperh&&i<r){
				cnt+=chocntrow[i];
				i++;
			}
			if(cnt==chocperh){
				hcutcnt++;
				rowcuts[hcutcnt]=i;
			}
		}
		int vcutcnt=0;
		for(int i=0;i<c;){
			int cnt=0;
			while(cnt<chocperv&&i<c){
				cnt+=chocntcol[i];
				i++;
			}
			if(cnt==chocperv){
				vcutcnt++;
				colcuts[vcutcnt]=i;
			}
		}
		int persqcnt;
		bool is_possible=true;
		if(hcutcnt==h+1&&vcutcnt==v+1){
			for(int i=0;i<hcutcnt;i++){
				for(int j=0;j<vcutcnt;j++){
					persqcnt=0;
					for(int k=rowcuts[i];k<rowcuts[i+1];k++){
						for(int l=colcuts[j];l<colcuts[j+1];l++){
							if(grd[k][l]=='@')
								persqcnt++;
						}
					}
					if(persqcnt!=chocpersq){
						is_possible=false;
						break;
					}
				}
				if(!is_possible)
					break;
			}
			if(is_possible)
				cout<<"POSSIBLE\n";
			else
				cout<<"IMPOSSIBLE\n";
		}
		else
			cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
