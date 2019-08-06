#include<bits/stdc++.h>

using namespace std;
int S = 1e5 + 1;
bool is_odd(int a) {
   int cnt = 0;
   for (int i = 0; 1 << i <= a; i++)
      cnt += min(1, 1 << i & a);
   return cnt % 2;
}
int main() {
   int t, n, q, a[S], v, p;
   cin >> t;
   for (int nt = 1; nt <= t; nt++) {
      cin >> n >> q;
      set < int > s;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         if (is_odd(a[i]))
            s.insert(i);
      }
      cout << "Case #" << nt << ":";
      for (int i = 0; i < q; i++) {
         cin >> p >> v;

         if (!is_odd(a[p]) and is_odd(v))
            s.insert(p);

         else if (is_odd(a[p]) and!is_odd(v))
            s.erase(s.find(p));

         a[p] = v;

         if (s.size() % 2 == 0)
            cout << " " << n;

         else
            cout << " " << max(n - * s.begin() - 1, * s.rbegin());
      }
      cout << "\n";
   }
   return 0;
}
