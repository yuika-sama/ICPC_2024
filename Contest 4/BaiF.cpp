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
	int a, b,c;
	cin >> a >> b >> c;
	map<string, int> m;
	map<string, int> tmp;
	vector<string> v;
	while (a--){
		int x;
		string s;
		cin >> s >> x;
		tmp[s] += x;
		v.pb(s);
	}
	for (auto i:tmp){
		if (i.sc >= 20){
			m[i.fi]+=1;
		}
	}
	tmp.clear();
	while (b--){
		int x;
		string s;
		cin >> s >> x;
		tmp[s] += x;
		v.pb(s);
	}
	for (auto i:tmp){
		if (i.sc >= 20){
			m[i.fi]+=1;
		}
	}
	tmp.clear();
	while (c--){
		int x;
		string s;
		cin >> s >> x;
		tmp[s] += x;
		v.pb(s);
	}
	for (auto i:tmp){
		if (i.sc >= 20){
			m[i.fi]+=1;
		}
	}
	tmp.clear();

	int cnt =0 ;
	for (auto i:m) if (i.sc == 3) cnt++;
	cout << cnt << ' ';
	for (auto i:v){
		if (m[i] == 3){
			cout << i << ' ';
			m[i] = 0;
		}
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