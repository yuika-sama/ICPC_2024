#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define fi first
#define sc second
#define pb push_back
#define eb emplace_back
#define ins insert
#define sz size()
#define len length
#define mp make_pair
#define al(v) (v).begin(), (v).end()
#define sp << ' ' <<
#define endl '\n'
#define precision(x) setprecision(x) << fixed
#define nekonooke {cout << "Ame nara ashita wa hareru darou~"}
const int oo = 1e9+7;

//end of template
ll q[200005], dp[200005], h[200005];
double getVal(ll a, ll b){
    double x = 1.0 * dp[a] + 1.0 * h[a] * h[a];
    double y = 1.0 * dp[b] + 1.0 * h[b] * h[b];
    return (x-y) / (1.0 * (h[a] - h[b]));
}
void solve(){
    /*hav fun with coding*/
    ll n, c;
    cin >> n >> c;
    for (int i=1; i<=n; i++){
        cin >> h[i];
    }
    q[1] = 1;
    int l = 1, r = 1;
    for (int i=2; i<=n; i++){
        while (l<r and getVal(q[l], q[l+1]) <= h[i] << 1LL){
            l++;
        }
        dp[i] = dp[q[l]] + (h[i] - h[q[l]]) * (h[i] - h[q[l]]) + c;
        while (l < r and getVal(q[r-1], q[r]) >= getVal(q[r], i)){
            r--;
        }
        q[++r] = i;
    }
    cout << dp[n];


}
main(){
    faster();
    int T = 1;
    // cin >> T;
    while (T--){
        solve();
        cout << endl;
    }
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
    return 0;
}