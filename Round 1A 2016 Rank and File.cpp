#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int t,member,n,cnt[2501];
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Case #"<<i+1<<": ";
        for(int i=0;i<2501;i++) cnt[i]=0;
        cin>>n;
        for(int i=0;i<(2*n-1);i++){
            for(int j=0;j<n;j++){
                cin>>member;
                cnt[member]++;
            }
        }
        for(int i=1;i<2501;i++){
            if(cnt[i]%2!=0){
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
