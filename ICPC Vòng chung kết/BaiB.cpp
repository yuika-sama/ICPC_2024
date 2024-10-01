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
vector<string> a;
bool Mod(string x, int n){
	int mod=(ll)(x[0]-'0');
	if (x.sz == 1){
		return mod%n==0;
	}
	for (int i=1; i<x.sz; i++){
		mod=((mod*10)%n+((x[i]-'0')%n))%n;
	}
	return mod == 0;
}
bool cmp(string a, string b){
	if (a.sz == b.sz) return a<b;
	return a.sz < b.sz;
}
void solve(){
	/*hav fun with coding*/
	int x; cin >> x;
	string r = ".";

	for (auto i:a){
		if (Mod(i, x)){
			r = i;
			break;
		}
	}
	if (r!=".") cout << r; else cout << -1;
}
main(){
	faster();
	int T = 1;  
	queue<string> q;
	q.push("8");
	q.push("6");
	while (true){
		string r = q.front();
		a.pb(r);
		q.pop();
		if (r.sz >= 200) break;
		int s = 0, t = 0;
		for (char i : r){
			if (i == '6') s++; else t++;
		}
		if (s ==0 ){
			q.push(r + '6');
			q.push(r + '8');
		} else q.push(r + r.back());
	}
	sort(al(a), cmp);
	cin >> T;
	while (T--){
		solve();
		cout << endl;
	}
	cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
	return 0;
}