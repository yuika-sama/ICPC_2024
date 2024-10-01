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

const int mxN = 1e6;
// Sieve of Erasthotenes
int p[mxN]; vi primes;
const int c = 1e9+7;
ll poww(ll a, ll b){
	if (b==0) return 1;
	ll tmp = poww(a, b/2);
	if (b%2==1) return (a * ((tmp*tmp)%c))%c;
	return (tmp*tmp)%c;
}

void cp() {

}

void solve(){

	for (ll i = 2; i < mxN; ++i) if (!p[i]) {
		for (ll j = i*i; j < mxN; j+=i) p[j]=1;
		primes.pb(i);
	}
	// Prime factors (up to 9*10^13. For greater see Pollard Rho)

	int num, n; cin >> num >> n;
	if (pow(trunc(sqrt(n)), 2) == n) {
		cout << 2*num;
		return ;
	}	
	set<int> factors;
	int ind=0, pf = primes[0];
	while (pf*pf <= n) {
		while (n%pf == 0) n /= pf, factors.insert(pf);
		pf = primes[++ind];
	}
	if (n != 1) factors.insert(n);

	cout << poww(num, factors.size());
}
main(){
	faster();
	int T = 1;
	while (T--){
		solve();
		cout << endl;
	}
	cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
	return 0;
}