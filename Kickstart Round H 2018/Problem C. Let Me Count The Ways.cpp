#include<bits/stdc++.h>
using namespace std;


typedef long long LL;
typedef unsigned long long ULL;

const int N = 2 * 100000;
LL fct[N + 5];
LL po[N + 5];
LL inv[N + 5];
const LL MOD = 1e9 + 7;

LL fast(LL A,LL B) {
    LL ans = 1;
    while(B) {
        if(B & 1) ans = ans * A % MOD;
        A = A * A % MOD;
        B /= 2;
    }
    return ans;
}

void pre() {
    fct[0] = 1;
    for(LL i = 1;i <= N;i++) fct[i] = fct[i-1] * i % MOD;
    inv[N] = fast(fct[N], MOD - 2);
    for(LL i = N - 1;i >= 0;i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    po[0] = 1;
    for(int i = 1;i <= N;i++) po[i] = po[i-1] * 2 % MOD;
}

LL combin(int n,int r) {
    return fct[n] * inv[r] % MOD * inv[n - r] % MOD;
}


int main(){
    pre();
	int ntc;
	cin>>ntc;
	int n,m;
	for(int tc = 1;tc <= ntc;tc++) {
		cin>>n>>m;
		
		LL ways = 0;
		
		 for(int i = 0;i <= m;i++) {
		     LL subways = combin(m,i) * po[i] % MOD * fct[2*n - i] % MOD;
		     if(i & 1) ways = (ways + MOD - subways) % MOD;
		     else ways = (ways + subways) % MOD;
		 } 
		cout<<"Case #"<<tc<<": "<<ways<<endl;
	}
	
	return 0;
}



