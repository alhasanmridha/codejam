#include<bits/stdc++.h>
using namespace std;
map < char, pair < int, int > > dir;
int main() {
    int t;
    dir['N']={-1,0};
    dir['S']={1,0};
    dir['W']={0,-1};
    dir['E']={0,1};
    cin >> t;
    for (int nt = 1; nt <= t; nt++) {
        int n, r, c, x, y;
        cin >> n >> r >> c >> x >> y;
        string s;
        cin >> s;
        unordered_set < int > us[r + 1];
        us[x].insert(y);
        for (int i = 0; i < n; i++) {
            int dx = dir[s[i]].first;
            int dy = dir[s[i]].second;
            x += dx;
            y += dy;
            while (us[x].find(y) != us[x].end()) {
                x += dx;
                y += dy;
            }
            us[x].insert(y);
        }
        cout << "Case #" << nt << ": " << x << " " << y << "\n";
    }
    return 0;
}
