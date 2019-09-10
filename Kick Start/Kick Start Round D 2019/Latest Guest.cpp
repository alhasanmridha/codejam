#include<bits/stdc++.h>
using namespace std;
#define S 100001
int h[S], n, g, m, t;
char c[S];
int new_pos(int a, char c) {
    a = (c == 'C' ? a + m : a - m);
    return (a % n + n) % n;
}
struct Stat {
    int type, tme, grp;
    Stat(int t, int tm, int g) {
        type = t;
        tme = tm;
        grp = g;
    }
    bool operator < (Stat s) {
        return tme < s.tme;
    }
};
int main() {
    cin >> t;
    for (int nt = 1; nt <= t; nt++) {
        cin >> n >> g >> m;
        vector < int > cnt(g, 0);
        vector < int > groups[2][n];
        for (int i = 0; i < g; i++) {
            cin >> h[i] >> c[i];
            h[i]--;
            int dest = new_pos(h[i], c[i]);
            groups[c[i] == 'A'][dest].push_back(i);
        }
        vector < Stat > cons[n];
        for (int i = 0; i < n; i++) {
            int tm = 0;
            while (i < n and groups[0][i].size() == 0) i++;
            if (i == n)
                break;
            cons[i].push_back({
                0,
                tm++,
                i
            });
            for (int j = i - 1; tm <= m; j--) {
                if (groups[0][(j + n) % n].size() > 0)
                    break;
                cons[(j + n) % n].push_back({
                    0,
                    tm++,
                    i
                });
            }
        }
        for (int i = 0; i < n; i++) {
            int tm = 0;
            while (i < n and groups[1][i].size() == 0) i++;
            if (i == n)
                break;
            cons[i].push_back({
                1,
                tm++,
                i
            });
            sort(cons[i].begin(), cons[i].end());
            for (int j = i + 1; tm <= m; j++) {
                if (groups[1][j % n].size() > 0)
                    break;
                cons[j % n].push_back({
                    1,
                    tm++,
                    i
                });
                sort(cons[j % n].begin(), cons[j % n].end());
            }
        }
        for (int i = 0; i < n; i++) {
            if (cons[i].size() == 0)
                continue;
            int tm = cons[i][0].tme;
            for (auto ob: cons[i]) {
                if (tm != ob.tme)
                    break;
                vector < int > v = groups[ob.type][ob.grp];
                for (int id: v)
                    cnt[id]++;
            }
        }
        cout << "Case #" << nt << ": ";
        for (int i = 0; i < g; i++)
            cout << cnt[i] << " ";
        puts("");
    }
    return 0;
}
