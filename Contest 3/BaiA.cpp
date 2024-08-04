
#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define ii pair<int, int>
#define pb push_back
#define bit(x, i) ((x >> i) & 1)
//#define int long long

using namespace std;

int  f[1003][1003][2];

int dis(ii a, ii b) {
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}

void solve() {
    int n, m; cin >> n >> m;
    ii a[n + 1], b[m + 1];
    for (int i = 1; i <= n; ++i) cin >> a[i].fi >> a[i].se;
    for (int i = 1; i <= m; ++i) cin >> b[i].fi >> b[i].se;
    memset(f, 0x3f, sizeof f);
    f[1][0][0] = 0;
    f[0][0][0] = f[0][0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 1 && j == 0) continue;
            f[i][j][0] = min(f[i - 1][j][0] + dis(a[i], a[i - 1]), f[i - 1][j][1] + dis(a[i], b[j]));
            if (j > 0) f[i][j][1] = min(f[i][j - 1][0] + dis(a[i], b[j]), f[i][j - 1][1] + dis(b[j - 1], b[j]));
        }
    }
    cout << f[n][m][0] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}