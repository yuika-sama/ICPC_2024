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
	int n; cin >> n;
	string s; cin >> s, s = '-' + s;
	
	constexpr int mxN = 4000 + 3;
	ll prefR[mxN];
	ll prefG[mxN];
	ll prefB[mxN];
	memset(prefR, 0, sizeof(prefR));
	memset(prefG, 0, sizeof(prefG));
	memset(prefB, 0, sizeof(prefB));

	for (int i = 1; i <= n; ++i) {
		char c = s[i];
		if (c == 'R') {
			prefR[i]++;
		}
		if (c == 'G')
			prefG[i]++;
		if (c == 'B')
			prefB[i]++;
		prefR[i] += prefR[i-1];
		prefG[i] += prefG[i-1];
		prefB[i] += prefB[i-1];
	}

	ll ans = 0;

	for (int l = 1; l <= n; ++l) {
		for (int r = l+3;r<=n;++r) {
			if(s[l]=='R'&& s[r]=='G') {
				ans+=prefB[r]-prefB[l-1];
				int mid=(l+r)/2;
				if(s[mid]=='B' && mid-l==r-mid) ans--;
			}
						if(s[l]=='G'&& s[r]=='R') {
				ans+=prefB[r]-prefB[l-1];
				int mid=(l+r)/2;
				if(s[mid]=='B' && mid-l==r-mid) ans--;
			}
						if(s[l]=='R'&& s[r]=='B') {
				ans+=prefG[r]-prefG[l-1];
				int mid=(l+r)/2;
				if(s[mid]=='G' && mid-l==r-mid) ans--;
			}
						if(s[l]=='B'&& s[r]=='R') {
				ans+=prefG[r]-prefG[l-1];
				int mid=(l+r)/2;
				if(s[mid]=='G' && mid-l==r-mid) ans--;
			}
						if(s[l]=='B'&& s[r]=='G') {
				ans+=prefR[r]-prefR[l-1];
				int mid=(l+r)/2;
				if(s[mid]=='R' && mid-l==r-mid) ans--;
			}
									if(s[l]=='G'&& s[r]=='B') {
				ans+=prefR[r]-prefR[l-1];
				int mid=(l+r)/2;
				if(s[mid]=='R' && mid-l==r-mid) ans--;
			}		
		}
	}
	
	cout << ans << '\n';
}
main(){
	faster();
	solve();
	cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
	return 0;
}
