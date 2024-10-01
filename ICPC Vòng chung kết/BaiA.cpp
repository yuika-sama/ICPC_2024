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
int n, m; 
int x[15], a[15];
int r;
bool Check(){
	stack<ll> st;
	st.push(a[0]);
	for (int i=1; i<n; i++){
		if (x[i] == 3){
			ll t = st.top();
			st.pop();
			t = ((t%m) * (a[i]%m))%m;
			st.push(t);
		} else if (x[i] == 2){
			st.push(a[i]*-1);
		} else st.push(a[i]);
	}
	ll res = 0;
	while (st.sz){
		res = res + st.top();
		st.pop();
	}
	return res%m==0;
}
void Try(int i){
	for (int j=1; j<=3;j++){
		x[i] = j;
		if (i == n-1){
			r += Check();
		} else Try(i+1);
	}
}
void solve(){
	/*hav fun with coding*/
	cin >> n >> m;
	memset(x, 0, sizeof(x));
	r = 0;
	for (int i=0; i<n; i++) cin >> a[i];
	Try(1);
	cout<<r;
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