#include<bits/stdc++.h>

using namespace std;

int t, r, c, k, v[301][301], hist[301], stmn[301][301][25], stmx[301][301][25], ans = 0, _log2[301];

int get_min(int i, int l, int r) {
    int j = _log2[r - l + 1];
    return min(stmn[i][l][j], stmn[i][r - (1 << j) + 1][j]);
}

int get_max(int i, int l, int r) {
    int j = _log2[r - l + 1];
    return max(stmx[i][l][j], stmx[i][r - (1 << j) + 1][j]);
}

int get_mx_rect_area_of_histo(int j) {
    for (int i = 0; i < r; i++) {
        int cnt = 0;
        for (int l = j + hist[i]; l < c and get_max(i, j, l) <= get_min(i, j, l) + k; l++)
            cnt++;
        hist[i] += cnt;
    }
    stack < int > st;
    int id = 0, area, mxarea = 0, x;
    while (id < r) {
        if (st.empty() or hist[st.top()] <= hist[id]) {
            st.push(id);
            id++;
        } else {
            x = st.top();
            st.pop();
            if (st.empty())
                area = id * hist[x];
            else
                area = (id - st.top() - 1) * hist[x];
            mxarea = max(area, mxarea);
        }
    }
    while (!st.empty()) {
        x = st.top();
        st.pop();
        if (st.empty())
            area = r * hist[x];
        else
            area = (r - st.top() - 1) * hist[x];
        mxarea = max(mxarea, area);
    }
    return mxarea;
}

int main() {
    _log2[1] = 0;
    for (int i = 2; i < 301; i++) _log2[i] = _log2[i / 2] + 1;
    cin >> t;
    for (int nt = 1; nt <= t; nt++) {
        cin >> r >> c >> k;
        ans = 0;
        for (int i = 0; i < r; i++) {
            hist[i] = 0;
            for (int j = 0; j < c; j++) {
                cin >> v[i][j];
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                stmn[i][j][0] = stmx[i][j][0] = v[i][j];
            }
            for (int k = 1; k < 25; k++) {
                for (int j = 0; j + (1 << k) <= c; j++) {
                    stmn[i][j][k] = min(stmn[i][j][k - 1], stmn[i][j + (1 << (k - 1))][k - 1]);
                    stmx[i][j][k] = max(stmx[i][j][k - 1], stmx[i][j + (1 << (k - 1))][k - 1]);
                }
            }
        }
        for (int j = 0; j < c; j++) {
            ans = max(ans, get_mx_rect_area_of_histo(j));
            for (int i = 0; i < r; i++) hist[i]--;
        }
        cout << "Case #" << nt << ": " << ans << "\n";
    }
    return 0;
}
