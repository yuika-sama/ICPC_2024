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
struct state{
	vector<int> p;
	int step;
};
vi TH1(vi p, int n){
	vi newp = p;
	for (int i=0; i<n; i++){
		swap(newp[2*i], newp[2*i+1]);
	}
	return newp;
}
vi TH2(vi p, int n){
	vi newp = p;
	for (int i=0; i<n; i++){
		swap(newp[i], newp[i+n]);
	}
	return newp;
}
int bfs(int n, vector<int> p){
	queue<state> q;
	set<vector<int>> vs;
	q.push({p, 0});
	vs.ins(p);
	while (!q.empty()){
		state cur = q.front(); q.pop();
		if (is_sorted(al(cur.p))) return cur.step;
		vector<int> p1 = TH1(cur.p, n);
		if (vs.find(p1) == vs.end()){
			q.push({p1, cur.step+1});
			vs.ins(p1);
		}
		vector<int> p2 = TH2(cur.p, n);
		if (vs.find(p2) == vs.end()){
			q.push({p2, cur.step+1});
			vs.ins(p2);
		}
	}
	return -1;
}
void solve(){
	/*hav fun with coding*/
	int n; cin >> n;
	vector<int> p(2*n);
	for (auto& i:p) cin >> i;
	int res = bfs(n, p);
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