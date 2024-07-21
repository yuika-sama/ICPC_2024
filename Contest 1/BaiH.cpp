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
// sol: https://usaco.guide/problems/cses-1081-common-divisors/solution
void solve(){
	/*hav fun with coding*/
	int n; cin >> n;
	// int a[n+5];
	vector<int> occ(1e6+1);
	for (int i=0; i<n; i++) {
		// cin >> a[i];
		int x; cin >> x;
		occ[x]++;
	}
	for (int gcd = 1e6; gcd > 0; gcd--){
		int div = 0;
		for (int j = gcd; j <= 1e6; j+=gcd){
			div += occ[j];
		}
		if (div >= 2){
			cout << gcd;
			return;
		}
	}	
}
main(){
	faster();
	int T = 1;
	cin >> T;
	while (T--){
		solve();
		cout << endl;
	}
	cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
	return 0;
}