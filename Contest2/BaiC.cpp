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
bool is_sorted(const vector<int>& P) {
    for (size_t i = 1; i < P.size(); ++i) {
        if (P[i] < P[i - 1]) return false;
    }
    return true;
}

// Function to apply operation 1
void apply_operation_1(vector<int>& P) {
    size_t N = P.size() / 2;
    for (size_t i = 0; i < 2 * N; i += 2) {
        swap(P[i], P[i + 1]);
    }
}

// Function to apply operation 2
void apply_operation_2(vector<int>& P) {
    size_t N = P.size() / 2;
    for (size_t i = 0; i < N; ++i) {
        swap(P[i], P[N + i]);
    }
}

// Function to find the minimum number of operations to sort the array
int minimum_operations(int N, vector<int>& P) {
    vector<int> original_P = P;
    int operations_count = 0;

    // Check by applying operation 1 and 2 alternately starting with operation 1
    for (int i = 0; i < 2 * N; ++i) {
        if (is_sorted(P)) return operations_count;
        if (operations_count % 2 == 0) {
            apply_operation_1(P);
        } else {
            apply_operation_2(P);
        }
        operations_count++;
    }

    // Reset and check by applying operation 1 and 2 alternately starting with operation 2
    P = original_P;
    operations_count = 0;
    for (int i = 0; i < 2 * N; ++i) {
        if (is_sorted(P)) return operations_count;
        if (operations_count % 2 == 0) {
            apply_operation_2(P);
        } else {
            apply_operation_1(P);
        }
        operations_count++;
    }

    return -1;
}

void solve(){
	/*hav fun with coding*/
	int n; cin >> n;
	vector<int> p(n*2);
	for (int i=0; i<2*n; i++){
		cin >> p[i];
	}
	cout << minimum_operations(n, p);
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