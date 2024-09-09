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
struct type{
	int i, j, id, type; 
};
const int N = 500001, Q = 500001, A = 500001;
int n, q, res[Q], last[A], bit[N];
type a[N+Q];

bool cmp(type u, type v){
	return (u.j < v.j or (u.j == v.j and u.type < v.type));
}
void update(int x, int k){
	for (x; x<=n; x+=x&-x) bit[x] += k;
}
int get(int x){
	int ans = 0;
	for (x; x>0; x-=x&-x) ans += bit[x];
	return ans;	
}
void solve(){
	/*hav fun with coding*/
	cin >> n >> q;
	for (int i=1; i<=n; i++){
		cin >> a[i].i;
		a[i].j = i, a[i].type = -1;
	}
	for (int i=1; i<=q; i++){
		cin >> a[i+n].i >> a[i+n].j;
		a[i+n].id = i;
	}
	sort(a+1, a+1+n+q, cmp);

	for (int i=1; i<=n+q; i++){
		if (a[i].type == -1){
			update(a[i].j, 1);
			if (last[a[i].i] > 0) update(last[a[i].i], -1);
			last[a[i].i] = a[i].j;
		} else {
			res[a[i].id] = get(a[i].j) - get(a[i].i-1);
		}
	}
	for (int i=1; i<=q; i++){
		cout << res[i] << endl;
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