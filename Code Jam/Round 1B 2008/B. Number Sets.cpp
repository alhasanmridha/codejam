#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000000001
# define S 1000001
typedef long long int LL;
bool is_comp[S];
int parents[1000001];
int find(int a){
	if(parents[a]!=a)
		parents[a]=find(parents[a]);
	return parents[a];
}
void merge(int a, int b){
	a=find(a);
	b=find(b);
	parents[b]=parents[a];
}
LL P;
vector < long long int > primes;
int solve(long long int m, long long int n) {
    int cnt = 0;
	int is_prime[n - m + 2];
	for (int i = 0; i + m <= n; i++){
		is_prime[i] = 1;
		parents[i]=i;
	}
	int cut_id = lower_bound(primes.begin(),primes.end(),P)-primes.begin();
	for (int j = cut_id; j < (int)primes.size() and primes[j] <= n; j++) {
		LL p = primes[j];
		LL k = p;
		if (k < m) k = (m + p - 1) / p * p;
		LL pre = k;
		k+=p;
		if(pre<=n)
			is_prime[pre-m] = 2;
		for (; k <= n; k+=p){
			is_prime[k - m] = 2;
			merge(pre-m,k-m);
		}
	}
	for (int j = 0; j < cut_id and primes[j] * primes[j] <= n; j++) {
		LL p = primes[j];
		LL k = p * p;
		if (k < m) k = (m + p - 1) / p * p;
		for (; k <= n; k+=p){
			is_prime[k - m] = is_prime[k-m]==2?2:0;
		}
	}

	for (int i = 0; m + i <= n; i++){
		if(is_prime[i]<2 or parents[i]==i) cnt++;
	}
    return cnt;
}
int main() {
    int t,nt = 0;
	LL l, r;
    for (long long int i = 2; i * i < MAXN; i++) {
        if (!is_comp[i])
            primes.push_back(i);
        for (unsigned long j = 0; j < primes.size() and primes[j] * i < S; j++) {
            is_comp[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    cin >> t;
    while (t--) {
        cin >> l >> r >> P;
        cout << "Case #" << ++nt << ": " << solve(l, r) << "\n";
    }
    return 0;
}
