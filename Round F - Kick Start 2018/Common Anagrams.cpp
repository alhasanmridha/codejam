#include<bits/stdc++.h>
using namespace std;
int n,dpa[51][26],dpb[51][26];
int main(){
    int t;
    cin>>t;
    for(int nt=1;nt<=t;nt++){ 
        string a,b;
        cin>>n>>a>>b;
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                dpa[i+1][j]=dpa[i][j];
                dpb[i+1][j]=dpb[i][j];
            }
            int la=a[i]-'A';
            int lb=b[i]-'A';
            dpa[i+1][la]=dpa[i][la]+1;
            dpb[i+1][lb]=dpb[i][lb]+1;
        }	
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
				int lngth=j-i+1;
				for(int I=0;I+lngth<=n;I++){
				   bool mat=true;	
					for(int k=0;k<26;k++){
						if(dpa[i+lngth][k]-dpa[i][k]!=dpb[I+lngth][k]-dpb[I][k]){
							mat=false;
							break;
						}
					}
					if(mat){
						cnt++;
						break;
					}
				}
            }
        }
        cout<<"Case #"<<nt<<": "<<cnt<<"\n";
    }
    return 0;
}
