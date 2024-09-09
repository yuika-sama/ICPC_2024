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
const int MAX = 100005;
int par[MAX], weight[MAX];
int find(int x){
	if (par[x] != x){
		int parent = par[x];
		par[x] = find(par[x]);
		weight[x] += weight[parent];
	}
	return par[x];
}
void Union(int a, int b, int w){
	int roota = find(a);
	int rootb = find(b);
	if (roota == rootb) return;
	par[rootb] = roota;
	weight[rootb] = w + weight[a] - weight[b];
}
void solve(){
	/*hav fun with coding*/
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		par[i] = i;
		weight[i] =0;
	}
	while (m--){
		char q; cin >> q;
		if (q == '!'){
			int a,b,w;
			cin >> a >> b >> w;
			Union(a,b,w);
		} else {	
			int a, b; cin >> a >> b;
			if (find(a) != find(b)) cout << "UNKNOWN";
			else cout << weight[b] - weight[a];
			cout << endl;
		}	
	}
}
main(){
	faster();
	int T = 1;
	cin >> T;
	while (T--){
		solve();
	}
	cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
	return 0;
}