#include<bits/stdc++.h>
using namespace std;
double max(double a, double b){
    return a>b?a:b;
}
int main(){
    int tn;
    cin>>tn;
    for(int tc=1;tc<=tn;tc++){
        int n,k;
        cin>>n>>k;
        double v[n];
        for(int i=0;i<n;i++)
        scanf("%lf",v+i);
        double e=0;
        for(int i=0;i<k+1;i++){
            double sum=0;
            for(int j=0;j<n;j++){
                sum = sum + max((double)v[j],e);

			}
            e=sum/(double)n;
        }
        cout<<"Case #"<<tc<<": "<<setprecision(7)<<fixed<<e<<"\n";
    }
}
