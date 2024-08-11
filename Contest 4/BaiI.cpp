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
#define sqr(x) x*x
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


void solve(){
	/*hav fun with coding*/
	int n; cin >> n;
	string s; cin >> s;
	int p = 0, m = 0;
	for (auto i:s){
		i == '+'? p++ : m++;
	}
	cin >> n;
	while (n--){
		ll a, b;
		cin >> a >> b;
		if (a == b){
			cout << (p == m?"YES":"NO") << endl;
			continue;
		}
		ll dif = m - p;
		ll t = a-b;
		if ((dif*b)%t == 0){
			ll k = (dif*b)/t;
			ll min_y1 = max(0LL, -k);
			ll max_y1 = min((ll)m, (ll)p - k);
			cout << (min_y1 <= max_y1?"YES":"NO");
		} else cout << "NO";
		cout << endl;
	}
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