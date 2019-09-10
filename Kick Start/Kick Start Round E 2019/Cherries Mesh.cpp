#include<bits/stdc++.h>
using namespace std;
#define S 100001
int n, m, parent[S], ans;
bool vis[S];
void initialize() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        vis[i] = false;
    }
    ans = 0;
}
int root(int x) {
    if (parent[x] != x)
        parent[x] = root(parent[x]);
    return parent[x];
}
int main() {
    int t, x, y;
    cin >> t;
    for (int nt = 1; nt <= t; nt++) {
        cin >> n >> m;
        initialize();
        while (m--) {
            cin >> x >> y;
            x = root(x);
            y = root(y);
            if (x != y) {
                ans++;
                parent[x] = y;
            }
        }
        vis[root(1)] = true;
        for (int i = 2; i <= n; i++) {
            if (!vis[root(i)])
                ans += 2;
            vis[root(i)] = true;
        }
        cout << "Case #" << nt << ": " << ans << "\n";
    }
    return 0;
}
