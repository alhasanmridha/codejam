#include<bits/stdc++.h>
using namespace std;
//---------------------start of NCR
int dp[1001][1001];
int ncr(int n, int r){
    if(n==r||r==0) return 1;
    if(dp[n][r]!=-1) return dp[n][r];
    return dp[n][r]=(ncr(n-1,r-1) % mod + ncr(n-1,r) % mod) % mod;
}
//--------------------------end of NCR
int main(){

}
