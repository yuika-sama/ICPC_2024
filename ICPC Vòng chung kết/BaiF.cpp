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
int swing(string s){
	reverse(al(s));
	int t = (s[0]-'0')*10 + s[1]-'0';
	return t;
}
void solve(){
	/*hav fun with coding*/
	string s; cin >> s;
	int a[20] = {0};
	for (auto i:s) a[i-'0']++;
	// for (auto i:s) if (a[i - '0'] > 0) a[i]++;
	if (s.sz == 2){
		for (int i=10; i<=100; i++){
			if (i%8==0 and swing(s) == i){
				cout << "YES";
				return;
			}
		}
	}
	bool r = false;
	if (Mod(s, 8)){
		cout << "YES";
		return;
	}
	for (int i=1; i<=9; i++){
		for (int j=1; j<=9; j++){
			for (int k=1; k<=9; k++){
				if (i==j and i==k){
					if (a[k] >= 3){
						if (k%2==0 and (k*10+k)%8==0){
							cout<< "YES";
							return;
						} else if (k%2==1 and (k*10+k)%8==4){

							cout << "YES";
							return;
						}
					}
				} else if (i==j and i!=k){
					if (a[i] >= 2 and a[k] >= 1){
						if (i%2==0 and (i*10+k)%8==0){

							cout << "YES";
							return;
						} else if (i%2==1 and (i*10+k)%8==4){

							cout << "YES";
							return;
						}
					}
				}
				else if (i==k and i!=j){
					if (a[i] >= 2 and a[j] >= 1){
						if (i%2==0 and (j*10+k)%8==0){

							cout << "YES";
							return;
						} else if (i%2==1 and (j*10+k)%8==4){

							cout << "YES";
							return;
						}
					}
				}
				else if (k == j and k != i){
					if (a[i] >= 1 and a[k] >= 2){
						if (i%2==0 and (j*10+k)%8==0){

							cout << "YES";
							return;
						} else if (i%2==1 and (j*10+k)%8==4){

							cout << "YES";
							return;
						}
					}
				} else if (k != i and k != j and j != i){
						if (a[i] >= 1 and a[j] >= 1 and a[k] >= 1){
							if (i%2==0 and (j*10+k)%8==0){
							cout << "YES";
							return;
						} else if (i%2==1 and (j*10+k)%8==4){
							cout << "YES";
							return;
						}	
					}
					
				}
			}
		}
	}
	cout << "NO";
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