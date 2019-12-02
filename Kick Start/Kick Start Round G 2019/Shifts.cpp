#include<bits/stdc++.h>
using namespace std;
#define MAXN 60000
typedef long long int LL;
int T, en, st, n, h;
LL a[20], b[20], target, A[MAXN];
vector < LL > t[4 * MAXN];
vector < pair < LL, LL > > gen[2];
void generate(int i, int part, LL ha, LL hb) {
  if (i == en) {
    gen[part].push_back(make_pair(ha, hb));
    return;
  }
  generate(i + 1, part, ha + a[i], hb);
  generate(i + 1, part, ha, hb + b[i]);
  generate(i + 1, part, ha + a[i], hb + b[i]);
}
void build(int v, int tl, int tr) {
  t[v].clear();
  if (tl == tr) {
    t[v].push_back(A[tl]);
    return;
  }
  int tm = (tl + tr) / 2;
  build(v * 2, tl, tm);
  build(v * 2 + 1, tm + 1, tr);
  merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(),
    back_inserter(t[v]));
}
int query(int v, int tl, int tr, int l, int r, LL x) {
  if (tl > r or tr < l) return 0;
  if (tl >= l and tr <= r) return (t[v].end() - lower_bound(t[v].begin(), t[v].end(), x));
  int mid = (tl + tr) / 2;
  int left = v * 2;
  int right = left | 1;
  return query(left, tl, mid, l, r, x) + query(right, mid + 1, tr, l, r, x);
}
int main() {
  cin >> T;
  for (int nt = 1; nt <= T; nt++) {
    cin >> n >> h;
    gen[0].clear();
    gen[1].clear();
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    en = n / 2;
    generate(0, 0, 0, 0);
    en = n;
    generate(n / 2, 1, 0, 0);
    sort(gen[1].begin(), gen[1].end());
    for (int i = 0; i < gen[1].size(); i++) A[i] = gen[1][i].second;
    build(1, 0, gen[1].size() - 1);
    LL ans = 0LL;
    for (int i = 0; i < gen[0].size(); i++) {
      target = h - gen[0][i].first;
      st = lower_bound(gen[1].begin(), gen[1].end(), make_pair(target, 0LL)) - gen[1].begin();
      target = h - gen[0][i].second;
      ans += query(1, 0, gen[1].size() - 1, st, gen[1].size() - 1, target);
    }
    cout << "Case #" << nt << ": " << ans << "\n";
  }
  return 0;
}
