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
#define T tuple<int, int, int>
const int oo = 1e9+7;

//end of template
char a[1005][1005];
int n, m;
int d[1005][1005];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool ok(int x, int y){
	return (x>=1 and y>=1 and x<=n and y<=m);
}
void solve(){
	/*hav fun with coding*/
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin >> a[i][j];
		}
	}
	memset(d, 0x3f, sizeof(d));
	priority_queue<T, vector<T>> q;
	for (int i=1; i<=n; i++){
		if (a[i][1] == '#'){
			q.push({0, i, 1});
			d[i][1] = 0;
		} else {
			q.push(1, i, 1);
			d[i][1] = 1;
		}
	}
	int res = 1e9;
	while (q.sz){
		auto [w, i, j] = q.top(); q.pop();
		if (w > d[i][j]) continue;
		if (j == m) {
			res = min(res, w);
			break;
		}
		for (int k=0; k<8; k++){
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if (ok(i1, j1)){
				if (a[i1][j1] == '#'){
					if (d[i1][j1] > w){
						q.push({w, i1, j1});
						d[i1][j1] = w;
					}else{
						if (d[i1][j1] > w + 1){
							q.push({w+1, i1, j1});
							d[i1][j1] = w+1;
						}
					}				
				}
			}
		}
	}
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