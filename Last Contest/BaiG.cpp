#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pb push_back
#define endl '\n'
const int oo = 1e9+7;
vector<int> bitmask;
int n, res =0 ;
int get(string s){
	int mask  =0;
	for (char c : s) mask |= (1 << (c - 'a'));
	return mask;
}
void Try(int id, int curMask){
	if (id == n){
		if (curMask == (1 << 26) - 1) res ++ ;
		return;
	}
	Try(id+1, curMask);
	Try(id+1, curMask | bitmask[id]);
}
void solve() {
    cin >> n;
    bitmask.resize(n);
    for (int i=0; i<n; i++){
    	string w;
    	cin >> w;
    	bitmask[i] = get(w);
    }
    Try(0, 0);
    cout << res;
}

int main() {
    faster();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
    return 0;
}
