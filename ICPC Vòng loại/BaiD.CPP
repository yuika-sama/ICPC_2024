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
bool c(int i){
	if (i<=10) return true;
	string s = to_string(i);
	for (int j=0; j<s.sz-1; j++){
		if (abs(s[j] - s[j+1]) > 1){
			return false;
		}
	}
	return true;
}

void solve(){
	/*hav fun with coding*/
	int n; cin >> n;
	queue<string> q;
	for (int i=1; i<=9; i++) q.push(to_string(i));
	int c =0;
	string t;
	while (true){
		c++;
		t = q.front();
		//cout<<t<<endl;
		q.pop();
		if(c==n) {
			break;
		}
		int n=t.size();
		int l= max(0,t[n-1]-1-'0');
		int r= min(9,t[n-1]+1-'0');
		for(int j=l;j<=r;j++){
			q.push(t+(char)(j+'0'));
		}

	}
	cout<<t;
}
main(){
	faster();
	int T = 1;
	// cin >> T;
	while (T--){
		solve();
		// int n=len(t);
		// int l= max(0,t[n-1]-'0');
	}
	cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
	return 0;
}