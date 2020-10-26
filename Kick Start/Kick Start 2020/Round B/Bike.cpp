#include<iostream>
using namespace std;
int main(){
    int t,nt=0,n,h[100];
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>h[i];
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(h[i]>h[i-1] and h[i]>h[i+1]) ans++;
        }
        cout<<"Case #"<<++nt<<": "<<ans<<"\n";
    }
}
