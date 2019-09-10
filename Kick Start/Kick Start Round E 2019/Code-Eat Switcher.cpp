#include<bits/stdc++.h>
using namespace std;
#define S 100001
long double a, b, c, e;
struct slot {
    long double c, e;
};
int main() {
    int t, d, s;
    cin >> t;
    for (int nt = 1; nt <= t; nt++) {
        cout << "Case #" << nt << ": ";
        cin >> d >> s;
        slot sl[s];
        for (int i = 0; i < s; i++) {
            cin >> c >> e;
            sl[i] = {
                c,
                e
            };
        }
        sort(sl, sl + s, [](slot a, slot b) {
            return a.c / a.e > b.c / b.e;
        });
        long double presum[s + 1], sufsum[s + 1];
        presum[0] = 0;
        sufsum[0] = 0;
        for (int i = 0; i < s; i++) {
            presum[i + 1] = sl[i].c + presum[i];
            sufsum[i + 1] = sl[s - 1 - i].e + sufsum[i];
        }
        for (int i = 0; i < d; i++) {
            cin >> a >> b;
            if (presum[s] < a) {
                cout << "N";
                continue;
            }
            int indx = (int)(upper_bound(presum, presum + s + 1, a) - presum);
            if (indx == s + 1) {
                if (b != 0)
                    cout << "N";
                else
                    cout << "Y";
                continue;
            }
            long double f = (presum[indx] - a) / sl[indx - 1].c;
            b -= f * sl[indx - 1].e;
            int eatindx = (int)(lower_bound(sufsum, sufsum + s + 1, b) - sufsum);
            if (eatindx + indx > s) {
                cout << "N";
                continue;
            }
            cout << "Y";
        }
        puts("");
    }
}
