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
int n;
bool vs[30], l[30], r[30];
int x[30];
int d;
void Try(int i){
	for (int j=1; j<=n; j++){
		if (!vs[j] and !l[i-j+n] and !r[i+j-1]){
			vs[j] = true;
			l[i-j+n] = true;
			r[i+j-1] = true;
			x[i] = j;
			if (i == n) d++;
			else Try(i+1);
			vs[j] = false;
			l[i-j+n] = false;
			r[i+j-1] = false;
		}
	}
}
void solve(){
	/*hav fun with coding*/
	cin >> n;
	d = 0;
	for (int i=1; i<=n; i++) x[i] = i;
	memset(vs, false, sizeof(vs));
	memset(l, false, sizeof(l));
	memset(r, false, sizeof(r));
	d = 0;
	Try(1);
	cout << d;
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