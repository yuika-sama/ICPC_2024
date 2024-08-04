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

	//sieve
	vector<bool> f(n+1, true);
	f[0] = false, f[1] = false;
	for (int i=2; i*i <= n; i++){
		if (f[i] == true){
			for (int j=i*i; j<=n; j+=i){
				f[j] = false;
			}
		}
	}
	vector<int> v;
	for (int i=1; i<=n; i++){
		if (f[i] == true){
			v.pb(i);
		}
	}

	//calclate
	if (n <= 2 or n%2==1) cout << 0;
	else {
		int res =0 ;
		for (int i=0; v[i] <= n/2; i++){
			int dif = n - v[i];
			if (binary_search(al(v), dif)){
				res++;
			}
		}
		cout << res;
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