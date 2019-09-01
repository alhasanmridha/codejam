#include<bits/stdc++.h>
using namespace std;
struct stone {
    int s, e, l;
};
int t, n, s, e, l,dp[100][10001];
stone st[100];
int solve(int id, int time) {
    if (id == n) return 0;
    int & ans = dp[id][time];
    if (ans != -1)
        return ans;
    ans = max(solve(id + 1, time + st[id].s) + st[id].e - st[id].l * time, solve(id + 1, time));
    return ans;
}
int main() {
    scanf("%d", & t);
    for (int nt = 1; nt <= t; nt++) {
        scanf("%d", & n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", & s, & e, & l);
            st[i] = {s,e,l};
        }
        sort(st, st + n, [](stone a, stone b) {
            return a.s * b.l < b.s * a.l;
        });
	for(int i = 0; i < n; i++) for(int j = 0; j <= 10000; j++) dp[i][j] = -1;    
        cout << "Case #" << nt << ": " << solve(0,0) << "\n";
    }
    return 0;
}
