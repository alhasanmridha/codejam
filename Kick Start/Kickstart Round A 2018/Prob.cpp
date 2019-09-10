#include<bits/stdc++.h>
using namespace std;
int main(){
    int tn;
    cin>>tn;
    for(int tc=1;tc<=tn;tc++){
        int n,k;
        cin>>n>>k;
        double v[n];
        for(int i=0;i<n;i++)
        scanf("%d",v+i);
        double e0=0;
        for(int i=0;i<k;i++){
            double sum=0;
            for(int j=0;j<n;j++){
                sum+=max(v[i],e0);
            }
            e0=sum/n;
        }
        cout<<"Case #"<<tc<<": "<<e0<<"\n";
    }
}
