#include<bits/stdc++.h>

#define S 100001
using namespace std;
int h[S], n, g, m, t;
char c[S];
int new_pos(int a, char c) {
   a = (c == 'C' ? a + 1 : a - 1);
   return (a + n) % n;
}
int main() {
   cin >> t;
   for (int nt = 1; nt <= t; nt++) {
      cin >> n >> g >> m;
      vector < int > cnt(g, 0);
      vector < set < int >> s(n);
      for (int i = 0; i < g; i++) {
         cin >> h[i] >> c[i];
         h[i]--;
         cnt[i] = 0;
      }
      for (int j = 0; j < g; j++) {
         s[h[j]].insert(j);
      }
      while (m--) {
         for (int i = 0; i < g; i++) {
            h[i] = new_pos(h[i], c[i]);
            s[h[i]].clear();
         }
         for (int j = 0; j < g; j++) {
            s[h[j]].insert(j);
         }
      }
      for (int i = 0; i < n; i++)
         for (set < int > ::iterator it = s[i].begin(); it != s[i].end(); ++it)
            cnt[ * it]++;
      cout << "Case #" << nt << ": ";
      for (int i = 0; i < g; i++)
         cout << cnt[i] << " ";
      puts("");
   }
   return 0;
}
