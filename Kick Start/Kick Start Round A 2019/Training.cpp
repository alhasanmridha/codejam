#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main(){
    int t;
    cin>>t;
    for(int nt=1;nt<=t;nt++){
        int n,p;
        cin>>n>>p;
        LL a[n];
        for(int i=0;i<n;i++){
            scanf("%lld",a+i);
        }
        sort(a,a+n);
        LL dp[n+1];
        dp[0]=0;
        for(int i=0;i<n;i++){
            dp[i+1]=dp[i]+a[i];
        }
        LL ans=(LL) 1e10;
        for(int i=0;i+p<=n;i++){
            ans=min(ans,p*a[i+p-1]-dp[i+p]+dp[i]);
        }
        cout<<"Case #"<<nt<<": "<<ans<<"\n";
    }
}
