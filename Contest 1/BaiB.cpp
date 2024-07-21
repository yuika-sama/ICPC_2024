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
vector<pair<int, bool>> adj[100005];
int parrent[100005];
int par;
int _size[100005];
int st[3][100005];
bool vs[100005];
bool check_(string z){
	for (int i=0; i<z.sz; i++){
		if (z[i] != '4' and z[i] != '7'){
			return false;
		}
	}
	return true;
}
void dfs(int u){
	vs[u] = true;
	_size[par]++;
	parrent[u] = par;
	for (auto i:adj[u]){
		int x = i.fi;
		int y = i.sc;
		if (!vs[x] and !y){
			dfs(x);
		}
	}
}
void solve(){
	/*hav fun with coding*/
	int n;
	cin >> n;
	for (int i=1; i<=n; i++){
		int x, y;
		string w;
		cin >> x >> y >> w;
		bool c = check_(w);
		adj[x].pb({y, c});
		adj[y].pb({x, c});
	}
	for (int i=1; i<=n; i++){
		if (!vs[i]){
			par = i;
			dfs(i);
		}
	}
	ll res = 0;
	for (int i=1; i<=n; i++){
		int p = parrent[i];
		st[1][i] = n - _size[p];
	}
	for (int i=1; i<=n; i++){
		ll p = parrent[i];
		ll f = n - _size[p];
		res += (f*(f-1));
	}
	cout << res;
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