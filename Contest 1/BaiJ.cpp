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
vector<int> cal(vector<int> &a, int n){
	vector<int> res(n, 0);
	vector<int> left(n, -1), right(n, n);
	stack<int> s;
	for (int i=0; i<n; i++){
		while (!s.empty() and a[s.top()] >= a[i]) s.pop();
		if (!s.empty()) left[i] = s.top();
		s.push(i);
	}
	while(s.sz) s.pop();
	for (int i=n-1; i>=0; i--){
		while (!s.empty() and a[s.top()] >= a[i]) s.pop();
		if (!s.empty()) right[i] = s.top();
		s.push(i);
	}
	for (int i=0; i<n; i++){
		int len = right[i] - left[i] - 1;
		res[len-1] = max(res[len-1], a[i]);
	}
	for (int i=n-2; i>=0; i--){
		res[i] = max(res[i], res[i+1]);
	}
	return res;
}

void solve(){
	/*hav fun with coding*/
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	vector<int> res = cal(a, n);
	for (int i=0; i<n; i++){
		cout << res[i] << ' ';
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