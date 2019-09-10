#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000001
# define S 31624
bool is_comp[S];
vector < int > primes;
int number_of_primes_in(int m, int n) {
    int cnt = 0;
    bool is_prime[n - m + 2];
    for (int i = 0; i < n - m + 2; i++) is_prime[i] = true;
    for (unsigned long j = 0; j < primes.size() and primes[j] * primes[j] <= n; j++) {
        int p = primes[j];
        int k = p * p;
        if (k < m) k = (m + p - 1) / p * p;
        for (; k <= n; k += p)
            is_prime[k - m] = false;
    }
    for (int i = 0; m + i <= n; i++)
        if (is_prime[i]) cnt++;
    return cnt;
}
int main() {
    int t, l, r, nt = 0;
    for (int i = 2; i * i < MAXN; i++) {
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
        cin >> l >> r;
        int ans = 0;
        ans += number_of_primes_in(l, r);                 //Case 1
        ans += r / 2 - (l + 1) / 2 - r / 4 + (l + 3) / 4; //Case 2
        ans -= (r >= 2 and l <= 2);                       //if X=2 is counted in both case 1 and 2
        ans += number_of_primes_in((l + 3) / 4, r / 4);   //Case 3 and 4.
        cout << "Case #" << ++nt << ": " << ans << "\n";
    }
    return 0;
}
