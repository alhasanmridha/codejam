#include<bits/stdc++.h>

#define S 100001 //size of the array
using namespace std;
typedef long long int ll;
int k, n;
struct point {
  ll x, c;
  bool operator < (point o) {
    return x < o.x;
  }
};
point p[S];
ll get_cost(int i, int j) {
  return p[i].c + abs(p[i].x - p[j].x);
}
int main() {
  int t;
  cin >> t;
  for (int nt = 1; nt <= t; ++nt) {
    cin >> k >> n;
    for (int i = 0; i < n; i++)
      cin >> p[i].x;
    for (int i = 0; i < n; i++)
      cin >> p[i].c;
    sort(p, p + n);
    ll ans = LLONG_MAX;
    priority_queue < ll > pq;
    ll sum = 0;
    vector < ll > b(n), e(n);
    for (int i = 0; i < n; i++)
      b[i] = e[i] = LLONG_MAX / 2;
    int fm = k / 2;
    int bm = k - k / 2;
    for (int i = 0; i < fm; i++) {
      sum += get_cost(i, n - 1);
      pq.push(get_cost(i, n - 1));
    }
    for (int i = fm; i < n; i++) {
      b[i] = sum - fm * (p[n - 1].x - p[i].x);
      if (!pq.empty()) {
        ll mx = pq.top();
        if (mx > get_cost(i, n - 1)) {
          pq.pop();
          sum -= (mx - get_cost(i, n - 1));
          pq.push(get_cost(i, n - 1));
        }
      }
    }
    while (!pq.empty())
      pq.pop();
    sum = 0;
    for (int i = 0; i < bm; i++) {
      sum += get_cost(n - i - 1, 0);
      pq.push(get_cost(n - 1 - i, 0));
    }
    for (int i = n - bm - 1; i >= 0; i--) {
      e[i] = sum - bm * (p[i].x - p[0].x);
      if (!pq.empty()) {
        ll mx = pq.top();
        if (mx > get_cost(i, 0)) {
          pq.pop();
          sum -= (mx - get_cost(i, 0));
          pq.push(get_cost(i, 0));
        }
      }
    }
    for (int i = 0; i < n; i++)
      ans = min(ans, b[i] + e[i] + p[i].c);
    cout << "Case #" << nt << ": " << ans << "\n";
  }
}
